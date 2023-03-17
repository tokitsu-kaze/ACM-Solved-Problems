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
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
char ans[MAX];
void go()
{
	int n,x,y,i;
	char op[22];
	x=y=1;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cout<<"? "<<x+1<<" "<<y<<" "<<n<<" "<<n<<endl;
		cin>>op;
		if(op[0]=='Y')
		{
			x++;
			ans[i]='D';
		}
		else
		{
			y++;
			ans[i]='R';
		}
	}
	x=y=n;
	for(i=2*n-3;i>=n-1;i--)
	{
		cout<<"? "<<1<<" "<<1<<" "<<x<<" "<<y-1<<endl;
		cin>>op;
		if(op[0]=='Y')
		{
			y--;
			ans[i]='R';
		}
		else
		{
			x--;
			ans[i]='D';
		}
	}
	ans[2*n-2]='\0';
	cout<<"! "<<ans<<"\n";
}