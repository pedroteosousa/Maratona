#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	double s, k;
	int q;
	scanf("%lf %d %lf", &s, &q, &k);
	multiset<double> p;
	while (q--) {
		double a; scanf("%lf", &a);
		p.insert(a/100.0);
	}
	while (p.size()) {
		double g = *p.begin();
		if (s != 0 && (k/s) <= g) {
			s *= (1.0+g);
		} else {
			s += k;
		}
		p.erase(p.begin());
	}
	printf("%lf\n", s);
    return 0;
}

