#include<stdio.h>

int main() {

	int a,b,c;
	printf("\nEnter three numbers : ");
	scanf("%d %d %d",&a,&b,&c);
	
	if ( a>=b && a>=c)
		printf("\n%d is the greatest\n",a);
	else if (b>=a && b>=c)
		printf("\n%d is the greatest\n",b);
	else
		printf("\n%d is the greatest\n",c);
}
