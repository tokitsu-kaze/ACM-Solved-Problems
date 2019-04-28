#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//  inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
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
	//	freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e6+3;
/*********************************  head  *********************************/
namespace Gauss
{
	const int p=1e6+3;
	ll mp[55][55],sol[55];
	ll pow2(ll a,ll b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	ll inv(ll x){return pow2(x,p-2);}
	ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}
	int gauss(int n,int m)
	{
		int r,c,id,i,j;
		ll tmp,ta,tb;
		r=c=0;
		while(r<n&&c<m)
		{
			id=r;
			for(i=r+1;i<n;i++)
			{
				if(abs(mp[i][c])>abs(mp[id][c])) id=i;
			}
			if(id!=r)
			{
				for(i=0;i<=m;i++) swap(mp[r][i],mp[id][i]);
			}
			if(abs(mp[r][c])!=0)
			{
				for(i=r+1;i<n;i++)
				{
					if(abs(mp[i][c])==0) continue;
					tmp=lcm(abs(mp[i][c]),abs(mp[r][c]));
					ta=tmp/abs(mp[i][c]);
					tb=tmp/abs(mp[r][c]);
					if(mp[i][c]*mp[r][c]<0) tb=-tb;
					for(j=c;j<=m;j++)
					{
						mp[i][j]=(mp[i][j]*ta-mp[r][j]*tb)%p;
						if(mp[i][j]<0) mp[i][j]+=p;
					}
				}
				r++;
			}
			c++;
		}
		for(i=r;i<n;i++)
		{
			if(mp[i][m]!=0) return -1;//no solution 
		}
		if(r<m) return m-r;//multi solution 
		for(i=m-1;~i;i--)
		{
			tmp=mp[i][m];
			for(j=i+1;j<m;j++)
			{
				if(mp[i][j]==0) continue;
				tmp=(tmp-mp[i][j]*sol[j])%p;
				if(tmp<0) tmp+=p;
			}
			sol[i]=tmp*inv(mp[i][i])%p;
		}
		return 0;
	}
}
using namespace Gauss;
void go()
{
	mt19937 rd(time(0));
	int ans,tmp;
	set<int> s;
//	for(int i=0;i<12;i++) s.insert(i);
	s.insert(0);
	s.insert(mod-1);
	while(sz(s)<50)
	{
		tmp=(int)(rd()%mod);
		s.insert(tmp);
	}
	int tot=0;
	for(auto it:s)
	{
		cout<<"? "<<it<<endl;
		cin>>ans;
		if(ans==0)
		{
			cout<<"! "<<it<<endl;
			return;
		}
		for(int i=0;i<11;i++) mp[tot][i]=pow2(it,i);
		mp[tot][11]=ans;
		tot++;
	}
	if(gauss(tot,11)!=0)
	{
		cout<<"! -1"<<endl;
		return;
	}
	for(int i=0;i<mod;i++)
	{
		ll now=0;
		for(int j=0;j<11;j++)
		{
			now+=sol[j]*pow2(i,j)%mod;
			now%=mod;
		}
		if(now==0)
		{
			cout<<"! "<<i<<endl;
			return;
		}
	}
	cout<<"! -1"<<endl;
}
