////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-15 20:32:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4858
////Problem Title: 
////Run result: Accept
////Run time:826MS
////Run memory:7364KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const ll mod=1e6;
vector<int> mp[MAX];
int v[MAX];
void init(int n)
{
	mem(v,0);
	for(int i=1;i<=n;i++)
	{
		mp[i].clear();
	}
}
int main()
{
	int t,n,m,i,j,a,b,k,op;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			init(n);
			while(m--) 
			{
				scanf("%d%d",&a,&b);
				mp[a].push_back(b);
				mp[b].push_back(a);
			}
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&op);
				if(op==0)
				{
					scanf("%d%d",&a,&b);
					v[a]+=b;
				}
				else
				{
					ll s=0;
					scanf("%d",&a);
					for(i=0;i<mp[a].size();i++)
					{
						s+=v[mp[a][i]];
					}
					printf("%lld\n",s);
				}
			}
		}
	}
	return 0;
}