#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct node{int l,r;};
int d[MAX],v[MAX],a[MAX],p[MAX],bit[MAX];
int ck(int x,int id,int V)
{
	int s=x-d[id];
	return 1LL*v[id]*v[id]+2LL*a[id]*s>1LL*V*V;
}
int main()
{
	int T,n,m,L,V,i,j,l,r,mid,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(i=0;i<=L;i++) bit[i]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
			bit[p[i]]=1;
		}
		for(i=1;i<=L;i++) bit[i]+=bit[i-1];
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			if(a[i]<0)
			{
				if(v[i]<=V) continue;
				l=d[i];
				r=L;
				while(l<r)
				{
					mid=(l+r)>>1;
					if(ck(mid+1,i,V)) l=mid+1;
					else r=mid;
				}
				if(bit[l]-bit[d[i]-1]) res.push_back({d[i],l});
			}
			else if(a[i]>0)
			{
				l=d[i];
				r=L;
				while(l<r)
				{
					mid=(l+r)>>1;
					if(ck(mid,i,V)) r=mid;
					else l=mid+1;
				}
				if(ck(l,i,V) && (bit[L]-bit[l-1])) res.push_back({l,L});
			}
			else if(a[i]==0)
			{
				if(v[i]>V && (bit[L]-bit[d[i]-1])) res.push_back({d[i],L});
			}
		}
		sort(res.begin(),res.end(),[](node x,node y){
			return x.r<y.r;
		});
		ans=0;
		now=0;
		for(auto &it:res)
		{
			if(now && p[now]<=it.r && p[now]>=it.l) continue;
			while(now+1<=m && p[now+1]<=it.r) now++;
			ans++;
		}
		printf("%d %d\n",(int)res.size(),m-ans);
	}
	return 0;
}

