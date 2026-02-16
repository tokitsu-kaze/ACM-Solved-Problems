#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int n,m;
char a[MAX][MAX],tmp[MAX][MAX];
void rotate90()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[i][j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[j][i]=tmp[n-i+1][j];
		}
	}
	swap(n,m);
}
int main()
{
	int i;
	n=4;
	m=7;
	for(i=1;i<=n;i++) scanf(" %[^\n]",a[i]+1);
	rotate90();
	rotate90();
	for(i=1;i<=n;i++)
	{
		a[i][m+1]='\0';
		puts(a[i]+1);
	}
	return 0;
}
