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
	//	freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int mp[1010][1010],x[888],y[888];
int nowx,nowy,dir[5][2]={0,0,-1,-1,1,-1,-1,1,1,1};
void move(int xx,int yy)
{
	int k;
	nowx+=xx;
	nowy+=yy;
	if(mp[nowx][nowy]) nowx-=xx;
	cout<<nowx<<" "<<nowy<<endl;
	cin>>k>>xx>>yy;
	if(k==-1) exit(0);
	mp[x[k]][y[k]]--;
	mp[xx][yy]++;
	x[k]=xx;
	y[k]=yy;
}
void go()
{
	int i,j,cnt[5],tmp,mx;
	mem(mp,0);
	cin>>nowx>>nowy;
	for(i=1;i<=666;i++)
	{
		cin>>x[i]>>y[i];
		mp[x[i]][y[i]]++;
	}
	while(nowx>500) move(-1,0);
	while(nowy>500) move(0,-1);
	while(nowx<500) move(1,0);
	while(nowy<500) move(0,1);
	mem(cnt,0);
	tmp=0;
	for(i=1;i<nowx;i++)
	{
		for(j=1;j<nowy;j++)
		{
			tmp+=mp[i][j];
		}
	}
	cnt[1]+=tmp;
	cnt[2]+=tmp;
	cnt[3]+=tmp;
	tmp=0;
	for(i=nowx+1;i<=999;i++)
	{
		for(j=1;j<nowy;j++)
		{
			tmp+=mp[i][j];
		}
	}
	cnt[1]+=tmp;
	cnt[2]+=tmp;
	cnt[4]+=tmp;
	tmp=0;
	for(i=1;i<nowx;i++)
	{
		for(j=nowy+1;j<=999;j++)
		{
			tmp+=mp[i][j];
		}
	}
	cnt[1]+=tmp;
	cnt[3]+=tmp;
	cnt[4]+=tmp;
	tmp=0;
	for(i=nowx+1;i<=999;i++)
	{
		for(j=nowy+1;j<=999;j++)
		{
			tmp+=mp[i][j];
		}
	}
	cnt[2]+=tmp;
	cnt[3]+=tmp;
	cnt[4]+=tmp;
	mx=max({cnt[1],cnt[2],cnt[3],cnt[4]});
	for(i=1;i<=4;i++)
	{
		if(mx==cnt[i])
		{
			while(1) move(dir[i][0],dir[i][1]);
		}
	}
}
/*
1 2
3 4
*/