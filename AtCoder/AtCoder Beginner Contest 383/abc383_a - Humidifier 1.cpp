#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int n,a,b,i,ans,pre;
	scanf("%d",&n);
	ans=0;
	pre=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		ans=max(0,ans-(a-pre));
		ans+=b;
		pre=a;
	}
	printf("%d\n",ans);
	return 0;
}
