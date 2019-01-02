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
		freopen("TEST.txt","r",stdin);
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
struct hash_table
{
	ll seed,p;
	ll Hash[26][MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		ll i,j;
		tmp[0]=1;
		for(i=1;i<=n;i++) tmp[i]=tmp[i-1]*seed%p;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<26;j++)
			{
				Hash[j][i]=(Hash[j][i-1]*seed%p+(s[i]-'a'+j)%26)%p;
			}
		}
	}
	ll get(int l,int r,int id)
	{
		return (Hash[id][r]-Hash[id][l-1]*tmp[r-l+1]%p+p)%p;	
	}
}ha[2];
char s[MAX];
void go()
{
	int n,i,q,x,y,len,ans;
	ll tmp;
	while(~scanf("%d",&n))
	{
		assert(n>=1&&n<=100000);
		scanf(" %[a-z]",s+1);
		assert(strlen(s+1)==n);
		ha[0].set(233333,1e9+7);
		ha[1].set(19260817,998244353);
		for(i=0;i<2;i++) ha[i].work(s,n);
		scanf("%d",&q);
		assert(q>=1&&q<=100000);
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&len);
			assert(len>=1);
			assert(x>=1&&x+len-1<=n);
			assert(y>=1&&y+len-1<=n);
			vector<int> res;
			ans=INF;
			tmp=ha[0].get(y,y+len-1,0);
			for(i=0;i<26;i++) if(ha[0].get(x,x+len-1,i)==tmp) res.pb(i);
			tmp=ha[1].get(y,y+len-1,0);
			for(i=0;i<sz(res);i++)
			{
				if(ha[1].get(x,x+len-1,res[i])==tmp)
				{
					ans=min(ans,res[i]);
					ans=min(ans,26-res[i]);
				}
			}
			if(ans==INF) ans=-1;
			printf("%d\n",ans);
		}
	}
}