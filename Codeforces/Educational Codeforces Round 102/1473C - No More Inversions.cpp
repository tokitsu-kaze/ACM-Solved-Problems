#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,k,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		vector<int> res;
		for(i=1;i<2*k-n;i++) res.push_back(i);
		now=k;
		for(i=2*k-n;i<=k;i++) res.push_back(now--);
		for(i=0;i<k;i++) printf("%d%c",res[i]," \n"[i+1==k]);
	}
	return 0;
}
