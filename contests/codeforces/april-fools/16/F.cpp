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
	int resp = 1;
	int num = 0;
	for (int i=1;i<s.size();i++) {
		num *= 10;
		num += s[i]-'0';
		if (num > 1) {
			resp += num;
			num = 0;
		}
	}
	printf("%d\n", resp);
    return 0;
}

