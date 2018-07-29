#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int pre[MAX];
int find(int x)
{
    if(pre[x]!=x) pre[x]=find(pre[x]);
    return pre[x];
}
struct node
{
    int a,b;
    double v;
    node(){}
    node(int x,int y,double _v)
    {
        a=x;
        b=y;
        v=_v;
    }
    friend bool operator <(node a,node b)
    {
        return a.v<b.v;
    }
}aa[MAX];
double ans;
void merge(int x,int y,double v)
{
    int rx,ry;
    rx=find(x);
    ry=find(y);
    if(rx!=ry)
    {
        pre[rx]=ry;
        ans+=v;
    }
}
int main()
{
    int t,i,n,m,a,b;
    double x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) pre[i]=i;
        ans=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%lf%lf",&a,&b,&x,&y);
            aa[i]=node(a,b,x/y);
        }
        sort(aa+1,aa+1+m);
        for(i=1;i<=m;i++)
        {
            merge(aa[i].a,aa[i].b,aa[i].v);
        }
        printf("%.1f\n",ans);
    }
    return 0;
}

