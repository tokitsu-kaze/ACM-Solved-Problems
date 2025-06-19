#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int op,x;};
int main()
{
	int T,n,a[44],b[44],i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			for(j=2;j<=n;j++)
			{
				if(a[j]<a[j-1])
				{
					swap(a[j],a[j-1]);
					res.push_back({1,j-1});
				}
				if(b[j]<b[j-1])
				{
					swap(b[j],b[j-1]);
					res.push_back({2,j-1});
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]>b[i])
			{
				swap(a[i],b[i]);
				res.push_back({3,i});
			}
		}
//		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
//		for(i=1;i<=n;i++) printf("%d%c",b[i]," \n"[i==n]);
		for(i=2;i<=n;i++) assert(a[i]>a[i-1] && b[i]>b[i-1] && a[i]<b[i]);
		printf("%d\n",res.size());
		for(auto &it:res) printf("%d %d\n",it.op,it.x);
	}
	return 0;
}
