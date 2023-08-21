#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int T,n,m;
long long a[MAXN],ans;
struct node
{
	long long val;
	int type;
}b[MAXN];
bool cmp(const node &A,const node &B)
{
	if(A.val!=B.val)
	return A.val<B.val;
	return A.type>B.type;
}
long long greed1()
{
	int p1=1;
	long long atked=0,nowsum=0;
	bool flag=true;
	for(int i=1;i<=m;++i)
	{
		while(p1<=n&&a[p1]<b[i].val)
		{
			atked+=a[p1++];
		}
		if(p1>n)
		{
			flag=false;
			break;
		}
		if(b[i].type==0)
		{
			nowsum+=a[p1++]-b[i].val;
		}
		else
		{
			++p1;
		}
	}
	if(flag)
	{
		for(int i=p1;i<=n;++i)
		{
			atked+=a[i];
		}
		return nowsum+atked;
	}
	else
	{
		return nowsum;
	}
}
long long greed2()
{
	long long temp=0;
	int p1=1;
	for(int i=n;i;--i)
	{
		while(p1<=m&&b[p1].type==1)++p1;
		if(p1<=m)
		{
			if(a[i]>b[p1].val)
			{
				temp+=a[i]-b[p1].val;
			}
			++p1;
		}
	}
	return temp;
}
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		printf("Case %d: ",cas);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%lld",&b[i].val);
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&b[i].type);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+m,cmp);
		int p=1;
		ans=0;
		ans=max(ans,greed1());
		ans=max(ans,greed2());
		printf("%lld\n",ans);
	}
	return 0;
}

