#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int x,y,v,f;
	node(){}
	node(int a,int b,int c,int d) :x(a),y(b),v(c),f(d){}
};
char mp[4][1011][1011];
int n,m,flag[4][1011][1011],dir[4][2]={-1,0,0,1,1,0,0,-1};
void debug(int x)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			putchar(mp[x][i][j]);
		}
		puts("");
	}
}
int check1(int z,int x,int y,int i)
{
	//0上1右2下3左
	if(i==0)
	{
		if(mp[z][x][y]=='-'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='U') return 0;
		else return 1;
	}
	else if(i==1)
	{
		if(mp[z][x][y]=='|'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='R') return 0;
		else return 1;
	}
	else if(i==2)
	{
		if(mp[z][x][y]=='-'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='D') return 0;
		else return 1;
	}
	else if(i==3)
	{
		if(mp[z][x][y]=='|'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='L') return 0;
		else return 1;
	}
}
int check2(int z,int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[z][x][y]=='*') return 0;
	return 1;
}
int check3(int z,int x,int y,int i)
{
	//0下1左2上3右 
	if(i==2)
	{
		if(mp[z][x][y]=='-'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='U') return 0;
		else return 1;
	}
	else if(i==3)
	{
		if(mp[z][x][y]=='|'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='R') return 0;
		else return 1;
	}
	else if(i==0)
	{
		if(mp[z][x][y]=='-'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='<'
		||mp[z][x][y]=='D') return 0;
		else return 1;
	}
	else if(i==1)
	{
		if(mp[z][x][y]=='|'
		||mp[z][x][y]=='>'
		||mp[z][x][y]=='v'
		||mp[z][x][y]=='^'
		||mp[z][x][y]=='L') return 0;
		else return 1;
	}
}
int bfs()
{
	node t,nex;
	int i,sx,sy,ex,ey;
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	sx--;
	sy--;
	ex--;
	ey--;
	queue<node> q;
	q.push(node(sx,sy,0,0));
	flag[0][sx][sy]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
//		cout<<t.f<<" "<<t.x<<" "<<t.y<<endl;
		if(t.x==ex&&t.y==ey) return t.v;
		for(i=0;i<4;i++)
		{
			if(!check1(t.f,t.x,t.y,i)) continue;
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			nex.v++;
			if(!check2(nex.f,nex.x,nex.y)) continue;
			if(!check3(nex.f,nex.x,nex.y,i)) continue;
			if(flag[nex.f][nex.x][nex.y]) continue;
			q.push(nex);
			flag[nex.f][nex.x][nex.y]=1;
	//		debug(nex.f);
	//		cout<<i<<" "<<nex.x<<" "<<nex.y<<endl;
		}
		nex=t;
		nex.f=(nex.f+1)%4;
		nex.v++;
		if(!flag[nex.f][nex.x][nex.y])
		{
			q.push(nex);
			flag[nex.f][nex.x][nex.y]=1;
		}
	}
	return -1;
}
int main()
{
	int i,j,sx,sy,ex,ey;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[0][i]);
			for(j=0;j<m;j++)
			{
				flag[0][i][j]=0;
				flag[1][i][j]=0;
				flag[2][i][j]=0;
				flag[3][i][j]=0;
				if(mp[0][i][j]=='+')
				{
					mp[1][i][j]='+';
					mp[2][i][j]='+';
					mp[3][i][j]='+';
				}
				else if(mp[0][i][j]=='-')
				{
					mp[1][i][j]='|';
					mp[2][i][j]='-';
					mp[3][i][j]='|';
				}
				else if(mp[0][i][j]=='|')
				{
					mp[1][i][j]='-';
					mp[2][i][j]='|';
					mp[3][i][j]='-';
				}
				else if(mp[0][i][j]=='^')
				{
					mp[1][i][j]='>';
					mp[2][i][j]='v';
					mp[3][i][j]='<';
				}
				else if(mp[0][i][j]=='>')
				{
					mp[1][i][j]='v';
					mp[2][i][j]='<';
					mp[3][i][j]='^';
				}
				else if(mp[0][i][j]=='v')
				{
					mp[1][i][j]='<';
					mp[2][i][j]='^';
					mp[3][i][j]='>';
				}
				else if(mp[0][i][j]=='<')
				{
					mp[1][i][j]='^';
					mp[2][i][j]='>';
					mp[3][i][j]='v';
				}
				else if(mp[0][i][j]=='L')
				{
					mp[1][i][j]='U';
					mp[2][i][j]='R';
					mp[3][i][j]='D';
				}
				else if(mp[0][i][j]=='U')
				{
					mp[1][i][j]='R';
					mp[2][i][j]='D';
					mp[3][i][j]='L';
				}
				else if(mp[0][i][j]=='R')
				{
					mp[1][i][j]='D';
					mp[2][i][j]='L';
					mp[3][i][j]='U';
				}
				else if(mp[0][i][j]=='D')
				{
					mp[1][i][j]='L';
					mp[2][i][j]='U';
					mp[3][i][j]='R';
				}
				else if(mp[0][i][j]=='*')
				{
					mp[1][i][j]='*';
					mp[2][i][j]='*';
					mp[3][i][j]='*';
				}
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}