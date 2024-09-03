#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int n,i,x,ans,pre[333];
	char op[2];
	memset(pre,0,sizeof pre);
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%s",&x,op);
		if(pre[op[0]]) ans+=abs(x-pre[op[0]]);
		pre[op[0]]=x;
	}
	printf("%d\n",ans);
	return 0;
}
