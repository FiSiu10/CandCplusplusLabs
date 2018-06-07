/*
 * A main() to demonstrate inheritance, polymorphism, virtual functions,
 * and an abstract class.
 * Uses classes: Shape, Rectangle, and Circle.
 * 
 * File:   main.cpp
 * Author: dale
 *
 * Created on November 7, 2011, 2:27 PM
 */

#include <cstdlib>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "ShapeStack.h"
#include "StackException.h"

using namespace std;

int main(int argc, char* argv[]) {
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Square s1(6, 9, 6);

    //Using ShapeStack
    ShapeStack *ss = new ShapeStack();
    ss->push(&c1);
    ss->push(&r1);
    ss->push(&c2);
    ss->push(&s1);

    c1.moveTo(27, 36); // move the first circle
    c2.moveTo(17, 4);  // this will move the second circle
    
    // Peeks at the top of the Stack
    try {
        cout << "Peek at top of Stack: ";
        ss->top()->draw();
    } catch (StackException& e) {
        cout << e.getMessage() << endl;
    }
    
    //Prints pops the Shape off the stack and draws it
    cout << "Pops the Shape off and draws it" << endl;
    while (ss->size() > 0) {
        try {
            ss->pop()->draw();
        } catch (StackException& e) {
            cout << e.getMessage() << endl;
        }
    }

    // This should cause an exception since the stay is empty
    try {
        ss->pop()->draw();
    } catch (StackException& e) {
        cout << e.getMessage() << endl;
    }
    
    // This should cause an exception since the stay is empty
    try {
        ss->top()->draw();
    } catch (StackException& e) {
        cout << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
