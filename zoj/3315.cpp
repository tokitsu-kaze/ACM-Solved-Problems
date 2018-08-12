#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
/*int n,m,ans,dir[2][2]={0,1,1,0},flag[440][440],flag2,t1,t2;
char a[440][440];
struct s
{
	int x,y;
}t,next;
int bfs(int x,int y)
{
	int i,j;
	queue<s>q;
	t.x=0;
	t.y=0;
	q.push(t);
	if(flag[0][0]) return 0;
	flag[0][0]=2;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<2;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(next.x<=x&&next.y<=y&&flag[next.x][next.y]==0)
			{
				flag[next.x][next.y]=2;
				q.push(next);
			}
		}
	}
	if(flag[x][y]==2) return 1;
	return 0;
}
void over(int x,int y,int s,int e)
{
	int i,j;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			if(a[s+i][e+j]=='X') flag[i][j]=1;
		}
	}
}
int check(int x,int y)
{
	int i,j,mm,nn;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			if(a[i][j]=='.') flag[i][j]=0;
			else flag[i][j]=1;
		}
	} 
	mm=m-1-x;
	nn=n-1-y;
	while(1)
	{
		if((mm>0&&nn<0)||(nn>0&&mm<0)) return 0;
		if(mm==0&&nn==0)
		{
			if(bfs(x,y)) return 1;
			return 0;
		}
		else if(mm-x<=0&&nn-y<=0)
		{
			over(mm,nn,m-mm-1,n-nn-1);
			if(bfs(m-mm-1,n-nn-1)) return 1;
			else return 0;
		}
		over(x,y,m-mm-1,n-nn-1);
		mm-=x;
		nn-=y;
	}
	return 0;
}
int main()
{ 
	int i,j;
	while(cin>>n>>m)
	{
		mem(a,'.');
		ans=flag2=0;
		getchar();
		for(i=0;i<m;i++)
		{
			scanf("%s",a[i]);
		}
		for(j=2;j<n+m-1&&!ans;j++)
		{  
            for(i=1;j-i>0&&!ans;i++)
            {
				over(m+n,m+n,0,0);
				t1=i;
				t2=j-i;
				if(check(i,j-i))
				{
					ans=j;
					flag2=1;
				}
			}
		}
		if(!flag2) puts("-1"); 
		else cout<<ans<<endl;
	}
    return 0;
}*/
int n,m,flag1[221][221],flag2[221][221],ans;
char a[221][221];
void over(int x,int y,int s,int e)
{
	int i,j;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			if(a[s+i][e+j]=='X') flag1[i][j]=0;
		}
	}
}
void search(int a,int b)
{
	int i,j,nn,mm;
	nn=n-1;
	mm=m-1;
	for(i=0;i<=a;i++)
	{
		for(j=0;j<=b;j++)
		{
			flag1[i][j]=1;
			flag2[i][j]=0;
		}
	}
	while(nn>a||mm>b)
	{
		nn-=a;
		mm-=b;
	}
	if(nn<0||mm<0) return;
	for(i=0,j=0;i<n&&j<m;i+=a,j+=b)
	{
		over(a,b,i,j);
	}
	flag2[0][0]=1;
	for(i=0;i<=nn;i++)
	{
		for(j=0;j<=mm;j++)
		{
			if(flag2[i][j])
			{
				if(flag1[i+1][j]) flag2[i+1][j]=1;
				if(flag1[i][j+1]) flag2[i][j+1]=1;
			}
		}
	}
	for(i=nn;i<n;i++)
	{
		for(j=mm;j<m;j++)
		{
			if(flag2[i][j])
			{
				if(flag1[i+1][j]) flag2[i+1][j]=1;
				if(flag1[i][j+1]) flag2[i][j+1]=1;
			}
		}
	}
	if(flag2[a][b]&&flag2[nn][mm])
	{
		if(ans==-1) ans=a+b;
		else ans=min(ans,a+b);
	}
}
int main()
{ 
	int i,j;
	while(cin>>m>>n)
	{
		mem(a,0);
		ans=-1;
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s",a[i]);
		}
		for(j=2;j<n+m-1&&ans==-1;j++)
		{  
            for(i=1;j-i>0&&ans==-1;i++)
            {
				search(i,j-i);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}