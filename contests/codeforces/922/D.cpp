#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 1e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

ll c[N][5];

bool cmp(int a, int b) {
	if (c[b][0]*c[a][1] < c[a][0]*c[b][1]) return true;
	return false;
}

int main() {
	vector<int> s;
	vector<string> str;
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) {
		string a;
		cin >> a;
		for (int j=0; j<a.size(); j++) {
			if (a[j] == 's') c[i][0]++;
			else c[i][1]++;
		}
		s.push_back(i);
		str.push_back(a);
	}
	sort(s.begin(), s.end(), cmp);
	string resp = string("");
	for (int i=0;i<n;i++) {
		resp += str[s[i]];
	}
	ll r = 0;
	ll count = 0;
	for (int i=resp.size()-1; i>=0; i--) {
		if (resp[i] == 's') r += count;
		else count++;
	}
	printf("%lld\n", r);
    return 0;
}

