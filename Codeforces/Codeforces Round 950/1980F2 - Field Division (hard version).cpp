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
	int T,n,m,k,i,x,y,id,prex,prey,preid;
	ll ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		map<int,pair<int,int>> l;
		map<int,int> nexl;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			if(l.count(x))
			{
				if(l[x].first>=y)
				{
					if(nexl.count(x)) nexl[x]=min(nexl[x],l[x].first);
					else nexl[x]=l[x].first;
				}
				else
				{
					if(nexl.count(x)) nexl[x]=min(nexl[x],y);
					else nexl[x]=y;
				}
				l[x]=min(l[x],{y,i});
			}
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
		preid=0;
		for(auto &it:res)
		{
			if(it.y>y)
			{
				if(it.y>prey) continue;
				delta[preid]+=1LL*(prex-it.x)*(prey-1);
				if(it.y<prey)
				{
					prex=it.x;
					prey=it.y;
				}
				else if(it.y==prey) prex=it.x;
				continue;
			}
			tmp=1LL*(x-it.x)*(y-1);
			ans+=tmp;
			
			if(preid) delta[preid]+=1LL*(prex-it.x)*(prey-1)-tmp;
			if(it.y<y)
			{
				if(nexl.count(it.x)) prey=min(nexl[it.x],y);
				else prey=y;
				preid=it.id;
				prex=x=it.x;
				y=it.y;
			}
			else if(it.y==y)
			{
				x=it.x;
				preid=0;
			}
//			cout<<ans<<endl;
		}
		tmp=1LL*x*(y-1);
		ans+=tmp;
		if(preid) delta[preid]+=1LL*prex*(prey-1)-tmp;
		printf("%lld\n",ans);
		for(i=1;i<=k;i++) printf("%lld%c",delta[i]," \n"[i==k]);
	}
	return 0;
}
/*
1
2 3 2
1 1
1 2
*/
