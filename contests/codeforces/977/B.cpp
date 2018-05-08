#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

map<pair<char, char>, int> v;

int main() {
	int n; scanf("%d", &n);
	string s;
	cin >> s;
	int mx = 0;
	pair<char, char> resp;
    for (int i=0;i<n-1;i++) {
		v[mp(s[i], s[i+1])]++;
		if (mx < v[mp(s[i], s[i+1])]) {
			mx = v[mp(s[i], s[i+1])];
			resp = mp(s[i], s[i+1]);
		}
	}
	printf("%c%c\n", resp.first, resp.second);
	return 0;
}

