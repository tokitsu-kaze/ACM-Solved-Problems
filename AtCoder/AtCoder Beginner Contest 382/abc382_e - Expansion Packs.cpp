#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5000+10;
double p[MAX],f[MAX],e[MAX];
int main()
{
	int n,x,i,j;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&p[i]);
		p[i]/=100.0;
	}
	for(i=1;i<=n;i++) f[0]=0;
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=n;j;j--)
		{
			f[j]=f[j]*(1-p[i])+f[j-1]*p[i];
		}
		f[0]=f[0]*(1-p[i]);
	}
//	for(i=1;i<=n;i++) printf("%.10f\n",f[i]);
	e[0]=0;
	for(i=1;i<=x;i++)
	{
		e[i]=1;
		for(j=1;j<=n;j++)
		{
			e[i]+=f[j]*e[max(0,i-j)];
		}
		e[i]/=(1-f[0]);
	}
	printf("%.10f\n",e[x]);
	return 0;
}
