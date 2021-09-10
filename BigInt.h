#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct BigInt {
	struct string *num;	
};

// call swap(&number1, &number2) to swap values
void swap(struct BigInt **inp1, struct BigInt **inp2);


// call _print(number) for priting the value only
void _print(struct BigInt *inp);


// call _println(number) for printing the value and move to next line
void _println(struct BigInt *inp);


//call is_num(val) to check whether val is a valid number or not
int is_num(struct BigInt *inp);


//call crop(val) to change values like 0000123 to 123 and -0029 to -29	
void crop(struct BigInt *inp);


// takes input from user by calling _input() and retunrs BigInt type pointer
struct BigInt* _input();


// call struct BigInt *number = _assign("123") to assign value 123 to number
struct BigInt* _assign(char *number);


// call struct BigInt *number = __assign(val); to assign value val to your number
struct BigInt* __assign(struct BigInt *number);

// convert integer data type to BigInt type
struct BigInt* itob(int n);


// to change the current value of inp to number
// call _change(&number, "123");
void _change(struct BigInt **inp, char *number);


// to change the current value of inp to number
// call _change(&number, new_val);
//here new_val will be of BigInt type
void __change(struct BigInt **inp, struct BigInt *value);


// to get absolute value 
// call absolute(number);
struct BigInt* absolute(struct BigInt *number);






//return -1 if inp1 is lexicographically smaller than inp2 and 1 if inp1 is lexicographically greater than inp2;
// return 0 in case both are equal
// Condition: This function assumes than length of inp1 and inp2 is same 
int compare(struct BigInt *inp1, struct BigInt *inp2);

// to check whether passed two numbers are equal or not
int are_equal(struct BigInt *inp1, struct BigInt *inp2);

// to check whether passed two numbers are not equal
int are_not_equal(struct BigInt *inp1, struct BigInt *inp2);


// retunrs 1 if inp1 is less than inp2 , otherwise 0
int less_than(struct BigInt *inp1, struct BigInt *inp2);


// retunrs 1 if inp1 is less than or equal to inp2 , otherwise 0
int less_than_equal(struct BigInt *inp1, struct BigInt *inp2);



// retunrs 1 if inp1 is greater than inp2 , otherwise 0
int greater_than(struct BigInt *inp1, struct BigInt *inp2);


// retunrs 1 if inp1 is greater than or equal to inp2 , otherwise 0
int greater_than_equal(struct BigInt *inp1, struct BigInt *inp2);








// auxillary function to help us calculate addition of two numbers
//this function basically adds two positive numbers
struct BigInt* add_util(struct BigInt *inp1, struct BigInt *inp2);


// auxillary function to help us calculate subtraction of two numbers
// performs inp1 - inp2 where inp1 >= inp2 && inp2 >= 0
struct BigInt* subtract_util(struct BigInt *inp1, struct BigInt *inp2);


// function to perform inp1 + inp2
struct BigInt* add(struct BigInt *inp1, struct BigInt *inp2);


// function to perform inp1 - inp2
struct BigInt* subtract(struct BigInt *inp1, struct BigInt *inp2);


// auxillary function to help us calculate multiplication of two numbers
struct BigInt* multiply_util(struct BigInt *inp, int x, int count);


// function to perform inp1 * inp2
struct BigInt* multiply(struct BigInt *inp1, struct BigInt *inp2);


// function to perform division of two numbers
// this function takes 2 positive numbers inp1, inp2 and perform inp1 / inp2
// inp1 >= 0 && inp2 >= 0
struct BigInt* divide_util(struct BigInt *inp2, struct BigInt *inp1);


// function to perform inp1 / inp2
struct BigInt* divide(struct BigInt *inp1, struct BigInt *inp2);


// function to perform inp1 % inp2
struct BigInt* modulo(struct BigInt *inp1, struct BigInt *inp2);


// function to calculate x ^ y in log(y) time
struct BigInt* power(struct BigInt *x, struct BigInt *y);


// How to call them: 
/* 
these functions has return type void

call swap(&inp1, &inp2);           to swap passed 2 numbers
call _print(inp);                  to print the number
call _println(inp);                to print the number and end of line
call _change(&inp, temp);          to change current value of inp to char *temp
call __change(&inp, temp);         to change current value of inp to BigInt *temp

*/

/* 
these functions has return type int .. they will return 1 if condition is satisfied
0 if not satisfied.


call are_equal(inp1, inp2);               to perform inp1 == inp2
call are_not_equal(inp1, inp2);           to perform inp1 != inp2
call less_than(inp1, inp2);               to perform inp1 < inp2
call less_than_equal(inp1, inp2);         to perform inp1 <= inp2
call greater_than(inp1, inp2);            to perform inp1 > inp2
call greater_than_equal(inp1, inp2);      to perform inp1 >= inp2

*/


/* 

these functions has return type struct BigInt type*

call _assign(inp);                 here inp is character array                     
call __assign(inp);                here inp is BigInt data type varibale
call _input();                     to take BigInt type input from user
call itob(inp);                    to convert integer to BigInt type
call absolute(inp);                to perform |inp1| i.e make every num positive
call add(inp1, inp2);              to perform inp1 + inp2
call subtract(inp1, inp2);         to perform inp1 - inp2
call multiply(inp1, inp2);         to perform inp1 * inp2
call divide(inp1, inp2);           to perform inp1 / inp2
call modulo(inp1, inp2);           to perform inp1 % inp2
call power(inp1, inp2);            to perform inp1 ^ inp2

*/


