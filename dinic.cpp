// Dinicão da massa
// Generico: O(V^2 E)
// BipMatch: O(V^(1/2) E)
// UnitCap: O(min{V^(2/3),E^(1/2)} E)
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 100000;

typedef long long ll;

struct dinic {
    int hd[N], nx[M], to[M], ht[M], es;
    ll fl[M], cp[M];
    int n, src, snk;
    int dist[N], seen[N], visi[N], turn;
    int qi, qf, qu[N];

    inline void init () // antes de montar o grafo
    { es = 2; }

    inline void reset () {
        es = 2;
        memset(hd, 0, sizeof hd);
        memset(seen, 0, sizeof seen);
        memset(visi, 0, sizeof visi);
    }

    inline void connect (int i, int j, ll cap) {
 //       printf("%d-%d [%lld]\n", i, j, cap);
        nx[es] = hd[i]; hd[i] = es; to[es] = j; cp[es] = cap; fl[es] = 0; es++; 
        nx[es] = hd[j]; hd[j] = es; to[es] = i; cp[es] = fl[es] = 0; es++;
    }

    bool bfs () {
        turn++;
        qi = qf = 0;

        qu[qf++] = snk;
        dist[snk] = 0;
        seen[snk] = turn;

        while (qi < qf) {
            int u = qu[qi++];

            if (visi[u] == turn)
                continue;
            visi[u] = turn;

            for (int ed = hd[u]; ed; ed = nx[ed]) {
                if (cp[ed^1] == fl[ed^1])
                    continue;
                int v = to[ed];

                if (seen[v] == turn && dist[v] <= dist[u]+1)
                    continue;
                seen[v] = turn;
                dist[v] = dist[u]+1;
                qu[qf++] = v;
            }
        }

        return (seen[src] == turn);
    }

    ll dfs (int u, ll flw) {
        if (u == snk || flw == 0)
            return flw;

        for (int & ed = ht[u]; ed; ed = nx[ed]) {
            int v = to[ed];
            if (fl[ed] >= cp[ed] || seen[v] != turn || dist[v]+1 != dist[u])
                continue;
            if (ll ret = dfs(v, min(flw, cp[ed] - fl[ed]))) {
                fl[ed] += ret;
                fl[ed^1] -= ret;
                return ret;
            }
        }

        return 0;
    }

    ll debug () {
        for (int i = 0; i < n; i++){ 
            printf("%d:", i);
            for (int ed = hd[i]; ed; ed = nx[ed])
                printf(" %d[%lld/%lld]", to[ed], fl[ed], cp[ed]);
            printf("\n");
        }
    }

    ll maxflow () {
        ll res = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++)
                ht[i] = hd[i];
            while (ll val = dfs(src, LLONG_MAX))
                res += val;
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, vector<int> > fi, se;
    map<int, string> as;
    struct dinic d;
    d.init();
    d.snk = n+m+1;
    d.src = n+m;
    d.n = n+m+2;
    for(int i=0;i<n;i++) {
        d.connect(n+m, i, 1);
        string s;
        cin >> s;
        as[i] = s;
        fi[s[0]+s[1]+s[2]].push_back(i);
        se[s[3]+s[4]+s[5]].push_back(i);
    }
    for(int i=0;i<m;i++) {
        d.connect(i+n, n+m+1, 1);
        string s;
        cin >> s;
        as[i+n] = s;
        for(int j=0;j<se[s[0]+s[1]+s[2]].size();j++) {
            d.connect(se[s[0]+s[1]+s[2]][j], i+n, 1);
        }
        for(int j=0;j<fi[s[3]+s[4]+s[5]].size();j++) {
            d.connect(fi[s[3]+s[4]+s[5]][j], i+n, 1);
        }
    }
    int nk = d.maxflow();
    printf("%d\n", nk);
    //d.debug();
    for(int i=0;i<n;i++) {
        for(int ed = d.hd[i]; ed; ed = d.nx[ed]) {
            if (d.fl[ed] == 1) {
                if (as[i][0]+as[i][1]+as[i][2] == as[d.to[ed]][3]+as[d.to[ed]][4]+as[d.to[ed]][5]) {
                    printf("AT %s %s\n", as[i].c_str(), as[d.to[ed]].c_str());
                }
                else printf("TA %s %s\n", as[d.to[ed]].c_str(), as[i].c_str());
            }
        }
    }
}
