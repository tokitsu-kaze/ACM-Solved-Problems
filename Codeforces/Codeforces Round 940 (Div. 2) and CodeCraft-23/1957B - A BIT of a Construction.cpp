#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n==1)
		{
			printf("%d\n",k);
			continue;
		}
		vector<int> res;
		x=0;
		for(i=0;i<30;i++)
		{
			if((1<<i)-1<=k) x=(1<<i)-1;
		}
		res.push_back(x);
		k-=x;
		res.push_back(k);
		while(res.size()<n) res.push_back(0);
		for(i=1;i<=n;i++) printf("%d%c",res[i-1]," \n"[i==n]);
	}
	return 0;
}
