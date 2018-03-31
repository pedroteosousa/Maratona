#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

double x(double a, double h) {
	a = a/2.0;
	double c = sqrt(a*a + h*h);
	return (a*h)/c;
}

int main() {
	double f;
	scanf("%lf", &f);
	for (int a=1;a<=10;a++) {
		for (int h=1;h<=10;h++) {
			if (fabs(f - x(a, h)) < 0.0001) {
				printf("%d %d\n", a, h);
				return 0;
			}
		}
	}
    return 0;
}

