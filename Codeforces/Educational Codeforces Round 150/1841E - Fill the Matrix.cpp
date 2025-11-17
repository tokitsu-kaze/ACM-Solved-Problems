#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],st[MAX],top,l[MAX],r[MAX];
struct node{int cnt,len;};
int main()
{
	int T,n,i,cnt;
	ll m,ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=n-a[i];
		}
		scanf("%lld",&m);
		for(i=1;i<=n;i++) r[i]=n;
		top=0;
		for(i=1;i<=n;i++)
		{
			while(top && a[st[top-1]]>a[i])
			{
				r[st[top-1]]=i-1;
				top--;
			}
			st[top++]=i;
		}
		for(i=1;i<=n;i++) l[i]=1;
		top=0;
		for(i=n;i;i--)
		{
			while(top && a[st[top-1]]>a[i])
			{
				l[st[top-1]]=i+1;
				top--;
			}
			st[top++]=i;
		}
		vector<node> res;
		map<pair<int,int>,int> vis;
		a[0]=a[n+1]=0;
		for(i=1;i<=n;i++)
		{
//			cout<<l[i]<<" "<<r[i]<<endl;
			if(vis.count({l[i],r[i]})) continue;
			vis[{l[i],r[i]}]=1;
			cnt=a[i]-max(a[l[i]-1],a[r[i]+1]);
			res.push_back({cnt,r[i]-l[i]+1});
		}
		sort(res.begin(),res.end(),[](node x,node y){
			return x.len>y.len;
		});
		ans=0;
		for(auto &it:res)
		{
			tmp=min(1LL*it.cnt,m/it.len);
			ans+=(it.len-1)*tmp;
			m-=it.len*tmp;
			if(tmp<it.cnt)
			{
				ans+=max(0LL,m-1);
				m=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
