#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,m,k,w,i,j;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		vector<vector<int>> bit(n+2,vector<int>(m+2,0));
		for(i=k;i<=n;i++)
		{
			for(j=k;j<=m;j++)
			{
				bit[i-k+1][j-k+1]++;
				bit[i+1][j-k+1]--;
				bit[i-k+1][j+1]--;
				bit[i+1][j+1]++;
			}
		}
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				bit[i][j]+=bit[i-1][j]+bit[i][j-1]-bit[i-1][j-1];
				res.push_back(bit[i][j]);
			}
		}
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		scanf("%d",&w);
		for(i=1;i<=w;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+w);
		reverse(a+1,a+1+w);
		ans=0;
		for(i=1,j=0;i<=w && j<res.size();i++,j++) ans+=1LL*a[i]*res[j];
		printf("%lld\n",ans);
	}
	return 0;
}
