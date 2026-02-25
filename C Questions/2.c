#include<stdio.h>

int main() {

	int num;
	printf("\nEnter the number: ");
	scanf("%d",&num);
	int sum = num + (num-1);
	printf("\nThe sum of current number (%d) and previous number (%d) is : %d\n",num,num-1,sum);
	return 0;
}
