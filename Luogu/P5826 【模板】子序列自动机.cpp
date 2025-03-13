#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Subsequence_Automaton
{
	const int rt=0;
	int n,VALMAX;
	vector<vector<int>> pos;
	void init(int _n,int *a)
	{
		int i;
		pos.clear();
		n=_n;
		VALMAX=0;
		for(i=1;i<=n;i++) VALMAX=max(VALMAX,a[i]);
		pos.resize(VALMAX+1);
		for(i=1;i<=n;i++) pos[a[i]].push_back(i);
	}
	int next(int now,int val)
	{
		if(val>VALMAX) return n+1;
		auto it=lower_bound(pos[val].begin(),pos[val].end(),now+1);
		if(it==pos[val].end()) return n+1;
		return *it;
	}
}seqam;
/*
seqam.init(n,a);  // a[1..n]
now=seqam.rt;
seqam.next(now,val);
*/
int a[MAX];
int main()
{
	int type,n,q,m,i,k,x,ok,now;
	scanf("%d%d%d%d",&type,&n,&q,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	seqam.init(n,a);
	while(q--)
	{
		scanf("%d",&k);
		now=seqam.rt;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&x);
			now=seqam.next(now,x);
		}
		if(now>n) puts("No");
		else puts("Yes");
	}
	return 0;
}
