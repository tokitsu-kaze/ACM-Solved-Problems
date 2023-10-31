#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e3+10;
ll a[MAX];
int n,tmp[MAX],t[MAX],b[MAX];
int ck(int x)
{
	int i,y;
	for(i=1;i<=n;i++)
	{
		a[i]=1ll*x*t[i];
		if(a[i]>b[i]) return 0;
	}
	if((b[1]-a[1])%tmp[1]) return 0;
	y=(b[1]-a[1])/tmp[1];
	for(i=1;i<=n;i++)
	{
		a[i]+=1ll*y*tmp[i];
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&t[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) tmp[i]=t[i]+t[n-i+1];
		for(i=0;i<=2000;i++)
		{
			if(ck(i))
			{
				puts("Yes");
				goto end;
			}
		}
		puts("No");
		end:;
	}
	return 0;
}
