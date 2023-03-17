#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
char ans[MAX];
int flag[MAX];
int main()
{
	int n,t,i,cnt[2];
	string a,b;
	while(~scanf("%d%d",&n,&t))
	{
		cin>>a>>b;
		mem(ans,0);
		mem(flag,0);
		int tmp=n-t;//ÏàÍ¬µÄ 
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			{
				if(tmp>0) ans[i]=a[i],tmp--;
				else
				{
					ans[i]='a';
					while(ans[i]==a[i]) ans[i]++;
				}
				flag[i]=1;
			}
		}
		cnt[0]=cnt[1]=tmp;
		for(i=0;i<n;i++)
		{
			if(flag[i]) continue;
			if(cnt[0]>0)
			{
				cnt[0]--;
				ans[i]=a[i];
				continue;
			}
			if(cnt[1]>0)
			{
				cnt[1]--;
				ans[i]=b[i];
				continue;
			}
			ans[i]='a';
			while(ans[i]==a[i]||ans[i]==b[i]) ans[i]++;
		}
		if(cnt[0]||cnt[1])
		{
			puts("-1");
			continue;
		}
		ans[n]='\0';
		puts(ans);
	}
	return 0;
}