#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int bit[MAX];
int main()
{
	int n,h,i,a,b,ans;
	scanf("%d%d",&n,&h);
	for(i=0;i<=h;i++) bit[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		bit[a]++;
		bit[b+1]--;
	}
	ans=bit[0];
	for(i=1;i<=h;i++)
	{
		bit[i]+=bit[i-1];
		ans=max(ans,bit[i]);
	}
	printf("%d\n",ans);
	return 0;
}
