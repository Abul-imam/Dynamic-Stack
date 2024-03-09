/**************************
Name: Abul Imam
Assignment: 5
Purpose of the file: This file will contain
all the constructor, destructor, setters, getters,
attributes for a stack that can work with an ADT (struct).
***************************/

#include "stack.h"

Stack::Stack(int user_size){
    /* ****************************************
    Constructor : Creates a stack using user inputed size or a default size.

    @param user_size : integer passed from the caller. Entered by user in the command line.
    @return na : na
    @exception na : na 
    *********************************************/
   if (user_size >= 2){
        size = user_size;
   }else{
        size = DEFAULTSIZE;
   }
   stack = new Data*[size];
   top = -1;
}

Stack::~Stack(){
    /* ****************************************
    Destructor: Deallocates anything left on the stack and the stack itself.
    *********************************************/
   for (int i=0; i<=top; i++){
        delete stack[i];
   }
   delete[] stack;
}

bool Stack::push(int id, string *info){
    /* ****************************************
    Push an item to the top of the stack, if there is room

    @param (int) id : any integer
    @return (bool) : True/False for pushed/not pushed.
    @exception na : na
    *********************************************/
    bool pushed = false;
    if (top < size-1 && id > 0 && *info != ""){
        Data *structData = new Data;
        structData->id = id;
        structData->information = *info;
        stack[++top] = structData;
        pushed = true;
    }
    return pushed;
}

bool Stack::isEmpty(){
    /* ****************************************
    Check stack for empty state

    @param na : na
    @return (bool) : True/False for empty / not-empty
    @exception na : na
    *********************************************/
    return top < 0;
}

bool Stack::peek(Data *structData){
    /* ****************************************
    Peek an item from the top of the stack if there is one.

    @param (Data*) : pointer for struct Data provided by the caller
    @return (bool) : True/False for success/failure to peek
    @exception na : na
    *********************************************/
   bool peeked = false;
   if (!isEmpty()){
        structData->id = stack[top]->id;
        structData->information = stack[top]->information;
        peeked = true;
   }else{
        structData->id = -1;
        structData->information = "";
   }
   return peeked;
}

bool Stack::pop(Data *structData){
    /* ****************************************
    Pop/delete an item from the top of the stack, if there is one.

    @param (Data*) : pointer for struct Data provided by the caller
    @return (bool) : True/False for success/failure to pop.
    @exception na : na
    *********************************************/
    bool popped = false;
    if (!isEmpty()){
        structData->id = stack[top]->id;
        structData->information = stack[top]->information;
        delete stack[top--];
        popped = true;
    }else{
        structData->id = -1;
        structData->information = "";
    }
    return popped;
}

int Stack::getSize(){
    /* ****************************************
    Returns the size of the stack.

    @param na : na
    @return (int) : Size of the stack.
    @exception na : na
    *********************************************/
    return size;
}




