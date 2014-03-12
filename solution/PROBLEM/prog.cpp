#include <stdio.h>
#include <cstring>


int values[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};
char line[10000];
int n;


int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", line);
        int len = strlen(line);
        int output = 0;
        for (int i = 0; i < len; i++) {
            output += values[line[i] - '0'];
        }
        printf("%d\n", output);
    }
    return 0;
}