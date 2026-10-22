#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int l,r;};
vector<node> seg[MAX];
int sum[MAX];
int main()
{
	int n,q,i,l,r,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=q;i++) seg[i].clear();
	for(i=0;i<=n;i++) sum[i]=0;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		seg[x].push_back({l,r});
	}
	for(i=1;i<=q;i++)
	{
		if(seg[i].size()==0) continue;
		sort(seg[i].begin(),seg[i].end(),[](node a,node b){
			return a.r<b.r;
		});
		vector<node> res;
		l=seg[i][0].l;
		r=seg[i][0].r;
		for(auto &it:seg[i])
		{
			if(it.l<=r)
			{
				r=it.r;
				l=min(l,it.l);
			}
			else
			{
				res.push_back({l,r});
				l=it.l;
				r=it.r;
			}
			while(res.size()>0 && res.back().r>=l)
			{
				l=min(l,res.back().l);
				res.pop_back();
			}
		}
		res.push_back({l,r});
		for(auto &it:res)
		{
			sum[it.l]++;
			sum[it.r+1]--;
		}
	}
	for(i=1;i<=n;i++)
	{
		sum[i]+=sum[i-1];
		printf("%d%c",sum[i]," \n"[i==n]);
	}
	return 0;
}
