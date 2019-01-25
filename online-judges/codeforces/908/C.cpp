#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

long long n, r;
vector<pair<long long, double> > all;

double solve(double a, double b, double c) {
	double d = b*b - 4*a*c;
	if (d < 0)
		return -1.0;
	d = sqrt(d);
	return (-b + d)/(2.0*a);
}

long long bs(long long x) {
	bool ok = true;
	double worst = -1.0;
	for (auto a : all) {
		double xd = a.first - x;
		double rd = r;
		double resp = solve(1.0, -2.0*a.second, -4*rd*rd +xd*xd +a.second*a.second);
		worst = max(worst, resp);
	}
	if (worst < 0) worst = (double)r;
	all.push_back(mp(x, worst));
}

int main() {
	scanf("%lld %lld", &n, &r);
	for (int i=0;i<n;i++) {
		long long x;
		scanf("%lld", &x);
		bs(x);
	}
	for (auto a : all) {
		printf("%.15lf ", a.second);
	}
	printf("\n");
    return 0;
}

