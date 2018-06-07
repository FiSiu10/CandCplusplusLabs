/*
 * A linked implementation of a stack that can be used to store Shape objects
 *
 * File:   ShapeStack.h
 * Author: fionasiu
 *
 * Created on March 6, 2018, 2:18 PM
 */

#ifndef SHAPESTACK_H
#define	SHAPESTACK_H

#include <cstdlib>
#include "Shape.h"
#include "StackException.h"

class ShapeStack {
private:
    // The node that will be used for the Stack
    typedef struct stackNode {
        struct stackNode *next;
        Shape *theShape;
    } StackNode;

    /** A pointer to the StackNode at the top of the stack */
    StackNode *topItem;
    /** The number of Shapes currently on the stack */
    int count;
public:
    /** Constructor initializes the data members */
    inline ShapeStack () : topItem(NULL), count(0) {
    }

    /**
     * Push a Shape onto the stack
     *
     * @param shape Pointer to the Shape to be stored
     */
    void push (Shape *shape);

    /**
     * Remove a Shape from the stack
     *
     * @throw A StackException if the stack is empty
     * @return A pointer to the Shape
     */
    Shape* pop(void) throw (StackException);
    //Shape* pop(void);

    /**
     * Peek at the Shape at the top of the stack
     *
     * @throw A StackException if the stack is empty
     * @return
     */
    Shape* top(void) throw (StackException);
    //Shape* top(void);

    /**
     * The number of Shapes currently on the stack
     * @return That number
     */
    inline int size(void) {
        return count;
    }

    /**
     * Query if the stack is empty
     *
     * @return true if the stack is empty
     */
    inline bool isEmpty(void) {
        return count == 0;
    }
};


#endif	/* STACK_H */

