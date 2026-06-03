#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll cal(int c,int d)
{
	if(1LL*c*d<0) return abs(d)/2+abs(c/2);
	else
	{
		if(c>=0) return d/2-(c-1)/2;
		else return abs(c)/2-(abs(d)-1)/2;
	}
}
ll work(int a,int b,int c,int d)
{
	int i,l,r;
	ll ans;
	ans=0;
	for(i=a;i<=b;i++)
	{
		ans+=cal(c,d);
		l=-abs(i);
		r=abs(i);
		l=max(l,c);
		r=min(r,d);
		if(l>r) continue;
		ans-=cal(l,r);
		if(i%2==0) ans+=r-l+1;
//		printf("%d %lld\n",i,ans);
	}
	return ans;
}

ll bf(int a,int b,int c,int d)
{
	int x,y;
	ll ans=0;
	for(x=a;x<=b;x++)
	{
		for(y=c;y<=d;y++)
		{
			if(max(abs(x),abs(y))%2==0) ans++;
		}
	}
	return ans;
}
mt19937 rd(time(0));
void bfck()
{
	int a,b,c,d;
	while(1)
	{
		a=rd()%10-5;
		b=rd()%10-5;
		c=rd()%10-5;
		d=rd()%10-5;
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(bf(a,b,c,d)!=work(a,b,c,d))
		{
			printf("%d %d %d %d\n",a,b,c,d);
			printf("%lld %lld\n",bf(a,b,c,d),work(a,b,c,d));
			exit(0);
		}
	}
}
int main()
{
	int a,b,c,d;
//	bfck();
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%lld\n",work(a,b,c,d));
	return 0;
}
/*
-2 1 3 4
4
*/
