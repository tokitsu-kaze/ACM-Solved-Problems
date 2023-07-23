#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> topsort(int n,
				    vector<int> mp[],
				    int *degree,
				    vector<int> &node)
{
	int i,x;
    queue<int> q;
    for(auto &it:node)
	{
	    if(!degree[it]) q.push(it);
	}
    vector<int> toplist;
    while(!q.empty())
	{
	    x=q.front();
	    q.pop();
	    toplist.push_back(x);
	    for(auto &to:mp[x])
		{
		    degree[to]--;
		    if(!degree[to]) q.push(to);
		}
	}
    return toplist;
}
const int sample[4][5]=
{
	{0,0,0,0,0},
	{0,1,3,10,11},
	{0,2,7,8,9},
	{0,4,5,6,12},
};
vector<int> mp[205],mp2[205],node;
int d[205],flag[205],flag2[205],fa[205],nex[205];
int ans[205][205];
void dfs(int x)
{
    if(flag2[x]) return;
    flag2[x]=1;
    node.push_back(x);
    for(auto &to:mp2[x]) dfs(to);
}
int main()
{
    int n,m,i,j,x,y,tot,ok,pretot;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
	{
	    mp[i].clear();
	    mp2[i].clear();
	    d[i]=flag[i]=flag2[i]=0;
	}
    ok=1;
    for(i=1;i<=n;i++)
	{
	    scanf("%d",&x);
	    if(x==i) ok=0;
	    mp[i].push_back(x);
	    d[x]++;
	    nex[i]=x;
	    mp2[i].push_back(x);
	    mp2[x].push_back(i);
	}
    if(!ok)
	{
	    puts("0");
	    return 0;
	}
    vector<int> toplist,circle;
    pretot=0;
    for(i=1;i<=n;i++)
	{
	    if(flag2[i]) continue;
	    node.clear();
	    dfs(i);
	    toplist=topsort(n,mp,d,node);
	    for(auto &it:toplist) flag[it]=1;
	    circle.clear();
	    for(auto &it:node)
		{
		    if(!flag[it])
			{
			    fa[nex[it]]=it;
			    circle.push_back(it);
			}
		}
	    if(circle.size()<=2||m<=2)
		{
		    puts("0");
		    return 0;
		}
	    if(circle.size()==3&&m==4)
		{
			for(i=0;i<circle.size();i++)
			{
			    for(j=1;j<=4;j++)
				{
				    ans[circle[i]][j]=sample[i+1][j]+pretot;
				}
			}
		    tot=12+pretot;
		}
	    else
		{
			x=circle[0];
		    tot=pretot;
		    j=1;
		    while(j<=m)
			{
			    y=x;
			    do
				{
				    ans[y][j]=++tot;
				    y=fa[y];
				    
				}
			    while(y!=x);
			    x=fa[x];
			    j++;
			}
		}
	    reverse(toplist.begin(),toplist.end());
	    for(auto &it:toplist)
		{
		    for(j=1;j<=m;j++) ans[it][j]=++tot;
		}
	    pretot=tot;
	}
    for(i=1;i<=n;i++)
	{
	    for(j=1;j<=m;j++)
		{
		    printf("%d%c",ans[i][j]," \n"[j==m]);
		}
	}
    return 0;
}
/*
5 10
2 3 1 1 4
1 6 8 10 15 17 19 24 26 28
3 5 7 12 14 16 21 23 25 30
2 4 9 11 13 18 20 22 27 29
40 39 38 37 36 35 34 33 32 31
50 49 48 47 46 45 44 43 42 41
 
6 10
2 3 1 5 6 4
6 3
2 3 1 5 6 4
4 4
2 3 1 1
*/
