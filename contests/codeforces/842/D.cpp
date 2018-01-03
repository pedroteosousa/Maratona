#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 2e6 + 5;
const int A = 3;
const int inf = 1791791791;
const int mod = 1e9+7;


typedef struct trie {
	int swap[20];
	struct node {
		int to[A], freq, end;
	};
	struct node t[N];
	int sz = 0;
	int offset = '0';

	void init() {
		memset(t, 0, sizeof(struct node));
		memset(swap, 0, sizeof(swap));
	}
	
	void insert(const char *s, int p = 0) {
		t[p].freq++;
		if (*s == 0) {
			t[p].end++;
			return;
		}
		if (t[p].to[*s - offset] == 0)
			t[p].to[*s - offset] = ++sz;
		insert(s+1, t[p].to[*s - offset]);
	}

	int mex(int p = 0, int prof = 19) {
		int k = swap[prof];
		if (t[p].to[k] == 0) return 0;
		else {
			if (t[t[p].to[k]].freq < (1<<prof)) {
				return mex(t[p].to[k], prof-1);
			} else {
				if (t[p].to[1^k] == 0) {
					return (1<<prof);
				} else {
					return (1<<prof) + mex(t[p].to[1^k], prof-1);
				}
			}
		}
	}
} trie;

int main() {
	trie t; t.init();
	int n, m; scanf("%d %d", &n, &m);
	set<int> all;
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		all.insert(a);
	}	
	for (auto a : all) {
		char s[50];
		for (int i=19;i>=0;i--) {
			s[19-i] = ((a & (1<<i))>0) + 48;
		} s[20] = '\0';
		t.insert(s);
	}
	while (m--) {
		int a; scanf("%d", &a);
		for (int i=19;i>=0;i--)
			t.swap[i] = (((a>>i)&1) ^ t.swap[i]);
		printf("%d\n", t.mex());
	}
}

