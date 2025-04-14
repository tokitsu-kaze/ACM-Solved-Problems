#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
void gen()
{
	srand(time(0));
	freopen("cc.in","w",stdout);
	int T,n,m,i;
	T=1000;
	printf("%d\n",T);
	while(T--)
	{
		n=20;
		m=6;
		printf("%d %d\n",n,m);
		for(i=1;i<=n;i++) printf("%d%c",rand()%m+1," \n"[i==n]);
		for(i=1;i<=m;i++) printf("%d%c",rand()%m+1," \n"[i==m]);
	}
}
const int K=101;
int nex[MAX][K];
void work(int *s,int len)
{
	for(int i=0;i<K;i++) nex[len][i]=nex[len+1][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<K;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]]=i;
	}
}
int a[MAX],b[105];
int mxlen[MAX];
int main()
{
//	freopen("cc.in","r",stdin);
//	freopen("ccans.txt","w",stdout);
	int T,n,m,i,j,now,alleq,beq;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
//		printf("%d %d\n",n,m);
//		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
//		for(i=1;i<=m;i++) printf("%d%c",b[i]," \n"[i==m]);
		mxlen[n]=1;
		for(i=n-1;i;i--)
		{
			if(a[i]==a[i+1]) mxlen[i]=mxlen[i+1]+1;
			else mxlen[i]=1;
		}
		alleq=1;
		for(i=2;i<=m;i++)
		{
			if(b[i]!=b[1]) alleq=0;
		}
		work(a,n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[1]) continue;
			if(alleq && mxlen[i]>m)
			{
				ans++;
				continue;
			}
			now=i;
			beq=1;
			for(j=2;j<=m;j++)
			{
				if(now<n && a[now+1]==b[j]) now++;
				else if(now<n && a[now+1]==a[now] && a[now+1]!=b[j])
				{
					if(j==2 || (beq && j-1==now-i+1)) now=n+1;
					else now+=mxlen[now]-1;
					now=nex[now][b[j]];
				}
				else now=nex[now][b[j]];
				if(b[j]!=b[j-1]) beq=0;
//				cout<<"*** "<<j<<" "<<now<<endl;
			}
			if(now<=n) ans+=n-now+1;
//			cout<<i<<" "<<now<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
25 8
4 1 4 3 1 1 1 4 4 5 3 4 1 3 4 1 2 1 4 1 4 5 2 1 4
1 1 1 5 1 4 1 2

18

2
20 6
5 6 5 6 5 6 6 6 1 6 3 1 5 1 4 5 2 2 2 1
1 1 1 2 2 1
20 6
5 3 3 3 1 6 6 3 5 5 1 1 6 4 5 1 3 5 3 4
5 5 1 6 3 3

1
4


7
10 3
3 3 2 2 3 2 1 1 2 3
3 3 2
10 3
3 2 3 2 1 1 1 1 3 1
1 1 3
10 3
3 2 1 3 3 2 3 2 2 3
3 2 3
10 3
2 1 2 2 3 1 1 1 3 2
2 1 1
10 3
3 1 2 1 2 2 3 1 3 1
2 2 1
10 3
2 1 3 1 2 2 2 2 2 2
1 2 2
10 3
2 1 1 1 1 3 2 3 2 2
1 1 1

13
2
12
9
6
10
7
*/
