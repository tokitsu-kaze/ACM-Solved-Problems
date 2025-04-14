#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ok,p;
	scanf("%d",&T);
	while(T--)
	{
		vector<pair<int,int>> res;
		scanf("%d",&n);
		ok=1;
		p=n-2;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i<=n-2 && a[i]==0) ok=0;
		}
		if(a[n-1]==0 || a[n]==0)
		{
			res.push_back({n-1,n});
			n--;
		}
		if(ok==0)
		{
			res.push_back({1,p});
			n-=p-1;
			res.push_back({1,n});
		}
		else res.push_back({1,n});
		printf("%d\n",res.size());
		for(auto &it:res) printf("%d %d\n",it.first,it.second);
	}
	return 0;
}

