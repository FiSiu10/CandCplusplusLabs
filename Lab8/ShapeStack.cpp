#include <cstdlib>
#include <iostream>
#include "ShapeStack.h"
#include "StackException.h"

/**
 * Push a Shape onto the stack
 *
 * @param shape Pointer to the Shape to be stored
 */
void ShapeStack::push(Shape *shape){
    StackNode *temp = new StackNode;
    temp->theShape = shape;
    temp->next = topItem;
    count++;
    topItem = temp;
}

/**
 * Remove a Shape from the stack
 *
 * @throw A StackException if the stack is empty
 * @return A pointer to the Shape
 */
Shape* ShapeStack::pop(void) throw (StackException) {
    
    if (isEmpty()) {
        throw StackException("Cannot remove Shape from the stack. It is empty.");
    }
    
    Shape *temp = topItem->theShape;
    StackNode *old = topItem;
    topItem = old->next;
    count--;
    delete old;
    return temp;
}

/**
 * Peek at the Shape at the top of the stack
 *
 * @throw A StackException if the stack is empty
 * @return
 */
Shape* ShapeStack::top(void) throw (StackException){
    if (isEmpty()){
        throw StackException("Cannot peek at the Shape. It is empty");
    }
    return topItem->theShape;
}