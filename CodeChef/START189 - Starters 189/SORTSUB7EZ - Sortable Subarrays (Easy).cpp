#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[55];
int ck(int l,int r)
{
	int i,j,ok;
	vector<int> res;
	res.push_back(0);
	for(i=l+1;i<=r;i++)
	{
		ok=0;
		for(j=res.back()+1;j<a[i];j++)
		{
			if(a[i]%(a[i]-j)==j)
			{
				ok=1;
				res.push_back(j);
				break;
			}
		}
		if(!ok)
		{
			if(a[i]<=res.back()) return 0;
			res.push_back(a[i]);
		}
	}
	return 1;
}
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				ans+=ck(i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

