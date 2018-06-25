////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-28 21:37:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1820KB
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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=8e4+10;
const ll mod=1e9+7;
char c[MAX],d[MAX];
int main()
{
	int t,n,a,b,cnt,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		scanf("%s %s",c,d);
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(c[i]==d[i]) cnt++;
		}
		if(a+b<=2*cnt+(n-cnt)&&abs(a-b)<=n-cnt) puts("Not lying");
		else puts("Lying");
	}
	return 0;
}
