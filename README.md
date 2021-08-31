# BigInt Library for C and C++ language.


### Description:
#### Always face problem with big values in C or C++, well from now onwards, you don't have to because here is a BigInt Library for your problem.


## What is BigInt?

BigInt is a inbuilt library provided by java to handle very large values efficiently and effectively.So I have tried to implement same functionality in C 
because it doesn't support any such thing.

___

## Why we need BigInt?

This data type allows us to safely perform arithmetic operations on large integers without implementing our own methods or functions.
In many Real world problems, we have to deal with very large values that can't be fit inside the range available, so that's where it helps a lot and 
saves precious time of a programmers.

___


## Features:

1. Store as big number as you want.

2. can perform multiplication division, addition, subtraction on very big numbers.

3. Allows to calculate factorial of any value.

4. calculate as big power of a number as you want.

___

## How this Idea came: 

1. Many a times while solving problems, we need to deal with large values which can't fit in the 64-bit variable as well.

2. We can't get the exact answer sometimes just because it does'nt fit in the range, so we need to find the answer under some modulo.

3. To ease the task of programmers of implementing their own classes every time.

___


## Why BigInt instead of inbuilt data types:

1. allows performing arithmetic operation on as big number as user want.

2. No need to worry about overflows.

3. No need to worry about modulo.

4. Useful when exact answer is required instead of under modulo.

___


### Design And Specification: 

First Problem was that how to allow as big number as user want. To resolve this issue, I have first implemented the dynamic string class which can store as
big number as user wants. It stores the number in the form of string.

Created 2 files :
1. "string.h"
2. "BigInt.h"

Note: Here I will be only explaning about BigInt class and its feature, if you want to know more about string class, you can check that [Here](https://github.com/Abhishek-1208/string-file-for-C/blob/main/README.md)

___

## Working And Functionalities of BigInt Class:

### Working: First you have to include this "BigInt.h" file in your program. You can achieve this by writing following line: #include "BigInt.h"

#### Initialization: 
1. You can initialize a variable of BigInt type by writing "struct BigInt *var_name = _init();"
2. You can also initialize a variable with some pre defined value by passing it to function as follow: "struct BigInt *var_name = _init_with_value("123");"

Now Since We're done with the initialization part, lets see the different functionalities and operations on BigInt.

___

#### Functions used internally to check for valid input and crop the garbage part:

##### 1. To check whether given input is a number or not:

<pre>
   Syntax:           is_num(var1); <br>
   Task:             checks whether given input is a number or not. <br> 
   return type:      int. returns 0 if input is not a number otherwise 1. <br>
   Algorithm Used:   Simple check. <br>
   Time Complexity:  O(n) , where n = digits in var1 <br>
   Space Complexity: O(1) <br>
</pre>

##### 2. To crop the extra part if user entered. For eg: -00123 will be croped to -123 and 0028 will be croped down to 28.

<pre>
   Syntax:           crop(var1);<br>
   Task:             crop the unnecessary part.<br>
   return type:      void<br>
   Algorithm Used:   Simple implementation<br>
   Time Complexity:  O(n) , where n = digits in var1<br>
   Space Complexity: O(1)<br>
</pre>

___

#### Some Standard Functions:

##### To take Input from user:
<pre>
   Syntax:      struct BigInt *var_name = _input();<br>
   return Type: struct BigInt*<br>
   Exception:   throws error if input is not a number<br>
</pre>

##### To Print Values:
<pre>
   Syntax:     _print(struct BigInt *inp)   : print the value without putting end of line after the number.<br>
   Syntax:     _println(struct BigInt *inp) : print the value and move the cursor to next line.<br>
   return type: void for both.<br>
</pre>
___

#### Arithmetic Operations: 
<pre>
##### Addition:       add(var1, var2);        equivalent to var1 + var2

##### Subtraction:    subtract(var1, var2);   equivalent to var1 - var2

##### Multiplication: multiply(var1, var2);   equivalent to var1 * var2

##### Division:       divide(var1, var2);     equivalent to var1 / var2

##### Modular:        modulo(var1, var2);     equivalent to var1 % var2
</pre>


##### 1. Addition: 
<pre>
   Syntax:           add(var1, var2);<br>
   Task:             Perform var1 + var2 and return the result of it.<br>
   return type:      BigInt type.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(n + m) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(max(n, m)) , To store the final value and return.<br>
</pre>
___

##### 2. Subtraction: 
<pre>
   Syntax:           subtract(var1, var2);<br>
   Task:             Perform var1 - var2 and return the result of it.<br>
   return type:      BigInt type.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(n + m) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(max(n, m)) , To store the final value and return.<br>
</pre>
___

##### 3. Multiplication: 
<pre>
   Syntax:           multiply(var1, var2);<br>
   Task:             Perform var1 * var2 and return the result of it.<br>
   return type:      BigInt type.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(n * m) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(n + m) , To store the final value and return.<br>
</pre>
___

##### 4. Division: 
<pre>
   Syntax:           divide(var1, var2);<br>
   Task:             Perform var1 / var2 and return the result of it.<br>
   return type:      BigInt type.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer or if var2 is 0.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(n * m) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(max(n, m)) , To store the final value and return.<br>
</pre>
___

##### 5. Modular:
<pre>
   Syntax:           modulo(var1, var2);<br>
   Task:             Perform var1 % var2 and return the result of it.<br>
   return type:      BigInt type.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer or if var2 is 0.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(n * m) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(max(n, m)) , To store the final value and return.<br>
</pre>
___

### Relational Operations:

#### Note: return value of all these 6 relations function will be either 1 or 0. 1 for true(condition is true) and 0 for false(condition is false).

##### 1. less than: 
   
<pre>
   Syntax:           less_than(var1, var2);<br>
   Task:             Perform var1 < var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___

##### 2. less than or equal to: 
   
<pre>
   Syntax:           less_than_equal(var1, var2);<br>
   Task:             Perform var1 <= var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___

##### 3. greater than: 
   
<pre>
   Syntax:           greater_than(var1, var2);<br>
   Task:             Perform var1 > var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___

##### 4. greater than or equal to: 
   
<pre>
   Syntax:           greater_than_equal(var1, var2);<br>
   Task:             Perform var1 >= var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___

##### 5. Equality: 
   
<pre>
   Syntax:           are_equal(var1, var2);<br>
   Task:             Perform var1 == var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___

##### 6. Not Equal:

<pre>
   Syntax:           are_not_equal(var1, var2);<br>
   Task:             Perform var1 != var2 and return the result of it.<br>
   return type:      int.<br>
   Exception:        Throws error if either of var1 or var2 is not an integer.<br>
   Algorithm Used:   School Mathematics.<br>
   Time Complexity:  O(max(n, m)) , where n = digits in var1, m = digits in var2.<br>
   Space Complexity: O(1) , To store the final value and return.<br>
</pre>
___


## See the sample Program by clicking [Here.](https://github.com/Abhishek-1208/BigInt-Library-for-C-and-Cpp/blob/main/sample_BigInt_Program.c)


