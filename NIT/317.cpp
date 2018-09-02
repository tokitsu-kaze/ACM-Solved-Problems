#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
map<PII,int> flag;
int tag[MAX];
int main()
{
	freopen("in.txt","w",stdout);
	ll t=10,i,n,x,y,x1,x2,y1,y2,temp,f;
	printf("%lld\n",t);
	t-=5;
	n=100000;
	printf("%lld\n",n);
	flag.clear();
	mem(tag,0);
	y1=llrand()%100000+1;
	y2=llrand()%100000+1;
	while(y1==y2)
	{
		y1=llrand()%100000+1;
		y2=llrand()%100000+1;
	}
	for(i=1;i<=n/2;i++)
	{
		x=llrand()%100000+1;
		while(tag[x]) x=llrand()%100000+1;
		printf("%lld %lld\n",x,y1);
		printf("%lld %lld\n",x,y2);
		tag[x]=1;
	}
	printf("%lld\n",n);
	flag.clear();
	mem(tag,0);
	x1=llrand()%100000+1;
	x2=llrand()%100000+1;
	while(x1==x2)
	{
		x1=llrand()%100000+1;
		x2=llrand()%100000+1;
	}
	for(i=1;i<=n/2;i++)
	{
		y=llrand()%100000+1;
		while(tag[y]) y=llrand()%100000+1;
		printf("%lld %lld\n",x1,y);
		printf("%lld %lld\n",x2,y);
		tag[y]=1;
	}
	while(t--)
	{
		flag.clear();
		n=100000;
		printf("%lld\n",n);
		while(n)
		{
			temp=llrand()%100000+1;
			f=rand()%2;
			if(f)
			{
				start1:
					x1=llrand()%100000+1;
					x2=llrand()%100000+1;
					while(temp)
					{
						if(n==0) break;
						y=llrand()%100000+1;
						if(flag[MP(x1,y)]||flag[MP(x2,y)]) goto start1;
						flag[MP(x1,y)]=flag[MP(x2,y)]=1;
						printf("%lld %lld\n",x1,y);
						printf("%lld %lld\n",x2,y);
						n-=2;
						temp-=2;
					}
			}
			else
			{
				start2:
					y1=llrand()%100000+1;
					y2=llrand()%100000+1;
					while(temp)
					{
						if(n==0) break;
						x=llrand()%100000+1;
						if(flag[MP(x,y1)]||flag[MP(x,y2)]) goto start2;
						flag[MP(x,y1)]=flag[MP(x,y2)]=1;
						printf("%lld %lld\n",x,y1);
						printf("%lld %lld\n",x,y2);
						n-=2;
						temp-=2;
					}
			}
		} 
		if(t==1) break;
	}
	while(t--)
	{
		flag.clear();
		n=100000;
		printf("%lld\n",n);
		while(n--)
		{
			x=llrand()%100000+1;
			y=llrand()%100000+1;
			while(flag[MP(x,y)])
			{
				x=llrand()%100000+1;
				y=llrand()%100000+1;
			}
			flag[MP(x,y)]=1;
			printf("%lld %lld\n",x,y);
		}
	}
	return 0;
}
*/
vector<int> v,x[MAX],y[MAX];
int flag[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,j,k,xx,yy,cnt,t,lim;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		lim=20;
		v.clear();
		for(i=1;i<=(int)1e5;i++)
		{
			x[i].clear();
			y[i].clear();
		}
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&xx,&yy);
			if(!flag[xx])
			{
				flag[xx]=1;
				v.pb(xx);
			}
			x[xx].pb(yy);
		}
		ans=0;
		mem(flag,0);
		for(i=0;i<sz(v);i++)
		{
			if(sz(x[v[i]])>=lim)
			{
				for(j=0;j<sz(x[v[i]]);j++)
				{
					flag[x[v[i]][j]]=1;
				}
				for(j=0;j<sz(v);j++)
				{
					cnt=0;
					if(j>=i&&sz(x[v[j]])>=lim) continue;
					for(k=0;k<sz(x[v[j]]);k++)
					{
						cnt+=flag[x[v[j]][k]];
					}
					ans+=(ll)cnt*(cnt-1)/2;
				}
				for(j=0;j<sz(x[v[i]]);j++)
				{
					flag[x[v[i]][j]]=0;
				}
			}
			else
			{
				sort(all(x[v[i]]));
				for(j=0;j<sz(x[v[i]]);j++)
				{
					for(k=j+1;k<sz(x[v[i]]);k++)
					{
						y[x[v[i]][j]].pb(x[v[i]][k]);
					}
				}
			}
		}
		for(i=1;i<=(int)1e5;i++)
		{
			if(!y[i].empty())
			{
				for(j=0;j<sz(y[i]);j++)
				{
					ans+=flag[y[i][j]];
					flag[y[i][j]]++;
				}
				for(j=0;j<sz(y[i]);j++)
				{
					flag[y[i][j]]--;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}