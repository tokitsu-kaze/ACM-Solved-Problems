#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,i,ans,cnt,pre,x;
	scanf("%d",&n);
	ans=cnt=pre=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>=pre) cnt++;
		else cnt=1;
		ans=max(ans,cnt);
		pre=x;
	}
	printf("%d\n",ans);
	return 0;
}
