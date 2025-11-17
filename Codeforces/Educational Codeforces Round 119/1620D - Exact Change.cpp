#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ck(int x,int a,int b)
{
	int tmp;
	tmp=min(b,x/2);
	x-=tmp*2;
	return x<=a;
}
int main()
{
	int T,n,i,v[105],tmp;
	ll a,b,c,ans,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		ans=LLINF;
		for(a=0;a<=2;a++)
		{
			for(b=0;b<=2;b++)
			{
				c=0;
				for(i=1;i<=n;i++)
				{
					tmp=v[i];
					mn=LLINF;
					if(ck(tmp%3,a,b)) mn=min(mn,tmp/3LL);
					tmp-=3;
					if(tmp>=0 && ck(tmp%3+3,a,b)) mn=min(mn,tmp/3LL);
					tmp-=3;
					if(tmp>=0 && ck(tmp%3+6,a,b)) mn=min(mn,tmp/3LL);
					c=max(c,mn);
				}
//				cout<<a<<" "<<b<<" "<<c<<endl;
				ans=min(ans,a+b+c);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

