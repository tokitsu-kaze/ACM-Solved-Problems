#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int a[111],b[111];
int main()
{
	int T,n,a,b,c,ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&c);
		tmp=n/(a+b+c);
		n-=tmp*(a+b+c);
		ans=tmp*3;
		if(n>0)
		{
			n-=a;
			ans++;
		}
		if(n>0)
		{
			n-=b;
			ans++;
		}
		if(n>0)
		{
			n-=c;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
