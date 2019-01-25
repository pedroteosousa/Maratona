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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	ll n;
	while (scanf(" %*d%*c%lld", &n) != EOF) {
		ll resp = 0;
		for (ll x = n+1; x <= 2*n; x++) {
			if ((n * x) % (x - n) != 0) continue;
			ll y = (n * x) / (x - n);
			if (x <= y) resp++;
		}
		printf("%lld\n", resp);
	}
}
