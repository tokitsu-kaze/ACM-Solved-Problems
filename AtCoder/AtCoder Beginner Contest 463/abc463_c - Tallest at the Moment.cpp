#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int h[MAX],l[MAX],id[MAX],qst[MAX],ans[MAX];
int main()
{
	int n,i,j,q;
	scanf("%d",&n);
	multiset<int> s;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&h[i],&l[i]);
		s.insert(h[i]);
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&qst[i]);
		id[i]=i;
	}
	sort(id+1,id+1+q,[](int x,int y){
		return qst[x]<qst[y];
	});
	for(i=1,j=1;i<=q;i++)
	{
		while(j<=n && l[j]<=qst[id[i]])
		{
			s.erase(s.find(h[j]));
			j++;
		}
		ans[id[i]]=*s.rbegin();
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
