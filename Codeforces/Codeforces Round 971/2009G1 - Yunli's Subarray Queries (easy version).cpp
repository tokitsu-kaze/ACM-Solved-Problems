#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
int cnt[MAX],a[MAX],ans[MAX];
int main()
{
	int T,n,k,q,i,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(i=0;i<=2*n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=a[i]-i+n;
		}
		multiset<int> s;
		for(i=1;i<=k-1;i++)
		{
			if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
			cnt[a[i]]++;
			s.insert(cnt[a[i]]);
		}
		for(i=k;i<=n;i++)
		{
			if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
			cnt[a[i]]++;
			s.insert(cnt[a[i]]);
			ans[i-k+1]=*s.rbegin();
			s.erase(s.find(cnt[a[i-k+1]]));
			cnt[a[i-k+1]]--;
			if(cnt[a[i-k+1]]) s.insert(cnt[a[i-k+1]]);
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",k-ans[l]);
		}
	}
	return 0;
}

