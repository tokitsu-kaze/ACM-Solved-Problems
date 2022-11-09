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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,k,ans,mp[111][111],x,op;
	while(~scanf("%d%d%d",&n,&m,&x))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		ans=op=0;
		for(j=1;j<=m;j++)
		{
			int res=0,p=0,t=0;
			for(i=1;i<=n;i++)
			{
				if(mp[i][j])
				{
					int temp=0;
					for(k=i;k<=i+x-1&&k<=n;k++)
					{
						if(mp[k][j]) temp++;
					}
					if(temp>res)
					{
						res=temp;
						p=t;
					}
					t++;
				}
			}
			ans+=res;
			op+=p;
		}
		printf("%d %d\n",ans,op);
	}
	return 0;
}