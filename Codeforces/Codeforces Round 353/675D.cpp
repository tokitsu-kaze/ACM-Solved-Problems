#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,x,t;
	while(~scanf("%d",&n))
	{
		scanf("%d",&x);
		set<int> s;
		set<int> ::iterator it1,it2;
		map<int,int> mp;
		s.insert(x);
		s.insert(-INF);
		s.insert(INF);
		vector<int> ans;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
			it1=s.find(x);
			it2=it1;
			it1--;
			it2++;
			t=0;
			if(*it1==-INF) t=1;
			else if(*it2==INF) t=0;
			else
			{
				if(!(mp[*it1]&2)) t=0;
				else if(!(mp[*it2]&1)) t=1;
			}
			if(t==0)
			{
				ans.pb(*it1);
				if(x<*it1) mp[*it1]+=1;
				else mp[*it1]+=2;
			}
			else
			{
				ans.pb(*it2);
				if(x>*it2) mp[*it2]+=2;
				else mp[*it2]+=1;
			}
		}
		for(i=0;i<sz(ans);i++)
		{
			printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
		}
	}
	return 0;
}