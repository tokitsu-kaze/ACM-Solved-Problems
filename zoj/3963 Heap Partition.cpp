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
vector<int> res[MAX];
int v[MAX],pos[MAX],cnt[MAX];
int main()
{
	int t,now,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			res[i].clear();
			pos[i]=-1;
			cnt[i]=0;
		}
		now=0;
		set<PII> s;
		s.insert(MP(-INF,-INF));
		set<PII> ::iterator it;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			it=s.upper_bound(MP(v[i],INF));
			it--;
	//		cout<<(*it).fi<<" "<<(*it).se<<endl;
			if((*it).fi==-INF)
			{
				res[++now].pb(i);
				s.insert(MP(v[i],i));
				pos[i]=now;
			}
			else
			{
				int p=pos[(*it).se];
				res[p].pb(i);
				pos[i]=p;
				s.insert(MP(v[i],i));
				cnt[(*it).se]++;
				if(cnt[(*it).se]==2) s.erase(*it);
			}
		}
		printf("%d\n",now);
		for(i=1;i<=now;i++)
		{
			printf("%d",sz(res[i]));
			for(j=0;j<sz(res[i]);j++) printf(" %d",res[i][j]);
			puts("");
		}
	}
	return 0;
}