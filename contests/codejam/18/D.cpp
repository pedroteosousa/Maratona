#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

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

	double len() { return hypot(x, y); }

	bool operator< (const point &p) const {
		return (x < p.x) || (x == p.x && y < p.y);
	}
};

struct point3d {
	double x, y, z;
	point3d (double a = 0, double b = 0, double c = 0) {
		x = a; y = b; z = c;
	}
	point in2d() {
		return point(x, y);
	}
	point3d rotate(double cx, double cy) {
		double sx = sqrt(1 - cx*cx);
		double sy = sqrt(1 - cy*cy);
		double nx = x*cy + y*sx*sy + z*cx*sy;
		double ny = cx*y + z*-sx;
		double nz = -sy*x + y*cy*sx + z*cy*cx;
		return point3d(nx, ny, nz);
	}
	void print() {
		printf("%.20lf %.20lf %.20lf\n", x, y, z);
	}
};

double side(point a, point b, point c) {
	return (a^b) + (b^c) + (c^a);
}

vector<point> convex_hull(vector<point> p) {
	int n = p.size(), k = 0;
	if (n == 1) return p;
	vector<point> hull(2*n);

	sort(p.begin(), p.end());

	for(int i=0; i<n; i++) {
		// use <= when including collinear points
		while(k>=2 && (side(hull[k-2], hull[k-1], p[i]) <= 0))
			k--;
		hull[k++] = p[i];
	}

	for(int i=n-2,t=k+1; i>=0; i--) {
		while(k>=t && (side(hull[k-2], hull[k-1], p[i]) <= 0))
			k--;
		hull[k++] = p[i];
	}

	hull.resize(k-1);
	return hull;
}

double area(vector<point> h) {
	double a = 0;
	for (int i=0;i<h.size();i++) {
		a += (h[i] ^ h[(i+1)%h.size()]);
	}
	return max(a, -a)/2.0;
}

vector<point3d> all;
vector<point> h;

int main() {
	for (int i=-1;i<2;i+=2) {
		for (int j=-1;j<2;j+=2) {
			for (int k=-1;k<2;k+=2) {
				point3d a(i/2.0, j/2.0, k/2.0);
				all.pb(a);
				h.pb(a.in2d());
			}
		}
	}
	int t; scanf("%d", &t);
	for (int te=1; te <= t; te++) {
		double a; scanf("%lf", &a);
		double l=1.0/sqrt(2), r = 1.0;
		for (int i=0;i<60;i++) {
			double m = (l+r)/2.0;
			h.resize(8);
			for (int j=0;j<8;j++) {
				h[j] = all[j].rotate(m, 1).in2d();
			}
			h = convex_hull(h);
			double g = area(h);
			if (g < a) r = m;
			else l = m;
		}
		double cx = l;
		l=1.0/sqrt(3), r = 1.0;
		for (int i=0;i<60;i++) {
			double m = (l+r)/2.0;
			h.resize(8);
			for (int j=0;j<8;j++) {
				h[j] = all[j].rotate(cx, m).in2d();
			}
			h = convex_hull(h);
			double g = area(h);
			if (g < a) r = m;
			else l = m;
		}
		vector<point3d> resp;
		resp.pb(point3d(0.5, 0, 0));
		resp.pb(point3d(0, 0.5, 0));
		resp.pb(point3d(0, 0, 0.5));
		printf("Case #%d:\n", te);
		for (int i=0;i<3;i++) {
			resp[i].rotate(cx, l).print();
		}
	}
    return 0;
}

