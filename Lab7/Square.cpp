/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Square.h"
/**
 * The draw() member function
 */
void Square::draw() const {
   std::cout << "Square of size [" << getWidth() << "." << getWidth() << "] drawn at " << getX() << " " << getY() << std::endl;
}


void Square::printMe(std::ostream& os) const {
    os << "Rectangle of size [" << getWidth() << "] at " << getX() << " " << getY();
}
 