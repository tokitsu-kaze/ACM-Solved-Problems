#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
const int MAXN = 1010;
const int MAXM = 2010;
  
struct Edge {  
    int to,next;  
    bool cut;  
} edge[MAXM];  
  
int n,m,q;  
int head[MAXN],tot;  
int Low[MAXN],DFN[MAXN],Stack[MAXN];  
int Index,top;  
bool Instack[MAXN];  
bool cut[MAXN];  
int add_block[MAXN];  
int bridge;  
int f[MAXN];  
  
int find_father(int u) {  
    if(f[u]==u)  
        return u;  
    return f[u]=find_father(f[u]);  
}  
  
void link(int u,int v) {  
    int x=find_father(u);  
    int y=find_father(v);  
    if(x==y)  
        return ;  
    f[x]=y;  
}  
  
void addedge(int u,int v) {  
    edge[tot].to = v;  
    edge[tot].next = head[u];  
    edge[tot].cut = false;  
    head[u] = tot++;  
}  
  
void Tarjan(int u,int pre) {  
    int v;  
    Low[u] = DFN[u] = ++Index;  
    Stack[top++] = u;  
    Instack[u] = true;  
    int son = 0;  
    for(int i = head[u]; i != -1; i = edge[i].next) {  
        v = edge[i].to;  
        if(v == pre)continue;  
        if( !DFN[v] ) {  
            son++;  
            Tarjan(v,u);  
            if(Low[u] > Low[v])Low[u] = Low[v];  
            if(Low[v] > DFN[u]) {  
                bridge++;  
                edge[i].cut = true;  
                edge[i^1].cut = true;  
                link(u,v);///ге  
            }  
            if(u != pre && Low[v] >= DFN[u]) {  
                cut[u] = true;  
                add_block[u]++;  
            }  
        } else if( Low[u] > DFN[v])  
            Low[u] = DFN[v];  
    }  
    if(u == pre && son > 1)cut[u] = true;  
    if(u == pre)add_block[u] = son - 1;  
    Instack[u] = false;  
    top--;  
}  
  
void solve(int N) {  
    memset(DFN,0,sizeof(DFN));  
    memset(Instack,false,sizeof(Instack));  
    memset(add_block,0,sizeof(add_block));  
    memset(cut,false,sizeof(cut));  
    Index = top = 0;  
    bridge = 0;  
    for(int i = 1; i <= N; i++)  
        if( !DFN[i] )  
            Tarjan(i,i);  
}  
  
void init() {  
    tot = 0;  
    memset(head,-1,sizeof(head));  
    for(int i=1; i<=n; i++)  
        f[i]=i;  
}  
  
int main() {  
    while(~scanf("%d%d%d",&n,&m,&q)) {  
        if(n==0)  
            break;  
        init();  
        int u,v;  
        for(int i=0; i<m; i++) {  
            scanf("%d%d",&u,&v);  
            addedge(u,v);  
            addedge(v,u);  
        }  
        solve(n);  
        for(int i=0; i<q; i++) {  
            scanf("%d%d",&u,&v);  
            printf("%s\n",find_father(u)==find_father(v)?"1":"0");  
        }  
    }  
    return 0;  
}  
