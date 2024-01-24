#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int bit[MAX];
int ck(int x)
{
	int i,res;
	cout<<"? "<<x;
	for(i=1;i<=x;i++) cout<<" "<<i;
	cout<<endl;
	cin>>res;
	if(res>bit[x]) return 1;
	return 0;
}
int main()
{
	int t,n,i,x,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			bit[i]=bit[i-1]+x;
		}
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		cout<<"! "<<l<<endl;
	}
	return 0;
}
