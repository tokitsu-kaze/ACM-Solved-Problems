#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,ans,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		s[0]='0';
		ans=n;
		f=0;
		for(i=1;i<=n;i++)
		{
			ans+=(s[i]!=s[i-1]);
			if(f==1 && s[i]=='1') f=2;
			if(f==0 && s[i-1]=='1' && s[i]=='0') f=1;
		}
		ans-=f;
		printf("%d\n",ans);
	}
	return 0;
}

