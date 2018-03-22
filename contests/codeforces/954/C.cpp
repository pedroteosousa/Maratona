#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[N];
int mx = 1000000000;

int main() {
	int n; scanf("%d", &n);
	set<int> s;
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);
		if (i != 0) {
			int k = abs(v[i] - v[i-1]);
			if (k == 0) {
				printf("NO\n");
				return 0;
			} else if (k != 1) {
				s.insert(k);
			}
		}
	}
	if (s.size() > 1) {
		printf("NO\n");
		return 0;
	} else {
		if (s.size() == 0) {
			printf("YES\n%d %d\n", mx, mx);
			return 0;
		} else {
			int y = *s.begin();
			int x = mx;
			for (int i=1;i<n;i++) {
				int k = abs(v[i] - v[i-1]);
				if (k == 1) {
					if ((v[i]-1)/y != (v[i-1]-1)/y) {
						printf("NO\n");
						return 0;
					}
				}
			}
			printf("YES\n%d %d\n", x, y);
		}
	}
    return 0;
}

