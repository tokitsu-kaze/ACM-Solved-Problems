////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 14:12:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5058
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1704KB
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
	int n,i,x;
	while(~scanf("%d",&n))
	{
		set<int> a,b;
		set<int> ::iterator it1,it2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.insert(x);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			b.insert(x);
		}
		if(sz(a)!=sz(b))
		{
			puts("NO");
			continue;
		}
		int flag=0;
		for(it1=a.begin(),it2=b.begin();it1!=a.end();it1++,it2++)
		{
			if(*it1!=*it2)
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}