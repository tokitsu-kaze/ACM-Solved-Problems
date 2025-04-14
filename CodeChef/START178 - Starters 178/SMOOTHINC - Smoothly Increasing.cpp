#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],tmp[MAX];
char ans[MAX];
int ck(int n)
{
	if(n==1) return 1;
	int i;
	for(i=1;i<n;i++)
	{
		if(tmp[i]>=tmp[i+1]) return 0;
		tmp[i]=tmp[i+1]-tmp[i];
	}
	return ck(n-1);
}
int main()
{
	int T,n,i,j,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans[i]='0';
		}
		ans[n+1]='\0';
		if(n>32)
		{
			puts(ans+1);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			tot=0;
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				tmp[++tot]=a[j];
			}
			ans[i]+=ck(tot);
		}
		puts(ans+1);
	}
	return 0;
}
