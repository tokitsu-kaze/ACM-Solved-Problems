#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int vis[MAX],p[MAX];
int main()
{
	int T,n,l,r,s,len,i,j,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&l,&r,&s);
		for(i=1;i<=n;i++) vis[i]=0;
		len=r-l+1;
		now=(1+len)*len/2;
		if(now>s)
		{
			puts("-1");
			continue;
		}
		for(i=n;i;i--)
		{
			if(len==0) break;
			if(now-len+i<=s)
			{
				vis[i]=1;
				p[l+len-1]=i;
				now-=len;
				len--;
				s-=i;
			}
		}
		if(s>0)
		{
			puts("-1");
			continue;
		}
		j=1;
		for(i=1;i<=n;i++)
		{
			if(l<=i && i<=r) continue;
			while(j<=n && vis[j]) j++;
			p[i]=j;
			j++;
		}
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
