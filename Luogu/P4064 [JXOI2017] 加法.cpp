#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> posr[MAX];
int n,x,k;
int a[MAX],bit[MAX];
int ck(int tar)
{
	int i,r,cnt;
	for(i=0;i<=n;i++) bit[i]=0;
	priority_queue<int> q;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		for(auto &it:posr[i]) q.push(it);
		bit[i]+=bit[i-1];
		while(bit[i]+a[i]<tar && !q.empty())
		{
			r=q.top();
			q.pop();
			if(r<i) continue;
			bit[i]+=x;
			bit[r+1]-=x;
			cnt++;
		}
		if(bit[i]+a[i]<tar) return 0;
	}
	return cnt<=k;
}
int main()
{
	int t,m,i,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&x);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			posr[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&l,&r);
			posr[l].push_back(r);
		}
		l=0;
		r=2e8;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}

