#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 1e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

char s[N];
int p[N];
int front[N], back[N];

int main() {
	int n;
	scanf("%s", s);
	n = strlen(s);
	int id = 0;
	set<int> rep;
	int j = 0;
	back[0] = -1;
	for (int i=0;i<=n;i++) {
		if (s[i] != s[i-1]) {
			p[id] = i-id;
			rep.insert(id);
			front[id] = i;
			back[i] = id;
			id = i;
		}
	}
	int m = 0, c = 0;
	while (front[m] < n && m < n) {
		int k = m;
		debug("m = %d, n = %d\n", m, n);
		while (k != n) {
			debug("%d %d\n", k, p[k]);
			p[k]--;
			if (k != m && front[k] < n) p[k]--;
			k = front[k];
		}
		for (int i=m;i<n;i=front[i]) {
			debug("%d (%d, %d) => %d %d\n", i, front[i], back[i], p[i], c);
			if (p[i] <= 0) {
				if (i == m) {
					m = front[i];
					continue;
				}
				if (front[i] == n) {
					front[back[i]] = n;
					continue;
				}
				front[back[i]] = front[i];
				back[front[i]] = back[i];
				if (s[front[i]] == s[back[i]]) {
					p[back[i]] += max(0, p[front[i]]);
					i = front[i];
					front[back[i]] = front[i];
					back[front[i]] = back[i];
				}
			}
		}
		//getchar();
		c++;
	}
	printf("%d\n", c);
    return 0;
}

