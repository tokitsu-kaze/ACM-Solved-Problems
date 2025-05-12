#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,i,x,sum,mn;
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum=0;
		mn=INF;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			sum+=x;
			if(x&1) mn=min(mn,x);
		}
		if(!(sum&1))
		{
			if(mn!=INF) sum-=mn;
			else sum=0;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
