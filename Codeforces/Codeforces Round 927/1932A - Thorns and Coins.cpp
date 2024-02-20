#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,n,i,ans;
	char s[55];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='@') ans++;
			else if(s[i]=='*')
			{
				if(i>1&&s[i-1]=='*') break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
