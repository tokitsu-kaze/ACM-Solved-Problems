#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const int mod=1e9+7;
int ans;
void work(int x,int y,string s)
{
	string tmp=s;
	int i,j,len,res=0;
	len=tmp.length();
	for(i=len-1;i>=0;i--)
	{
		if(i==len-1&&tmp[i]-'0'==y) break;
		if(tmp[i]-'0'==y)
		{
			for(j=i+1;j<len;j++)
			{
				swap(tmp[j],tmp[j-1]);
				res++;
			}
			break;
		}
	}
	for(i=len-2;i>=0;i--)
	{
		if(i==len-2&&tmp[i]-'0'==x) break;
		if(tmp[i]-'0'==x)
		{
			for(j=i+1;j<len-1;j++)
			{
				swap(tmp[j],tmp[j-1]);
				res++;
			}
			break;
		}
	}
	i=0;
	while(i<len&&tmp[i]=='0') i++,res++;
	while(i) swap(tmp[i],tmp[i-1]),i--;
	ll t;
	sscanf(tmp.c_str(),"%lld",&t);
//	cout<<t<<" "<<res<<endl;
	if(t%25==0) ans=min(ans,res);
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s[0]=='0'&&s.length()==1)
		{
			puts("0");
			continue;
		}
		ans=INF;
		work(0,0,s);
		work(2,5,s);
		work(5,0,s);
		work(7,5,s);
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}