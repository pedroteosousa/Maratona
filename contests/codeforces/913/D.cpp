#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

vector< pair<int, pair<long long, int> > > val;
multiset< pair<long long, pair<int, int> > > s;

int solve(int n, long long t, bool print = false, int temp = 0) {
	s.clear();
	long long sum = 0;
	int mx = 0;
	for (int i=0;i<n;i++) {
		int mn = -val[i].first;
		if (!print && mn < s.size()) {
			return mx;
		}
		if (s.size() == mn) {
			pair<long long, pair<int, int> > k = *s.begin();
			if (-k.first > val[i].second.first) {
				s.erase(s.begin());
				s.insert(mp(-val[i].second.first, mp(-val[i].first, val[i].second.second)));
				sum += k.first + val[i].second.first;
			}
		} else {
			if (sum + val[i].second.first <= t) {
				s.insert(mp(-val[i].second.first, mp(-val[i].first, val[i].second.second)));
				sum += val[i].second.first;
			} else {
				pair<long long, pair<int, int> > k = *s.begin();
				if (-k.first > val[i].second.first) {
					s.erase(s.begin());
					s.insert(mp(-val[i].second.first, mp(-val[i].first, val[i].second.second)));
					sum += k.first + val[i].second.first;
				}
			}
		}
		if (s.size() > mx) {
			mx = s.size();
		}
		if (print && temp == s.size()) {
			printf("%d\n%d\n", temp, temp);
			for (auto a : s) {
				printf("%d ", a.second.second);						
			} printf("\n");
			return 0;
		}
	}
	return mx;
}

int main() {
	int n;
	long long t;
	scanf("%d %lld", &n, &t);
	for (int i=0;i<n;i++) {
		int a; long long ti;
		scanf("%d %lld", &a, &ti);
		val.push_back(mp(-a, mp(ti, i+1)));
	}
	sort(val.begin(), val.end());
    solve(n, t, true, solve(n, t));
	return 0;
}

