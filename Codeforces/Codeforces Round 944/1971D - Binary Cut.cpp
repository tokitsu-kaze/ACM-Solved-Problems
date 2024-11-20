#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int main()
{
	int t,n,i,ans,f;
	char s[505];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		ans=1;
		f=0;
		for(i=1;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				ans++;
				if(s[i-1]=='0') f=1;
			}
		}
		printf("%d\n",ans-f);
	}
	return 0;
}
