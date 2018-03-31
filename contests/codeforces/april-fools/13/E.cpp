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
	for (int i=0;i<s.size();i++) {
		if (s[i] == 'H') printf("H");
		else printf("%s", s.c_str());
	}
	printf("\n");
    return 0;
}

