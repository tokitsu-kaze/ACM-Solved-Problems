#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
double sq[MAX],ans[MAX];
void dfs(int l,int r,int x,int y)
{
	if(l>r) return;
	int i,pos,mid;
	mid=(l+r)>>1;
	pos=x;
	for(i=x;i<=min(y,mid-1);i++)
	{
		if(a[i]+sq[abs(mid-i)]>a[pos]+sq[abs(mid-pos)]) pos=i;
	}
	ans[mid]=max(ans[mid],a[pos]+sq[abs(mid-pos)]);
	dfs(l,mid-1,x,pos);
	dfs(mid+1,r,pos,y);
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	j=1;
	sq[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(j*j<i) j++;
		sq[i]=sqrt(i);
		ans[i]=0;
	}
	dfs(1,n,1,n);
	reverse(a+1,a+1+n);
	reverse(ans+1,ans+1+n);
	dfs(1,n,1,n);
	reverse(a+1,a+1+n);
	reverse(ans+1,ans+1+n);
	for(i=1;i<=n;i++) printf("%d\n",max(0,(int)ceil(ans[i]-a[i])));
	return 0;
}
