#include <bits/stdc++.h>
using namespace std;
char s[5050];
int main()
{
	int n,i,x,y,rx,ry,t;
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&t);
	x=y=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='E') x++;
		else if(s[i]=='S') y--;
		else if(s[i]=='W') x--;
		else if(s[i]=='N') y++;
		else assert(0);
	}
	rx=x*(t/n);
	ry=y*(t/n);
	t-=t/n*n;
	x=y=0;
	for(i=1;i<=t;i++)
	{
		if(s[i]=='E') rx++;
		else if(s[i]=='S') ry--;
		else if(s[i]=='W') rx--;
		else if(s[i]=='N') ry++;
		else assert(0);
	}
	printf("%d %d\n",rx,ry);
	return 0;
}
