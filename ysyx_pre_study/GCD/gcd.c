#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
		if(a%b==0)
				return abs(b);
		else{
				int result = gcd(b,a%b);
				return result;
		}
}
int main(void)
{
	int result = gcd(60,48);
	printf("gcd of 60 and 48 is %d\n", result);
	return 0;
}
