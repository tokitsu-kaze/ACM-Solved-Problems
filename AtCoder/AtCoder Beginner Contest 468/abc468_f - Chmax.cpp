#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct LIS
{
	#define type int
	const type inf=INF;
	vector<int> work(vector<type> a,bool strict)
	{
		int i,pos,len,n;
		n=a.size();
		vector<type> b(n,inf);
		vector<int> tmp(n),res;
		for(i=0;i<n;i++)
		{
			//    strict: lower_bound
			//not strict: upper_bound
			if(strict) pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
			else pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
			b[pos]=a[i];
			tmp[i]=pos;
		}
		len=lower_bound(b.begin(),b.end(),inf)-b.begin();
		for(i=n-1;~i;i--)
		{
			if(!len) break;
			if(tmp[i]+1==len)
			{
				len--;
				res.push_back(i);
			}
		}
		return res;
	}
	#undef type
}lis;
int p[MAX];
int main()
{
	int n,i,ans,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	vector<int> res;
	ans=0;
	mx=0;
	for(i=1;i<=n;i++)
	{
		if(p[i]>mx)
		{
			mx=p[i];
			ans++;
		}
		else res.push_back(p[i]);
	}
	res=lis.work(res,true);
	ans+=res.size();
	printf("%d\n",ans);
	return 0;
}
/*
赛时漏了个限制：题目的操作会满足每个前缀最大值都取到。
那么如果当前会更新前缀最大值，直接更新 x；
不是前缀最大值，也无法更新 x，看看是否要更新 y。
那直接把每一次会更新前缀最大值的数删掉，
剩下的数跑一遍 LIS 是不是就做完了。
*/
