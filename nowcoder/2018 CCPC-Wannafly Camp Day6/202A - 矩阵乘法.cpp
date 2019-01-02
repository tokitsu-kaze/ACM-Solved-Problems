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
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int a[4111][66],b[4111][11][266],res[4111][11];
void go()
{
	int n,p,m,i,j,k,l,len,ans,tmp;
	char s[66];
	while(~scanf("%d%d%d",&n,&p,&m))
	{
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			for(j=p-1;~j;j--)
			{
				scanf("%X",&a[i][j]);
			}
			for(l=0;l<8;l++)
			{
				for(j=0;j<256;j++)
				{
					for(k=0;k<8;k++)
					{
						if(j&(1<<k)) b[i][l][j]+=a[i][l*8+k];
					}
				}
			}
		}
		mem(res,0);
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			tmp=1;
			k=0;
			for(j=len-1;~j;j--)
			{
				if(s[j]=='1') res[i][k]+=tmp;
				if(tmp==128)
				{
					k++;
					tmp=1;
				}
				else tmp*=2;
			}
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				tmp=0;
				for(k=0;k<8;k++)
				{
					tmp+=b[i][k][res[j][k]];
				}
				ans^=tmp;
			}
		}
	/*	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				tmp=0;
				for(k=0;k<8;k++)
				{
					tmp+=b[i][k][res[j][k]];
				}
				printf("%d ",tmp);
			}
			puts("");
		}*/
		printf("%d\n",ans);
	}
}

