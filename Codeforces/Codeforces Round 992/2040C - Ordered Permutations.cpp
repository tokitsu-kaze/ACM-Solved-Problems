#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int res[MAX];
int main()
{
	int T,n,i,j,tmp;
	ll k,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		j=n;
		tmp=1;
		for(i=1;i<=j;i++)
		{
			if(i==j) now=0;
			else if(j-i-1>60) now=k+1;
			else now=(1LL<<(j-i-1));
			if(k>now)
			{
				k-=now;
				res[j]=tmp++;
				j--;
				i--;
			}
			else res[i]=tmp++;
		}
		if(k>1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
1 2 3 4 5

1 2 3 5 4
1 2 4 5 3
1 3 4 5 2

1 2 5 4 3
1 3 5 4 2
1 4 5 3 2

1 5 4 3 2

*/

