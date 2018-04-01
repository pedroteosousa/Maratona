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
	int k = 0;
	for (int i=1;i<n;i++) {
		if (s[i] != s[i-1]) {
			k++;
			i++;
		}
	}
	printf("%d\n", n-k);
    return 0;
}

