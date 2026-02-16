#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int N=1000+10;
const int M=5e4+10;
ll pre[N][M],suf[N][M];
int p[N],v[N];
char ans[N];
int main()
{
	int n,m,i,j;
	ll ra,rb,mx;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&p[i],&v[i]);
	memset(pre,0,sizeof pre);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			pre[i][j]=pre[i-1][j];
			if(j-p[i]>=0) pre[i][j]=max(pre[i][j],pre[i-1][j-p[i]]+v[i]);
		}
	}
	memset(suf,0,sizeof suf);
	for(i=n;i;i--)
	{
		for(j=0;j<=m;j++)
		{
			suf[i][j]=suf[i+1][j];
			if(j-p[i]>=0) suf[i][j]=max(suf[i][j],suf[i+1][j-p[i]]+v[i]);
		}
	}
	mx=pre[n][m];
	for(i=1;i<=n;i++)
	{
		ra=max(pre[i-1][m],suf[i+1][m]);
		rb=v[i];
		for(j=0;j<=m;j++)
		{
			if((i==1||pre[i-1][j]) && (i==n||suf[i+1][m-j])) ra=max(ra,pre[i-1][j]+suf[i+1][m-j]);
			if(j-p[i]>=0) rb=max(rb,pre[i-1][j-p[i]]+suf[i+1][m-j]+v[i]);
			if(m-j-p[i]>=0) rb=max(rb,pre[i-1][j]+suf[i+1][m-j-p[i]]+v[i]);
		}
		if(ra==mx && rb==mx) ans[i]='B';
		else if(ra!=mx && rb!=mx) ans[i]='B';
		else if(ra==mx) ans[i]='C';
		else ans[i]='A';
//		printf("%d %lld %lld\n",i,ra,rb);
	}
	ans[n+1]='\0';
	puts(ans+1);
	return 0;
}
