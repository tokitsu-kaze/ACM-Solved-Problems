#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int res[MAX];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		res[1]=2;
		res[2]=1;
		res[3]=3;
		for(i=4;i<=n;i+=2)
		{
			if(i+1<=n)
			{
				res[i]=i+1;
				res[i+1]=i;
			}
			else res[i]=i;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}

