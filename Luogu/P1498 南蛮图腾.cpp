#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2048+10;
char mp[MAX/2][MAX];
void dfs(int x,int y,int len)
{
	if(len==1) return;
	int i,j,k;
	for(i=x,j=y,k=0;k<len;i--,j++,k++) mp[i][j]='/';
	for(i++,k=0;k<len;i++,j++,k++) mp[i][j]='\\';
	for(i=x,j=y+1,k=0;k<len/2;j+=4,k++) mp[i][j]=mp[i][j+1]='_';
	dfs(x,y,len/2);
	dfs(x-len/2,y+len/2,len/2);
	dfs(x,y+len,len/2);
}
int main()
{
	int n,m,i,j;
	scanf("%d",&n);
	memset(mp,' ',sizeof mp);
	dfs((1<<n)-1,0,1<<n);
	m=(1<<n)-1+2;
	for(i=0;i<(1<<n);i++)
	{
		mp[i][m]='\0';
		puts(mp[i]);
		m++;
	}
	return 0;
}

