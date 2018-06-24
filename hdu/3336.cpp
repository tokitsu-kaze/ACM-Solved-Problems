////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-03 22:06:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3336
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:3432KB
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
const int MAX=2e5+10;
const ll mod=10007;
int Next[MAX];
void getnext(char *b,int *Next,int len)
{
	int i,j;
	i=0;
	j=Next[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j]) Next[++i]=++j;
		else j=Next[j];
	}
}
char a[MAX];
int res[MAX];
int main()
{
	int t,ans,i,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&len,a);
		getnext(a,Next,len);
		for(i=1;i<=len;i++)
		{
			res[i]=1;
		}
		ans=0;
		for(i=1;i<=len;i++)
		{
			res[i]=res[Next[i]]+1;
			ans+=res[i];
			ans%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}