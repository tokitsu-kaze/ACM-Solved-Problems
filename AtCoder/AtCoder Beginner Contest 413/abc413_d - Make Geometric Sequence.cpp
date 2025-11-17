#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX];
int ck(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(a[i-1]*a[i+1]!=a[i]*a[i]) return 0;
	}
	return 1;
}
int main()
{
	int T,n,i,px,py;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		if(ck(n))
		{
			puts("Yes");
			continue;
		}
		vector<ll> x,y;
		for(i=1;i<=n;i++)
		{
			if(a[i]<0) x.push_back(a[i]);
			else y.push_back(a[i]);
		}
		sort(x.begin(),x.end());
		reverse(x.begin(),x.end());
		sort(y.begin(),y.end());
		px=py=0;
		for(i=1;i<=n;i++)
		{
			if(i&1)
			{
				if(px<x.size()) a[i]=x[px++];
				else if(py<y.size()) a[i]=y[py++];
			}
			else
			{
				if(py<y.size()) a[i]=y[py++];
				else if(px<x.size()) a[i]=x[px++];
			}
		}
		if(ck(n))
		{
			puts("Yes");
			continue;
		}
		px=py=0;
		for(i=1;i<=n;i++)
		{
			if(!(i&1))
			{
				if(px<x.size()) a[i]=x[px++];
				else if(py<y.size()) a[i]=y[py++];
			}
			else
			{
				if(py<y.size()) a[i]=y[py++];
				else if(px<x.size()) a[i]=x[px++];
			}
		}
		if(ck(n)) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
2
5
1 -1 1 -1 1
5
-1 1 -1 1 -1
*/
