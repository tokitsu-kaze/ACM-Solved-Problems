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
const int MAX=2e5+10;
const ll mod=1e9+7;
int l[MAX],r[MAX],v[MAX],flag[MAX],len[MAX];
int main()
{
	int n,i,x,tot,pre,ll,rr,ans;
	while(~scanf("%d",&n))
	{
		pre=tot=0;
		set<PII > s;
		mem(len,0);
		ll=rr=1;
		scanf("%d",&pre);
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==pre) rr++;
			else
			{
				s.insert(MP(rr-ll+1,++tot));
				l[tot]=tot-1;
				r[tot]=tot+1;
				v[tot]=pre;
				len[tot]=rr-ll+1;
				ll=rr=i;
			}
			pre=x;
		}
		s.insert(MP(rr-ll+1,++tot));
		l[tot]=tot-1;
		r[tot]=tot+1;
		v[tot]=pre;
		len[tot]=rr-ll+1;
		set<PII > ::iterator it,del;
		ans=0;
		mem(flag,0);
		flag[0]=flag[tot+1]=1;
		while(sz(s))
		{
			it=s.end();
			it--;
			it=s.lower_bound(MP((*it).fi,-INF));
//			cout<<(*it).fi<<" "<<(*it).se<<endl;
			l[r[(*it).se]]=l[(*it).se];
			r[l[(*it).se]]=r[(*it).se];
			if(flag[l[(*it).se]]||flag[r[(*it).se]]);
			else if(v[l[(*it).se]]==v[r[(*it).se]])
			{
				r[l[(*it).se]]=r[r[(*it).se]];
				l[r[r[(*it).se]]]=l[(*it).se];
				s.erase(MP(len[l[(*it).se]],l[(*it).se]));
				s.erase(MP(len[r[(*it).se]],r[(*it).se]));
				s.insert(MP(len[l[(*it).se]]+len[r[(*it).se]],l[(*it).se]));
				len[l[(*it).se]]+=len[r[(*it).se]];
			}
			flag[(*it).se]=1;
			s.erase(it);
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}