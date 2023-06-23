#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int st[MAX],a[MAX];
int main()
{
	int n,i,r,top,ans;
	scanf("%d%d",&n,&r);
	top=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		a[i]=r%10;
		r=(r*6807LL+2831)%201701;
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
