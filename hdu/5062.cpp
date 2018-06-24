////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 14:35:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5062
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1676KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const long double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int ans[7];
void init()
{
	int i,j,k,temp=0;
	char a[11],b[11];
	mem(ans,0);
	for(k=0,i=1;k<=6;k++)
	{
		if(temp) temp*=10;
		else temp=1;
		for(;i<=temp;i++)
		{
			sprintf(a,"%d",i);
			strcpy(b,a);
			reverse(b,b+strlen(b));
			if(strcmp(a,b)==0)
			{
				int flag=0;
				for(j=1;j<=(strlen(a)-1)/2;j++)
				{
					if(a[j]<=a[j-1]) flag=1;
				}
				if(!flag) ans[k]++;
			}
		}
		if(k) ans[k]+=ans[k-1];
	}
}
int main()
{
	init();
	int t,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}