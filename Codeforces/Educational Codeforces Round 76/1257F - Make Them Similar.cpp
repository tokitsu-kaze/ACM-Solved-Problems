#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,a[105],c[105],i,x,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	map<vector<int>,int> mp;
	vector<int> res(n);
	for(x=0;x<(1<<15);x++)
	{
		for(i=0;i<n;i++) c[i]=a[i]&((1<<15)-1);
		for(i=0;i<n;i++) res[i]=__builtin_popcount(c[i]^x);
		for(i=1;i<n;i++) res[i]=res[0]-res[i];
		res[0]=0;
		if(!mp.count(res)) mp[res]=x;
	}
	ans=-1;
	for(x=0;x<(1<<15);x++)
	{
		for(i=0;i<n;i++) c[i]=((a[i]>>15)<<15);
		for(i=0;i<n;i++) res[i]=__builtin_popcount(c[i]^(x<<15));
		for(i=1;i<n;i++) res[i]-=res[0];
		res[0]=0;
		if(mp.count(res))
		{
			ans=(x<<15)+mp[res];
			break;
		}
	}
//	for(i=0;i<n;i++) res[i]=__builtin_popcount(a[i]^ans);
//	for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	printf("%d\n",ans);
	return 0;
}
/*
折半一下，算出来的结果是vector，丢进map。
枚举 1 的个数，map里查就行，复杂度O(n*sqrt(V)*log^2 V)。
推一下式子 a1+b1=ai+bi，转化一下变成 a1-ai=bi-b1，
可以省去一个枚举的 log。
*/
