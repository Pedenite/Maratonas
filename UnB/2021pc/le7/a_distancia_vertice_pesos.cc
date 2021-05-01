#include <bits/stdc++.h>
using namespace std;

#define MAX (int) (2e4+1)
#define oo 0x7fffffff
typedef vector<vector<pair<int, int>>> grafo;

int d[MAX];
int n;
grafo g(MAX);

void dijkstra(int start){
	for(int u = 1; u <= n; u++)
		d[u] = oo;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[start] = 0;
	pq.push(make_pair(d[start], start));

	int dt, w;
	int u, v;
	while(!pq.empty()){
		tie(dt, u) = pq.top();
        pq.pop();
		if(dt > d[u])
            continue;

		for(auto edge : g[u]){
			tie(v, w) = edge;

			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push(make_pair(d[v], v));
			}
		}
	}
}

int main() {
    int m, s, q, a, b, w, x;

    scanf("%d %d %d %d", &n, &m, &s, &q);
    while (m--) {
        scanf("%d %d %d", &a, &b, &w);
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }

    dijkstra(s);
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", d[x]);
    }

    return 0;
}
