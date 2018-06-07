/* Compute mean and staple standard deviation from inputs
 * 
 * File:   statistics.c
 * Author: Fiona Siu
 *
 * Created on January 23, 2018, 1:18 PM
 */

#include <stdio.h>
#include <stdlib.h>

/* Compute mean from sum and count */
double mean(const double sum, const int count) {
    double mean = sum / count;
    return mean;
}

/* Compute sample standard deviation from sum, sum of squares, and
count */
double ssdev(const double sum, const double sumsq, const int count) {
    double ssdev = sqrt(((count*sumsq) - (sum*sum))/(count*(count-1)));
    return ssdev;
}