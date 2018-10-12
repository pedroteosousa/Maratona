#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

map<ppp, int> cnt;

vector<ppp> sg;

int mni, mnj;

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

void add(int i, int j, int ii, int jj){
	if(i == ii && j == jj) return ;
	mni = min(min(ii, i), mni);
	mnj = min(min(jj, j), mnj);
	
	pii p = pii(i, j);
	int gc = gcd(abs(ii-i), abs(jj-j));
	int sti = (ii - i)/gc;
	int stj = (jj - j)/gc;

	int cnt = gc;
	while(cnt--){
		//printf("add %d %d - %d %d\n", p.fst, p.snd, p.fst + sti, p.snd + stj);
		sg.pb(ppp(p, pii(p.fst + sti, p.snd + stj)));
		p.fst += sti;
		p.snd += stj;
	}
}

int main (){
	while(scanf("%d", &n) != EOF){
		cnt.clear();
		int pi = 0, pj = 0;
		mni = INT_MAX;
		mnj = INT_MAX;
		sg.clear();
		for(int a=0;a<n;a++){
			char c;
			int i, j;
			scanf(" %c %d %d", &c, &i, &j);
			if(c == 'L'){
				add(pi, pj, pi+i, pj+j);			
			}
			pi += i;
			pj += j;
		}
		for(int i=0;i<sg.size();i++)
			if(sg[i].fst > sg[i].snd)
				swap(sg[i].fst, sg[i].snd);
		sort(sg.begin(), sg.end());
		sg.erase(unique(sg.begin(), sg.end()), sg.end());
		//printf("mni %d mnj %d\n", mni, mnj);
		for(int i=0;i<sg.size();i++){
			sg[i].fst.fst -= mni;
			sg[i].snd.fst -= mni;
			sg[i].fst.snd -= mnj;
			sg[i].snd.snd -= mnj;
				
			//printf("sg %d %d %d %d %d\n", i, sg[i].fst.fst, sg[i].fst.snd, sg[i].snd.fst, sg[i].snd.snd);
			
			cnt[sg[i]]++;
		}
		sg.clear();
		scanf("%d", &m);
		mni = INT_MAX;
		mnj = INT_MAX;
		pi = 0; pj = 0;
		for(int a=0;a<m;a++){
			char c;
			int i, j;
			scanf(" %c %d %d", &c, &i, &j);
			if(c == 'L')
				add(pi, pj, pi+i, pj+j);
			pi += i;
			pj += j;
		}
		//printf("mni %d mnj %d\n", mni, mnj);
		for(int i=0;i<sg.size();i++)
			if(sg[i].fst > sg[i].snd)
				swap(sg[i].fst, sg[i].snd);
		sort(sg.begin(), sg.end());
		sg.erase(unique(sg.begin(), sg.end()), sg.end());
		for(int i=0;i<sg.size();i++){
			sg[i].fst.fst -= mni;
			sg[i].snd.fst -= mni;
			sg[i].fst.snd -= mnj;
			sg[i].snd.snd -= mnj;

			//printf("sg %d %d %d %d %d\n", i, sg[i].fst.fst, sg[i].fst.snd, sg[i].snd.fst, sg[i].snd.snd);
			
			cnt[sg[i]]--;
		}
		int ok = 1;
		for(auto it: cnt){
			if(it.snd != 0){
				ok = 0;
				break;
			}
		}
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
}
