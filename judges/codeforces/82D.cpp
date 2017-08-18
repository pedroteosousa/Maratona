#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1791791791;

#define pb push_back

int v[N][N];
int val[N];
int p[N][N];
set<int> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &val[i]);
		s.insert(i);
	}
	if (n < 3) {
		if (n == 1) {
			printf("%d\n1\n", val[0]);
		}
		if (n == 2) {
			printf("%d\n1 2\n", max(val[0], val[1]));
		}
		return 0;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			v[i][j] = inf;
		}
	}
	v[0][0] = max(val[1], val[2]); p[0][0] = -1;
	v[1][0] = max(val[0], val[2]); p[1][0] = -1;
	v[2][0] = max(val[1], val[0]); p[2][0] = -1;
	for (int i=1;i<=(n-3)/2;i++) {
		int mn = inf;
		int id = -1;
		for (int j=0;j<n;j++) {
			int t = i*2;
			//printf("t = %d | j = %d | i = %d\n", t, j, i);
			if (j <= t) {
				v[j][i] = v[j][i-1] + max(val[t+1], val[t+2]); p[j][i] = j;
				if (v[t+1][i] > max(val[t+2], val[j]) + v[j][i-1]) {
					v[t+1][i] = max(val[t+2], val[j]) + v[j][i-1]; p[t+1][i] = j;
				}
				if (v[t+2][i] > max(val[t+1], val[j]) + v[j][i-1]) {
					v[t+2][i] = max(val[t+1], val[j]) + v[j][i-1]; p[t+2][i] = j;
				}
			}
			else {
				break;
			}
		}
	}
	int mn = inf;
	/*for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			printf("%d ", v[j][i]);
		}
		printf("\n");
	}*/
	int id = -1;
	if (n % 2 == 0) {
		for (int i=0;i<n;i++) {
			//printf("mn1 = %d\n", mn);
			int t = (v[i][(n-3)/2] + max(val[i], val[n-1]));
			if (t < mn) {
				mn = t;
				id = i;
			}
			//printf("mn2 = %d\n", mn);
		}
	}
	else {
		for (int i=0;i<n;i++) {
			int t = (v[i][(n-3)/2] + val[i]);
			if (t < mn) {
				mn = t;
				id = i;
			}
		}
	}
	vector<int> ord;
	int i = (n-3)/2;
	while (id != -1) {
		ord.pb(id);
		id = p[id][i--];
	}
	printf("%d\n", mn);
	for (i = ord.size()-1;i>=0;i--) {
		set<int>::iterator it = s.begin();
		int a, b, c;
		a = *it; it++;
		b = *it; it++;
		c = *it; it++;
		if (b == ord[i]) swap(a, b);
		if (c == ord[i]) swap(a, c);
		printf("%d %d\n", min(b,c)+1, max(b,c)+1);
		s.erase(b);
		s.erase(c);
	}
	while(s.size()) {
		printf("%d ", *s.begin()+1);
		s.erase(s.begin());
	}
	printf("\n");
    return 0;
}

