#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n,k,cnt[MAX];
int ck(int x)
{
	int i,j,res;
	for(i=0;i<=n+1;i++) cnt[i]=0;
	j=0;
	res=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<x) cnt[a[i]]++;
		while(cnt[j]>0 && j<x) j++;
		if(j==x)
		{
			res++;
			for(j=0;j<x;j++) cnt[j]=0;
			j=0;
		}
	}
	return res>=k;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}

