#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2000+10;
struct node{int l,r;};
int l[MAX],r[MAX];
int main()
{
	int T,n,i,j,nl,nr,cnt,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				nl=max(l[i],l[j]);
				nr=min(r[i],r[j]);
				if(nl<=nr) res.push_back({min(l[i],l[j]),max(r[i],r[j])});
			}
		}
		sort(res.begin(),res.end(),[](node x,node y){
			return x.r<y.r;
		});
		now=-1;
		cnt=0;
		for(auto &it:res)
		{
			if(it.l>now)
			{
				cnt++;
				now=max(now,it.r);
			}
		}
		printf("%d\n",n-cnt*2);
	}
	return 0;
}
