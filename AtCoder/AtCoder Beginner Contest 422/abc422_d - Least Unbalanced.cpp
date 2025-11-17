#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int a[MAX];
void dfs(int l,int r,int cnt)
{
	if(l==r)
	{
		a[l]+=cnt;
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,cnt-cnt/2);
	dfs(mid+1,r,cnt/2);
}
int main()
{
	int n,k,i,j,cnt,tmp;
	scanf("%d%d",&n,&k);
	n=(1<<n);
	if(k%n==0)
	{
		puts("0");
		for(i=0;i<n;i++) printf("%d%c",k/n," \n"[i+1==n]);
		return 0;
	}
	tmp=k/n;
	cnt=k-tmp*n;
	for(i=0;i<n;i++) a[i]=tmp;
	dfs(0,n-1,cnt);
	puts("1");
	for(i=0;i<n;i++) printf("%d%c",a[i]," \n"[i+1==n]);
	return 0;
}
