#include <bits/stdc++.h>
using namespace std;
int n;
char s[1111],res[2049];
char cal(char x,char y)
{
	if(x==y) return x;
	return 'F';
}
void dfs(int x,int h)
{
	if(h==n)
	{
		res[x]=(s[x-(1<<n)]=='1'?'I':'B');
		putchar(res[x]);
		return;
	}
	dfs(x*2,h+1);
	dfs(x*2+1,h+1);
	res[x]=cal(res[x*2],res[x*2+1]);
	putchar(res[x]);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	dfs(1,0);
	puts("");
//	puts(res+1);
	return 0;
}
