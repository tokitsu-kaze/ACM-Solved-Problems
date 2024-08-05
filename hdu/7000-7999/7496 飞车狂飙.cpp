#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
char s[MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n,i,d,x,y,ok,px,py;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		map<pair<int,int>,int> mp;
		d=0;
		x=y=0;
		mp[{x,y}]=1;
		ok=1;
		for(i=0;i<n;i++)
		{
			if(s[i]=='L') d--;
			else if(s[i]=='R') d++;
			if(d==-1) d=3;
			if(d==4) d=0;
			px=x;
			py=y;
			x+=dir[d][0];
			y+=dir[d][1];
			if(i==n-1) break;
			if(mp.count({x,y})) ok=0;
			mp[{x,y}]=1;
		}
		if(!ok) cout<<"-1\n";
		else if(!(x==0&&y==0)) cout<<"0\n";
		else if(!(px==0&&py==-1)) cout<<"0\n";
		else cout<<"1\n";
	}
	return 0;
}

