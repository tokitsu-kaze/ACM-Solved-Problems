////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-30 13:45:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6019
////Problem Title: 
////Run result: Accept
////Run time:624MS
////Run memory:1756KB
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
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e4;
int main()
{
	int t,a,n,i,ans,sz;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1;
		set<int> s;
		sz=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			s.insert(a);
			if(s.size()==sz)
			{
				s.clear();
				ans++;
				s.insert(a);
				sz=1;
			}
			else sz++;
		}
		printf("%d\n",ans);
	}
	return 0;
}