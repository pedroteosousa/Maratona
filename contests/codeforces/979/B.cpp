#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

string s[10];

int freq(int k, int n) {
	map<int, int> m;
	int mx = 0;
	for (int i=0;i<s[k].size();i++) {
		mx = max(mx, ++m[s[k][i]]);
	}
	if ((int)s[k].size()-mx == n) return (int)s[k].size();
	else if ((int)s[k].size()-mx < n) {
		if (n == 1) {
			if ((int)s[k].size() == mx) return (int)s[k].size()-1;
			else return (int)s[k].size();
		} else {
			return (int)s[k].size();		
		}
	}
	else return mx + n;
}

int main() {
	int n; scanf("%d", &n);
	int p[3] = {0, 0, 0};
	for (int i=0;i<3;i++) {
		cin >> s[i];
		p[i] = freq(i, n);
	}
	if (p[0] > p[1] && p[0] > p[2]) printf("Kuro\n");
	else if (p[1] > p[0] && p[1] > p[2]) printf("Shiro\n");
	else if (p[2] > p[0] && p[2] > p[1]) printf("Katie\n");
	else printf("Draw\n");
    return 0;
}

