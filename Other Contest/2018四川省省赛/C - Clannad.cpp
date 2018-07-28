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
const int MAX=1e6+10;
const ll mod=1e9+7;
struct AC_Automaton
{
    int next[MAX][26],fail[MAX],l[MAX],last[MAX];
    ll cnt[MAX];
    int root,tot;
    int newnode()
    {
        int i;
        mem(next[tot],0);
        fail[tot]=0;
        cnt[tot]=0;
        l[tot]=0;
        last[tot]=0;
        return tot++;
    }
    void init()
    {
        tot=0;
        root=newnode();
    }
    void insert(char *s)
    {
        int len,now,i;
        len=strlen(s);
        now=root;
        for(i=0;i<len;i++)
        {
            int t=s[i]-'a';
            if(!next[now][t]) next[now][t]=newnode();
            now=next[now][t];
        }
        cnt[now]++;
        l[now]=len;
    }
    void setfail()
    {
        int i,now;
        queue<int>q;
        for(i=0;i<26;i++)
        {
            if(next[root][i]) q.push(next[root][i]);
        }
        while(!q.empty())
        {
            now=q.front();
            q.pop();
            if(cnt[fail[now]]) last[now]=fail[now];
            else last[now]=last[fail[now]];
            for(i=0;i<26;i++)
            {
                if(next[now][i])
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
                else next[now][i]=next[fail[now]][i];
            }
        }
    }
    ll dp[MAX];
    void query(char *s)
    {
        int len,now,i,res;
        len=strlen(s+1);
        now=root;
        dp[0]=1;
        for(i=1;i<=len;i++)
        {
            int t=s[i]-'a';
            now=next[now][t];
            int temp=now;
            dp[i]=0;
            while(temp)
            {
                dp[i]+=dp[i-l[temp]];
                dp[i]%=mod;
                temp=last[temp];
            }
        }
        for(i=1;i<=len;i++) printf("%lld%c",dp[i]," \n"[i==len]);
    }
}ac;
char s[MAX],tmp[MAX];
int main()
{
    int n,t,i,m;
    ll x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ac.init(); 
        scanf("%s",s+1);
        for(i=0;i<m;i++)
        {
            scanf("%s",tmp);
            ac.insert(tmp);
        }
        ac.setfail();
        ac.query(s);
    }
    return 0;
}