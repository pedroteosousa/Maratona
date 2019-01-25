
#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> G;
vector<int> V, K, A;

deque<int> Q;

void dfs(int i) {
    if (K[i] == 1)
        Q.push_back(V[i]);
    if (K[i] == -1) {
        A[i] = Q.front();
        Q.pop_front();
    }
    for (auto j : G[i])
        dfs(j);
    if (K[i] == -1) Q.push_front(A[i]);
    if (K[i] == 1) Q.pop_back();
}

int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    int n;
    scanf(" %d", &n);
    G.resize(1 + 2 * n);
    V.resize(1 + 2 * n);
    K.resize(1 + 2 * n);
    A.resize(1 + 2 * n);

    for (int i = 1; i <= n; i++) {
        int t;
        scanf(" %d", &t);
        K[i] = t;
        if (t == 1) {
            int a, v;
            scanf(" %d%d", &a, &v);
            G[a].push_back(i);
            V[i] = v;
        } else {
            int a;
            scanf(" %d", &a);
            G[a].push_back(i);
        }
    }

    dfs(0);
    for (int i = 1; i <= n; i++) {
        if (K[i] == -1)
            printf("%d\n", A[i]);
    }
}