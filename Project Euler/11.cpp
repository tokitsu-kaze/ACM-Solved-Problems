#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int mp[22][22],dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int main()
{
	int i,j,k,l,x,y;
	ll ans,now;
	mem(mp,0);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	ans=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<20;k++)
			{
				now=mp[j][k];
				x=j;
				y=k;
				for(l=0;l<3;l++)
				{
					x+=dir[i][0];
					y+=dir[i][1];
					if(x<0||y<0||x>=20||y>=20) continue;
					now*=mp[x][y]; 
				}
				ans=max(ans,now); 
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*

70600674

*/