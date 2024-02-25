#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct hash_map
{
	#define type int
	#define TA pair<type,type>
    static const int p=999917;
    TA val[MAX];
	type w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    hash_map(){top=tot=0;}
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,TA y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(TA y)
    {
        int x=y.first%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    type& operator [](TA y)
    {
        int x=y.first%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
    #undef TA
    #undef type
}flag;
namespace HASH
{
	#define type int
	int m,k;
	vector<type> sd,p;
	vector<vector<type>> tmp;
	void set(vector<type> _sd,vector<type> _p)
	{
		sd=_sd;
		p=_p;
		assert(sd.size()==p.size());
		k=sd.size();
	}
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp.resize(k);
		for(j=0;j<k;j++)
		{
			tmp[j].resize(m+1);
			tmp[j][0]=1;
			for(i=1;i<=m;i++) tmp[j][i]=1ll*tmp[j][i-1]*sd[j]%p[j];
		}
	}
	struct hash_table
	{
		vector<vector<type>> ha;
		void work(int *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				for(i=1;i<=n;i++) ha[j][i]=(1ll*ha[j][i-1]*sd[j]+s[i])%p[j];
			}
		}
		vector<type> get(int l,int r)
		{
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=(ha[j][r]-1ll*ha[j][l-1]*tmp[j][r-l+1])%p[j];
				if(res[j]<0) res[j]+=p[j];
			}
			return res;
		}
	};
	#undef type
}
HASH::hash_table haax,haay,habx,haby;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);
*/
int n,m,a[MAX],b[MAX],len[MAX];
pair<int,int> cal_ha(int tot,int pos,int k,
					HASH::hash_table &hax,HASH::hash_table &hay)
{
	int lx,rx,ly,ry;
	lx=pos;
	rx=pos+k/2-1;
	ry=pos+k-1;
	ly=ry-k/2+1;
	
	ly=tot-ly+1;
	ry=tot-ry+1;
	swap(ly,ry);
	
	vector<int> hx,hy;
	hx=hax.get(lx,rx);
	hy=hay.get(ly,ry);
	pair<int,int> res={hx[0]+hy[0],hx[1]+hy[1]};
	if(res.first>=HASH::p[0]) res.first-=HASH::p[0];
	if(res.second>=HASH::p[1]) res.second-=HASH::p[1];
	return res;
}
int ck(int k)
{
	int i;
	flag.clear();
	for(i=1;i+k-1<=n;i++) flag[cal_ha(n,i,k,haax,haay)]=1;
	for(i=1;i+k-1<=m;i++)
	{
		if(flag.count(cal_ha(m,i,k,habx,haby))) return 1;
	}
	return 0;
}
int cal(int tot)
{
	int l,r,mid;
	l=1;
	r=tot;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(len[mid+1])) l=mid+1;
		else r=mid;
	}
	return len[l];
}
int main()
{
	int i,tot,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	HASH::set({131,233},{402653189,805306457});
	HASH::init(max(n,m));
	haax.work(a,n);
	reverse(a+1,a+1+n);
	for(i=1;i<=n;i++) a[i]=100-a[i];
	haay.work(a,n);
	reverse(b+1,b+1+m);
	habx.work(b,m);
	reverse(b+1,b+1+m);
	for(i=1;i<=m;i++) b[i]=100-b[i];
	haby.work(b,m);
	ans=0;
	tot=0;
	for(i=1;i<=min(n,m);i+=2) len[++tot]=i;
	ans=max(ans,cal(tot));
	tot=0;
	for(i=0;i<=min(n,m);i+=2) len[++tot]=i;
	ans=max(ans,cal(tot));
	printf("%d\n",ans);
	return 0;
}
