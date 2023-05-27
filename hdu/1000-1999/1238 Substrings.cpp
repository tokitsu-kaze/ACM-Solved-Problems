#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,ans,l,ok;
	string a[111],b[111],tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
			reverse(b[i].begin(),b[i].end());
		}
		ans=a[0].size();
		while(ans>0)
		{
			for(l=0;l+ans-1<a[0].size();l++)
			{
				tmp=a[0].substr(l,ans);
				ok=1;
				for(i=1;i<n;i++)
				{
					if(a[i].find(tmp)==a[i].npos && b[i].find(tmp)==b[i].npos)
					{
						ok=0;
						break;
					}
				}
				if(ok) goto end;
			}
			ans--;
		}
		end:;
		printf("%d\n",ans);
	}
	return 0;
}
