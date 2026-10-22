#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		j=n;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0) continue;
			while(j>=i && a[j]==1) j--;
			if(i>j) break;
			a[j]+=a[i];
			a[i]=0;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
