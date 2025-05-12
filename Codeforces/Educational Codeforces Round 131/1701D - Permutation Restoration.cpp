#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node{int l,r,p;};
int res[MAX],a[MAX],ans[MAX];
void gen(int n)
{
	int i;
	for(i=1;i<=n;i++) ans[i]=i;
	random_shuffle(ans+1,ans+1+n);
	for(i=1;i<=n;i++) a[i]=i/ans[i];
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	puts("");
}
void ck(int n)
{
	int i;
	for(i=1;i<=n;i++) assert(i/res[i]==a[i]);
}
int main()
{
	int T,n,i,x,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
//		n=20;
//		gen(n);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			s.insert(i);
			res[i]=0;
		}
		vector<node> tmp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0) continue;
			l=i/(a[i]+1)+1;
			r=i/a[i];
			tmp.push_back({l,r,i});
		}
		sort(tmp.begin(),tmp.end(),[](node x,node y){
			return x.r<y.r;
		});
		for(auto &it:tmp)
		{
			res[it.p]=*s.lower_bound(it.l);
			s.erase(res[it.p]);
		}
		for(i=1;i<=n;i++)
		{
			if(res[i]==0)
			{
				res[i]=*s.begin();
				s.erase(s.begin());
			}
		}
		ck(n);
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
2
10
0 0 1 0 2 1 1 2 1 10
20
0 0 0 0 1 0 0 0 0 3 5 2 3 1 1 16 1 1 1 1
*/
