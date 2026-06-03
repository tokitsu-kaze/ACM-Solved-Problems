#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int n,q,k,b[11],i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	multiset<int> s;
	for(i=1;i<=n;i++) s.insert(a[i]);
	while(q--)
	{
		scanf("%d",&k);
		for(i=1;i<=k;i++) scanf("%d",&b[i]);
		for(i=1;i<=k;i++) s.erase(s.find(a[b[i]]));
		printf("%d\n",*s.begin());
		for(i=1;i<=k;i++) s.insert(a[b[i]]);
	}
	return 0;
}
