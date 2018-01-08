#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

vector<int> conn[N];
int p[N];

int dfs(int r) {
	for (auto a : conn[r]) {
		p[r] += dfs(a);
	}
	if (conn[r].size() == 0) return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=1;i<n;i++) {
		int a;
		scanf("%d", &a);
		a--;
		conn[a].push_back(i);
	}
	dfs(0);
	int count = 0;
	for (int i=0;i<n;i++) {
		if ((conn[i].size() != 0 && p[i] >= 3) || conn[i].size() == 0) {
			count++;
		}
	}
	if (count == n) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
    return 0;
}

