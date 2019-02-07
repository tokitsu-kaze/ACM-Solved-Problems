#include <bits/stdc++.h>
using namespace std;
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
//		freopen("TEST.txt","r",stdin);
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
int check[1010];
void go()
{
	int t,n,i,len,cnt,id;
	char a[111],b[111];
	map<string,int> mp,mp2;
	mp["Terran"]=1;
	mp["Zerg"]=1;
	mp["Protoss"]=1;
	
	mp2["Zerg,Protoss,Terran"]=1;
	mp2["Zerg,Terran,Protoss"]=1;
	mp2["Terran,Protoss,Zerg"]=1;
	mp2["Terran,Zerg,Protoss"]=1;
	mp2["Protoss,Zerg,Terran"]=1;
	mp2["Protoss,Terran,Zerg"]=1;
	
	scanf("%d",&t);
	assert(t>=1&&t<=20);
	while(t--)
	{
		scanf("%d",&n);
		assert(n>=1&&n<=1000);
		VI tmp[3];
		mem(check,0);
		for(i=1;i<=n;i++)
		{
			scanf(" %d %s %s",&id,a,b);
			check[id]++;
			assert(strcmp(a,"is")==0);
			assert(mp.count(b));
			if(b[0]=='T') tmp[0].pb(id);
			else if(b[0]=='Z') tmp[1].pb(id);
			else if(b[0]=='P') tmp[2].pb(id);
		}
		for(i=1;i<=n;i++) assert(check[i]==1);
		scanf(" %s",a);
		assert(mp2.count(a));
		len=strlen(a);
		cnt=0;
		for(i=0;i<len;i++)
		{
			if(a[i]=='T'||a[i]=='Z'||a[i]=='P') b[cnt++]=a[i];
		}
		assert(cnt==3);
		VI res;
		for(i=0;i<cnt;i++)
		{
			if(b[i]=='T')
			{
				for(auto it:tmp[0]) res.pb(it);
			}
			else if(b[i]=='Z')
			{
				for(auto it:tmp[1]) res.pb(it);
			}
			else if(b[i]=='P')
			{
				for(auto it:tmp[2]) res.pb(it);
			}
		}
		assert(sz(res)==n);
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
} 