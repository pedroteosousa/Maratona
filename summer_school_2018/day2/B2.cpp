#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long double ld;

const ld eps = 1e-8;

struct point {
	ld x, y;
	point(ld a, ld b) {
		x = a; y = b;
	}
	point operator- (const point &p) {
		return point(x-p.x, y-p.y);
	}
	point operator+ (const point &p) {
		return point(x+p.x, y+p.y);
	}
	ld operator^ (const point &p) {
		return x*p.y - y*p.x;
	}
	point operator* (const ld p) {
		return point(x*p, y*p);
	}
	ld operator* (const point &p) {
		return x*p.x + y*p.y;
	}
	ld len() {
		return hypot(x, y);
	}
	ld distLine(point b, point c, int r) {
		point a(x, y);
		int ret = 0;
		ld resp = 0;
		if ((a-b)*(c-b) >= 0) ret |= 1;
		if ((a-c)*(b-c) >= 0) ret |= 2;
		ld area = ((a-b)^(c-b));
		area = max(area, -area);
		resp = area/(b-c).len();
		if (r == 0)
			return resp;
		else if (r == 1) {
			if (ret & 1) {
				return resp;
			} else return (b-a).len();
		} else {
			if (ret == 3) {
				return resp;
			} else {
				ld d1 = (b-a).len();
				ld d2 = (c-a).len();
				return min(d1, d2);
			}
		}
	}
};

ld distLines(point a, point b, point c, point d, int r1, int r2) {
	point e = b + (d-c);
	ld d1 = a.distLine(c, d, r2);
	ld d2 = b.distLine(c, d, r2);
	ld d3 = c.distLine(a, b, r1);
	ld d4 = d.distLine(a, b, r1);
	ld mn = min(min(d1, d2), min(d3, d4));
	if (abs((e-a)^(e-b)) <= eps) {
		return mn;
	}
	point ab = b-a, cd = d-c;
	ld t = ((ab^c) + (a^ab))/(cd^ab);
	point n = cd*t + c;
	ld d5 = n.distLine(a, b, r1);
	ld d6 = n.distLine(c, d, r2);
	d5 = max(d5, d6);
	return min(d5, mn);
}

int main() {
	ld x, y;
	scanf("%Lf %Lf", &x, &y);
	point a(x, y);
	scanf("%Lf %Lf", &x, &y);
	point b(x, y);
	scanf("%Lf %Lf", &x, &y);
	point c(x, y);
	scanf("%Lf %Lf", &x, &y);
	point d(x, y);
	ld resp = 0;
	// 1
	printf("%.10Lf\n", (a-c).len());
	// 2
	printf("%.10Lf\n", a.distLine(c, d, 2));
  	// 3
	printf("%.10Lf\n", a.distLine(c, d, 1));
  	// 4
	printf("%.10Lf\n", a.distLine(c, d, 0));
	// 5
	printf("%.10Lf\n", c.distLine(a, b, 2));
	// 6
	printf("%.10Lf\n", distLines(a, b, c, d, 2, 2));
	// 7
	printf("%.10Lf\n", distLines(a, b, c, d, 2, 1));
	// 8
	printf("%.10Lf\n", distLines(a, b, c, d, 2, 0));
	// 9
	printf("%.10Lf\n", c.distLine(a, b, 1));
	// 10
	printf("%.10Lf\n", distLines(a, b, c, d, 1, 2));
	// 11
	printf("%.10Lf\n", distLines(a, b, c, d, 1, 1));
	// 12
	printf("%.10Lf\n", distLines(a, b, c, d, 1, 0));
	// 13
	printf("%.10Lf\n", c.distLine(a, b, 0));
	// 14
	printf("%.10Lf\n", distLines(a, b, c, d, 0, 2));
	// 15
	printf("%.10Lf\n", distLines(a, b, c, d, 0, 1));
	// 16
	printf("%.10Lf\n", distLines(a, b, c, d, 0, 0));
	
	return 0;
}

