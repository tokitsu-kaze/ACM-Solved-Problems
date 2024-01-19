#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
	int n,ans,ans2;
	scanf("%d",&n);
	ans=0;
	ans2=0;
	while(n>0)
	{
		ans++;
		if(ans2==0&&n%3==1) ans2=ans;
		n-=(n+2)/3;
	}
	printf("%d %d\n",ans,ans2);
	return 0;
}
