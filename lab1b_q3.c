#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char text[1000], words[100][50];
    int count[100] = {0}, i, j, k = 0, n = 0;
    fgets(text, sizeof(text), stdin);
    for (i = 0; text[i]; i++) text[i] = tolower(text[i]);
    char *token = strtok(text, " ,.-\n");
    while (token) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[n], token);
            count[n++] = 1;
        }
        token = strtok(NULL, " ,.-\n");
    }
    for (i = 0; i < n; i++)
        printf("%s: %d\n", words[i], count[i]);
    return 0;
}
