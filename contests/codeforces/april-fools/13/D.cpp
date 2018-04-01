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
	int n;
	cin >> s;
	scanf("%d", &n);
	for (int i=0;i<s.size();i++) {
		int k = s[i]-'A';
		if (k > 26) k = s[i]-'a';
		if (k < n) {
			s[i] = 'A'+k;
		} else {
			s[i] = 'a'+k;
		}
	}
	cout << s << endl;
    return 0;
}

