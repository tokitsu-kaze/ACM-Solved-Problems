#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[MAX],n;
char op[MAX][5];
int cal(int j,int x)
{
	for(int i=1;i<=n;i++)
	{
		if(op[i][0]=='A') x&=(a[i]>>j)&1;
		else if(op[i][0]=='O') x|=(a[i]>>j)&1;
		else x^=(a[i]>>j)&1;
	}
	return x;
}
int main()
{
	int m,i,j,ans,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s%d",op[i],&a[i]);
	ans=0;
	for(j=30;~j;j--)
	{
		if((ans|(1<<j))>m) continue;
		if(cal(j,1)==0) continue;
		if(cal(j,0)==1) continue;
		ans|=(1<<j);
	}
	for(i=1;i<=n;i++)
	{
		if(op[i][0]=='A') ans&=a[i];
		else if(op[i][0]=='O') ans|=a[i];
		else ans^=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
