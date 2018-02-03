#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

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



int main () {
	point a, b, c, d, v1, v2;
	double x, y;
	scanf("%lf %lf", &x, &y); a = point(x, y);
	scanf("%lf %lf", &x, &y); b = point(x, y);
	scanf("%lf %lf", &x, &y); c = point(x, y);
	scanf("%lf %lf", &x, &y); d = point(x, y);
	scanf("%lf %lf", &x, &y); v1 = point(x, y);
	scanf("%lf %lf", &x, &y); v2 = point(x, y);
	return 0;
}
