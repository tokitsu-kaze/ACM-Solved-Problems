#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[55][55];
int dir[4][2]={1,0,0,-1,-1,0,0,1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,m,k,sx,sy,i,j,d;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>sx>>sy;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		d=0;
		k--;
		while(k--)
		{
			if(sx<1||sx>n||sy<1||sy>m) break;
			if(mp[sx][sy]>10) d=(d+1)%4;
			sx+=dir[d][0];
			sy+=dir[d][1];
		}
		if(sx<1||sx>n||sy<1||sy>m) cout<<"Lost in the dark"<<"\n";
		else cout<<sx<<" "<<sy<<"\n";
	}
	return 0;
}
