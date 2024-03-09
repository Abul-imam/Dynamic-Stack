/**************************
Name: Abul Imam
Assignment: 5
Purpose of the file: This file contains all
the directives needed for stack.cpp to run.
***************************/

#ifndef STACK_H
#define STACK_H

#define DEFAULTSIZE 10

#include "data.h"

class Stack {
    /*********************************************
     * This stack class works with an ADT (struct) that stores
     * id and infromation. It can be created dynamically using
     * user provided stack size or a default no.
     * 
     * @attrib top : index of the top element. -1 = empty
     * @attrib size : size of the stack.
     * @attrib (**stack) : pointer to a pointer used to access information inside struct (Data). 
     * *********************************************/

public:
    /**********************
     * Constructors/Destructor
     **********************/
    Stack(int);
    ~Stack();

    /**********************
     * Getters/Accessors
     **********************/
    bool isEmpty();
    bool peek(Data*);
    int getSize();

    /**********************
     * Setters/Mutators
     **********************/
    bool pop(Data*);
    bool push(int, string*);
  
private: 
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
