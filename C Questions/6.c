
#include<stdio.h>

int main() {
        int a[10];
        printf("Enter 10 numbers: ");
        for (int i = 0; i < 10; i++) {
                scanf("%d",&a[i]);
        }
        printf("\nThe numbers divisible by 5 are : \n");
        for (int i = 0; i < 10; i++) {
                if (a[i]%5==0) {
                        printf("%d ",a[i]);
                }
        }
        return 0;
}
