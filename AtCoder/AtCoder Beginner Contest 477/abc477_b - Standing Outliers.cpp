#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,d,a[105],i,j,ok;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		ok=1;
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(abs(a[i]-a[j])<d) ok=0;
		}
		if(ok) res.push_back(i);
	}
	printf("%d\n",(int)res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
