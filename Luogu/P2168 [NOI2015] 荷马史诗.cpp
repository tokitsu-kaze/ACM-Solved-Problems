#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct k_Huffman
{
	#define type pair<ll,int>
	type work(int n,int k,ll *a)// a[1..n], sorted 
	{
		int i,mx;
		ll res,s;
		queue<type> q,d;
		s=((n-1)%(k-1)?k-1-(n-1)%(k-1):0);//计算要补多少个0 
		while(s--) q.push({0,0});
		for(i=1;i<=n;i++) q.push({a[i],0});
		res=0;
		while(q.size()+d.size()>1)
		{
			s=0;
			mx=0;
			for(i=0;i<k;i++)
			{
				if(q.size()&&d.size())
				{
					if(q.front().first<=d.front().first)
					{
						s+=q.front().first;
						mx=max(mx,q.front().second);
						q.pop();
					}
					else
					{
						s+=d.front().first;
						mx=max(mx,d.front().second);
						d.pop();
					}
				}
				else if(q.size())
				{
					s+=q.front().first;
					mx=max(mx,q.front().second);
					q.pop();
				}
				else if(d.size())
				{
					s+=d.front().first;
					mx=max(mx,d.front().second);
					d.pop();
				}
			}
			res+=s;
			d.push({s,mx+1});
		}
		mx=0;
		if(d.size()>0) mx=d.front().second;
		else mx=q.front().second;
		return {res,mx};
	}
	#undef type
}hfm;
ll a[MAX];
int main()
{
	int n,k,i,s;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	auto it=hfm.work(n,k,a);
	printf("%lld\n",it.first);
	printf("%d\n",it.second);
	return 0;
}
