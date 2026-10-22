#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char s[MAX][MAX];
int sqr(int x){return x*x;}
int main()
{
	int n,r,c,i,j;
	scanf("%d%d",&n,&r);
	c=(n+1)/2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(sqr(i-c)+sqr(j-c)<=sqr(r)) s[i][j]='#';
			else s[i][j]='.';
		}
		s[i][n+1]='\0';
		puts(s[i]+1);
	}
	return 0;
}
