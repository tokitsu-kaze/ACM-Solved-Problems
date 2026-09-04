#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,vis[1010],x;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	while(m--)
	{
		scanf("%d",&x);
		vis[x]=1;
	}
	vector<int> res;
	for(i=0;i<n;i++)
	{
		if(!vis[i]) res.push_back(i);
	}
	if(res.size()==0) printf("%d\n",n);
	else
	{
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
	}
	return 0;
}
