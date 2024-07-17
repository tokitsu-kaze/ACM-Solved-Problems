#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int p[MAX],b[MAX];
int main()
{
	int t,n,i,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		set<int> s;
		for(i=1;i<=n;i++) s.insert(i);
		ok=1;
		for(i=1;i<=n/2;i++)
		{
			scanf("%d",&b[i]);
			if(!s.count(b[i])) ok=0;
			s.erase(b[i]);
			p[i*2]=b[i];
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		s.insert(0);
		for(i=n-1;i>=1;i-=2)
		{
			p[i]=*(--s.lower_bound(p[i+1]));
			if(p[i]==0)
			{
				ok=0;
				break;
			}
			s.erase(p[i]);
		}
		if(ok)
		{
			for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
		}
		else puts("-1");
	}
	return 0;
}
