#include <stdio.h>
#include "BigInt.h"

int main() {
        printf("Enter the 2 number: ");
        struct BigInt *val1 = _input();
        struct BigInt *val2 = _input();

        printf("their addition is ");
        _println(add(val1, val2));

        printf("their subtraction is ");
        _println(subtract(val1, val2));

        printf("their multiplication is ");
        _println(multiply(val1, val2));

        printf("their division is ");
        _println(divide(val1, val2));
        printf("35 raise to power 21 is ");
        _println(power(itob(35), itob(21)));

}
