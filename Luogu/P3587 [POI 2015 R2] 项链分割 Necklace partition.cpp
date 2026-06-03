#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX],lst[MAX];
ull sum[MAX],w[MAX];
mt19937_64 rd(time(0));
int main()
{
	int n,k,i,mn,len;
	ll cnt;
	ull now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) sum[i]=lst[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		w[i]=rd();
		sum[a[i]]^=w[i];
		lst[a[i]]=i;
	}
	for(i=1;i<=k;i++) w[lst[i]]^=sum[i];
	map<ull,vector<int>> mp;
	now=0;
	cnt=0;
	mn=INF;
	for(i=1;i<=n;i++)
	{
		now^=w[i];
		auto &res=mp[now];
		if(res.size()>0)
		{
			cnt+=res.size();
			auto it=lower_bound(res.begin(),res.end(),max(1,i-n/2));
			if(it!=res.end())
			{
				len=i-*it;
				mn=min(mn,abs((n-len)-len));
			}
			it=upper_bound(res.begin(),res.end(),max(1,i-n/2));
			if(it!=res.begin())
			{
				it--;
				len=i-*it;
				mn=min(mn,abs((n-len)-len));
			}
		}
		res.push_back(i);
	}
	printf("%lld %d\n",cnt,mn);
	return 0;
}
/*
环是骗人的，只要求其中一段就行，而且不会跨越端点。
把每个位置随机权值，令一种数的所有位置权值异或和为0，
这样只要区间异或和为0就是一种合法方案。
*/
