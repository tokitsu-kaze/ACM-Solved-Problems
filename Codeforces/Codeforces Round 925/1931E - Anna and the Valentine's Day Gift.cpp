#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,m,now,x,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		vector<int> res;
		now=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt=0;
			while(x%10==0)
			{
				x/=10;
				cnt++;
			}
			if(cnt) res.push_back(cnt);
			while(x)
			{
				x/=10;
				now++;
			}
		}
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		for(i=1;i<res.size();i+=2) now+=res[i];
		if(now>m) puts("Sasha");
		else puts("Anna");
	}
	return 0;
}
