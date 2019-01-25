#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair
#define PI 3.14159265

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

double eps = 1e-7;

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

point h[N];
double a[N];

int main() {
	int n, q; scanf("%d %d", &n, &q);
	point bar(0,0);
	for (int i=0;i<n;i++) {
		scanf("%lf %lf", &h[i].x, &h[i].y);
		bar = bar + h[i];
	}
	bar = bar / (double)n;
	double area = 0;
	for (int i=1;i<=n;i++) {
		area -= h[i%n]^h[i-1];
	} area /= 2.0;
	for (int i=0;i<n;i++) {
		point down(0, -1);
		point dir = (bar - h[i]);
		a[i] = acos((down*dir)/dir.len());
		if (dir.x < 0) a[i] *= -1.0;
		printf("a[i] = %lf\n", a[i] * 180.0 / PI);
	}
	int top = -1;
	int pins[2] = {0, 1};
	point cbar = bar;
	while (q--) {
		int tp, f; scanf("%d %d", &tp, &f); f--;
		if (tp == 1) {
			int t; scanf("%d", &t); t--;
			int k = -1;
			if (f != pins[0]) swap(pins[0], pins[1]);
			if (pins[0] == pins[1]) {
				pins[1] = t;
				continue;
			}
			k = pins[1];
			pins[0] = t;
			
			point g;
			if (top == -1) {
				g = h[k];
			} else {
				g = (h[k]-bar).rotate(-a[top]) + cbar;
			}
			cbar = point(0, -1) * (bar - h[k]).len() + g;
			printf("cbar = (%lf %lf)\n", cbar.x, cbar.y);
			top = k;
		} else {
			point g;
			if (top == -1) {
				g = h[f];
			} else {
				g = (h[f]-bar).rotate(-a[top]) + cbar;
			}
			printf("%.10lf %.10lf\n", g.x, g.y);
		}
	}
	return 0;
}

