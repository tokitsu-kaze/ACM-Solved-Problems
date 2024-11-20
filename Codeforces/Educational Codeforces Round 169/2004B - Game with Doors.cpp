#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int t,n,i,x,y,l,r,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&l,&r);
		ans=min(r,y)-max(l,x);
		if(ans<0) ans=1;
		else
		{
			if(x!=l) ans++;
			if(y!=r) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

