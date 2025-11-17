#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
void dfs(int l,int r)
{
	if(l+1==r)
	{
		if(a[l]>a[r]) swap(a[l],a[r]);
		return;
	}
	int mid=(l+r)/2;
	dfs(l,mid);
	dfs(mid+1,r);
	if(a[l]>a[mid+1])
	{
		for(int i=l;i<=mid;i++) swap(a[i],a[mid+1+(i-l)]);
	}
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n=(1<<n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1,n);
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
