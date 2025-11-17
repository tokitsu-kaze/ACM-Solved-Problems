#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(i&1) ans-=i*i*i;
		else ans+=i*i*i;
	}
	printf("%d\n",ans);
	return 0;
}
