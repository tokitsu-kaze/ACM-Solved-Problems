#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],precnt[MAX],sufcnt[MAX];
int main()
{
	int n,i,ans,pre,suf;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) precnt[i]=sufcnt[i]=0;
	pre=suf=0;
	for(i=1;i<=n;i++)
	{
		sufcnt[a[i]]++;
		if(sufcnt[a[i]]==1) suf++;
	}
	ans=0;
	for(i=1;i<n;i++)
	{
		sufcnt[a[i]]--;
		if(sufcnt[a[i]]==0) suf--;
		precnt[a[i]]++;
		if(precnt[a[i]]==1) pre++;
		ans=max(ans,pre+suf);
	}
	printf("%d\n",ans);
	return 0;
}
