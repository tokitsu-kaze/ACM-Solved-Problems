#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
string s[MAX];
char tmp[MAX];
int main()
{
	int t,n,i,j,ans,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%s",tmp);
			s[i]=string(tmp);
		}
		ans=0;
		now=0;
		for(j=0;j<20;j++)
		{
			for(i=1;i<=n;i++)
			{
				if(s[i].size()==0) continue;
				now+=s[i].back()-'0';
				s[i].pop_back();
			}
			ans+=now/10;
			now/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
