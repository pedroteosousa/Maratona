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
	int n; scanf("%d", &n);
	string s; cin >> s;
	int mn = n;
	for (int i=1;i<=(n/2);i++) {
		bool flag = true;
		for (int j=0;j<i;j++) {
			if (s[i+j] != s[j]) flag = false;
		}
		if (flag) {
			mn = min(mn, n+1-i);
		}
	}
	printf("%d\n", mn);
    return 0;
}

