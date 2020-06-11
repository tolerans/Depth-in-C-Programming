#include <stdio.h>
#include <stdlib.h>
/**
 * Contains examples for 
 * the display of fixed and 
 * type definitions that are not changed
 * */
 
//# define EXIT_SUCCESS 0
//typedef unsigned long size_t ;

char const * const immutable [3] = {
	" This " ,
	" string is " ,
	" immutable " ,
};

enum value_list {name, height, weight, gender, age, enum_num, };

char const * const person [enum_num] = {
	[height] = "169cm",
	[weight] = "55kg",
	[gender] = "female",
	[age] = "32",
};

int main(void) {
	
	double A[5] = {
		[0] = 9.0,
		[1] = 2.9,
		[4] = 3.E+25,
		[3] = .00007,
	};
	
	for(size_t i = 0; i < 5; ++i){
		printf("Elements %zu is %g, \tits square is %g\n",
			   i,
			   A[i],
			   A[i]*A[i]);
	}
	
	//immutable[2] = "This is an error"; --> read only location 
	
	for ( unsigned i = 0; i < 3; ++ i)
		printf ("Corvid %u is the %s\n" , 
				i, 
				immutable[i]);
				
	for ( unsigned i = 0; i < enum_num; ++ i) //positional values ​​start from 0 to the index value enum_num (5)
		printf ("Person %u. attributes is the %s\n" , 
				i, 
				person[i]);
	
	return EXIT_SUCCESS;
}

