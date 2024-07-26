#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct node{int v,id;} a[MAX];
int l,d;
int ck(vector<int> res)
{
	int cnt=0;
	for(auto &it:res) cnt+=(it>=l);
	if(cnt>=2) return 0;
	return res[3]-res[0]>d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,pos,ok,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].v;
			a[i].id=i;
		}
		sort(a+1,a+1+n,[&](node x,node y){
			if(x.v==y.v) return x.id>y.id;
			return x.v<y.v;
		});
		for(i=1;i<=n;i++)
		{
			if(a[i].id==1) pos=i;
		}
		ok=0;
		if(pos<=3||pos==n) ok|=ck({a[1].v,a[2].v,a[3].v,a[n].v});
		else
		{
			ok|=ck({a[1].v,a[2].v,a[3].v,a[pos].v});
			ok|=ck({a[1].v,a[2].v,a[pos].v,a[n].v});
		}
		if(ok) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
