#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,ans,cnt0;
	char s[33];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=cnt0=0;
		for(i=1;i<=n;i++)
		{
			ans+=s[i]-'0';
			cnt0+=(s[i]=='0');
		}
		if(cnt0) ans+=9;
		else ans+=8;
		printf("%d\n",ans);
	}
	return 0;
}

