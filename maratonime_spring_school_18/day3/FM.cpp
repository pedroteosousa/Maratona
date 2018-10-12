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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1322, C = 109;

int n, m, k;
int s[MAXN];

char M[MAXN][MAXN];

int acu[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

inline int sum(int aa, int bb, int a, int b){
	return acu[aa][bb] - acu[a-1][bb] - acu[aa][b-1] + acu[a-1][b-1];
}

int main (){
	int nl, nc;
	while(scanf("%d%d%d%d", &n, &m, &nl, &nc) != EOF){
		memset(M, 0, sizeof(M));
		for(int aa=0;aa<n;aa++){
			getchar();
			for(int bb=0;bb<m;bb++){
				int a = aa+C, b = bb+C;
				M[a][b] = getchar();
			}
		}
		for(int a=1;a<MAXN;a++){
			for(int b=1;b<MAXN;b++){
				acu[a][b] = acu[a-1][b] + acu[a][b-1] - acu[a-1][b-1] + (M[a][b] == 'X');
			}
		}
		int ans = INT_MAX;
		for(int a=1;a<=nl;a++){
			for(int b=1;b<=nc;b++){
				int res = 0;
				for(int ta=0;a+(ta+1)*nl-1 < MAXN;ta++){
					for(int tb=0;b +(tb+1)*nc-1 < MAXN;tb++){
						int ia = a+ta*nl;
						int ib = b+tb*nc;
						int fa = ia + nl -1;
						int fb = ib + nc -1;
						if(sum(fa, fb, ia, ib) != 0)
							res++;
					}
				}
				ans = min(ans, res);
			}
		}
		printf("%d\n", ans);
	}
}
