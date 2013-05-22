#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)


int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
	char line[210];
	scanf("%s", line);
	int len = strlen(line);
	
	// reverse even rows
	int rows = len / n;
	for (int r = 1; r < rows; r += 2) {
	    reverse(line + r * n, line + r * n + n);
	}

	// print output
	int pos = 0;
	REP(i, len) {
	    printf("%c", line[pos]);
	    pos = pos + n;
	    if (pos >= len) {
		pos = pos - len + 1;
	    }
	}
	printf("\n");
	scanf("%d", &n);
    }
    return 0;
}