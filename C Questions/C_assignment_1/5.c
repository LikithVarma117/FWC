#include <stdio.h>

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(arr[0] == arr[n - 1])
        printf("First and Last numbers are the same");
    else
        printf("First and Last numbers are not the same");

    return 0;
}
