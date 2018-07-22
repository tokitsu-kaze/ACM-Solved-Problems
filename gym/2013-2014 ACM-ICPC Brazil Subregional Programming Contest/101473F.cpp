#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int d[MAX],dis[MAX];
map<int,int> mp;
int main()
{
	int n,i,j,s,now,ans,pre;
	while(~scanf("%d",&n))
	{
		s=0;
		mp.clear();
		mem(dis,0); 
		for(i=0;i<n;i++)
		{
			scanf("%d",&d[i]);
			s+=d[i];
			if(i==0) dis[i]=d[i];
			else dis[i]=dis[i-1]+d[i];
		}
		if(s%3)
		{
			puts("0");
			continue;
		}
		s/=3;
		ans=0;
		now=0;
		pre=0;
		for(i=0,j=0;i<n;i++)
		{
			while(1)
			{
				if(now==s)
				{
					if(mp[dis[j-1==-1?n-1:j-1]%(3*s)]&&mp[(dis[j-1==-1?n-1:j-1]+s)%(3*s)])
					{
	//					cout<<dis[i-1]<<" "<<dis[j-1==-1?n-1:j-1]<<" "<<(dis[j-1==-1?n-1:j-1]+s)%(3*s)<<endl;
						mp[dis[j-1==-1?n-1:j-1]%(3*s)]--;
						mp[(dis[j-1==-1?n-1:j-1]+s)%(3*s)]--;
						ans++;
					}
					else
					{
						mp[dis[i-1==-1?n-1:i-1]%(3*s)]++;
						mp[dis[j-1==-1?n-1:j-1]%(3*s)]++;
					}
					break;
				}
				now+=d[j];
				j++;
				j%=n;
				if(now>s)
				{
					j--;
					now-=d[j];
					break;
				}
			}
			now-=d[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}