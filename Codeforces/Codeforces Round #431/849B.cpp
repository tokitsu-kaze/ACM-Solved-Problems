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
const int MAX=1e3+10;
const ll mod=1e9+7;
int n;
double y[MAX];
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
bool judge(int a,int b)
{
	int i,j,cnt;
	bool flag[MAX];
	double d=(y[b]-y[a])/(b-a);
	mem(flag,0);
	flag[a]=flag[b]=1;
	cnt=2;
	for(i=1;i<=n;i++)
	{
		if(i==a||i==b) continue;
		if(sgn(d*(i-a)-(y[i]-y[a]))==0)
		{
			cnt++;
			flag[i]=1;
		}
	}
	if(cnt==n-1) return 1;
	if(cnt==n) return 0;
	for(i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		for(j=i+1;j<=n;j++)
		{
			if(flag[j]) continue;
			if(sgn((y[j]-y[i])/(j-i)-d)!=0) return 0;
		}
	}
	return 1;
}
int main()
{
	int i;
	while(~scanf("%lld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&y[i]);
		}
		if(n<=2)
		{
			if(n==1) puts("No");
			else if(n==2) puts("Yes");
			continue;
		}
		if(judge(1,2)||judge(2,3)||judge(1,3)) puts("Yes");
		else puts("No");
	}
	return 0;
}