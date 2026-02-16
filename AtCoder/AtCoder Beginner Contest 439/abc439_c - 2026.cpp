#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
int cnt[MAX];
int main()
{
	int n,x,y,i;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(x=1;x*x<=n;x++)
	{
		for(y=x+1;x*x+y*y<=n;y++)
		{
			cnt[x*x+y*y]++;
		}
	}
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(cnt[i]==1) res.push_back(i);
	}
	printf("%d\n",(int)res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
