#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1791791791;

#define pb push_back

pair<pair<int, int>, int> v[N], mx[N];
int lis[N], p[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[i] = {{a, b}, i};
		lis[i] = 1;
		mx[i+1] = {{inf, inf}, inf};
	}
	sort(v, v+n);
	mx[0] = {{0, 0}, -1};
	for (int i=0;i<n;i++) {
		int j = lower_bound(mx+1, mx+n+1, v[i]) - mx - 1;
		//printf("j = %d -> %d %d %d\n", j, mx[j].first.first, mx[j].first.second, mx[j].second);
		if (mx[j].first.first < v[i].first.first && mx[j].first.second < v[i].first.second) {
			lis[i] = max(lis[i], j+1);
			p[v[i].second] = mx[j].second;
			mx[j+1] = min(mx[j+1], v[i]);
			//printf("j = %d i = %d p = %d\n", j, i, p[i]);
		}
	}
	int mxx = 0;
	int id = inf;
	for (int i=0;i<n;i++) {
		if (mxx < lis[i]) {
			mxx = lis[i];
			id = v[i].second;
			//printf("%d\n", i);
		}
	}
	printf("%d\n", mxx);
	while(id != -1) {
		printf("%d ", id+1);
		id = p[id];
	}
	printf("\n");
    return 0;
}

