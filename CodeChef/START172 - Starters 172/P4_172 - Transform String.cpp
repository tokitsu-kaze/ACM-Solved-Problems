#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int K=26;
int nex[MAX][26];
void work(char *s,int len)
{
	for(int i=0;i<K;i++) nex[len][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<26;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
char a[MAX],b[MAX];
int vis[MAX];
int main()
{
	int T,n,m,i,j,now,ok;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		reverse(a+1,a+1+n);
		reverse(b+1,b+1+m);
		work(a,n);
		for(i=1;i<=n;i++) vis[i]=0;
		ok=1;
		for(i=1,j=0;i<=m;i++)
		{
			j=nex[j][b[i]-'a'];
			if(j>n)
			{
				ok=0;
				break;
			}
			vis[j]=1;
		}
		if(ok==0)
		{
			puts("-1");
			continue;
		}
		reverse(vis+1,vis+1+n);
		ans=0;
		now=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) ans+=now;
			else now++;
//			cout<<i<<" "<<vis[i]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
