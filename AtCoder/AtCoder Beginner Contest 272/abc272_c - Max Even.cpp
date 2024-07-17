#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int INF=2e9+1;
int main()
{
	int n,i,x,ans;
	vector<int> res[2];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		res[x&1].push_back(x);
	}
	sort(res[0].begin(),res[0].end());
	sort(res[1].begin(),res[1].end());
	reverse(res[0].begin(),res[0].end());
	reverse(res[1].begin(),res[1].end());
	ans=-INF;
	if(res[0].size()>1) ans=max(ans,res[0][0]+res[0][1]);
	if(res[1].size()>1) ans=max(ans,res[1][0]+res[1][1]);
	if(ans==-INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
