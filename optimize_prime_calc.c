#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(long number){
    int k = 1, a = 0, b = 0;
    long sr;
    switch(number){
		
        case 1: return 0;
        case 2: return 1;
        case 3: return 1;
        case 4: return 0;
        case 5: return 1;
        case 6: return 0;
        case 7: return 1;
    }
    if (number % 2 == 0) return 0;
    if (number % 3 == 0) return 0;
    sr = (int) sqrt(number);
    while (b < sr) {
        a = (6 * k) - 1;
        b = (6 * k) + 1;
        if (number % a == 0)
            return 0;
        if (number % b == 0)
            return 0;
        k += 1;
    }
    return 1;
}

int main() {
	
	int count = 0;
	printf("From to	  	  Prime Amount	   Non Prime Amount	  	Percentage\n");
	
	for (int i = 2; i <= 10000000; i++) {
		if(is_prime(i)) {
			//printf("Debug2\n");
			count++;
		}
		//printf("%d\n",i);
		if ((i % 1000000 == 0)){
			float percentage;
			percentage = (((float) count / i) * 100 );
			printf("2-%d	      %d		  %d		%f\n",i ,count, i-count, percentage);
			
		}
	}
					
		return 0;
	}
	
	
	
	

