#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
char s[MAX],t[12];
int sum[MAX];
int main()
{
	int q,i,j,l,r,n,m,ok;
	scanf("%d",&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	sum[0]=0;
	for(i=1;i+m-1<=n;i++)
	{
		ok=1;
		for(j=1;j<=m;j++)
		{
			if(s[i+j-1]!=t[j]) ok=0;
		}
		sum[i]=sum[i-1]+ok;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(r-l+1<m) puts("No");
		else if(sum[r-m+1]-sum[l-1]>0) puts("Yes");
		else puts("No");
	}
	return 0;
}
