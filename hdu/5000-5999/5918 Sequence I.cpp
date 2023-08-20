////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-18 14:17:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5918
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:1936KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cmath>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int p;
void KMP(int *a,int *b,int lena,int lenb)
{
	int i,j,k,ans=0;
	for(k=0;k+(lenb-1)*p<lena;k++)
	{
		i=k;
		j=0;
		while(i<lena)
		{
			if(j==-1||a[i]==b[j])
			{
				i+=p;
				j++;
			}
			else break;
			if(j==lenb)
			{
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
}
int a[MAX],b[MAX];
int main()
{
	int t,cas=1,i,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<m;i++) scanf("%d",&b[i]);
		printf("Case #%d: ",cas++);
		KMP(a,b,n,m);
	}
	return 0;
}
