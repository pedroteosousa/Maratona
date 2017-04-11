#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-12;

struct point {
    double x, y;
    point(double xp = 0.0, double yp = 0.0) {
        x = xp;
        y = yp;
    }
    point(const point &p) {
        x = p.x;
        y = p.y;
    }
    point operator+ (const point &p) const {return point(x+p.x, y+p.y);}
    point operator- (const point &p) const {return point(x-p.x, y-p.y);}
    point operator* (double c) {return point(c*x, c*y);}
    point operator/ (double c) {return point(x/c, y/c);}
};

double dot(point p, point q) {return p.x*q.x+p.y*q.y;}
double dist(point p, point q) {return sqrt(dot(p-q,p-q));}
double cross(point p, point q) {return p.x*q.y-p.y*q.x;}

point projectInLine(point c, point a, point b) {return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}
point projectInSegment(point c, point a, point b) {
    point lineP = projectInLine(c, a, b);
    double maxDist = max(dist(a, lineP), dist(b, lineP));
    if (maxDist > dist(a, b)) {
        if (dist(a, c) > dist(b, c)) return b;
        else return a;
    }
    else return lineP;
}

int main() {
    point c = point(1, 0);
    point a = point(0, 0);
    point b = point(1, 1);
    printf("%lf\n", dist(c, projectInLine(c, a, b)));
    return 0;
}

