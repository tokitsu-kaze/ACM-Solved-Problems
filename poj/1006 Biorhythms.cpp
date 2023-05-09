#include <cstdio>
#include <cmath>
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
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int r,t;
	r=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int CRT(int a[],int m[],int n)
{
	int p=1,res=0,i,x,y;
	for(i=0;i<n;i++)
	{
		p*=m[i];
	}
	for(i=0;i<n;i++)
	{
		exgcd(p/m[i],m[i],x,y);
		res=(res+p/m[i]*x*a[i])%p;
	}
	if(res<0) res+=p;
	return res;
}
int main()
{
	int t,i,m[5]={23,28,33},a[5],d,cas=1;
	while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d))
	{
		if(a[0]+a[1]+a[2]+d==-4) break;
		for(i=0;i<3;i++)
		{
			a[i]%=m[i];
		}
		int ans=CRT(a,m,3);
		ans-=d;
		if(ans<=0) ans+=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",cas++,ans);
	}
	return 0;
}