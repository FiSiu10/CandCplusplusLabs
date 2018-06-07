/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statistics.h
 * Author: Fiona Siu
 *
 * Created on January 23, 2018, 1:19 PM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

// Compute mean from sum and count 
double mean(const double sum, const int count);

// Compute sample standard deviation from sum, sum of squares, and
double ssdev(const double sum, const double sumsq, const int count);

//Print all the results into the file
void printStats(FILE *dest, const int count, const double mean,
        const double ssdev);

#endif /* STATISTICS_H */

