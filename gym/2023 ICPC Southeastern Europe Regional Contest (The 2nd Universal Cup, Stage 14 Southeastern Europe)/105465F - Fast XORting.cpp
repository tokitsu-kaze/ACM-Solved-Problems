#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<18)+10;
int a[MAX],tmp[MAX];
ll cal(int l1,int r1,int l2,int r2)
{
	int i,j,tot;
	ll res=0;
	i=l1;
	j=l2;
	tot=0;
	while(i<=r1 && j<=r2)
	{
		// 2 3 5 , 1 6 7
		if(a[i]<a[j]) tmp[tot++]=a[i++];
		else
		{
			res+=r1-(i-1);
			tmp[tot++]=a[j++];
		}
	}
	while(i<=r1) tmp[tot++]=a[i++];
	while(j<=r2) tmp[tot++]=a[j++];
//	printf("%d %d %d %d %lld\n",l1,r1,l2,r2,res);
	return res;
}
int main()
{
	int n,i,j,k,bit,l,r,mid,x;
	ll ans,ra,rb;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[x]=i;
	}
	bit=0;
	while((1<<bit)<n) bit++;
	ans=0;
	x=0;
	for(i=0;i<bit;i++)
	{
		ra=rb=0;
		for(j=0;j<n;j+=(2<<i))
		{
			l=j;
			mid=l+(1<<i)-1;
			r=j+(2<<i)-1;
			ra+=cal(l,mid,mid+1,r);
			rb+=cal(mid+1,r,l,mid);
			for(k=l;k<=r;k++) a[k]=tmp[k-l];
		}
		if(rb<ra) x|=(1<<i);
		ans+=min(ra,rb);
	}
	if(x>0) ans++;
	printf("%lld\n",ans);
	return 0;
}
/*
xor最多一次。
第k位 xor 1 相当于每两块 2^k 子数组交换。
模拟归并排序过程，看交换优还是不交换优。 
*/
