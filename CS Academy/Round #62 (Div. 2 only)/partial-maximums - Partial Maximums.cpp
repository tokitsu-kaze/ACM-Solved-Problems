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
const ll mod=1e9+7;
int a[MAX];  
int main()  
{
	int n,i,ans,max1,max2,pos;
	while(~scanf("%d",&n))  
	{  
		max1=max2=0;
		ans=0;
		set<int> s;
		map<int,int> mp,cnt;
		for(i=1;i<=n;i++)  
		{  
			mp[a[i]]=i;
			scanf("%d",&a[i]);
			if(*s.lower_bound(a[i])==INF) ans++;
			if(max1<a[i]) max2=max1,max1=a[i],cnt[a[i]]--;  
			else if(max2<a[i]) cnt[max1]++,max2=a[i];
		}  
		pos=1; 
		for(i=2;i<=n;i++)  
		{  
			if(cnt[a[pos]]<cnt[a[i]]) pos=i;  
		}
		s.insert(INF);
	//	cout<<pos<<endl;
		for(i=1;i<=n;i++)  
		{
			if(i==pos) continue;
			if(*s.lower_bound(a[i])==INF) ans++;
			s.insert(a[i]);
		}
		printf("%d\n",ans);  
	}  
	return 0;  
}  