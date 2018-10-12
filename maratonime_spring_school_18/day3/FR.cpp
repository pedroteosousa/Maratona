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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
vector<pii> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int go(int u, int p){
	int mn = INT_MAX;
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		if(nxt == p) continue;
		int cus = ar.snd;
		if(mn == INT_MAX) mn = 0;

		mn += min(go(nxt, u), cus);
	}
	return mn;
}

int main (){
	while(scanf("%d%d", &n, &m) != EOF){
		for(int a=1;a<=n;a++)
			adj[a].clear();
		for(int a=1;a<n;a++){
			int i, j, c;
			scanf("%d%d%d", &i, &j, &c);
			adj[i].pb(pii(j, c));
			adj[j].pb(pii(i, c));
		}
		printf("%d\n", go(m, m));
	}
}
