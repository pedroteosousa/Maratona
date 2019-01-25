#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

pair<int, int> v[N];
set<pair<int, int> > s;
int dsz[N];

int main() {
	int n; scanf("%d", &n);
	int resp = 0;
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i].first);
		resp = max(resp, v[i].first+1);
		v[i].second = i;
		v[i].first *= -1;
	}
    s.insert(mp(n, 0));
	sort(v, v+n);

	dsz[n] = 1;
	int qtd = 1;
	set<int> szs;
	szs.insert(n);
	int mxqtd = 0;
	for (int i=0;i<n;i++) {
		pair<int, int> p = *s.upper_bound(mp(v[i].second, 0));
		s.erase(p);
		s.insert(mp(v[i].second, p.second));
		s.insert(mp(p.first, v[i].second+1));
		
		int oldsz = p.first - p.second;
		int nsz1 = v[i].second - p.second;
		int nsz2 = p.first - v[i].second - 1;
		if (--dsz[oldsz] == 0) {
			szs.erase(oldsz);
		}
		if (nsz1 > 0 && dsz[nsz1]++ == 0) {
			szs.insert(nsz1);
		}
		if (nsz2 > 0 && dsz[nsz2]++ == 0) {
			szs.insert(nsz2);
		}
		int asz = *szs.begin();
		//printf("asz = %d && szs.size() == %d\n", asz, (int)szs.size());
		if ((int)szs.size() == 1 && mxqtd <= dsz[asz]) {
			mxqtd = dsz[asz];
			resp = v[i+1].first*-1 + 1;
		}
	}
	printf("%d\n", resp);
	return 0;
}

