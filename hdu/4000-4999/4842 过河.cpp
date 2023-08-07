////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-10 14:42:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4842
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:3668KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int dp[MAX],flag[MAX];
int main()
{
	int n,s,t,l,i,j,pre,x[111],ans,tmp,tag=0;
	while(~scanf("%d%d%d%d",&l,&s,&t,&n))
	{
		if(tag) puts("");
		tag=1;
		mem(flag,0);
		for(i=0;i<n;i++) scanf("%d",&x[i]);
		if(s==t)
		{
			ans=0;
			for(i=0;i<n;i++) ans+=(x[i]%s==0);
			printf("%d",ans);
			continue;
		}
		sort(x,x+n);
		tmp=pre=0;
		for(i=0;i<n;i++)
		{
			x[i]-=tmp;
			if(x[i]-pre>t*(t-1)) pre+=t*(t-1),tmp+=x[i]-pre;
			else pre=x[i];
			flag[pre]=1;
		}
		assert(l-pre>0);
		l=pre;
		mem(dp,0x3f);
		dp[0]=0;
		for(i=0;i<=l;i++)
		{
			for(j=i+s;j<=i+t&&j<=l+t;j++)
			{
				dp[j]=min(dp[j],dp[i]+flag[j]);
			}
		}
		ans=INF;
		for(i=l;i<l+t;i++) ans=min(ans,dp[i]);
		printf("%d",ans);
	}
	return 0;
}
/*
10000
3 3 5
3 6 9 12 1002
*/