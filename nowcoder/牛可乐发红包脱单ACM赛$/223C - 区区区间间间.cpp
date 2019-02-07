#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long int ll;

int n;
int v[N], l[N], r[N];

ll solve (bool flag) {
	if (flag)
		for (int i = 0; i < n; ++i)
			v[i] = -v[i];
	for (int i = 0; i < n; ++i)
		l[i] = r[i] = i;
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j and v[i] >= v[j - 1])
			j = l[j - 1];
		l[i] = j;
	}
	for (int i = n - 2; i >= 0; --i) {
		int j = i;
		while (j < n - 1 and v[i] > v[j + 1])
			j = r[j + 1];
		r[i] = j;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += ll(v[i]) * (i - l[i] + 1) * (r[i] - i + 1);
	return ans;
}

int main () {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		printf("%lld\n", solve(0) + solve(1));
	}
	return 0;
}