/* 
 * File:   StackException.h
 * Author: fionasiu
 *
 * Created on March 6, 2018, 2:18 PM
 */
#ifndef STACKEXCEPTION_H
#define	STACKEXCEPTION_H

#include <string>

class StackException {
private:
    std::string message;
public:
    inline StackException(std::string msg) {
        message = msg;
    }

    inline std::string getMessage(void) {
        return message;
    }
};


#endif	/* STACKEXCEPTION_H */

