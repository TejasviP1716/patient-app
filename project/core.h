// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function get the integer value followed by newline char
int inputInt(void);

//This function get the positive integer as a value
int inputIntPositive(void);

//This function get the positive integer as a value within the boundaries of upper and lower limits
int inputIntRange(int lowerRange, int upperRange);

// This function get the input of a character out of a specific range
char inputCharOption(const char* strng);

// This function get the input of some string of a certain length
void inputCString(char* str, int minChar, int maxChar);

// for exclusive number
void inputCStringNumExc(char* string, int min, int max);

//This function display the array of ten digits as a formatted phone number
void displayFormattedPhone(const char* string);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
