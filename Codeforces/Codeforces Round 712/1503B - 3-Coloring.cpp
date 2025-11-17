#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,j,ban,x,y;
	cin>>n;
	vector<pair<int,int>> pos[2];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			pos[(i+j)&1].push_back({i,j});
		}
	}
	for(i=1;i<=n*n;i++)
	{
		cin>>ban;
		if(pos[1].size()==0)
		{
			x=pos[0].back().first;
			y=pos[0].back().second;
			pos[0].pop_back();
			if(ban!=2) cout<<2<<" "<<x<<" "<<y<<endl;
			else cout<<3<<" "<<x<<" "<<y<<endl;
		}
		else if(pos[0].size()==0)
		{
			x=pos[1].back().first;
			y=pos[1].back().second;
			pos[1].pop_back();
			if(ban!=1) cout<<1<<" "<<x<<" "<<y<<endl;
			else cout<<3<<" "<<x<<" "<<y<<endl;
		}
		else
		{
			if(ban!=1)
			{
				x=pos[1].back().first;
				y=pos[1].back().second;
				pos[1].pop_back();
				cout<<1<<" "<<x<<" "<<y<<endl;
			}
			else if(ban!=2)
			{
				x=pos[0].back().first;
				y=pos[0].back().second;
				pos[0].pop_back();
				cout<<2<<" "<<x<<" "<<y<<endl;
			}
		}
	}
	return 0;
}
