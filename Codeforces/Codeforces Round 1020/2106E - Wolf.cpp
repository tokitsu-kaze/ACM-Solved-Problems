#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],cntl,cntr,pos[MAX],tl,tr;
void dfs(int l,int r,int k)
{
	if(l>r) return;
	int mid=(l+r)>>1;
//	cout<<mid<<" "<<p[mid]<<endl;
	if(p[mid]==k) return;
	if(pos[k]<mid)
	{
		if(p[mid]<k) cntr++;
		else tr--;
		dfs(l,mid-1,k);
	}
	else
	{
		if(p[mid]>k) cntl++;
		else tl--;
		dfs(mid+1,r,k);
	}
}
int main()
{
	int T,n,q,i,l,r,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		vector<int> res;
		for(i=0;i<q;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			if(pos[k]<l||pos[k]>r)
			{
				res.push_back(-1);
				continue;
			}
			cntl=cntr=0;
			tl=k-1;
			tr=n-k;
			dfs(l,r,k);
			if(cntl<=tl && cntr<=tr) res.push_back(cntl+cntr+abs(cntl-cntr));
			else res.push_back(-1);
		}
		for(i=0;i<q;i++) printf("%d%c",res[i]," \n"[i+1==q]);
	}
	return 0;
}
