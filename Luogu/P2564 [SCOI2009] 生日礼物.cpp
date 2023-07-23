#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct node{int pos,col;};
int cnt[MAX];
int main()
{
	int n,k,i,j,m,x,now,ans;
	scanf("%d%d",&n,&k);
	vector<node> res;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			res.push_back({x,i});
		}
	}
	sort(res.begin(),res.end(),[&](node a,node b){
		return a.pos<b.pos;
	});
	assert(res.size()==n);
	ans=INT_MAX;
	now=0;
	for(i=0,j=0;i<n;i++)
	{
		while(j<n&&now<k)
		{
			cnt[res[j].col]++;
			if(cnt[res[j].col]==1) now++;
			j++;
		}
		if(now==k) ans=min(ans,res[j-1].pos-res[i].pos);
		cnt[res[i].col]--;
		if(cnt[res[i].col]==0) now--;
	}
	printf("%d\n",ans);
	return 0;
}
