#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n;
int cal(int pos)
{
	int i,l,r,cnt[2],ok;
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0) ok=0;
	}
	if(ok) return 0;
	l=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1) l=i;
		else break;
	}
	r=n+1;
	for(i=n;i;i--)
	{
		if(a[i]==1) r=i;
		else break;
	}
	cnt[0]=cnt[1]=0;
	for(i=min(l,pos)+1;i<=max(r,pos+1)-1;i++) cnt[a[i]]++;
	return cnt[1]*2+cnt[0];
}
int main()
{
	int pos,i,ans;
	scanf("%d%d",&n,&pos);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",cal(pos));
	return 0;
}
/*
5 3
1 0 1 1 1
*/
