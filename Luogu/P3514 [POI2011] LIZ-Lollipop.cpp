#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
char s[MAX];
int a[MAX],n,bit[MAX],ansl,ansr;
int ck(int ql,int qr,int x,int f)
{
	if(ql<1||qr>n||ql>qr) return 0;
	int l,r,mid;
	l=ql;
	r=qr;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(f==0)
		{
			if(bit[mid+1]-bit[ql-1]<=x) l=mid+1;
			else r=mid;
		}
		else
		{
			if(bit[qr]-bit[mid]>=x) l=mid+1;
			else r=mid;
		}
	}
	if(f==0)
	{
		ansl=ql;
		ansr=l;
		return bit[l]-bit[ql-1]==x;
	}
	else
	{
		ansl=l;
		ansr=qr;
		return bit[qr]-bit[l-1]==x;
	}
}
int main()
{
	int t,q,i,op,x,y,mx[3],mn[3],ok;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	bit[0]=0;
	memset(mx,0,sizeof mx);
	memset(mn,0x3f,sizeof mn);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='T') a[i]=2;
		else a[i]=1;
		bit[i]=bit[i-1]+a[i];
		mx[a[i]]=max(mx[a[i]],i);
		mn[a[i]]=min(mn[a[i]],i);
	}
	while(q--)
	{
		scanf("%d",&x);
		ok=0;
		for(i=1;i<=2;i++)
		{
			if(ck(mn[i],n,x,0)||
		  	   ck(1+mn[i],n,x,0)||
		       ck(1,mx[i],x,1)||
			   ck(1,-1+mx[i],x,1))
			{
				ok=1;
				break;
			}
		}
		if(ok) printf("%d %d\n",ansl,ansr);
		else puts("NIE");
	}
	return 0;
}


