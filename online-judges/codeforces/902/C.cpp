#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int rep[N];
int a[N];
int p[N][5];

int main() {
	int h;
	int n = 1;
	scanf("%d", &h);
	int found = 0;
	for (int i=0;i<=h;i++) {
		scanf("%d", &a[i]);
		rep[i] = n;
		
		int t = a[i];
		int k = n;
		while (t--) {
			p[n][0] = p[n][1] = rep[i-1];
			n++;
		}

		if (i != 0 && a[i] > 1 && a[i-1] > 1) {
			p[k][1]++;
			found = 1;
		}
	}
	if (found) {
		printf("ambiguous\n");
		for (int j=0;j<2;j++) {
			for (int i=0;i<n-1;i++) {
				printf("%d ", p[i+1][j]);
			}
			printf("\n");
		}
	} else {
		printf("perfect\n");
	}
    return 0;
}

