#include <bits/stdc++.h>



using namespace std;


const int N = 100007;


int v[N];



int main() {

	int n;

	scanf("%d", &n);

	for (int i=0;i<n;i++) {

		scanf("%d", &v[i]);

	}

	set<int> s;

	for (int i=2;i<n-1;i++) {

		s.insert(-(v[i]-v[i-1]));

	}

	int mx[2] = {0, 0};

	if (s.size()) {

		mx[0] = -*s.begin();

		s.erase(s.begin());

		if (s.size()) {

			mx[1] = -*s.begin();

		}

	}

	int left = v[n-1] - v[n-2];

	left = max((max(left, mx[0])+1)/2, max(mx[1], min(left, mx[0])));

	int right = v[1] - v[0];

	right = max((max(right, mx[0])+1)/2, max(mx[1], min(right, mx[0])));

	printf("%d\n", min(left, right));

	return 0;

}
