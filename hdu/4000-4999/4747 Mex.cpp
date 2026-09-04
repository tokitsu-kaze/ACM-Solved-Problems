#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
    #define type ll
    static const type inf=INF;
    #define ls (id<<1)
    #define rs (id<<1|1)
    int n,ql,qr,qop;
    type a[MAX],tag[MAX<<2],qv;
    struct node
    {
        type sum,mx;
        void init(){sum=mx=0;}
    }t[MAX<<2],null_node;
    node merge_node(node x,node y)
    {
        node res;
        res.sum=x.sum+y.sum;
        res.mx=max(x.mx,y.mx);
        return res;
    }
    void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
    void pushdown(int l,int r,int id)
    {
        if(tag[id]==-1) return;
        int mid=(l+r)>>1;
        t[ls].sum=(mid-l+1)*tag[id];
        t[rs].sum=(r-mid)*tag[id];
        t[ls].mx=t[rs].mx=tag[id];
        tag[ls]=tag[rs]=tag[id];
        tag[id]=-1;
    }
    void build(int l,int r,int id)
    {
        tag[id]=-1;
        t[id].init();
        if(l==r)
        {
            t[id]={a[l],a[l]};
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,ls);
        build(mid+1,r,rs);
        pushup(id);
    }
    void update(int l,int r,int id)
    {
        if(l>=ql&&r<=qr)
        {
            t[id].sum=(r-l+1)*qv;
            t[id].mx=qv;
            tag[id]=qv;
            return;
        }
        pushdown(l,r,id);
        int mid=(l+r)>>1;
        if(ql<=mid) update(l,mid,ls);
        if(qr>mid) update(mid+1,r,rs);
        pushup(id);
    }
    node query(int l,int r,int id)
    {
        if(l>=ql&&r<=qr) return t[id];
        pushdown(l,r,id);
        int mid=(l+r)>>1;
        if(qr<=mid) return query(l,mid,ls);
        if(ql>mid) return query(mid+1,r,rs);
        return merge_node(query(l,mid,ls),query(mid+1,r,rs));
    }
    int dfs(int l,int r,int id)
    {
        if(l==r) return l;
        pushdown(l,r,id);
        int mid=(l+r)>>1;
        if(t[ls].mx>qv) return dfs(l,mid,ls);
        else return dfs(mid+1,r,rs);
    }
    void build(int _n)
    {
        n=_n;
        build(1,n,1);
        null_node.init();
    }
    void upd(int l,int r,type v)
    {
        if(l>r) return;
        ql=l;
        qr=r;
        qv=v;
        update(1,n,1);
    }
    type ask_sum(int l,int r)
    {
        if(l>r) return null_node.sum;
        ql=l;
        qr=r;
        return query(1,n,1).sum;
    }
    type ask_max(int l,int r)
    {
        if(l>r) return null_node.mx;
        ql=l;
        qr=r;
        return query(1,n,1).mx;
    }
    type ask_pos(type v)
    {
        qv=v;
        return dfs(1,n,1);
    }
    #undef type
    #undef ls
    #undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int a[MAX],vis[MAX],lst[MAX],nex[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,mex,l,r;
    ll ans;
    while(cin>>n)
    {
        if(n==0) break;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]=min(a[i],n);
        }
        for(i=0;i<=n;i++) vis[i]=0;
        mex=0;
        for(i=1;i<=n;i++)
        {
            vis[a[i]]=1;
            while(vis[mex]) mex++;
            tr.a[i]=mex;
        }
        for(i=0;i<=n;i++) lst[i]=n+1;
        for(i=n;i;i--)
        {
            nex[i]=lst[a[i]];
            lst[a[i]]=i;
        }
        ans=0;
        tr.build(n);
        for(i=1;i<=n;i++)
        {
            ans+=tr.ask_sum(1,n);
            tr.upd(i,i,0);
            if(a[i]<tr.ask_max(1,n))
            {
                l=tr.ask_pos(a[i]);
                r=nex[i]-1;
                if(l<=r) tr.upd(l,r,a[i]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
考虑每次删一个数 ai，线段树维护 [i,n] 的答案。
*/
