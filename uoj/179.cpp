#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
template<class T> void read(T *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
typedef double db;
typedef vector<db> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
struct Simplex
{
	int m,n;
	VI B,N;
	VVD D;
	void Pivot(int r,int s)
	{
		int i,j;
		for(i=0;i<m+2;i++)
		{
			if(i==r) continue;
			for(j=0;j<n+2;j++)
			{
				if(j==s) continue;
				D[i][j]-=D[r][j]*D[i][s]/D[r][s];
			}
		}
		for(j=0;j<n+2;j++)
		{
			if (j!=s) D[r][j]/=D[r][s];
		}
		for(i=0;i<m+2;i++)
		{
			if(i!=r) D[i][s]/=-D[r][s];
		}
		D[r][s]=1.0/D[r][s];
		swap(B[r],N[s]);
	}
	bool simplex(int phase)
	{
		int i,j,s,r;
		int x=phase==1?m+1:m;
		while(1)
		{
			s=-1;
			for(j=0;j<=n;j++)
			{
				if(phase==2&&N[j]==-1) continue;
				if(s==-1||D[x][j]<D[x][s]||D[x][j]==D[x][s]&&N[j]<N[s]) s=j;
			}
			if(D[x][s]>-eps) return 1;
			r=-1;
			for(i=0;i<m;i++)
			{
				if(D[i][s]<eps) continue;
				if(r==-1||D[i][n+1]/D[i][s]<D[r][n+1]/D[r][s]) r=i;
				if(D[i][n+1]/D[i][s]==D[r][n+1]/D[r][s]&&B[i]<B[r]) r=i;
			}
			if(r==-1) return 0;
			Pivot(r,s);
		}
	}
	db work(const VVD &A,const VD &b,const VD &c,VD &res)
	{
		int i,j,k,r,s;
		m=(int)b.size();
		n=(int)c.size();
		N=VI(n+1);
		B=VI(m);
		D=VVD(m+2,VD(n+2));
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				D[i][j]=A[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			B[i]=n+i;
			D[i][n]=-1;
			D[i][n+1]=b[i];
		}
		for(j=0;j<n;j++)
		{
			N[j]=j;
			D[m][j]=-c[j];
		}
		N[n]=-1;
		D[m+1][n]=1;
		r=0;
		for(i=1;i<m;i++)
		{
			if(D[i][n+1]<D[r][n+1]) r=i;
		}
		if(D[r][n+1]<-eps)
		{
			Pivot(r,n);
			if(!simplex(1)||D[m+1][n+1]<-eps) return -numeric_limits<db>::infinity();//no solution 
			for(i=0;i<m;i++)
			{
				if(B[i]!=-1) continue;
				s=-1;
				for(j=0;j<=n;j++)
				{
					if(s==-1||D[i][j]<D[i][s]||D[i][j]==D[i][s]&&N[j]<N[s]) s=j;
				}
				Pivot(i,s);
			}
		}
		if(!simplex(2)) return numeric_limits<db>::infinity();//solution is INF
		res=VD(n);
		for(i=0;i<m;i++)
		{
			if(B[i]<n) res[B[i]]=D[i][n+1];
		}
		return D[m][n + 1];
	}
}sp;
void go()
{
	int n,m,t,i,j;
	db ans;
    while(read(n,m,t))
    {
		VVD a(m,VD(n,0));
		VD b(m);
		VD c(n);
		for(auto &it:c) read(it);
		for(i=0;i<m;i++)
		{
			for(auto &it:a[i]) read(it);
			read(b[i]);
		}
		VD res(n);
		ans=sp.work(a,b,c,res);
		if(ans==-numeric_limits<db>::infinity()) puts("Infeasible");
		else if(ans==numeric_limits<db>::infinity()) puts("Unbounded");
		else
		{
			printf("%.10f\n",ans);
			if(t)
			{
				for(i=0;i<sz(res);i++) printf("%.10f%c",res[i]," \n"[i==sz(res)-1]);
			}
		}
		
	}
}
