#include <stdio.h>

long f(long n);

long f(long n){
	if(n == 1){
		return 1;
	}
	else{
		return f(n - 1) + n;
	}
}

int main(void){
	long val = f(100);
	printf("%ld\n",val);
	return 0;
}