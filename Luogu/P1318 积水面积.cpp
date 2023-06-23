#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int st[MAX],a[MAX];
int main()
{
	int n,i,x,top,ans;
	scanf("%d",&n);
	top=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(top&&a[i]>a[st[top-1]])
		{
			if(top>1)
			{
				ans+=(i-st[top-2]-1)*
				  (min(a[st[top-2]],a[i])-a[st[top-1]]);
			}
			top--;
		}
		st[top++]=i;
//		printf("%d %d\n",i,ans);
	}
	printf("%d\n",ans);
	return 0;
}
