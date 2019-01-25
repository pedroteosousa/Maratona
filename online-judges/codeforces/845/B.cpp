#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int sum(int k) {
	int s = 0;
	for (int i=0;i<3;i++) {
		s += k%10;
		k/=10;
	}
	return s;
}

bool isLucky(int k) {
	if (sum(k%1000) == sum(k/1000)) return true;
	return false;
}

int dif(int a, int b) {
	int c = 0;
	for (int i=0;i<6;i++) {
		if (a%10 != b%10) c++;
		a /= 10;
		b /= 10;
	}
	return c;
}

int main() {
	int k;
	scanf("%d", &k);
	int mn = inf;
	for (int i=0;i<=999999;i++) {
		if (isLucky(i)) {
			mn = min(mn, dif(k, i));
		}
	}
	printf("%d\n", mn);
    return 0;
}

