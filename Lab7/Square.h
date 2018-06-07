/* 
 * File:   Square.h
 * Author: fionasiu
 *
 * Created on March 6, 2018, 3:07 PM
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include <iostream>

class Square : public Rectangle {
private:
    double side;
protected:
    void printMe(std::ostream& os) const;
public:
    /**
     * This constructor passes the x,y location to the base class constructor
     * in Rectangle and also initializes the Square's size.
     *
     * We choose to make this an inline function.
     *
     * @param s Side
     * @param xLoc Initial x coordinate
     * @param yLoc Initial y coordinate
     */
    inline Square(double s, int x, int y) : Rectangle(s, s, x, y) {
    }

    inline double getSide(void) const {
        return getWidth();
    }

    /**
     * The Square "draws" itself at its current location
     */
    void draw() const;
};

#endif /* SQUARE_H */

