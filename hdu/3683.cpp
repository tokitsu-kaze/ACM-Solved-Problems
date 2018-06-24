////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 23:28:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3683
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-10;
const int MAX=5e4+10;
const ll mod=1e9+7;
int xx,yy;
int dir[4][2]={0,1,1,1,1,0,1,-1};
int mp[22][22];
int bfs(int v,int g)
{
	int i,j,k,x,y,sum,s=0;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(mp[i][j]==-1)
			{
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					sum=1;
					while(1)
					{
						if(x<0||x>=15||y<0||y>=15||mp[x][y]!=v) break;
						sum++;
						x+=dir[k][0];
						y+=dir[k][1];
					}
					x=i-dir[k][0];
					y=j-dir[k][1];
					while(1)
					{
						if(x<0||x>=15||y<0||y>=15||mp[x][y]!=v) break;
						sum++;
						x-=dir[k][0];
						y-=dir[k][1];
					}
					if(sum>=5)
					{
						s++;
						xx=i;
						yy=j;
						if(s>=g) return 1;
						break;
					}
				}
			}
		}
	}
	return 0;
}
int check(int v)
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			if(mp[i][j]==-1)
			{
				mp[i][j]=v;
				if(!bfs(v^1,1)&&bfs(v,2))
				{
					xx=i;
					yy=j;
					return 1;
				}
				mp[i][j]=-1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,n,x,y,d,w,b,tag;
	while(~scanf("%d",&n)&&n)
	{
		mem(mp,-1);
		w=b=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&d);
			mp[x][y]=d;
			if(d==0) w++;
			else b++;
		}
		if(w>b)
		{
			puts("Invalid.");
			continue;
		}
		if(w==b) tag=1;
		else tag=0;
		if(bfs(tag,1))
		{
			if(!tag) printf("Place white at (%d,%d) to win in 1 move.\n",xx,yy);
			else printf("Place black at (%d,%d) to win in 1 move.\n",xx,yy);
		}
		else if(bfs(tag^1,2)) puts("Lose in 2 moves.");
		else
		{
			if(check(tag))
			{
				if(!tag) printf("Place white at (%d,%d) to win in 3 moves.\n",xx,yy);
				else printf("Place black at (%d,%d) to win in 3 moves.\n",xx,yy);
			}
			else puts("Cannot win in 3 moves.");
		}
	}
	return 0;
}