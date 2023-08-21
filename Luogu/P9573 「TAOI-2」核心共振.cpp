#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int flag[MAX];
int main()
{
	int t,i,a,b,n,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		vector<int> res;
		for(i=1;i<=p;i++)
		{
			if(i==2&&p>2*n) break;
			a=i;
			b=p-i;
			if(a>b) break;
			while(a<=n||b<=n)
			{
				if(a<=n) res.push_back(a);
				if(b<=n&&a!=b) res.push_back(b);
				a+=p;
				b+=p;
			}
		}
		for(i=1;i<=n;i++) flag[i]=0;
		for(auto &it:res) flag[it]=1;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) res.push_back(i);
		}
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
	}
	return 0;
}
