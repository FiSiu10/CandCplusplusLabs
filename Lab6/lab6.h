/*
 * This program makes change using Canadian currency denominations. 
 * 
 * File:   lab6.h
 * Author: Fiona Siu
 *
 * Created on March 3, 2018, 10:41 AM
 */

#ifndef LAB6_H
#define LAB6_H

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ChangeValue {\
        double revisedBalance;
        int numOfChangeItems;
    } ChangeValue;

    typedef struct Currency {
        double value;
        string name;
        string pluralName;
    } Currency;

    double getMoneyValue(string prompt);
    ChangeValue makeChange(double balance, double denominationValue);

#ifdef __cplusplus
}
#endif

#endif /* LAB6_H */

