#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[1000][5];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a; scanf("%d", &a);
		int k = max((a+2)/3, 3);
		for (int i=0;i<k;i++) {
			for (int j=0;j<3;j++) v[i][j] = 0;
		}
		bool flag = false;
		for (int i=2;i<k;i++) {
			while (v[i-2][0] == 0 || v[i-2][1] == 0 || v[i-2][2] == 0) {
				printf("%d %d\n", i, 2);
				fflush(stdout);
				int x, y; scanf("%d %d", &x, &y);
				if (x == -1) {
					exit(0);
				}
				if (x == y && x == 0) {
					flag = true;
					break;
				}
				v[x-1][y-1] = 1;
			}
			if (flag) break;
		}
		if (flag) continue;
		k = k-1;
		int x = 1, y = 1;
		do {
			printf("%d %d\n", k, 2);
			fflush(stdout);
			scanf("%d %d", &x, &y);
		} while(x != 0 || y != 0);
	}
    return 0;
}

