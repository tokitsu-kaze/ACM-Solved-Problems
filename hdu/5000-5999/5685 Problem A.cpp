////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 13:50:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5685
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:2172KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=9973;
char a[MAX];
int s[MAX];
int pow2(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return pow2(x,mod-2);
}
int main()
{
	int n,i,len,l,r;
	while(~scanf("%d",&n))
	{
		scanf("%s",a+1);
		mem(s,0);
		len=strlen(a+1);
		s[0]=1;
		for(i=1;i<=len;i++)
		{
			s[i]=s[i-1]*(a[i]-28)%mod;
		}
		while(n--)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",s[r]*inv(s[l-1])%mod);
		}
	}
	return 0;
}