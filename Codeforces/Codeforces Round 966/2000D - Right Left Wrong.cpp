#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
ll bit[MAX];
char s[MAX];
int main()
{
	int t,n,i,j;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bit[i]=bit[i-1]+a[i];
		}
		scanf("%s",s+1);
		ans=0;
		for(i=1,j=n;i<=n;i++)
		{
			while(j>0 && s[j]!='R') j--;
			if(s[i]=='L')
			{
				if(i<j) ans+=bit[j]-bit[i-1];
				j--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
