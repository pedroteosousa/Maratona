#include <bits/stdc++.h>

using namespace std;

double inf = 1e300;

vector< pair<double, double> > lef, rig, up, down;

bool cmp(pair<double, double> &a, pair<double, double> &b) {
	if (a.first == b.first) {
		if (a.first < 0.0) {
			if (b.first < 0.0) return a.second*b.first < b.second*a.first;
			else return a.second*b.first > b.second*a.first;
		}
		else {
			if (b.first < 0.0) return a.second*b.first > b.second*a.first;
			else return a.second*b.first < b.second*a.first;
		}
	}
	if (a.first < 0.0) {
		if (b.first < 0.0) return a.first < b.first;
		else return true;
	}
	else {
		if (b.first < 0.0) return false;
		else return a.first > b.first;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		lef.push_back(make_pair(a, b));
		up.push_back(make_pair(a, b));
		rig.push_back(make_pair(a, -b));
		down.push_back(make_pair(a, -b));
	}
	sort(lef.begin(), lef.end());
	sort(rig.begin(), rig.end());
	sort(up.begin(), up.end(), cmp);
	sort(down.begin(), down.end(), cmp);
	double xl = inf, xr = - inf, yl = inf, yr = -inf;
	//printf("%lf\n%lf\n%lf\n%lf\n", xl, yl, xr, yr);
	for (int i=1;i<n;i++) {
		pair<double, double> p1, p2;
		p1 = lef[i]; p2 = lef[i-1];
		double x = (p1.second-p2.second)/(p1.first-p2.first);
		double y = p1.first*x - p1.second;
		//printf("x = %lf e y = %lf\n", x, y);
		if (p1.first != p2.first) { xl = min(xl, x); xr = max(xr, x); yl = min(yl, y); yr = max(yr, y); }
		p1 = rig[i]; p2 = rig[i-1];
		 x = (p2.second-p1.second)/(p1.first-p2.first);
		 y = p1.first*x + p1.second;
		//printf("x = %lf e y = %lf\n", x, y);
		if (p1.first != p2.first) { xl = min(xl, x); xr = max(xr, x); yl = min(yl, y); yr = max(yr, y); }
		p1 = up[i]; p2 = up[i-1];
		 x = (p1.second-p2.second)/(p1.first-p2.first);
		 y = p1.first*x - p1.second;
		//printf("x = %lf e y = %lf\n", x, y);
		if (p1.first != p2.first) { xl = min(xl, x); xr = max(xr, x); yl = min(yl, y); yr = max(yr, y); }
		p1 = down[i]; p2 = down[i-1];
		 x = (p2.second-p1.second)/(p1.first-p2.first);
		 y = p1.first*x + p1.second;
		//printf("x = %lf e y = %lf\n", x, y);
		if (p1.first != p2.first) { xl = min(xl, x); xr = max(xr, x); yl = min(yl, y); yr = max(yr, y); }
	}
	printf("%lf %lf %lf %lf\n", xl, yl, xr, yr);
	return 0;
}