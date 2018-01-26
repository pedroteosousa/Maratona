#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

struct point {
	ll x, y;
	point(ll a, ll b) {
		x = a; y = b;
	}
	point operator+ (const point &p) {
		return point(x+p.x, y+p.y);
	}
	point operator- (const point &p) {
		return point(x-p.x, y-p.y);
	}
	pair<double, double> operator* (double p) {
		return make_pair(x*p, y*p);
	}
};

pair<double, double> rotate(pair<double, double> p, double ang) {
	double x = p.first, y = p.second;
	return make_pair(x*cos(ang) - y*sin(ang), x*sin(ang) + y*cos(ang));
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		ll x, y, r, R;
		scanf("%lld %lld %lld", &x, &y, &r);
		point c1(x, y);
		scanf("%lld %lld %lld", &x, &y, &R);
		point c2(x, y);
		ll dist = (c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y);
		if (r > R) {
			swap(c1, c2);
			swap(r, R);
		} else if (r == R && c1.x == c2.x && c1.y == c2.y) {
			printf("Oops, too many points\n\n");
			continue;
		}
		if (dist > (r+R)*(r+R) || dist < (R-r)*(R-r)) {
			printf("There are no points\n\n");
		} else if (dist == (r+R)*(r+R) || dist == (R-r)*(R-r)) {
			printf("There are only 1 of them\n");
			point c = c1-c2;
			pair<double, double> p = c*((double)R/sqrt(dist));
			printf("%lf %lf\n\n", p.first+(double)c2.x, p.second+(double)c2.y);
		} else {
			printf("There are only 2 of them\n");
			point c = c1-c2;
			double cos_a = (double)(r*r - R*R - dist)/(-2.0*(double)R*sqrt(dist));
			pair<double, double> p1 = c*((double)R/sqrt(dist));
			p1 = rotate(p1, acos(cos_a));
			pair<double, double> p2 = c*((double)R/sqrt(dist));
			p2 = rotate(p2, -acos(cos_a));
			if (p1 > p2) swap(p1, p2);
			printf("%lf %lf\n", p1.first+(double)c2.x, p1.second+(double)c2.y);
			printf("%lf %lf\n\n", p2.first+(double)c2.x, p2.second+(double)c2.y);
		}
	}
	return 0;
}

