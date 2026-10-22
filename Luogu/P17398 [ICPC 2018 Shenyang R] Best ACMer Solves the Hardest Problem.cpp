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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e7+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
vector<PII > res[MAX],cl;
void init()
{
	int i,j;
	for(i=0;i<=6000;i++)
	{
		for(j=0;j<=6000;j++)
		{
			if(i*i+j*j<=MAX-10) res[i*i+j*j].pb(MP(i,j));
			else break;
		}
	}
}
bool check(int x,int y)
{
	if(x<0||y<0||x>6000||y>6000) return 0;
	return 1;
} 
ll pre,ans;
void change(int &x,int &y)
{
	x=(x+pre)%6000+1;
	y=(y+pre)%6000+1;
}
bool exist[6010][6010]={0};
int mp[6010][6010]={0};
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
void go()
{
	int i,t,cas=1,x,y,w,n,q,op,k,tx,ty;
	init();
	read(t);
	while(t--)
	{
		cl.clear();
		read(n,q);
		for(i=1;i<=n;i++)
		{
			read(x,y,w);
			exist[x][y]=1;
			mp[x][y]=w;
			cl.pb(MP(x,y));
		}
		pre=0;
		set<PII > s;
		printf("Case #%d:\n",cas++);
		while(q--)
		{
			read(op,x,y);
			change(x,y);
			if(op==1)
			{
				read(w);
				exist[x][y]=1;
				mp[x][y]=w;
				cl.pb(MP(x,y));
			}
			else if(op==2)
			{
				exist[x][y]=0;
				mp[x][y]=0;
			}
			else if(op==3)
			{
				read(k,w);
				s.clear();
				for(auto it:res[k])
				{
					for(i=0;i<4;i++)
					{
						tx=x-it.fi*dir[i][0];
						ty=y-it.se*dir[i][1];
						if(!check(tx,ty)) continue;
						if(exist[tx][ty]) s.insert(MP(tx,ty));
					}
				}
				for(auto it:s) mp[it.fi][it.se]+=w;
			}
			else
			{
				read(k);
				s.clear();
				for(auto it:res[k])
				{
					for(i=0;i<4;i++)
					{
						tx=x-it.fi*dir[i][0];
						ty=y-it.se*dir[i][1];
						if(!check(tx,ty)) continue;
						if(exist[tx][ty]) s.insert(MP(tx,ty));
					}
				}
				ans=0;
				for(auto it:s) ans+=mp[it.fi][it.se];
				printf("%lld\n",ans);
				pre=ans;
			}
		}
		for(auto it:cl)
		{
			exist[it.fi][it.se]=0;
			mp[it.fi][it.se]=0;
		}
	}
}