#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,i,cnt,d,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> a;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==0) cnt++;
			else a.push_back(x);
		}
		while(a.size()>1)
		{
			sort(a.begin(),a.end());
			vector<int> tmp;
			if(cnt>0)
			{
				tmp.push_back(a[0]);
				cnt--;
			}
			for(i=1;i<a.size();i++)
			{
				d=a[i]-a[i-1];
				if(d==0) cnt++;
				else tmp.push_back(d);
			}
			swap(a,tmp);
		}
		if(a.size()==0) puts("0");
		else printf("%d\n",a[0]);
	}
	return 0;
}
