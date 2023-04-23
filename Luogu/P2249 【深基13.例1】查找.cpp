#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int a[MAX];
int main()
{
	int n,m,i,pos,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		pos=lower_bound(a+1,a+1+n,x)-a;
		if(a[pos]!=x) pos=-1;
		printf("%d%c",pos," \n"[i==m]);
	}
	return 0;
}
