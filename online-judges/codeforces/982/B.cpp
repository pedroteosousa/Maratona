#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

pair<int, int> w[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &w[i].first);
		w[i].second = i+1;
	}
	sort(w, w+n);
	string s; cin >> s;
	int intro = 0;
	set<pair<int, int> > extro;
	for (int i=0;i<s.size();i++) {
		if (s[i] == '0') {
			w[intro].first *= -1;
			extro.insert(w[intro]);
			printf("%d ", w[intro++].second);
		} else {
			printf("%d ", (*extro.begin()).second);
			extro.erase(extro.begin());
		}
	} printf("\n");
    return 0;
}

