#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,r,d,cntr,cntd;
	char a[MAX],temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,a);
		queue<char> q;
		r=d=0;
		for(i=0;i<n;i++)
		{
			if(a[i]=='R') r++;
			else if(a[i]=='D') d++;
			q.push(a[i]);
		}
		cntr=cntd=0;
		while(sz(q)&&r&&d)
		{
			temp=q.front();
			q.pop();
			if(temp=='D')
			{
				if(cntr)
				{
					cntr--;
					d--;
				}
				else
				{
					cntd++;
					q.push(temp);
				}
			}
			else
			{
				if(cntd)
				{
					cntd--;
					r--;
				}
				else
				{
					cntr++;
					q.push(temp);
				}
			}
		}
		if(r) puts("R");
		else if(d) puts("D");
	}
	return 0;
} 