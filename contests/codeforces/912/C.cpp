#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

ll find(ll x, ll h0, ll regen, ll dmg) {
	return x+(dmg-h0)/regen;
}

ll out[N];
int gg[N];
ll regen0[N];
vector< vector<ll> > en;
vector< pair< ll, ll > > all;
vector< vector<ll> > updates;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	ll bty, inc, dmg;
	scanf("%lld %lld %lld", &bty, &inc, &dmg);
	memset(out, -1, sizeof out);
	memset(regen0, -1, sizeof regen0);
	for (int i=0;i<n;i++) {
		vector<ll> info;
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		info.pb(a); info.pb(b); info.pb(c);
		en.pb(info);

		if (info[0] <= dmg) {
			all.push_back(mp(0, 0));
			continue;
		}

		if (info[2] == 0 && info[1] <= dmg) {
			regen0[i] = 0;
		}
		if (info[2] != 0 && dmg >= info[1]) {
			all.push_back(mp(0, 0));
			ll nx = find(0, info[1], info[2], dmg);
			all.push_back(mp(nx, 1));
			out[i] = nx;
			gg[i] = (int)all.size()-1;
		}
	}

	for (int i=0;i<m;i++) {
		vector<ll> info;
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		info.pb(a); info.pb(b); info.pb(c);
		updates.pb(info);
	}
	sort(updates.begin(), updates.end());
	for (int i=0;i<m;i++) {
		vector<ll> info = updates[i];
		
		if (en[info[1]-1][0] <= dmg) continue;
		if (en[info[1]-1][2] == 0) {
			if (dmg >= info[2]) {
				if (regen0[info[1]-1] == -1) {
					regen0[info[1]-1] = info[0];
				}
			} else {
				all.push_back(mp(regen0[info[1]-1], 0));
				all.push_back(mp(info[0]-1, 1));
				regen0[info[1]-1] = -1;
			}
		}
		if (dmg >= info[2] && en[info[1]-1][2] != 0) {
			ll nx = find(info[0], info[2], en[info[1]-1][2], dmg); 
			if (out[info[1]-1] != -1 && out[info[1]-1] >= info[0]) {
				all[gg[info[1]-1]].first = nx;
				out[info[1]-1] = nx;
			} else {
				all.push_back(mp(info[0], 0));
				all.push_back(mp(nx, 1));
				out[info[1]-1] = nx;
				gg[info[1]-1] = (int)all.size() - 1;
			}
		} else if (dmg < info[2] && en[info[1]-1][2] != 0) {
			if (gg[info[1]-1] != 0) {
				all[gg[info[1]-1]].first = info[0]-1;
				out[info[1]-1] = -1;
				gg[info[1]-1] = 0;
			}
		}
	}
	for (int i=0;i<n;i++) {
		if (regen0[i] != -1) {
			all.push_back(mp(regen0[i], 0));
		}
	}
	sort(all.begin(), all.end());
	debug("all.size() = %d\n", (int)all.size());
	ll count = 0;
	ll mx = 0;
	for (auto a : all) {
		debug("a = (%lld, %lld)\n", a.first, a.second);
		if (a.second == 0) {
			count++;
		}
		mx = max(mx, (a.first*inc + bty)*count);
		debug("mx = %lld && count = %lld\n", mx, count);
		if (a.second == 1) {
			count--;
		}
	}
	if (inc > 0 && count > 0) printf("-1\n");
	else printf("%lld\n", mx);
    return 0;
}

