#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll v[20], b[20];

int main() {
	for (int i=0;i<14;i++) {
		scanf("%lld", &v[i]);
	}
	long long resp = 0;
	for (int i=0;i<14;i++) {
		if (v[i] == 0) continue;
		ll k = i+1;
		ll g = v[i];
		b[i] = -v[i];
		int p = 14;
		while (p--) {
			b[k%14] += (v[i]/14ll);
			g -= (v[i]/14ll);
			k++;
		}
		while (g--) {
			b[k%14]++;
			k++;
		}
		long long temp = 0;
		for (int j=0;j<14;j++) {
			if ((v[j]+b[j])%2 == 0) {
				temp += (v[j]+b[j]);
			}
			b[j] = 0;
		}
		resp = max(resp, temp);
	}
	printf("%lld\n", resp);
    return 0;
}

