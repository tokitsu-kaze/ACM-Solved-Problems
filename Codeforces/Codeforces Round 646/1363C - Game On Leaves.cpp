#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
vector<int> mp[MAX];
int main()
{
	int T,n,x,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		if(mp[x].size()<=1) puts("Ayush");
		else if((n-1)&1) puts("Ayush");
		else puts("Ashish");
	}
	return 0;
}
