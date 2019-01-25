#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

char resp[N];

int main() {
	int n; scanf("%d", &n);
	string s; cin >> s;
	int id = n - 1;
	for (int i=1;i<s.size();i++) {
		if (s[i] < s[i-1]) {
			id = i-1;
			break;
		}
	}
	int j = 0;
	for (int i=0;i<s.size();i++) {
		if (i == id) continue;
		resp[j++] = s[i];
	}
	resp[j] = '\0';
	cout << string(resp) << endl;
    return 0;
}

