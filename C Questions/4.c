#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int n, i;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter number of characters to remove: ");
    scanf("%d", &n);

    for(i = n; i <= strlen(str); i++) {
        str[i - n] = str[i];
    }

    printf("Updated string: %s", str);

    return 0;
}
