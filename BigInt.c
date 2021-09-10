// structure to represent out integer
struct BigInt {
	struct string *num;	
};

// call swap(&number1, &number2) to swap values
void swap(struct BigInt **inp1, struct BigInt **inp2) {
	
	struct BigInt *temp = *inp1;
	*inp1 = *inp2;
	*inp2 = temp;
	
}

// call _print(number) for priting the value only
void _print(struct BigInt *inp) {
	print(inp -> num);
}

// call _println(number) for printing the value and move to next line
void _println(struct BigInt *inp) {
	print(inp -> num);
	printf("\n");
}

//call is_num(val) to check whether val is a valid number or not
int is_num(struct BigInt *inp) {
	
	int idx = 0, len = size(inp -> num);
	if(len == 0) {
		return 1;
	}
	
	char temp = at(inp -> num, 0);
//	in case negative value is given
	if(temp == '-') {
		idx++;	
	}
		
	else if(temp < '0' || temp > '9') {
		return 0;
	}
	
	
	while(idx < len) {
		temp = at(inp -> num, idx);
		if(temp < '0' || temp > '9') {
			return 0;
		}
		else {
			idx++;
		}
	}
	
	return 1;
	
}


//call crop(val) to change values like 0000123 to 123 and -0029 to -29	
void crop(struct BigInt *inp) {

	int len = size(inp -> num);
	if(len == 0) {
		return;
	}
	
	int idx = 0, left = 0, count = 0;
	if(at(inp -> num, 0) == '-') {
		idx = 1;
		left = 1;
	}
	
	// eliminating all 0's before starting of a number
	while(idx < len && at(inp -> num, idx) == '0') {
		idx++;
		count++;
	}
	
	// in case -00000 or 0000 is given 
	if(idx == len) {
		clear(inp -> num);
		push_back(inp -> num, '0');
		return;	
	}
	
	
	while(idx < len) {
		
		//equals to of doing inp[left] = inp[idx]
		change_at(inp -> num, left, at(inp -> num, idx));
		
		idx++;
		left++;
	}
	
	// delete remaining digits after croping all initial zeroes
	while(count--) {
		pop_back(inp -> num);
	}
	
}

// takes input from user by calling _input() and retunrs BigInt type pointer
struct BigInt* _input() {
	
	struct BigInt *inp = (struct BigInt*)malloc(sizeof(struct BigInt));
	inp -> num = init();
	
	char x = '\0';
	while(scanf("%c", &x) && x != '\n' && x != ' ') {
		push_back(inp -> num, x);	
	}
//  if entered value is not an integer .. then exit
	if(is_num(inp) == 0) {
		printf("given value is not a number\n");
		exit(1);
	}
//  otherwise crop the number first and return it
	else {
		crop(inp);
		return inp;
	}
	
	
}

// call struct BigInt *number = _assign("123") to assign value 123 to number
struct BigInt* _assign(char *number) {
	
	struct BigInt *inp = (struct BigInt*)malloc(sizeof(struct BigInt));
	
	inp -> num = init_with_value(number);
	
	if(is_num(inp) == 0) {
		printf("given value is not a number\n");
		exit(1);
	}
	
	else {
		crop(inp);
		return inp;		
	}
	
}



// call struct BigInt *number = __assign(val); to assign value val to your number
struct BigInt* __assign(struct BigInt *number) {
	
	struct BigInt *inp = (struct BigInt *)malloc(sizeof(struct BigInt));
	inp -> num = init();
	
	// using assign_string function to ease the task.
	//see string.c file for assign_string implementation
	assign_string(inp -> num, number -> num );
	
	return inp;
	
}

// to convert integer data type to BigInt data type
struct BigInt* itob(int n) {
	
	if(n == 0) {
		return _assign("0");
	}
	
	int is_neg = (n < 0);
	n = abs(n);
	
	struct BigInt *result = (struct BigInt*)malloc(sizeof(struct BigInt));
	result -> num = init();
	
	while(n) {
		push_back(result -> num, '0' + n % 10);
		n /= 10;
	}
	
	if(is_neg) {
		push_back(result -> num, '-');
	}
	
	reverse(result -> num);
	return result;
	
}


// to change the current value of inp to number
// call _change(&number, "123");
void _change(struct BigInt **inp, char *number) {
	free(*inp);
	*inp = _assign(number);
}


// to change the current value of inp to number
// call _change(&number, new_val);
//here new_val will be of BigInt type
void __change(struct BigInt **inp, struct BigInt *value) {
	free(*inp);
	*inp = __assign(value);
}

// to get absolute value 
// call absolute(number);
// absolute(-5) = 5;
// absolute(5) = 5;
struct BigInt* absolute(struct BigInt *number) {
	
	struct BigInt *res = __assign(number);
	if(at(res -> num, 0) == '-') {
		erase(res -> num, 0);
	}
	
	return res;
	
}






//return -1 if inp1 is lexicographically smaller than inp2 and 1 if inp1 is lexicographically greater than inp2;
// return 0 in case both are equal
// Note: This function assumes than length of inp1 and inp2 is same 
int compare(struct BigInt *inp1, struct BigInt *inp2) {
	
	int len = size(inp1 -> num);
	int idx = 0;
	
	while(idx < len) {
		if(at(inp1 -> num, idx) < at(inp2 -> num, idx)) {
			return -1;
		}	
		else if(at(inp1 -> num, idx) > at(inp2 -> num, idx)) {
			return 1;
		}
		else {
			idx++;
		}
	}
	
	return 0;
	
}

// to check whether passed two numbers are equal or not
int are_equal(struct BigInt *inp1, struct BigInt *inp2) {
	
	int size1 = size(inp1 -> num);
	int size2 = size(inp2 -> num);
	// if size is not equal .. it means they are not equal
	if(size1 != size2) {
		return 0;	
	}
	
	return compare(inp1, inp2) == 0;
	
}


// simply return the negation of are_equal function
int are_not_equal(struct BigInt *inp1, struct BigInt *inp2) {
	return !are_equal(inp1, inp2);
}


// retunrs 1 if inp1 is less than inp2 , otherwise 0
int less_than(struct BigInt *inp1, struct BigInt *inp2) {
	
	//if inp1 is negative and inp2 is positive , clearly less than condition satisfied
	if(at(inp1 -> num, 0) == '-' && at(inp2 -> num, 0) != '-') {
		return 1;
	}
	// if inp1 is + and inp2 is - , it inp2 is less than , condition not satisfied
	else if(at(inp1 -> num, 0) != '-' && at(inp2 -> num, 0) == '-') {
		return 0;
	}
	
	//reaching here means they have same sign , so now we have to compare values
	else {
		int size1 = size(inp1 -> num);
		int size2 = size(inp2 -> num);
		// if both are negative
		if(at(inp1 -> num, 0) == '-') {
			if(size1 > size2) {
				return 1;	
			}
			else if(size1 < size2) {
				return 0;
			}
			else {
				return compare(inp1, inp2) == 1;
			}
		}
		
		// if both are positive
		else {
			if(size1 > size2) {
				return 0;	
			}
			else if(size1 < size2) {
				return 1;
			}
			else {
				return compare(inp1, inp2) == -1;
			}	
		}
		
	}
	
		
}

// simply check both conditions one by one and returns the result accordingly
int less_than_equal(struct BigInt *inp1, struct BigInt *inp2) {
	return less_than(inp1, inp2) || are_equal(inp1, inp2);
}


// negate the result of less_than_equal and get the desired answer
int greater_than(struct BigInt *inp1, struct BigInt *inp2) {
	return less_than_equal(inp1, inp2) == 0;
}

// simply negate the result of less_than function and get the answer
int greater_than_equal(struct BigInt *inp1, struct BigInt *inp2) {
	return less_than(inp1, inp2) == 0;
}









// auxillary function to help us calculate addition of two numbers
//this function basically adds two positive numbers
struct BigInt* add_util(struct BigInt *inp1, struct BigInt *inp2) {
	
	struct BigInt *ans = _assign("");
	int carry = 0;
	int i = size(inp1 -> num) - 1;
	int j = size(inp2 -> num) - 1;
	while(i >= 0 && j >= 0) {
		int sum = carry + (at(inp1 -> num,  i) - '0') + (at(inp2 -> num, j) - '0');
		push_back(ans -> num, '0' + sum % 10);
		carry = sum / 10;
		i--, j--;
	}
	
	while(i >= 0) {
		int sum = carry + (at(inp1 -> num, i) - '0');
		push_back(ans -> num, '0' + sum % 10);
		carry = sum / 10;
		i--;
	}
	
	while(j >= 0) {
		int sum = carry + (at(inp2 -> num, j) - '0');
		push_back(ans -> num, '0' + sum % 10);
		carry = sum / 10;
		j--;
	}
	
	if(carry) {
		push_back(ans -> num, '0' + carry);
	}	
	
	reverse(ans -> num);
	return ans;
}


// auxillary function to help us calculate subtraction of two numbers
// performs inp1 - inp2 where inp1 >= inp2 && inp2 >= 0
struct BigInt* subtract_util(struct BigInt *inp1, struct BigInt *inp2) {
	
	if(less_than(inp1, inp2)) {
		swap(&inp1, &inp2);
	}
	struct BigInt *result = _assign("");
	int carry = 0;	
	int len1 = size(inp1 -> num);
	int len2 = size(inp2 -> num);
	int gap = len1 - len2;
	int idx  = len2 - 1;
	while(idx >= 0) {
		int diff = (at(inp1 -> num, idx + gap) - '0') - (at(inp2 -> num, idx) - '0') - carry;
		if(diff < 0) {
			carry = 1;
			diff += 10;	
		}
		else {
			carry = 0;
		}
		push_back(result -> num, diff + '0');
		idx--;
		
	}
	
	idx = gap - 1;
	while(idx >= 0) {
		if(at(inp1 -> num, idx) == '0' && carry) {
			push_back(result -> num, '9');
			continue;
		}
		int diff = (at(inp1 -> num, idx) - '0') - carry; 
		if(idx > 0 || diff > 0) {
			push_back(result -> num, diff + '0');
		}
		carry = 0;
		idx--;
	}
	reverse(result -> num);
	crop(result);
	return result;
} 


// function to perform inp1 + inp2
struct BigInt* add(struct BigInt *inp1, struct BigInt *inp2) {
	
	/*check signs and perform accordingly*/
	
	if(at(inp1 -> num, 0) != '-' && at(inp2 -> num, 0) != '-') {
		return add_util(inp1, inp2);
	} 	
	
	if(at(inp1 -> num, 0) == '-' && at(inp2 -> num, 0) == '-') {
		struct BigInt *ans = add_util(absolute(inp1), absolute(inp2));
		insert_at(ans -> num, 0, '-');
		return ans;
	}
	
	if(less_than(inp1, itob(0))) {
		swap(&inp1, &inp2);
	}
	
	struct BigInt *abs1 = absolute(inp1), *abs2 = absolute(inp2);
	
	if(are_equal(abs1, abs2)) {
		return itob(0);
	}
	
	struct BigInt *result = subtract_util(abs1, abs2);
	
	if(less_than(abs1, abs2)) {
		insert_at(result -> num, 0, '-');
	}
	crop(result);
	return result;
		

}

// function to perform inp1 - inp2
struct BigInt* subtract(struct BigInt *inp1, struct BigInt *inp2) {
	/*check signs and perform accordingly*/
	struct BigInt *temp1 = __assign(inp1);
	struct BigInt *temp2 = __assign(inp2);
	
	if(at(temp1 -> num, 0) != '-' && at(temp2 -> num, 0) != '-') {
		insert_at(temp2 -> num, 0, '-');
		return add(temp1, temp2);
	} 	
	
	if(at(temp1 -> num, 0) == '-' && at(temp2 -> num, 0) == '-') {
		erase(temp2 -> num, 0);
		return add(temp1, temp2);
	}
	if(at(temp1 -> num, 0) != '-' && at(temp2 -> num, 0) == '-') {
		erase(temp2 -> num, 0);
		return add(temp1, temp2);
	}
	
	if(at(temp1 -> num, 0) == '-' && at(temp2 -> num, 0) != '-') {
		insert_at(temp2 -> num, 0, '-');
		return add(temp1, temp2);
	}
	
	
}


// auxillary function to help us calculate multiplication of two numbers
// it multiplies 2 positive numbers
struct BigInt* multiply_util(struct BigInt *inp, int x, int count) {
	
	struct BigInt *result = _assign("");	
	
	int idx = size(inp -> num) - 1;
	int carry = 0;
	while(idx >= 0) {
		int y = at(inp -> num, idx) - '0';
		int value = x * y + carry;
		carry = value / 10;
		push_back(result -> num, '0' + value % 10);
		idx--;
	}
	if(carry) {
		push_back(result -> num, '0' + carry);
	}
	reverse(result -> num);
	while(count--) {
		push_back(result -> num, '0');
	}
	crop(result);
	return result;
}


// returns inp1 * inp2
struct BigInt* multiply(struct BigInt *inp1, struct BigInt *inp2) {
	
	int is_neg = 0;
	if(less_than(inp1, itob(0)) == 1 && less_than_equal(inp2, itob(0)) == 0) {
		is_neg = 1;
	}
	else if(less_than_equal(inp1, itob(0)) == 0 && less_than(inp2, itob(0)) == 1) {
		is_neg = 1;
	}
	
	struct BigInt *temp1 = absolute(inp1), *temp2 = absolute(inp2);
	if(less_than(temp1, temp2)) {
		swap(&temp1, &temp2);
	}
	
	struct BigInt *result = itob(0);
	int idx = size(temp2 -> num) - 1, count = 0;
	
	while(idx >= 0) {
		result = add(result, multiply_util(temp1, at(temp2 -> num, idx) - '0', count++));
		idx--;
	}
	
	if(is_neg) {
		insert_at(result -> num, 0, '-');
	}
	
	return result;
	
}


// auxillary function to help us calculate division of two numbers
// performs inp2 / inp1
struct BigInt* divide_util(struct BigInt *inp2, struct BigInt *inp1) {
	struct BigInt *res = _assign(""), *rem = itob(0);

	while(!empty(inp2 -> num)) {
		int zeroes = -1;
		while(less_than(rem, inp1) && !empty(inp2 -> num)) {
			zeroes++;
			rem = add(multiply(rem, itob(10)), itob(at(inp2 -> num, 0) - '0'));
			erase(inp2 -> num, 0);
		}
		
		while(zeroes--) {
			push_back(res -> num, '0');
		}
		
		struct BigInt *temp = __assign(inp1);
		int count = 1;
		while(less_than_equal(add(temp, inp1), rem)) {
			temp = add(temp, inp1);
			count++;
		}
		if(less_than_equal(temp, rem) == 0) {
			count = 0;
		}
		
		push_back(res -> num, '0' + count);	
		rem = subtract(rem, temp);
		
	}
	
	
	crop(res);
	return res;
}

// peforms inp1 / inp2
struct BigInt* divide(struct BigInt *inp1, struct BigInt *inp2) {
	
	if(are_equal(inp2,itob(0))) {
		printf("Divison with 0 is not possible\n");
		exit(1);	
	}
	
	
	int is_neg = 0;
	if(less_than(inp1, itob(0)) == 1 && less_than_equal(inp2, itob(0)) == 0) {
		is_neg = 1;
	}
	else if(less_than_equal(inp1, itob(0)) == 0 && less_than(inp2, itob(0)) == 1) {
		is_neg = 1;
	}
	
	struct BigInt *val1 = absolute(inp1), *val2 = absolute(inp2);
	struct BigInt *result = divide_util(val1, val2);
	
	
	if(is_neg) {
		insert_at(result -> num, 0, '-');
	}
	
	return result;
	
}


// performs inp1 % inp2
struct BigInt* modulo(struct BigInt *inp1, struct BigInt *inp2) {

	if(are_equal(inp2,itob(0))) {
		printf("modulo with 0 is not possible\n");
		exit(1);	
	}
	
	struct BigInt *div = divide(inp1, inp2);
	struct BigInt *mul = multiply(div, inp2);
	struct BigInt *result = subtract(inp1, mul);
	return result;
}


//find x ^ y in log(y) time
struct BigInt* power(struct BigInt *x, struct BigInt *y) {
	struct BigInt *result = itob(1);
	
	while(greater_than(y, itob(0))) {
		if(are_equal(modulo(y, itob(2)), itob(1))) {
			__change(&result, multiply(result, x));
		}		
		__change(&x, multiply(x, x));
		__change(&y, divide(y, itob(2)));
	}
	return result;
	
}
