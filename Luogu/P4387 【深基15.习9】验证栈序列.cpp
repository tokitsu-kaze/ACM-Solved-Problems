#include <bits/stdc++.h> 
using namespace std;
const int MAX=1e5+10;
int st[MAX],top;
int a[MAX],b[MAX];
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		top=0;
		j=1;
		for(i=1;i<=n;i++)
		{
			st[top++]=a[i];
			while(top&&st[top-1]==b[j])
			{
				j++;
				top--;
			}
		}
		if(top) puts("No");
		else puts("Yes");
	}
}
