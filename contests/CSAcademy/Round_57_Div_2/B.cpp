#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

vector<int> v;
char s[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
    scanf("%s", s);
	int t = 0;
	for (int i=0;i<n;i++) {
		if (s[i] == '1') {
			v.push_back(t);
			t = 0;
		} else {
			t++;
		}
	}
	v.push_back(t);
	if ((int)v.size() == 1) {
		long long resp = ((long long)n)*((long long)k);
		printf("%lld\n", resp);
		return 0;
	}
	if (s[0] == s[n-1] && s[0] == '0' && k > 1) v.push_back(v[0] + v[(int)v.size()-1]);
	sort(v.begin(), v.end());
	printf("%d\n", v[(int)v.size()-1]);
	return 0;
}

