#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

typedef pair<int, int> pii;
#define f first
#define b second
#define pb push_back
#define mp make_pair
#define cost first
#define nd second

pii node[N];
int visited[N];
vector<int> nodes[N];
vector<pii> adj[N];
map<pii, int> findNode;
vector<int> dist[N];

int nextNode = 0;

int getNode(int f, int b)
{
    if (findNode.find(mp(f, b)) == findNode.end())
    {
        int nod = nextNode++;
        adj[nod].clear();
        node[nod]= mp(f, b);
        //printf("node %d = (%d, %d)\n", nod, f, b);
        nodes[b].pb(nod);
        findNode[mp(f, b)] = nod;
        return nod;
    }
    else return findNode[mp(f, b)];
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, f, m;
        scanf("%d %d %d", &n, &f, &m);
        nextNode = 0;
        findNode.clear();
        for(int i=1;i<=n;i++) {
            nodes[i].clear();
        }
        for(int i=0;i<n;i++) {
            int a = getNode(1, i+1);
            int b = getNode(1, (i+1)%n+1);
            adj[a].pb(mp(1, b));
            adj[b].pb(mp(1, a));
        }
        for(int i=0;i<m;i++) {
            int bi, fi, bj, fj, t;
            scanf("%d %d %d %d %d", &bi, &fi, &bj, &fj, &t);
            int a = getNode(fi, bi);
            int b = getNode(fj, bj);
            adj[a].pb(mp(t, b));
            for(int j=0;j<nodes[bi].size();j++) {
                if (nodes[bi][j] == a) continue;
                adj[a].pb(mp(abs(fi - node[nodes[bi][j]].f), nodes[bi][j]));
                adj[nodes[bi][j]].pb(mp(abs(fi - node[nodes[bi][j]].f), a));
            }
            adj[b].pb(mp(t, a));
            for(int j=0;j<nodes[bj].size();j++) {
                if (nodes[bj][j] == b) continue;
                adj[b].pb(mp(abs(fj - node[nodes[bj][j]].f), nodes[bj][j]));
                adj[nodes[bj][j]].pb(mp(abs(fj - node[nodes[bj][j]].f), b));
            }
        }
        for(int i=0;i<nextNode;i++) {
            dist[i].clear();
            for(int j=0;j<nextNode;j++) {
                dist[i].pb(0);
                visited[j] = 0;
            }
            priority_queue<pii> q;
            q.push(mp(0, i));
            while(q.size()) {
                pii p = q.top();
                q.pop();
                if (visited[p.nd] != 0) continue;
                visited[p.nd] = 1;
                dist[i][p.nd] = -p.cost;
                for(int j=0;j<adj[p.nd].size();j++) {
                    q.push(mp(p.cost - adj[p.nd][j].cost, adj[p.nd][j].nd));
                }
            }
        }
        int q; scanf("%d", &q);
        for(int i=0;i<q;i++) {
            int bi, fi, bj, fj;
            scanf("%d %d %d %d", &bi, &fi, &bj, &fj);
            int resp = 1791791791;
            if (bi == bj) resp = abs(fi - fj);
            for(int j=0;j<nodes[bi].size();j++) {
                for(int k=0;k<nodes[bj].size();k++) {
                    resp = min(resp, abs(fi - node[nodes[bi][j]].f) + dist[nodes[bi][j]][nodes[bj][k]] + abs(fj - node[nodes[bj][k]].f));
                    //printf("resp = %d: %d -> %d: dist = %d\n", resp, nodes[bi][j], nodes[bj][k], dist[nodes[bi][j]][nodes[bj][k]]);
                }
            }
            printf("%d\n", resp);
        }
    }
    return 0;
}

