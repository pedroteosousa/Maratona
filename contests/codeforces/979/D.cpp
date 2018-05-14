#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1e5 + 5;
const int A = 3;
const ll inf = 1791791791;
const ll mod = 1e9+7;

struct trie {
	struct node {
		int to[A], freq, end;
		int mn;
	};
	vector<node> t;
	int sz = 0;
	int offset = '0';

	// init trie
	void init() {
		node a;
		for (int i=0;i<A;i++) {
			a.to[i] = 0;
		}
		a.freq = 0;
		a.end = 0;
		a.mn = inf;
		t.pb(a);
	}

	// insert string
	void insert(char *s, int val, int p = 0) {
		//if (p == 0) printf("adding\n");
		t[p].freq++;
		t[p].mn = min(t[p].mn, val);
		if (*s == 0) {
			t[p].end++;
			return;
		}
		if (t[p].to[*s - offset] == 0) {
			t[p].to[*s - offset] = ++sz;
			node a;
			for (int i=0;i<A;i++) {
				a.to[i] = 0;
			}
			a.freq = 0;
			a.end = 0;
			a.mn = inf;
			t.pb(a);
		}
		insert(s+1, val, t[p].to[*s - offset]);
	}
	int search(int mx, int target) {
		int pos = 0;
		int cur = 0;
		/*printf("searching mx = %d, target = ", mx);
		for (int i=19;i>=0;i--) {
			printf("%d", (target>>i)&1);
		} printf("\n");*/
		for (int i=19;i>=0;i--) {
			int nx = ((target >> i) & 1);
			//printf("t[%d].mn = %d\n", pos, t[pos].mn);
			//printf("t[%d].to[%d] = %d\n", pos, nx, t[pos].to[nx]);
			if (t[pos].to[nx] != 0 && t[t[pos].to[nx]].mn <= mx) {
				pos = t[pos].to[nx];
				cur += (nx << i);
			} else {
				if (nx == 0) nx = 1;
				else nx = 0;
				if (t[pos].to[nx] != 0 && t[t[pos].to[nx]].mn <= mx) {
					pos = t[pos].to[nx];
					cur += (nx << i);
				} else {
					return -1;
				}	
			}
		}
		return cur;
	}
};

trie tr[N];
char sb[50];

int main() {
	int q; scanf("%d", &q);	
	set<int> a;
	for (int i=1;i<N;i++) {
		tr[i].init();
	}
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int u; scanf("%d", &u);
			for (int i=0;i<20;i++) {
				if (u & (1<<i)) sb[19-i] = '1';
				else sb[19-i] = '0';
			} sb[20] = '\0';
			//printf("sb = %s\n", sb);
			for (int i=1;i*i<=u;i++) {
				if (u % i == 0) tr[i].insert(sb, u);
				if ((u/i) != i) tr[u/i].insert(sb, u);
			}
		} else {
			int x, k, s; scanf("%d %d %d", &x, &k, &s);
			if (x % k != 0 || x >= s) {
				printf("-1\n");
				continue;
			}
			int mx = s-x;
			int b = (1<<20)-1;
			printf("%d\n", tr[k].search(mx, b^x));	
		}
	}
	return 0;
}

