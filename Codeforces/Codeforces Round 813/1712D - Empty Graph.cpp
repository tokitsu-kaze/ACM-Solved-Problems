#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],k,n;
int ck(int x)
{
	int cnt,now,i;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]*2<x) cnt++;
	}
	for(i=1;i<n;i++)
	{
		now=cnt;
		if(a[i]*2>=x && a[i]<x) now++;
		if(a[i+1]*2>=x && a[i+1]<x) now++;
		if(now<=k) return 1;
	}
	return 0;
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
		r=1e9;
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
/*
这种题首先挖掘性质 
两点最短路，要么直接走，要么绕一个最小点走。
直接走，最长的最短路肯定是相邻两点，更长不会优，所以 min(a[i],a[i+1])；
绕路，肯定绕 mn=min{ai}，所以是 2*mn；
所以答案为 max{min{a[i],a[i+1],2*mn}}。
这种形式考虑二分答案
2*ai<ans的都要改，然后 min(a[i],a[i+1]) 只要有一个就行。
枚举 i，算一下 a[i] 和 a[i+1] 是否需要改动(就是可能已经被改过了)
*/
