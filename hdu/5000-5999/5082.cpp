////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 14:47:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
int main()
{
	int i;
	char a[111],b[111],ans1[111],ans2[111];
	while(~scanf("%s%s",a,b))
	{
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='_')
			{
				strcpy(ans1,a+i+1);
				break;
			}
		}
		for(i=0;i<strlen(b);i++)
		{
			if(b[i]=='_')
			{
				strcpy(ans2,b+i+1);
				break;
			}
		}
		printf("%s_small_%s\n",ans1,ans2);
	}
	return 0;
}