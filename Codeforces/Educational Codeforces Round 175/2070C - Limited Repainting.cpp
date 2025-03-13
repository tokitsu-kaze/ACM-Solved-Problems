#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char col[MAX];
int a[MAX],n,k;
int ck(int x)
{
	int i,cnt;
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(a[i]>x) res.push_back(i);
	}
	if(res.size()==0) return 1;
	if(col[res[0]]=='B') cnt=1;
	else cnt=0;
	for(i=1;i<res.size();i++)
	{
		if(col[res[i]]!=col[res[i-1]])
		{
			if(col[res[i]]=='B') cnt++;
		}
	}
	return cnt<=k;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",col+1);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
