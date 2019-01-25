#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

string s;
ll dp[MAXN][MAXN];

ll solve(int i, int j) {
	if (j < 0) return 0;
	if (i < 0) return j == 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	dp[i][j] = 0;
	ll a1 = solve(i-1, j-1);
	ll a2 = solve(i-1, j+1);
	if (s[i] == ')') dp[i][j] = a2 % modn;
	else if (s[i] == '(') dp[i][j] = a1 % modn;
	else dp[i][j] = (a1 + a2) % modn;
	//printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
	return dp[i][j];
}

int main (){
	while (cin >> s) {
		int n = s.size();
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				dp[i][j] = -1;
			}
		}
		printf("%lld\n", solve(n-1, 0));
	}
}
