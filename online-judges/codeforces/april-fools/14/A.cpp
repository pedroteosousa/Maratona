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
	string a, b;
	cin >> a >> b;
	int p = 0;
	for (int i=0;i<a.size();i+=2) {
		if (a[i] == '8') {
			if (b[i] == '[') p++;
			if (b[i] == '(') p--;
		} else if (a[i] == '[') {
			if (b[i] == '(') p++;
			if (b[i] == '8') p--;
		} else {
			if (b[i] == '8') p++;
			if (b[i] == '[') p--;
		}
	}
	if (p == 0) printf("TIE\n");
	else if (p > 0) printf("TEAM 1 WINS\n");
	else printf("TEAM 2 WINS\n");
    return 0;
}

