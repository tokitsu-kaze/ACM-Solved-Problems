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
const int MAX=3e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
string s[MAX],now[MAX],ans[2][MAX];
int n,m,res[2];
void go()
{
	int i,j,cnt[5],sum,pos;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			now[i].resize(m);
		}
		vector<char> tmp;
		tmp.pb('A');
		tmp.pb('T');
		tmp.pb('C');
		tmp.pb('G');
		/*****-*****/
		sort(all(tmp));
		map<string,int> mp;
		res[0]=INF;
		do
		{
			string mpp;
			mpp+=tmp[0];
			mpp+=tmp[1];
			sort(all(mpp));
			if(mp[mpp]) continue;
			mp[mpp]=1;
			sum=0;
			for(i=0;i<n;i+=2)
			{
				cnt[0]=0;
				pos=0;
				for(j=0;j<m;j++)
				{
					if(tmp[pos]!=s[i][j]) cnt[0]++;
					pos^=1;
				}
				cnt[1]=0;
				pos=1;
				for(j=0;j<m;j++)
				{
					if(tmp[pos]!=s[i][j]) cnt[1]++;
					pos^=1;
				}
				if(cnt[0]<cnt[1]) pos=0;
				else pos=1;
				sum+=cnt[pos];
				for(j=0;j<m;j++)
				{
					now[i][j]=tmp[pos];
					pos^=1;
				}
			}
			for(i=1;i<n;i+=2)
			{
				cnt[2]=0;
				pos=2;
				for(j=0;j<m;j++)
				{
					if(tmp[pos]!=s[i][j]) cnt[2]++;
					pos^=1;
				}
				cnt[3]=0;
				pos=3;
				for(j=0;j<m;j++)
				{
					if(tmp[pos]!=s[i][j]) cnt[3]++;
					pos^=1;
				}
				if(cnt[2]<cnt[3]) pos=2;
				else pos=3;
				sum+=cnt[pos];
				for(j=0;j<m;j++)
				{
					now[i][j]=tmp[pos];
					pos^=1;
				}
			}
			if(sum<res[0])
			{
				res[0]=sum;
				for(i=0;i<n;i++) ans[0][i]=now[i];
			}
		}
		while(next_permutation(all(tmp)));
		
		/*****|*****/
		sort(all(tmp));
		mp.clear();
		res[1]=INF;
		do
		{
			string mpp;
			mpp+=tmp[0];
			mpp+=tmp[1];
			sort(all(mpp));
			if(mp[mpp]) continue;
			mp[mpp]=1;
			sum=0;
			for(j=0;j<m;j+=2)
			{
				cnt[0]=0;
				pos=0;
				for(i=0;i<n;i++)
				{
					if(tmp[pos]!=s[i][j]) cnt[0]++;
					pos^=1;
				}
				cnt[1]=0;
				pos=1;
				for(i=0;i<n;i++)
				{
					if(tmp[pos]!=s[i][j]) cnt[1]++;
					pos^=1;
				}
				if(cnt[0]<cnt[1]) pos=0;
				else pos=1;
				sum+=cnt[pos];
				for(i=0;i<n;i++)
				{
					now[i][j]=tmp[pos];
					pos^=1;
				}
			}
			for(j=1;j<m;j+=2)
			{
				cnt[2]=0;
				pos=2;
				for(i=0;i<n;i++)
				{
					if(tmp[pos]!=s[i][j]) cnt[2]++;
					pos^=1;
				}
				cnt[3]=0;
				pos=3;
				for(i=0;i<n;i++)
				{
					if(tmp[pos]!=s[i][j]) cnt[3]++;
					pos^=1;
				}
				if(cnt[2]<cnt[3]) pos=2;
				else pos=3;
				sum+=cnt[pos];
				for(i=0;i<n;i++)
				{
					now[i][j]=tmp[pos];
					pos^=1;
				}
			}
			if(sum<res[1])
			{
				res[1]=sum;
				for(i=0;i<n;i++) ans[1][i]=now[i];
			}
		}
		while(next_permutation(all(tmp)));
		if(res[0]<res[1]) pos=0;
		else pos=1;
		for(i=0;i<n;i++) cout<<ans[pos][i]<<"\n";
	}
}