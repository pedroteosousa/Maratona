#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int n, k;
int t[N], f[N];
bool one[N];
int same[N];
int type[N], val[N];
int mn[N][2];

int main() {
	scanf("%d %d", &n, &k);
	for (int i=0;i<n;i++) scanf("%d", &t[i]);
	for (int i=0;i<n;i++) scanf("%d", &f[i]);
	for (int i=0;i<n;i++) {
		if (t[i] == 0 || f[i] == 0) one[i] = true;
		int mxt = (t[i] + k - 1) / k;
		int mxf = (f[i] + k - 1) / k;
		if (f[i] >= mxt && t[i] >= mxf) {
			type[i] = 2;
			if (f[i] == t[i]) same[i] == -1;
			else if (f[i] > mxt && t[i] > mxf) same[i] = 2;
			else if (f[i] > mxt) same[i] = 1;
			else if (t[i] > mxf) same[i] = 0;
			continue;
		}
		if (f[i] < mxt - 1 || t[i] < mxf - 1) {
			printf("NO\n");
			return 0;
		}
		if (t[i] == mxf - 1) {
			type[i] = 1;
			val[i] = f[i] - (t[i] - 1) * k;
		}
		if (f[i] == mxt - 1) {
			type[i] = 0;
			val[i] = t[i] - (f[i] - 1) * k;
		}
	}
	for (int i=0;i<n;i++) {
		//printf("%d: one = %d, type = %d, val = %d\n", i, one[i], type[i], val[i]);
		mn[i][0] = mn[i][1] = k+1;
	}
	//    t          f
	mn[n][0] = mn[n][1] = 0;
	for (int i=n-1;i>=0;i--) {
		if (type[i] == 2) {
			if (mn[i+1][0] + 1 <= k || mn[i+1][1] <= k) {
				mn[i][1] = min(1, mn[i][1]);
				if (same[i] == 2 || same[i] == 0) mn[i][1] = min(0, mn[i][1]); 
				mn[i][0] = min(0, mn[i][0]);
			}
			if (mn[i+1][1] + 1 <= k || mn[i+1][0] <= k) {
				mn[i][0] = min(1, mn[i][0]);
				if (same[i] == 2 || same[i] == 1) mn[i][0] = min(0, mn[i][0]); 
				mn[i][1] = min(0, mn[i][1]);
			}
		} else if (type[i] == 0) {
			if (mn[i+1][1] <= k) {
				int left = val[i] - min(k, val[i]-1);
				if (one[i]) left = val[i];
				mn[i][0] = min(left, mn[i][0]);
			}
			if (mn[i+1][0] <= k) {
				int left = val[i] - min(k - mn[i+1][0], val[i]-1);
				if (one[i]) left = val[i] + mn[i+1][0];
				mn[i][0] = min(left, mn[i][0]);
			}
		} else if (type[i] == 1) {
			if (mn[i+1][0] <= k) {
				int left = val[i] - min(k, val[i]-1);
				if (one[i]) left = val[i];
				mn[i][1] = min(left, mn[i][1]);
			}
			if (mn[i+1][1] <= k) {
				int left = val[i] - min(k - mn[i+1][1], val[i]-1);
				if (one[i]) left = val[i] + mn[i+1][1];
				mn[i][1] = min(left, mn[i][1]);
			}
		}
		//printf("%d: {%d, %d}\n", i, mn[i][0], mn[i][1]);
	}
	if (mn[0][0] <= k || mn[0][1] <= k) printf("YES\n");
	else printf("NO\n");
    return 0;
}

