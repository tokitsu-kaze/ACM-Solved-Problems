#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char res[MAX][MAX];
int main()
{
	int n,i,j,a[MAX],id[MAX],cnt,ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[i]=i;
	}
	memset(res,'0',sizeof res);
	sort(id+1,id+1+n,[&](int x,int y){
		return a[x]>a[y];
	});
	for(j=1;j<=n;j++)
	{
		for(i=j;a[id[j]]>0;)
		{
			res[i][id[j]]='1';
			i++;
			a[id[j]]--;
			if(i==n+2) i=1;
		}
	}
	cnt=0;
	for(i=1;i<=n+1;i++)
	{
		ok=0;
		for(j=1;j<=n;j++)
		{
			if(res[i][j]=='1') ok=1;
		}
		if(ok) cnt++;
	}
	printf("%d\n",cnt);
	for(i=1;i<=n+1;i++)
	{
		ok=0;
		for(j=1;j<=n;j++)
		{
			if(res[i][j]=='1') ok=1;
		}
		res[i][n+1]='\0';
		if(ok) puts(res[i]+1);
	}
	return 0;
}
