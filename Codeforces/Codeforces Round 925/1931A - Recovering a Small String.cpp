#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,k;
	string ans,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans="zzz";
		for(i=1;i<=26;i++)
		{
			for(j=1;j<=26;j++)
			{
				for(k=1;k<=26;k++)
				{
					now="";
					now+='a'+i-1;
					now+='a'+j-1;
					now+='a'+k-1;
					if(i+j+k!=n) continue;
					ans=min(ans,now);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
