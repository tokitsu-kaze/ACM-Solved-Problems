#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int K=26;
int nex[MAX][K];
void work(char *s,int len)
{
	for(int i=0;i<K;i++) nex[len][i]=nex[len+1][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<K;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
char s[MAX],t[55];
int main()
{
	int n,m,i,j,now;
	ll ans;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	work(s,n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		now=i-1;
		for(j=1;j<=m;j++) now=nex[now][t[j]-'a'];
		ans+=now-i;
	}
	printf("%lld\n",ans);
	return 0;
}
