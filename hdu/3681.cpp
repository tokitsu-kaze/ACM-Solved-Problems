////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 14:24:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3681
////Problem Title: 
////Run result: Accept
////Run time:1856MS
////Run memory:32556KB
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int x,y,v,flag;
	node(){}
	node(int a,int b,int c,int d):x(a),y(b),v(c),flag(d){}
};
int n,m,tot,y,sx,sy,dir[4][2]={1,0,0,1,-1,0,0,-1};
char mp[22][22];
map<pair<int,int>,int> pos;
int flag[15][15][(1<<15)+1];
bool check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
bool bfs(int v)
{
	int i,j,k;
	node t,next;
	queue<node> q;
	q.push(node(sx,sy,v,0));
	mem(flag,0);
	flag[sx][sy][0]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
	//	cout<<t.x<<" "<<t.y<<" "<<(t.flag&((1<<y)-1))<<" "<<((1<<y)-1)<<endl;
		if((t.flag&((1<<y)-1))==((1<<y)-1)) return 1;
		if(t.v==0) continue;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			next.v--;
			if(check(next.x,next.y))
			{
				if(mp[next.x][next.y]=='D') continue;
				if(mp[next.x][next.y]=='Y')
				{
					int p=pos[MP(next.x,next.y)];
					if(next.flag&(1<<p));
					else next.flag|=(1<<p);
				}
				else if(mp[next.x][next.y]=='G')
				{
					int p=pos[MP(next.x,next.y)];
					if(next.flag&(1<<p));
					else
					{
						if(flag[next.x][next.y][next.flag]<next.v)
						{
							q.push(next);
							flag[next.x][next.y][next.flag]=next.v;
						}
						next.flag|=(1<<p);
						next.v=v;
					}
				}
				if(flag[next.x][next.y][next.flag]<next.v)
				{
					q.push(next);
					flag[next.x][next.y][next.flag]=next.v;
				}
				if((next.flag&((1<<y)-1))==((1<<y)-1)) return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		y=tot=0;
		pos.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='Y') pos[MP(i,j)]=tot++;
				else if(mp[i][j]=='F')
				{
					sx=i;
					sy=j;
				}
			}
		}
		y=tot;
		if(y==0)
		{
			puts("0");
			continue;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='G') pos[MP(i,j)]=tot++;
			}
		}
		int l,r,mid;
		l=1;
		r=n*m;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(bfs(mid)) r=mid;
			else l=mid+1;
		}
		if(bfs(r)) printf("%d\n",r);
		else puts("-1");
	}
	return 0;
}
/*
5 5
GDSSS
DDSSS
FSSSS
SSSSY
YYYYY
*/