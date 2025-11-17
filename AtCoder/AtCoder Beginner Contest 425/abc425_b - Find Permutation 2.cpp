#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,j,cnt[12],a[12],ok;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0) cnt[a[i]]++;
	}
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(cnt[i]>1) ok=0;
	}
	if(!ok)
	{
		puts("No");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]!=-1) continue;
		for(j=1;j<=n;j++)
		{
			if(cnt[j]==0)
			{
				cnt[j]=1;
				a[i]=j;
				break;
			}
		}
	}
	puts("Yes");
	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}
