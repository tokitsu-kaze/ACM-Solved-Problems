#include <bits/stdc++.h>
using namespace std;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int MAX=1e7+10;
short mp[4001][4001];
char a[4001],b[4001];
short n,m,k;
bool ck(short x)
{
	int i,j;
	if(x<=k) return 1;
	for(i=1;i<=n-x+1;i++)
	{
		for(j=1;j<=m-x+1;j++)
		{
			if(x-(mp[i+x-1][j+x-1]-mp[i-1][j-1])<=k) return 1;
		}
	}
	return 0;
}
void go()
{
	short t,i,j,x,y,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		for(i=0;i<=n;i++) mp[i][0]=0;
		for(i=0;i<=m;i++) mp[0][i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				mp[i][j]=(a[i]==b[j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			x=i;
			y=1;
			while(x<=n&&y<=m)
			{
				mp[x][y]+=mp[x-1][y-1];
				x++;
				y++;
			}
		}
		for(i=2;i<=m;i++)
		{
			x=1;
			y=i;
			while(x<=n&&y<=m)
			{
				mp[x][y]+=mp[x-1][y-1];
				x++;
				y++;
			}
		}
		l=0;
		r=min(n,m);
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
}
