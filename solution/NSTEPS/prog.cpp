#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    while (n--) {
        scanf("%d %d", &x, &y);
        if (x == y) {
            printf("%d\n", (x << 1) - (x & 1));
        } else if (x == y + 2) {
            printf("%d\n", (y << 1) + 2 - (y & 1));
        } else {
            printf("No Number\n");
        }
    }
    return 0;
}
