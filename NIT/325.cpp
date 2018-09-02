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
const double eps=1e-6;
const int MAX=5e4+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t,n,i,j,x;
	t=30;
	printf("%d\n",t);
	t--;
	n=2000;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
	{
		x=rand()%10;
		for(j=1;j<=i;j++)
		{
			printf("%d",x);
		}
		puts("");
	}
	t--;
	n=2000;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",0);
		}
		puts("");
	}
	while(t--)
	{
		n=rand()%2000+1;
		printf("%d\n",n);
		x=rand()%9+1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				printf("%d",x);
			}
			puts("");
		}
		if(t==25) break;
	}
	while(t--)
	{
		n=rand()%2000+1;
		printf("%d\n",n);
		for(i=1;i<=n;i++)
		{
			x=rand()%10;
			int temp=max(rand()%i,i/4);
			map<int,int> mp;
			while(temp--)
			{
				mp[rand()%i]=1;
			}
			for(j=1;j<=i;j++)
			{
				if(mp[j]) printf("%d",rand()%10);
				else printf("%d",x);
			}
			puts("");
		}
		if(t==15) break;
	}
	while(t--)
	{
		n=rand()%2000+1;
		printf("%d\n",n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				x=rand()%10;
				printf("%d",x);
			}
			puts("");
		}
	}
	return 0;
}
*/
char ans[2005],a[2005];
vector<int> p[2];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,n,i,j,flag,temp,pos;
	char maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		p[flag].clear();
		p[flag].pb(0);
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			maxx='0';
			for(j=0;j<sz(p[flag]);j++)
			{
				if(a[p[flag][j]]>maxx) maxx=a[p[flag][j]];
			}
			temp=flag^1;
			p[temp].clear();
			for(j=0;j<sz(p[flag]);j++)
			{
				if(a[p[flag][j]]==maxx)
				{
					if(p[temp].empty()||p[flag][j]>p[temp].back()) p[temp].pb(p[flag][j]);
					p[temp].pb(p[flag][j]+1);
				}
			}
			flag^=1;
			ans[i]=maxx;
		}
		ans[n]='\0';
		pos=0;
		while(ans[pos]=='0') pos++;
		if(pos==n) puts("0");
		else puts(ans+pos);
	}
	return 0;
}
/*
2
3
0
32
123
5
8
89
877
8965
65897
*/