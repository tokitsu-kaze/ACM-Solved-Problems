#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true;
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct president_tree
{
	#define type int
	int root[MAX*2],ls[40*MAX*2],rs[40*MAX*2],tot,ql,qr;
	type sum[40*MAX*2],qv;
	void init()
	{
		mem(root,0);
		tot=1;
		ls[0]=rs[0]=sum[0]=0;
	}
	int newnode(int x)
	{
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		sum[tot]=sum[x];
		return tot++;
	}
	void insert(int l,int r,int &id,int pre) //set(ql,ql,v)
	{
		id=newnode(pre);
		sum[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) insert(l,mid,ls[id],ls[pre]);
		else insert(mid+1,r,rs[id],rs[pre]);
	}
	int kthsmall(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[ls[id]]-sum[ls[pre]];
		if(temp>=k) return kthsmall(l,mid,ls[id],ls[pre],k);
		else return kthsmall(mid+1,r,rs[id],rs[pre],k-temp);
	}
	void set(int l,int r,type v=0){ql=l;qr=r;qv=v;}
}pt;
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,last,nex[N][K],fa[N],len[N],cnt[N];
	int newnode()
	{
		tot++;
		len[tot]=cnt[tot]=0;
		mem(nex[tot],0);
		return tot;
	}
	void init()
	{
		tot=0;
		last=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		p=last;
		np=last=newnode();
		len[np]=len[p]+1;
		cnt[last]++;
		while(p&&!nex[p][x])
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=1;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
	}
	int sum[N],tp[N];
	void topsort()
	{
		int i;
		for(i=1;i<=len[last];i++) sum[i]=0;
		for(i=1;i<=tot;i++) sum[len[i]]++;
		for(i=1;i<=len[last];i++) sum[i]+=sum[i-1];
		for(i=1;i<=tot;i++) tp[sum[len[i]]--]=i;
		for(i=tot;i;i--) cnt[fa[tp[i]]]+=cnt[tp[i]];
	}
	void build_tree(VI mp[])
	{
		for(int i=1;i<=tot;i++) mp[i].clear();
		for(int i=1;i<=tot;i++) mp[fa[i]].pb(i);
	}
	int pos[N],id[N];
	void init_pos(char *s,int n)//s[1..n]
	{
		int now=1;
		for(int i=1;i<=tot;i++) id[i]=tot;
		for(int i=1;i<=n;i++)
		{
			now=nex[now][s[i]-'a'];
			pos[i]=now;
			id[now]=i;
		}
	}
	int st[N][21];
	void init_ST()
	{
		int i,j,x;
		for(i=1;i<=tot;i++)
		{
			x=tp[i];
			st[x][0]=fa[x];
			for(j=1;j<20;j++)
			{
				st[x][j]=st[st[x][j-1]][j-1];
			}
		}
	}
	int get_substr(int l,int r)//init_pos  init_ST
	{
		int now,tmp,i;
		now=pos[r];
		for(i=19;~i;i--)
		{
			tmp=st[now][i];
			if(tmp&&len[tmp]>=r-l+1) now=tmp;
		}
		return now;
	}
}sam;
char s[MAX];
VI mp[MAX<<1];
int dl[MAX<<1],dr[MAX<<1],tot;
void dfs(int x)
{
	dl[x]=++tot;
	pt.set(sam.id[x],sam.id[x],1);
//	debug(x,sam.id[x])
	pt.insert(1,sam.tot,pt.root[tot],pt.root[tot-1]);
	for(auto to:mp[x]) dfs(to);
	dr[x]=tot;
}
void go()
{
	int t,n,q,l,r,k,res,i;
	read(t);
	while(t--)
	{
		read(n,q);
		read(s+1);
		sam.init();
		for(i=1;i<=n;i++) sam.add(s[i]-'a');
		sam.topsort();
		sam.init_pos(s,n);
		sam.init_ST();
		sam.build_tree(mp);
		pt.init();
		tot=0;
		dfs(1);
		while(q--)
		{
			read(l,r,k);
			res=sam.get_substr(l,r);
			if(sam.cnt[res]<k)
			{
				puts("-1");
				continue;
			}
	//		debug(res,dl[res],dr[res])
			printf("%d\n",pt.kthsmall(1,sam.tot,pt.root[dr[res]],pt.root[dl[res]-1],k)-(r-l+1)+1);
		}
	}
}
