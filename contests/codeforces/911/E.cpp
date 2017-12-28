#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

bool isOK(vector<int> a) {
	stack<int> s;
	int cur = 1;
	for (int i=0;i<a.size();i++) {
		s.push(a[i]);
		while (s.size() && cur == s.top()) {
			s.pop();
			cur++;
		}
	}
	if (s.size()) return false;
	else return true;
}

int main() {
	set<int> s;
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a;
	for (int i=0;i<n;i++) {
		s.insert(i+1);		
	}
	vector<int> mx;
	for (int i=0;i<k;i++) {
		int c;
		scanf("%d", &c);
		s.erase(c);
		a.push_back(c);
		mx.push_back(c);
	}
	mx.push_back(n+1);
	sort(mx.begin(), mx.end());
	int mxi = 0;
	for (int i=k;i<n;i++) {
		set<int>::iterator it;
		do {
			it = s.upper_bound(mx[mxi]);
			if (it == s.begin()) mxi++;
		} while (it == s.begin());
		it--;
		debug("*it = %d\n", *it);
		a.push_back(*it);
		s.erase(it);
	}
	if (isOK(a)) {
		for (int i=0;i<n;i++) {
			printf("%d ", a[i]);
		} printf("\n");
	} else printf("-1\n");
	return 0;
}

