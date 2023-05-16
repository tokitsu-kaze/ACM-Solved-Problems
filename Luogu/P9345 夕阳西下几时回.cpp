#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
bool vis[MAX];
int main()
{
	int t,n,k,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) vis[i]=0;
		vector<int> res;
		k--;
		for(i=2;i*2<=n;i++)
		{
			if(k==0) break;
			if(vis[i]) continue;
			res.push_back(i);
			vis[i]=1;
			for(j=i*2;j<=n;j*=2)
			{
				if(k==0) break;
				if(vis[j]) break;
				res.push_back(j);
				vis[j]=1;
				k--;
			}
		}
		if(k)
		{
			puts("No");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) res.push_back(i);
		}
		puts("Yes");
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	}
	return 0;
}
