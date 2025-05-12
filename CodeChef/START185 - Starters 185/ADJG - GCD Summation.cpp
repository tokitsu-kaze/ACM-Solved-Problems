#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,x,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n>k+1)
		{
			puts("-1");
			continue;
		}
		vector<int> res;
		x=k-(n-2);
		res.push_back(x);
		res.push_back(2*x);
		now=2*x;
		while(res.size()<n) res.push_back(++now);
		reverse(res.begin(),res.end());
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}
