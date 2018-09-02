#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int pre;
int get(int flag)
{
	return flag%2?llrand()%(MAX-10)+1:pre;
}
int main()
{
	srand(time(0));
	freopen("in.txt","w",stdout);
	int t=6,cas,n[]={(int)1e4,(int)5e4,(int)1e5,(int)2e5,(int)3e5,(int)3e5},i;
	printf("%d\n",t);
	for(cas=0;cas<t;cas++)
	{
		printf("%d\n",n[cas]);
		pre=llrand()%(MAX-10)+1;
		for(i=1;i<=n[cas];i++) printf("%d%c",pre=get(rand()%3)," \n"[i==n[cas]]);
	}
	return 0;
}
*/


int top;
PII s[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,t,pre,x,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=pre=0;
		vector<pair<PII,int> > ans;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n) scanf("%d",&x);
			else x=0;
			temp=x-pre;
			if(temp>0) s[top++]=MP(i,temp);
			else
			{
				while(temp<0)
				{
					PII p=s[--top];
					if(abs(temp)<p.se)
					{
						ans.pb(MP(MP(p.fi,i-1),abs(temp)));
						temp+=p.se;
						p.se=temp;
						s[top++]=p;
						temp=0;
					}
					else
					{
						ans.pb(MP(MP(p.fi,i-1),p.se));
						temp+=p.se;
					}
				}
			}
			pre=x;
		}
		printf("%d\n",sz(ans));
		for(i=sz(ans)-1;~i;i--) printf("%d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se);
	}
	return 0;
}
/*
2
7
1 2 3 4 3 2 1
4
1 2 3 4
*/