#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[N];

int main() {
	int f, i, t; scanf("%d %d %d", &f, &i, &t);
	getchar();
	for (int j=0;j<f;j++) {
		for (int k=0;k<i;k++) {
			char c = getchar();
			if (c == 'Y') {
				v[k]++;
			}
		}
		getchar();
	}
	int resp = 0;
	for (int j=0;j<i;j++) {
		if (v[j] >= t) resp++;
	}
	printf("%d\n", resp);
    return 0;
}

