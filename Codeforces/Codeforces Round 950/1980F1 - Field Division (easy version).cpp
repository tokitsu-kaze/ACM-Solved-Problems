#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y,id;};
ll delta[MAX];
int main()
{
	int T,n,m,k,i,x,y,id,pre;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		map<int,pair<int,int>> l;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			if(l.count(x)) l[x]=min(l[x],{y,i});
			else l[x]={y,i};
			delta[i]=0;
		}
		vector<node> res;
		for(auto &it:l)
		{
			x=it.first;
			y=it.second.first;
			id=it.second.second;
			res.push_back({x,y,id});
		}
		reverse(res.begin(),res.end());
		
		x=n;
		y=m+1;
		ans=0;
		for(auto &it:res)
		{
			if(it.y>y) continue;
			ans+=1LL*(x-it.x)*(y-1);
			if(it.y<y)
			{
				x=it.x;
				y=it.y;
				delta[it.id]=1;
			}
			else if(it.y==y) x=it.x;
//			cout<<ans<<endl;
		}
		ans+=1LL*x*(y-1);
		printf("%lld\n",ans);
		for(i=1;i<=k;i++) printf("%lld%c",delta[i]," \n"[i==k]);
	}
	return 0;
}
