#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[100];
    int i, count = 0;

    printf("Enter main string: ");
    scanf("%s", str);

    printf("Enter substring: ");
    scanf("%s", sub);

    for(i = 0; i <= strlen(str) - strlen(sub); i++) {
        if(strncmp(&str[i], sub, strlen(sub)) == 0) {
            count++;
        }
    }

    printf("Occurrences: %d", count);

    return 0;
}
