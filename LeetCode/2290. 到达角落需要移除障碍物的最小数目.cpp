#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;


struct node
{
	int id;
	int v;
	node(){}
	node(int a,int b) :id(a),v(b){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
vector<node> mp[MAX];
bool flag[MAX];
int dis[MAX];
void dij(int s)
{
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.id]>dis[t.id]+to.v)
			{
				dis[to.id]=dis[t.id]+to.v;
				q.push(node(to.id,dis[to.id]));
			}
		}
	}
}
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n,m,i,j,id1,id2,x,y;
        n=sz(grid);
        m=sz(grid[0]);
        for(i=1;i<=n*m;i++) mp[i].clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                id1=(i)*m+(j+1);
                x=i+1;
                y=j;
                id2=(x)*m+(y+1);
                if(x<n&&y<m)
                {
                    mp[id1].pb(node(id2,grid[x][y]));
                    mp[id2].pb(node(id1,grid[i][j]));
                }
                
                x=i;
                y=j+1;
                id2=(x)*m+(y+1);
                if(x<n&&y<m)
                {
                    printf("%d %d %d %d\n",i,j,x,y);
                    mp[id1].pb(node(id2,grid[x][y]));
                    mp[id2].pb(node(id1,grid[i][j]));
                }
            }
        }
        dij(1);
        return dis[n*m];
    }
};
