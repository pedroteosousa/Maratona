#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int z[N];

void zf(vector<int> s) {
	int n = s.size();
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

vector<int> s;
int p[N];
int main() {
	int n; scanf("%d", &n);
	int h = 1;
	for (int i=0;i<n;i++) {
		scanf("%d", &p[i]);
		if (p[i] != 0) {
			s.pb(s[p[i]-1]);
		} else {
			s.pb(h);
			h++;
		}
	}
	zf(s);
	for (int i=0;i<n;i++) {
		printf("%d ", z[i]);
	}printf("\n");
	return 0;
}
