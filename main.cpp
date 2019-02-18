//
//  main.cpp
//  irvine class
//
//  Created by Eugene Sumaryev on 2/16/19.
//  Copyright © 2019 com.eugene All rights reserved.
//


#include <cctype>     // Provides isdigit
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include "LLstack.h"


using namespace std;
using class_program_stack::LLstack;

// PROTOTYPES for functions
bool evaluate_stack_tops(LLstack& numbers, char symbol);
void evaluate_expr(string& expr);
bool isNeg(stringstream& input);

string anotherstring;
LLstack numbers;

int main(int argc, const char * argv[]) {
    
    bool done;
    string input;
    
    while (!done){
        cout << "Type an expression:"<<endl;

         //get user input
         getline(cin, input);
         //convert input to stream
         stringstream check(input);

        //check if the user input is just 0
        //otherwise, evaluate the expression
        if (input.compare("0") == 0)
            done = true;
        if(!done)
            evaluate_expr(input);
    }
    return 0;
}

void evaluate_expr(string& expr){
    double result;
    double number;
    char symbol;
    string formattedString;
    const char DECIMAL = '.';
    LLstack numbers;
    bool badResult = false;
    
    //convert input string to a stream for parsing the expression
    stringstream line(expr);
    
    //continue to evaluate stream while the input is valid
    //and no '=' was encountered
    while (line && line.peek( ) != '='){
       if (isdigit(line.peek( )) || (line.peek( ) == DECIMAL) || (isNeg(line)))
       {
            line >> number;
            numbers.push(number);
        }
       else if (strchr("+-*/", line.peek( )) != NULL)
       {
           line >> symbol;
           //returns true if evaluation failed because of
           //bad operands
           badResult = evaluate_stack_tops(numbers, symbol);
       }
       else
           line.ignore( );
    }
    
    //check if stack is empty 
    if(!numbers.empty())
        result = numbers.pop();
    
    //if any extra operands are left
    //throw exception
    try {
        if(!numbers.empty())
                throw "Error too many operands";
    }
    catch (const char* msg) {
        cerr << msg << endl;
        badResult = true;
    }
    
    if(!badResult)
        cout<<result<<endl;
}

//function to check for negative numbers
bool isNeg(stringstream& line){
    bool negNumber = false;
    
    if (line.get() == '-')
        if(isdigit(line.peek()))
           negNumber = true;
    
    line.unget();
    return negNumber;
}



bool evaluate_stack_tops(LLstack& numbers, char symbol)
// Library facilities used: stack
{
    double operand1, operand2;
    bool badResultValue = false;
  
    //check if the stack is empty and then pop both operands
    //if a stack is empty during one of the pops
    //we have too many operators
    if(!numbers.empty())
         operand2 = numbers.pop( );
    
    try {
        if(numbers.empty())
            throw "Too many operators";
    }
    catch (const char* msg) {
        cerr << msg << endl;
        badResultValue = true;
    }
    


    if (!badResultValue) {
        operand1 = numbers.pop( );
        //if the operation is a division and one of the operators
        //is 0, throw an error
        try {
            if((operand1 == 0 || operand2 == 0) && symbol == '/')
                throw "Error division by zero";
            }
        catch (const char* msg) {
            cerr << msg << endl;
            badResultValue = true;
        }
    }
    
    //perform the necessary operation depending on the operator
    if (!badResultValue) {
        switch (symbol)
        {
            case '+': numbers.push(operand1 + operand2);
                break;
            case '-': numbers.push(operand1 - operand2);
                break;
            case '*': numbers.push(operand1 * operand2);
                break;
            case '/': numbers.push(operand1 / operand2);
                break;
        }
    }
    
    //returns true if division by zero was attempted
    //otherwise returns false which means good result
    return badResultValue;
    
}
/*
 OUTPUT:
 
 Type an expression:
 2.5 5.4 + =
 7.9
 Type an expression:
 10 40 + =
 50
 Type an expression:
 10 20 - =
 -10
 Type an expression:
 10 0 / =
 Error division by zero
 Type an expression:
 10 25 * / =
 Too many operators
 Type an expression:
 10 20 45 / =
 Error too many operands
 Type an expression:
 -10 -15 - =
 5
 Type an expression:
 102 12 45 25 / * - -2 / =
 -40.2
 Type an expression:
 0
 Program ended with exit code: 0
 */
















