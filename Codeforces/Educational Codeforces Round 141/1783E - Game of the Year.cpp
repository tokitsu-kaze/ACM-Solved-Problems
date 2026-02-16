#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int tag[MAX],a[MAX],b[MAX];
int main()
{
	int T,n,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=0;i<=n;i++) tag[i]=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<=b[i]) continue;
			tag[b[i]]++;
			tag[a[i]]--;
		}
		for(i=1;i<=n;i++) tag[i]+=tag[i-1];
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			ok=1;
			for(j=i;j<=n;j+=i)
			{
				if(tag[j]) ok=0;
			}
			if(ok) res.push_back(i);
		}
		printf("%d\n",(int)res.size());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
