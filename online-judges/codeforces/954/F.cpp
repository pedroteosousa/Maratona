#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
const ll mod = 1000000007;

template <int n> struct matrix {
	long long mat[n][n];
	matrix () {
		memset (mat, 0, sizeof (mat));
	}
	matrix (long long temp[n][n]) {
		memcpy (mat, temp, sizeof (mat));
	}
	void identity() {
		memset (mat, 0, sizeof (mat));
		for (int i=0;i<n;i++)
			mat[i][i] = 1;
	}
	matrix<n> mul (const matrix<n> &a, long long m) const {
		matrix<n> temp;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++) {
					temp.mat[i][j] += (mat[i][k]*a.mat[k][j])%m;
					temp.mat[i][j] %= m;
				}
		return temp;
	}
	matrix<n> operator% (long long m) {
		matrix<n> temp(mat);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				temp.mat[i][j] %= m;
		return temp;
	}
	matrix<n> pow(long long e, long long m) {
		matrix<n> temp;
		if (e == 0) {
			temp.identity();
			return temp%m;
		}
		if (e == 1) {
			memcpy (temp.mat, mat, sizeof (temp.mat));
			return temp%m;
		}
		temp = pow(e/2, m);
		if (e % 2 == 0)
			return (temp.mul(temp, m))%m;
		else
			return (((temp.mul(temp, m))%m).mul(pow(1, m), m))%m;
	}
	void print() {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				printf("%5lld ", mat[i][j]);
			}
			printf("\n");
		}
	}
};

vector<pair<ll, int> > t;

int main () {
	ll m; int n; scanf("%d %lld", &n, &m);
	while (n--) {
		ll l, r; int a; scanf("%d %lld %lld", &a, &l, &r);
		t.push_back(make_pair(l, a));
		t.push_back(make_pair(r+1ll, -a));
	}
	t.push_back(make_pair(m+1, -1));
	sort(t.begin(), t.end());
	matrix<3> p;
	for (int i=0;i<3;i++) {
		for (int j=0;j<3;j++) {
			p.mat[i][j] = 1ll;
		}
	}
	p.mat[0][2] = p.mat[2][0] = 0ll;
	matrix<3> resp;
	resp.identity();
	matrix<3> e(p.mat);
	ll cur = 2ll;
	int kt[3] = {0, 0, 0};
	for (int i=0;i<t.size();i++) {
		pair<ll, int> v = t[i];
		ll d = v.first - cur;
		cur = v.first;
		resp = e.pow(d, mod).mul(resp, mod);
		//e.pow(d, mod).print();
		if (v.second > 0) {
			kt[v.second-1]--;
			for (int j=0;j<3;j++) {
				e.mat[v.second-1][j] = 0;
				//e.mat[j][v.second-1] = 0;
				//resp.mat[v.second-1][j] = 0;
			}
		} else {
			v.second *= -1;
			kt[v.second-1]++;
			if (kt[v.second-1] == 0) for (int j=0;j<3;j++) {
				e.mat[v.second-1][j] = p.mat[v.second-1][j];
				//e.mat[j][v.second-1] = p.mat[j][v.second-1];
			}
		}
		//printf("%lld\n", cur);
		//resp.print();
	}
	printf("%lld\n", resp.mat[1][1]);
	return 0;
}
