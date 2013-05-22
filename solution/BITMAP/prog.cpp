// approach: BFS
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define ST first
#define ND second


bool in_range(int x, int y, int w, int h) {
    if (x < 0 || y < 0 || x >= w || y >= h) { 
	return false;
    }
    return true;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        // input
        int n, m;
        scanf("%d %d", &n, &m);
        int matrix[n][m];
        memset(matrix, -1, n * m * sizeof(int));

        queue< pair<int, int> > todo;

        char line[m+1];
        REP(i, n) {
	    scanf("%s", line);
	    REP(j, m) {
                if (line[j] == '1') {
		    matrix[i][j] = 0;
		    todo.push(make_pair(i, j));
                }
            }
        }

        // process all vertexes
        pair<int, int> move[4] = { make_pair(1, 0), 
				  make_pair(-1, 0), 
				  make_pair(0, 1), 
				  make_pair(0, -1) };
        while (not todo.empty()) {
	    pair<int, int> next = todo.front();
	    todo.pop();
	    int nextVal = matrix[next.ST][next.ND] + 1;
	    REP(i, 4) {
		int new_x = next.ST + move[i].ST;
		int new_y = next.ND + move[i].ND;
		if (in_range(new_x, new_y, n, m) && matrix[new_x][new_y] == -1) {
		    matrix[new_x][new_y] = nextVal;
		    todo.push(make_pair(new_x, new_y));
		}
	    }
	}
       
        // output
        REP(i, n) {
	    REP(j, m) {
		printf("%d ", matrix[i][j]);
	    }
	    printf("\n");
        }
    }

    return 0;
}
