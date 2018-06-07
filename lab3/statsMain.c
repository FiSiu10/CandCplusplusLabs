/* Prints all the results from the standard deviation and mean calculation
 * from numbers read from a file and into an output file
 * 
 * File:   statsMain.c
 * Author: Fiona Siu
 *
 * Created on January 23, 2018, 1:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"

int main(int argc, char *argv[]) {
    
    FILE *file;

    //Check to see if there are 2 command line arguments
    //If there isn't 2 command line arguments then the system will exit
    if (argc != 2) {
        fprintf(stderr, "Usage: %s fileName\n", argv[0]);
        return (EXIT_FAILURE);
    }

    //Open file and if it returns 0 then the file did not
    //open successfully
    if((file = fopen(argv[1], "r"))==NULL){
        fprintf(stderr, "Usage: %s fileName\n", argv[0]);
        return(EXIT_FAILURE);
    }

    //Read all the values in the file and update variables
    double x;
    int count;
    double sum = 0;
    double sumsq = 0;
    while (fscanf(file, "%lf", &x) == 1){
        count++;
        sum = sum + x;
        sumsq = (x*x) + sumsq;
    }
    
    if(count < 2){
        fprintf(stderr, "Usage: %s fileName\n", argv[0]);
        return(EXIT_FAILURE);
    }
    
    //Calculate mean and standard deviations and print results
    double average = mean(sum, count);
    double deviation = ssdev(sum, sumsq, count);
    
    //Concatenate output filename with "Result_" and prints results into that file
    char *result = "Result_"; 
    char *inFile = argv[1];
    char str[100];
    strncpy(str, result, 15);
    strncat(str, inFile, 50);
    FILE *dest = fopen(str, "w");
    printStats(dest, count, average, deviation);
    
    //close file
    fclose(file);
    fclose(dest);
    return (EXIT_SUCCESS);
}

//Prints output to console and into new output file
void printStats(FILE *dest, const int count, const double mean, const double ssdev){
    printf("%d Values, Mean = %6.5lf, Sample Standard Deviation = %6.5lf", count, mean, ssdev);
    fprintf(dest, "%d Values, Mean = %6.5lf, Sample Standard Deviation = %6.5lf", count, mean, ssdev);
}


