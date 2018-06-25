////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-02 10:38:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5532
////Problem Title: 
////Run result: Accept
////Run time:1123MS
////Run memory:3240KB
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],c[MAX],d[MAX];
int main()
{
	int t,i,n,pos1,pos2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=-a[i];
			c[i]=d[i]=INF;
		}
		for(i=0;i<n;i++)
		{
			pos1=upper_bound(c,c+n,a[i])-c;
			pos2=upper_bound(d,d+n,b[i])-d;
			c[pos1]=a[i];
			d[pos2]=b[i];
		}
		if(n-(lower_bound(c,c+n,INF)-c)<=1||n-(lower_bound(d,d+n,INF)-d)<=1) puts("YES");
		else puts("NO");
	}
	return 0;
}