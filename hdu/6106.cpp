////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-12 10:08:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6106
////Problem Title: 
////Run result: Accept
////Run time:31MS
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int a,b,c,ab,bc,ac,abc,ans,n,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
			if(ab<abc||bc<abc||ac<abc) continue;
			if(a<ab+ac-abc||b<ab+bc-abc||c<bc+ac-abc) continue;
			ans=max(ans,a+b+c-ab-bc-ac+abc);
		}
		printf("%d\n",ans);
	}
	return 0;
}