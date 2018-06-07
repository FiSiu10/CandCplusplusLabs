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
#include <vector>
#include <stdexcept>
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
    
    // Adds shape into vector
    vector <Shape*> shape;
    shape.push_back(&c1);
    shape.push_back(&r1);
    shape.push_back(&c2);
    shape.push_back(&s1);
    shape.pop_back();    
    
    cout << "shape.front() is " << *shape.front() << endl;
    cout << "shape.back() is " << *shape.back() << endl;
    cout << "shape.capacity() is " << shape.capacity() << endl;
    cout << "shape.max_size() is " << shape.max_size() << endl;
   
    // Print out shape at index 2
    try{
        cout << "shape at index 2 is " << *shape.at(2) << endl;
    }catch(const std::out_of_range& oor){
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    
    
    // Print out shape at index 4 should throw an error
    try{
        cout << "shape at index 4 is " << *shape.at(4) << endl;
    }catch(const std::out_of_range& oor){
        std::cerr << "out of range " << oor.what() << '\n';
    }
    
    int p = shape.size();
    cout << "Pop back list size of " << p << endl;  
    
    // Add r2 to the beginning of the vector
    Rectangle r2(1, 2, 3, 4);
    vector<Shape*>::iterator i3 = shape.begin();
    shape.insert(i3, &r2);
    cout << "shape.front() is " << *shape.front() << endl;
    int n = shape.size();
    cout << "Pop back list size of " << n << endl;    
    
    // Print the items in the vector
    for (vector<Shape*>::iterator i1 = shape.begin(); i1 != shape.end(); i1++){
        cout << *(*i1) << endl;
    }

    return EXIT_SUCCESS;
}
