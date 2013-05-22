#include <stdio.h>

#define FOR(i, a, b) for( int i = a; i <= (b); i++)


int main() {
    int ans[101];
    ans[0] = 0;
    FOR(i, 1, 100) {
	ans[i] = i * i + ans[i-1];
    }
    int n;
    scanf("%d", &n);
    while (n > 0) {
	printf("%d\n", ans[n]);
	scanf("%d", &n);
    }
    return 0;
}