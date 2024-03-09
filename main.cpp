/**************************
Name: Abul Imam
Assignment: 5
Purpose of the file: This file will create a stack based
on the size passed from the user. It will utilize a struct
called Data to store id and information. Then it will test
the stack thoroughly for functionality and rigidity. 
***************************/

#include "main.h"


int main(int argc, char **argv) {
    /*********************************************
    This main function makes sure user provides 2 parameters (program name + int)
    while executing from command line. Otherwise the program doesn't run. The int is used
    to create a stack of that size. The stack uses an ADT struct (Data). Main() runs explicit
    and random tests to check the stack's rigidity and functionality.

    @param argc : argument count
    @param argv : argument vector/value

    @return 0 : successful execution

    @exception na : na
    *********************************************/
    
    srand(time(NULL));
    
    if (argc ==2 && isInteger(argv[1])){

        int user_size = std::stoi(argv[1]);

        cout << "\nAttempting to create a stack of size: " << user_size << endl;
        cout << "Note: This Stack accepts size >= 2. If any other No detected, it will Default to size: " << DEFAULTSIZE <<endl;
        cout << endl;

        Stack stack(user_size);
        int size = stack.getSize();
        cout << "Successfully created a Stack of size: " << size << endl;

        Data *myData = new Data;
        std::string randomStr;
        int value;

        //counters for tests
        int is_empty = 0;
        int peeked = 0;
        int popped = 0;
        int pushed = 0;

        cout << "\nBeginning tests..." << endl;

        /************************************************
        ******* UNDERFLOW TESTS *************************
        ************************************************/

       cout << "   Underflow tests  ==> ";

       for (int i=0; i < size*MULTIPLIER; i++){

        if (stack.isEmpty()){
            is_empty++;
        } else{
            is_empty--;
        }

        if (stack.peek(myData)){
            peeked++;
        } else{
            peeked--;
        }

        if (stack.pop(myData)){
            popped++;
        } else{
            popped--;
        }

        rand_string(&randomStr);
       
        if (stack.push(i+1, &randomStr)){
            pushed++;
            if (stack.peek(myData)){
                peeked++;
            } else{
                peeked--;
            }
            if (stack.pop(myData)){
                popped++;
            } else{
                popped--;
            }    
        } else{
            pushed--;
        }
       }

       if (peeked == 0 && 
           popped == 0 &&
           pushed == round(size*MULTIPLIER) &&
           is_empty == round(size*MULTIPLIER)){
           cout << "passed" << endl;
        } else{
            cout << "failed" << endl;
        }

        /************************************************
        ******* OVERFLOW TESTS **************************
        ************************************************/
        cout << "   Overflow tests ==> ";

        // reset counters for tests
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0;

        for (int i=0; i <= size; i++){
            value = rand() % MAX_INT + 1;
            rand_string(&randomStr);
            stack.push(value, &randomStr);
        }

        for (int i=0; i <size*MULTIPLIER; i++){
            if (stack.isEmpty()){
                is_empty++;
            } else{
                is_empty--;
            }

            if (stack.peek(myData)){
                peeked++;
            } else{
                peeked--;
            }

            if (stack.pop(myData)){
                popped++;
            } else{
                popped--;
            }

            rand_string(&randomStr);
            if (stack.push(i+1, &randomStr)){
                pushed++;
            } else{
                pushed--;
            }

            rand_string(&randomStr);
            if (stack.push(i+2, &randomStr)){
                pushed++;
            } else{
                pushed--;
            }
        }
        
        if (pushed == 0 &&
            popped == round(size*MULTIPLIER) &&
            peeked == round(size*MULTIPLIER) &&
            -is_empty == round(size*MULTIPLIER)){
                cout << "passed" <<endl;
            } else{
                cout << "failed" <<endl;
            }

        /************************************************
        ******** EMPTYING AND MORE UNDERFLOW TESTS ******
        ************************************************/
        
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0;

        cout << "   Simple underflow tests ==> ";

        //emptying stack
        for (int i=0; i<size+1; i++){

            if(stack.isEmpty()){
                is_empty++;
            } else{
                is_empty--;
            }

            if(stack.peek(myData)){
                peeked++;
            } else{
                peeked--;
            }

            if(stack.pop(myData)){
                popped++;
            } else{
                popped--;
            }
        }

        if (pushed == 0 &&
            popped == size-1 &&
            peeked == size-1 && 
            -is_empty == size-1) {
                cout << "passed" << endl;
            } else {
                cout << "failed" << endl;
        }

        /************************************************
        ******** MID-STACK TESTS ************************
        ************************************************/
        
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0;

        cout << "   Mid-stack tests ==> ";
        for (int i=0; i<int(size/2); i++){
            value = rand() % MAX_INT + 1;
            rand_string(&randomStr);
            stack.push(value, &randomStr);
        }

        for (int i=0; i<size*MULTIPLIER; i++){

            if (stack.isEmpty()){
                is_empty++;
            } else{
                is_empty--;
            }

            if (stack.peek(myData)){
                peeked++;
            } else{
                peeked--;
            }

            if (stack.pop(myData)){
                popped++;
            } else{
                popped--;
            }

            value = rand() % MAX_INT + 1;
            rand_string(&randomStr);
            if (stack.push(value, &randomStr)){
                pushed++;
            } else{
                pushed--;
            }
        }

        if(popped == round(size*MULTIPLIER) &&
           peeked == round(size*MULTIPLIER) &&
           pushed == round(size*MULTIPLIER) && 
           -is_empty == round(size*MULTIPLIER)) {
           cout << "passed" << endl;
        } else {
            cout << "failed" << endl;
        }

        /************************************************
        ******** RANDOM TESTS ***************************
        ** essentially this is only a crash test ********
        *************************************************/
       cout << "   Random testing ==> ";

       // clearing stack to start
       while(!stack.isEmpty()){
            stack.pop(myData);
       }

       // filling the stack half way with random numbers to begin random tests
       for (int i=0; i<int(size/2); i++){
            value = rand() % MAX_INT + 1;
            rand_string(&randomStr);
            stack.push(value, &randomStr);
       }

       int choice = rand() % CHOICES + 1;
       for (int i=0; i<size*RANDOM_MULTIPLIER; i++){
        switch(choice){
            case 1:
                //contains bad data (neg & pos int mixed)
                value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                rand_string(&randomStr);
                stack.push(value, &randomStr); 
                break;

            case 2:
                ///good data
                value = rand() % MAX_INT + 1;
                rand_string(&randomStr);
                stack.push(value, &randomStr);
                break;

            case 3: 
                //empty string
                value = rand() % MAX_INT + 1;
                randomStr = "";
                stack.push(value, &randomStr);
                break;

            case 4:
                stack.pop(myData);
                break;

            case 5:
                stack.peek(myData);
                break;

            case 6:
                stack.isEmpty();
                break;
        }
        choice = rand() % CHOICES + 1;

       }
       cout << "passed " << endl;

       cout << "Testing complete." << endl;

       //Deallocating memory
       delete myData;
    }
    else{
        cout << "Please enter 1 parameter: <program name> <parameter:int>"<< endl;
        cout << "Program only accepts INTEGER for stack size." <<endl;
    }
    return 0;
}
