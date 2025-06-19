#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX];
int main()
{
	int T,n,i,w,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&w);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		multiset<int> s;
		s.insert(0);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			auto it=s.upper_bound(w-a[i]);
			if(it!=s.begin())
			{
				it--;
				x=*it;
				s.erase(it);
				s.insert(x+a[i]);
			}
			else s.insert(a[i]);
		}
		printf("%d\n",s.size());
	}
	return 0;
}
