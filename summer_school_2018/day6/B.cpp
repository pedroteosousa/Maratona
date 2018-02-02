#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int z[N];

void zf(const char *s) {
	int n = strlen(s);
	int l, r;
	l = r = 0;
	for (int i=0;i<n;i++) {
		if (i > r) {
			l = r = i;
			while (r < n && s[r] == s[r-l]) r++;
			z[i] = r-l;
			r--;
		}
		else {
			if (z[i-l] >= r-i+1) {
				l = i;
				while (r < n && s[r] == s[r-l]) r++;
				z[i] = r-l;
				r--;
			} else {
				z[i] = z[i-l];
			}
		}
	}
}

char s[N];
int p[N], pa[N], w[N];

int find(int x) {
	return (pa[x] == x) ? x : pa[x] = find(pa[x]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	pa[b] = a;
	w[a] += w[b];
}

int main() {
	int n; scanf("%d", &n);
	memset(s, 0, sizeof s);
	for (int i=0;i<n;i++) {
		w[pa[i] = i] = 1;
		scanf("%d", &p[i]);
	}
	for (int i=n-1;i>=0;i--) {
		int k = p[i]-1;
		while (k >= 0) {
			join(i--, k--);
		}
		if (p[i]-1 >= 0) i++;
	}
	char mander = 'a';
	for (int i=0;i<n;i++) {
		if (find(i) == i) s[i] = mander++;
	}
	for (int i=0;i<n;i++) {
		s[i] = s[find(i)];
	}
	//printf("s = %s\n", s);
	zf(s);
	for (int i=0;i<n;i++) {
		printf("%d ", z[i]);
	}printf("\n");
	return 0;
}
