// problem: longest path in undirected graph
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define PB push_back

struct EDGE {
    int begin;
    int end;
    int len;
	
    EDGE(int b, int e, int l) {
		begin = b;
		end = e;
		len = l;
	}
};

struct VERTEX {
	int long_1;
    int long_2;
	vector<EDGE> edge;
};


int dfs(VERTEX v[], int parent, int next) {
	v[next].long_1 = 0;
	v[next].long_2 = 0;
    REP(i, v[next].edge.size()) {
        if (v[next].edge[i].end != parent) {
            v[next].long_1 = max(v[next].long_1, v[next].edge[i].len + dfs(v, next, v[next].edge[i].end));
            if(v[next].long_1 > v[next].long_2) {
                swap(v[next].long_1, v[next].long_2);
            }
        }
    }
	return v[next].long_2;
}


int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		// input
        int n;
		scanf("%d", &n);
		VERTEX v[n];
		int b, e, l;
		for(int i=0; i<n-1; i++) {
			scanf("%d %d %d", &b, &e, &l);
            --b;
            --e;
			v[b].edge.PB(EDGE(b, e, l));
			v[e].edge.PB(EDGE(e, b, l));
		}
        
        // solve
		dfs(v, -1, 0);
		
        // out
		int out = v[0].long_1 + v[0].long_2;
		REP(i, n) {
			out = max(out, v[i].long_1 + v[i].long_2);
		}
        printf("%d\n", out);
	}
	return 0;
}
