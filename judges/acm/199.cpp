#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1791791791;

#define pb push_back

struct person {
	int s, b, index;
};

bool operator<(const person &a, const person &b) {
	if (a.s < b.s) return true;
	else if (a.s == b.s) {
		if (a.b < b.b) return true;
		else if (a.b == b.b) return a.index < b.index;
		else return false;
	}
	else return false;
}

vector<struct person> v;
vector< pair<struct person, int> > temp;
pair<int, int> mx[N];
int p[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.pb({a, b, i});
		mx[i+1] = {inf, inf};
	}
	mx[0] = {0, -1};
	mx[n+1] = {inf, inf};
	sort(v.begin(), v.end());
	int cur = 0;
	for (int i=0;i<n;i++) {
		if (cur != v[i].s) {
			cur = v[i].s;
			for (int j=0;j<temp.size();j++) {
				if (mx[temp[j].second].first > temp[j].first.b) {
					mx[temp[j].second] = {temp[j].first.b, temp[j].first.index};
				}
			}
			temp.clear();
		}
		int k = lower_bound(mx, mx+n+1, (pair<int, int>){v[i].b, v[i].index}) - mx - 1;
		//printf("k = %d && i = %d\n", k, i);
		if (mx[k].first < v[i].b) {
			p[v[i].index] = mx[k].second;
			temp.pb({v[i], k+1});
		}
	}
	for (int j=0;j<temp.size();j++) {
		if (mx[temp[j].second].first > temp[j].first.b) {
			mx[temp[j].second] = {temp[j].first.b, temp[j].first.index};
		}
	}
	int fi = -1;
	for (int i=0;i<=n+1;i++) {
		//printf("%d %d\n", mx[i].first, mx[i].second);
	}
	for (int i=0;i<=n+1;i++) {
		if (mx[i].second == inf) {
			fi = mx[i-1].second;
			printf("%d\n", i-1);
			break;
		}
	}
	while(fi != -1) {
		printf("%d ", fi+1);
		fi = p[fi];
	}
	printf("\n");
	return 0;
}

