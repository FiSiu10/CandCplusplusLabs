/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * This program makes change using Canadian currency denominations
 * Author: Fiona Siu
 *
 * Created on January 16, 2018, 12:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(void) {

    double price, tenderedAmount, changeDue, roundNumber, changeItemValue, nickels;
    int numOfChangeItems;
    
    //Prompt the user for purchase amount
    printf("Enter the amount of the purchase: ");
    // Read the number into purchaseAmount variable
    scanf("%lf", &price);
    
    //Prompt the user for amount tendered
    printf("Enter the amount tendered: ");
    //Read the number into tenderedAmount variable
    scanf("%lf", &tenderedAmount);
    
    //Calculate change due and print result
    changeDue = tenderedAmount - price;
    printf("Change Due is $%4.2lf\n", changeDue);
    
    //Round to nearest nickel and print result

    nickels = changeDue / 0.05;
    roundNumber = round(nickels)*0.05;

    printf("Rounded to the nearest nickel $%4.2lf\n", roundNumber);
    
    //Calculate denominations and print out the results
    changeItemValue = 20.00;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Twenties\n", numOfChangeItems);
    
    changeItemValue = 10.00;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Tens\n", numOfChangeItems);
    
    changeItemValue = 5.00;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Fives\n", numOfChangeItems);
    
    changeItemValue = 2.00;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Toonies\n", numOfChangeItems);
    
    changeItemValue = 1.00;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Loonies\n", numOfChangeItems);
    
    changeItemValue = 0.25;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Quarters\n", numOfChangeItems);
    
    changeItemValue = 0.10;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Dimes\n", numOfChangeItems);
    
    changeItemValue = 0.05;
    numOfChangeItems = changeDue / changeItemValue;
    changeDue = changeDue - numOfChangeItems * changeItemValue;
    printf("%d Nickels\n", numOfChangeItems);
    
    return (EXIT_SUCCESS);
}

