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

const int MAXN = 21234;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];
int deg[MAXN];

vector<int> v;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int foi[MAXN], mrk[MAXN];
int tempo;

int ok;

void go(int u, int ch, int x, int y){
	tempo++;
	queue<int> q;
	mrk[u] = tempo;
	mrk[x] = tempo;
	mrk[y] = tempo;
	mrk[ch] = tempo;
	q.push(ch);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int cnt = 0;
		for(int nxt: adj[u]){
			if(mrk[nxt] == tempo) continue;	
			cnt++;
			mrk[nxt] = tempo;
			q.push(nxt);
		}
		if(cnt > 1){
			ok = 1;
			return ;
		}
	}
}

void marca(int u){
	foi[u] = 1;
	for(int nxt: adj[u]){
		if(foi[nxt]) continue;
		marca(nxt);
	}
}

void test(int u){
	//printf("test %d\n", u);
	vector<int> op = adj[u];
	sort(op.begin(), op.end());
	go(u, op[0], op[1], op[2]);
	//printf("%d %d %d ok %d\n", op[0], op[1], op[2], ok);
	go(u, op[1], op[0], op[2]);
	//printf("%d %d %d ok %d\n", op[1], op[0], op[2], ok);
	go(u, op[2], op[1], op[0]);
	//printf("%d %d %d ok %d\n", op[2], op[1], op[0], ok);
	marca(u);
}

int main (){
	while(scanf("%d%d", &n, &m)!=EOF){
		tempo = 0;
		for(int a=1;a<=n;a++){
			mrk[a] = 0;
			foi[a] = 0;
			adj[a].clear();
			deg[a] = 0;
		}
		v.clear();
		int mx = 0;
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);			
			deg[i]++; deg[j]++;
			adj[i].pb(j);
			adj[j].pb(i);
			mx = max(mx, deg[i]);
			mx = max(mx,deg[j]);
		}
		if(mx > 3){
			puts("YES");
			continue;
		}
		else if(mx < 3){
			puts("NO");
			continue;
		}
		for(int a=0;a<n;a++){
			if(deg[a] == 3)
				v.pb(a);	
		}

		ok = 0;
		for(int u: v){
			if(foi[u]) continue;
			test(u);
			if(ok) break;
		}
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
}
