#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int ma[100][100];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	int n, m;
	scanf("%d %d", &n, &m); getchar();
	vector<int> p;
	for (int i=0;i<4;i++) p.push_back(i);
	char s[1000];
	int x0, xf, y0, yf;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			char c = getchar();
			if (c == '#') ma[i][j] = 1;
			else ma[i][j] = 0;
			if (c == 'S') {
				x0 = i;
				y0 = j;
			}
			if (c == 'E') {
				xf = i;
				yf = j;
			}
		}
		getchar();
	}
	int count = 0;
	scanf("%s", s);
	for (int i=0;i<4*3*2;i++) {
		int x = x0, y = y0;
		int k = strlen(s);
		for (int i=0;i<k;i++) {
			int op = s[i] - '0';
			x += dir[p[op]][0];
			y += dir[p[op]][1];
			if (x == xf && y == yf) {
				count++;
				break;
			}
			if (ma[x][y] == 1 || x < 0 || x >= n || y < 0 || y >= m) break;
		}
		next_permutation(p.begin(), p.end());
	}
	printf("%d\n", count);
    return 0;
}

