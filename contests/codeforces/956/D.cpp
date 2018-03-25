#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

double EPS = 1e-12;

struct point {
	double x, y;

	point (double a = 0, double b = 0) { x = a; y = b; }
	point (const point &p) { x = p.x; y = p.y; }

	point operator+ (const point &p) { return {x+p.x, y+p.y}; }
	point operator- (const point &p) { return {x-p.x, y-p.y}; }
	point operator* (double c) { return {c*x, c*y}; }
	point operator/ (double c) { return {x/c, y/c}; }

	double operator^ (const point &p) { return x*p.y - y*p.x; }
	double operator* (const point &p) { return x*p.x + y*p.y; }

	point rotate (double c, double s) {
		return {x*c - y*s, x*s + y*c}; 
	}
	point rotate (double ang) {
		return rotate(cos(ang), sin(ang));
	}

	double len() { return hypot(x, y); }

	bool operator< (const point &p) const {
		return (x < p.x) || (x == p.x && y < p.y);
	}
};

point h1[N], h2[N];

double ag(const point& p)
{   
	return atan2(p.y,p.x);
}

bool cmp(const point &a, const point &b) {
	return ag(a) < ag(b);
}

int main () {
	double w;
	int n; scanf("%d %lf", &n, &w);
	int n1 = 0, n2 = 0;
	for (int i=0;i<n;i++) {
		double x, v;
		scanf("%lf %lf", &x, &v);
		if (x < 0) {
			h2[n2++] = point(x, v);
		} else {
			h1[n1++] = point(x, v);
		}
	}
	sort(h1, h1+n1, cmp);
	sort(h2, h2+n2, cmp);
	for (int i=0<n1;i++) {

	}
	return 0;
}
