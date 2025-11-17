#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,a;
	double t;
	ll cnt,k,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%lld",&n,&k,&x);
		priority_queue<pair<double,ll>> q;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			q.push({a,1});
		}
		while(k>0)
		{
			t=q.top().first;
			cnt=q.top().second;
			q.pop();
			if(k>=cnt)
			{
				k-=cnt;
				q.push({t/2,cnt*2});
			}
			else
			{
				q.push({t/2,2*k});
				q.push({t,cnt-k});
				k=0;
			}
		}
		while(x>0)
		{
			t=q.top().first;
			cnt=q.top().second;
			q.pop();
			x-=cnt;
		}
		printf("%.10f\n",t);
	}
	return 0;
}

