////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-07 13:15:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3389
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1720KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=1e4+10;
const ll mod=1e9+7;
int flag[MAX];
int main()
{
	int i,j,n,p,t,ans,x,cas=1;
	mem(flag,0);
	for(i=1;i<=10000;i++)
	{
		if(flag[i]) continue;
		for(j=i+1;j<=10000;j++)
		{
			if((i+j)%2==1&&(i+j)%3==0)
			{
				p=j;
				break;
			}
		}
		if(flag[p]) continue;
		for(j=p;j<=10000;j+=6) flag[j]=1;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(flag[i]) ans^=x;
		}
		printf("Case %d: ",cas++);
		ans?puts("Alice"):puts("Bob");
	}
	return 0;
}