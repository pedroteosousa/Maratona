#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	pair<int, int> f, l;
	bool found = false;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			char c; scanf(" %c", &c);
			if (c == 'B') {
				if (!found) f = mp(i, j);
				l = mp(i, j);
				found = true;
			}
		}
	}
	printf("%d %d\n", (l.first - f.first)/2 + f.first + 1, (l.second - f.second)/2 + f.second + 1);
    return 0;
}

