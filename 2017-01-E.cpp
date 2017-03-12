#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long mod = 1000000007;
long long inf = 1791791791;

int val[N];

long long power(int e) {
    if (e <= 0) return 1ll;
    else {
        long long temp = power(e>>1);
        if (e & 1) return (2ll*(temp*temp)%mod)%mod;
        else return (temp*temp)%mod;
    }
}

int main() {
    int t; scanf("%d", &t);
    for(int j=0;j<t;j++) {
        int n; scanf("%d", &n);
        long long substring = 0, subsequence;
        int mini = inf, maxi = -inf;
        for(int i=0;i<n;i++) {
            scanf("%d", &val[i]);
            mini = min(mini, val[i]);
            maxi = max(maxi, val[i]); 
        }
        if (mini == maxi) {
            printf("%lld %lld\n", ((((long long)n)*((long long)n+1ll))/2ll)%mod, (power(n)-1ll)%mod);
        }
        else {
            int minc = 0, maxc = 0;
            for(int i=0;i<n;i++) {
                if (mini == val[i]) minc++;
                if (maxi == val[i]) maxc++;
            }
            int minimum = -1, maximum = -1;
            for(int i=0;i<n;i++) {
                if (mini == val[i]) minimum = i;
                if (maxi == val[i]) maximum = i;
                substring += (long long)min(minimum, maximum) + 1ll;
                substring %= mod;
            }
            subsequence = ((((power(minc)-1)*(power(maxc)-1))%mod)*power(n-minc-maxc))%mod;
            printf("%lld %lld\n", substring, subsequence);
        }
    }
    return 0;
}

