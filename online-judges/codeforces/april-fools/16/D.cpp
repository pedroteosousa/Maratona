#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
    int resp = 0;
	while (n != 0) {
		if (n % 8 == 1) resp++;
		n /= 8;
	}
	printf("%d\n", resp);
	return 0;
}

