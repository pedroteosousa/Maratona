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
	string s;
	cin >> s;
	int res = 0;
	for (int i=0;i<s.size();i++) {
		bool a1 = '@' < s[i];
		bool a2 = '[' > s[i];
		bool a3 = '`' < s[i];
		bool a4 = '{' > s[i];
		a1 = a1 && a2;
		a3 = a3 && a4;
		int j = 0;
		if (s[i] <= 'z' && s[i] >= 'a') j = s[i]-'a'+1;
		if (s[i] <= 'Z' && s[i] >= 'A') j = s[i]-'A'+1;
		int j1 = a1, j2 = a3;
		res += j1*j - j*j2;
	}
	printf("%d\n", res);
    return 0;
}

