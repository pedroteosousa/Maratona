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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

const char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----"};
string st;
vector<int> g;

char str[50000];
map<char, string> cs;
map<string, char> sc;

int main (){
	for (int i=0;i<strlen(s);i++) {
		cs[s[i]] = v[i];
		sc[v[i]] = s[i];
	}
	while (cin >> st) {
		int i = 0;
		g.clear();
		for (auto a : st) {
			g.pb(cs[a].size());
			for (auto b: cs[a]) {
				str[i] = b;
				i++;
			}
		}
		str[i] = '\0';
		int k = 0;
		//cout << str << endl;
		for (int j=(int)g.size()-1;j>=0;j--) {
			string p(str+k, str+k+g[j]);
			k += g[j];
			cout << sc[p];
		}
		cout << endl;
	}
}
