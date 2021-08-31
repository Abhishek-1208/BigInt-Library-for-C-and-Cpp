// Sample Program to understand working of BigInt library:

#include <stdio.h>
#include "BigInt.h"

int main() {

    struct BigInt *var1 = _init_with_value("123");
    struct BigInt *var2 = _init_with_value("20");
    struct BigInt *result;
    int res;


    // result = var1 + var2;
    result = add(var1, var2);
    _println(result);
    
    // result = var1 - var2;
    result = subtract(var1, var2);
    _println(result);
    
    // result = var1 * var2;
    result = multiply(var1, var2);
    _println(result);
    
    // result = var1 / var2;
    result = divide(var1, var2);
    _println(result);
            
    // result = var1 % var2;
    result = modulo(var1, var2);
    _println(result);
    
    
    // res = var1 < var2;
    res = less_than(var1, var2);
    if(res == 0) {
         printf("var1 is greater than or equal to var2\n");    
    }


    // res = var1 >= var2;
    res = greater_than_equal(var1, var2);
    if(res == 1) {
         printf("var1 is greater than or equal to var2\n");    
    }
    
    // res = var1 != var2;
    res = are_not_equal(var1, var2);
    if(res == 0) {
         printf("var1 is equal to var2\n");    
    }
    
    //take input from user
    result = _input();
    _println(result);


}

