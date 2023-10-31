#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int st[MAX],top;
int main()
{
	int n,i,ans,x;
	scanf("%d",&n);
	top=ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=x;
		if(x) st[top++]=x;
		else
		{
			ans-=st[top-1];
			top--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
