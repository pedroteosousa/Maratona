#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1005;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int ma[N][N];
vector<int> conn[N];
int dist[N][5];

void bfs(int k, int p) {
	queue<int> q;
	dist[k][p] = 0;
	q.push(k);
	while (q.size()) {
		int n = q.front();
		q.pop();
		for (auto a : conn[n]) {
			if (a == k || dist[a][p] != 0) continue;
			q.push(a);
			dist[a][p] = dist[n][p] + 1;
		}
	}
}

int main() {
	int n, m, s, t; scanf("%d %d %d %d", &n, &m, &s, &t);
	s--; t--;
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		ma[a][b] = ma[b][a] = 1;
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	bfs(s, 0); bfs(t, 1);
	int d = dist[t][0];
    int resp = 0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (ma[i][j] == 0) {
				if(dist[i][0] + dist[j][1] + 1 >= d && dist[i][1] + dist[j][0] + 1 >= d) resp++;
			}
		}
	}
	printf("%d\n", resp);
	return 0;
}

