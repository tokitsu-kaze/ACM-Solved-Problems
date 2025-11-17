#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
int res[MAX];
int main()
{
	init_prime(MAX-10);
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) res[i]=0;
		res[1]=1;
		for(i=n;i>=2;i--)
		{
			if(prime[i]!=i) continue;
			vector<int> tmp;
			for(j=i;j<=n;j+=i)
			{
				if(res[j]) continue;
				tmp.push_back(j);
			}
			tmp.push_back(*tmp.begin());
			tmp.erase(tmp.begin());
			reverse(tmp.begin(),tmp.end());
			for(j=i;j<=n;j+=i)
			{
				if(res[j]) continue;
				res[j]=tmp.back();
				tmp.pop_back();
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
