#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 2e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef struct node {
	int to[100];
	int freq;
	bool end;
} trie;
int sz = 0;

trie t[N];

void insert(char *s, int p = 0) {
	t[p].freq++;
	if (*s == 0) {
		t[p].end = true;
		return;
	}
	if (t[p].to[*s] == 0)
		t[p].to[*s] = ++sz;
	insert(s+1, t[p].to[*s]);
}

bool find_prefix(char *s, int p = 0) {
	if (t[p].end)
		return true;
	if (*s == 0 && t[p].to[*s] == 0)
		return false;
	return find_prefix(s+1, t[p].to[*s]);
}

int count(char *s, int p = 0) {
	if (*s == 0)
		return t[p].freq;
	if (t[p].to[*s] == 0)
		return 0;
	return count(s+1, t[p].to[*s]);
}

int find(char *s, int p = 0) {
	if (*s == 0)
		return t[p].end;
	if (t[p].to[*s] == 0)
		return false;
	return find(s+1, t[p].to[*s]);
}

int erase() {
	for (++sz; sz--; ) {
		for (int i=0;i<100;i++) {
			t[sz].freq = t[sz].end = t[sz].to[i] = 0;
		}
	}
	sz++;
}

char s[N];

int main() {
	int te;
	scanf("%d", &te);
	while (te--) {
		int n;
		scanf("%d", &n);
		bool ok = true;
		while (n--) {
			scanf("%s", s);
			if (find(s)) continue;
			if (count(s) || find_prefix(s))
				ok = false;
			insert(s);
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
		erase();
	}
    return 0;
}

