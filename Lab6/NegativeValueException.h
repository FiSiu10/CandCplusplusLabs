/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NegativeValueException.h
 * Author: fionasiu
 *
 * Created on March 3, 2018, 10:41 AM
 */

#ifndef NEGATIVEVALUEEXCEPTION_H
#define NEGATIVEVALUEEXCEPTION_H
#include <exception>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

    class NegativeValueException : public exception {
    public:
        virtual const char* what() const throw () {
            return "Negative values are not allowed";
        }
    };


#ifdef __cplusplus
}
#endif

#endif /* NEGATIVEVALUEEXCEPTION_H */

