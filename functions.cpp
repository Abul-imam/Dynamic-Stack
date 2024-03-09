/**************************
Name: Abul Imam
Assignment: 5
Purpose of the file: This file contains functions necessary for main()
to function properly. rand_str() generates strings, isInteger() verifies
if an array of char is Int or not. 
***************************/

#include "functions.h"

void rand_string(std::string *str){
    /*********************************************
    This function generates a random string that can
    be stored inside the struct Data.

    @param (string*) : string pointer for string provided by the caller.
    @return na : na
    @exception na : na
    *********************************************/

    // create size 1 to MAXSTRSIZE
    int rnum = rand() % MAXSTRSIZE + 1;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}

bool isInteger(char *input){
    /*********************************************
    This function checks if a pointer to an array of char is integer or not.

    @param (char*) : character pointer passed from caller
    @return (bool) : true/false indicating isInteger/notInteger
    @exception na : na

    @note : the function first checks if the 1st char pointer is empty/NULL.
    Then it uses strtol to convert to long integer. If the char array contains
    anything other than integers then the *endptr doesnt point to '\0'.
    *********************************************/
   bool isInteger = true;

   if (!input || *input == '\0'){
        isInteger = false;
   }else{
        char *endptr;
        strtol(input, &endptr, 10);

        if (*endptr != '\0'){
            isInteger = false;
        }
   }
   return isInteger;
}

