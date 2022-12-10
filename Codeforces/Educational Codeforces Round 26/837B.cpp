#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,rx[3],ry[3],bx[3],by[3],gx[3],gy[3],flag[5],tag;
	char mp[111][111];
	while(~scanf("%d%d",&n,&m))
	{
		mem(rx,0);
		mem(ry,0);
		mem(bx,0);
		mem(by,0);
		mem(gx,0);
		mem(gy,0);
		mem(flag,0);
		rx[0]=ry[0]=bx[0]=by[0]=gx[0]=gy[0]=INF;
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='R')
				{
					flag[0]=1;
					rx[0]=min(rx[0],j);
					ry[0]=min(ry[0],i);
					rx[1]=max(rx[1],j);
					ry[1]=max(ry[1],i);
				}
				else if(mp[i][j]=='B')
				{
					flag[1]=1;
					bx[0]=min(bx[0],j);
					by[0]=min(by[0],i);
					bx[1]=max(bx[1],j);
					by[1]=max(by[1],i);
				}
				else if(mp[i][j]=='G')
				{
					flag[2]=1;
					gx[0]=min(gx[0],j);
					gy[0]=min(gy[0],i);
					gx[1]=max(gx[1],j);
					gy[1]=max(gy[1],i);
				}
			}
		}
		if(flag[0]&&flag[1]&&flag[2])
		{
			if(rx[1]-rx[0]==bx[1]-bx[0]&&rx[1]-rx[0]==gx[1]-gx[0])
			{
				if(ry[1]-ry[0]==by[1]-by[0]&&ry[1]-ry[0]==gy[1]-gy[0])
				{
					tag=0;
					for(i=ry[0];i<=ry[1];i++)
					{
						for(j=rx[0];j<=rx[1];j++)
						{
							if(mp[i][j]!='R') tag=1;
						}
					}
					for(i=by[0];i<=by[1];i++)
					{
						for(j=bx[0];j<=bx[1];j++)
						{
							if(mp[i][j]!='B') tag=1;
						}
					}
					for(i=gy[0];i<=gy[1];i++)
					{
						for(j=gx[0];j<=gx[1];j++)
						{
							if(mp[i][j]!='G') tag=1;
						}
					}
					if(!tag) puts("YES");
					else puts("NO");
				}
				else puts("NO");
			}
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}