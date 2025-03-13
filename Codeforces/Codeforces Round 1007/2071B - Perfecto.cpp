#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=5e5+10;
int p[MAX];
int main()
{
	srand(time(0));
	int T,n,i,ok,f,limt;
	ll sum,sq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) p[i]=i;
		limt=50;
		ok=0;
		while(limt--)
		{
			random_shuffle(p+1,p+1+n);
			sum=sq=0;
			f=1;
			for(i=1;i<=n;i++)
			{
				sum+=p[i];
				while(sq*sq<sum) sq++;
				if(sq*sq==sum)
				{
					f=0;
					break;
				}
			}
			if(f)
			{
				ok=1;
				break;
			}
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}

