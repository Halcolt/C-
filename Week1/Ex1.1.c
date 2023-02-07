#include <stdio.h>

int main() {
    char str[50];
    int count[256] = {0};

    printf("Enter a string:\n");
    fgets(str, 50, stdin);

    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        count[(int) str[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("Character '%c' appeared %d times\n", i, count[i]);
        }
    }

    return 0;
}