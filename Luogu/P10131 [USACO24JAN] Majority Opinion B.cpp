#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],res[MAX],tot;
int main()
{
	int t,n,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>=2&&a[i]==a[i-1]) s.insert(a[i]);
			if(i>=3&&a[i]==a[i-2]) s.insert(a[i]);
			if(i>=3&&a[i-1]==a[i-2]) s.insert(a[i-1]);
		}
		if(!s.size())
		{
			puts("-1");
			continue;
		}
		tot=0;
		for(auto &it:s) res[++tot]=it;
		for(i=1;i<=tot;i++) printf("%d%c",res[i]," \n"[i==tot]);
	}
	return 0;
}
