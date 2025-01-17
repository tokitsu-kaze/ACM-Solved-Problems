#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int a[MAX],res[MAX];
void bf(int n,int m)
{
	int i,j,k;
	res[1]=a[1];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			int ok=1;
			for(k=1;k<i;k++)
			{
				if(res[__gcd(i,k)]==__gcd(a[j],res[k]))
				{
					ok=0;
					break;
				}
			}
			if(ok)
			{
				res[i]=a[j];
				break;
			}
		}
	}
	for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
}
int main()
{
	init_prime(MAX-10);
	int T,n,m,i,x,cnt,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+m);
		reverse(a+1,a+1+m);
//		bf(n,m);
		res[1]=a[1];
		for(i=2;i<=n;i++)
		{
			x=i;
			cnt=0;
			while(x>1)
			{
				tmp=prime[x];
				while(x%tmp==0)
				{
					x/=tmp;
					cnt++;
				}
			}
			if(cnt+1>m)
			{
				puts("-1");
				goto end;
			}
			res[i]=a[cnt+1];
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		end:;
	}
	return 0;
}

