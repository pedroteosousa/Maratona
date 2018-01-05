#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	long long a, b, x, y, z;	
	scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &z);
	long long a2 = 2*x + y;
	long long b2 = 3*z+y;
	printf("%lld\n", max(0ll, a2-a)+ max(0ll, b2-b));
    return 0;
}

