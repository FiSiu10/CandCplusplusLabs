/*
 * This program makes change using Canadian currency denominations.
 *
 * File:   lab6.cpp
 * Author: Fiona Siu
 *
 * Created on March 3, 2018, 10:24 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
#include "lab6.h"
#include "NegativeValueException.h"

using namespace std;

static const Currency currency[] = {
    {20.00, "Twenty", "Twenties"},
    {10.00, "Ten", "Tens"},
    {5.00, "Five", "Fives"},
    {2.00, "Twoonie", "Twoonies"},
    {1.00, "Loonie", "Loonies"},
    {0.25, "Quarter", "Quarters"},
    {0.10, "Dime", "Dimes"},
    {0.05, "Nickel", "Nickels"}
};

/* Prompts the user for a money value and will throw an
 * exception if the value is negative
 */

double getMoneyValue(string prompt) {
    double amount = 0.0;
    cout << prompt;
    cin >> std::setprecision(2) >> std::fixed >> amount;

    if (amount < 0.0) {
        NegativeValueException nve;
        throw nve;
    }
    return amount;
}

/*
 * Calculates the number of items to be returned based on the denomination
 * 
 * @return Number of items based on the denomination
 */
ChangeValue makeChange(double balance, double denominationValue) {
    ChangeValue total;
    total.numOfChangeItems = balance / denominationValue;
    total.revisedBalance = total.revisedBalance - (total.numOfChangeItems * denominationValue);
    return total;
}

int main(void) {

    string getTotal = "Enter the amount of the purchase $";
    double amount, tender;

    try {
        amount = getMoneyValue(getTotal);
    }catch (NegativeValueException& e) {
        cout << e.what() << '\n';
        amount = getMoneyValue(getTotal);
    }

    string getTender = "Enter the amount tendered $";

    try {
        tender = getMoneyValue(getTender);
    }catch (NegativeValueException& e) {
        cout << e.what() << '\n';
        amount = getMoneyValue(getTotal);
    }

    while (tender < amount) {
        cout << "Not enough money tendered. Try again.\n";
        amount = getMoneyValue(getTotal);
        tender = getMoneyValue(getTender);
    }

    double changeDue = tender - amount;
    cout << "Change Due is $" << std::setprecision(2) << std::fixed << changeDue;

    double nickels = changeDue / currency[7].value, roundNumber;
    roundNumber = round(nickels) * currency[7].value;
    cout << "\nRounded to the nearest nickel $" << std::setprecision(2) << std::fixed << roundNumber;

    ChangeValue value;

    for (int i = 0; i < sizeof (currency); i++) {
        double changeItemValue = currency[i].value;
        value = makeChange(changeDue, changeItemValue);
        if (value.numOfChangeItems > 1) {
            cout << "\n" << value.numOfChangeItems << " " << currency[i].pluralName;
        }
        if (value.numOfChangeItems == 1) {
            cout << "\n" << value.numOfChangeItems << " " << currency[i].name;
        } 
    }

    return (EXIT_SUCCESS);

}



