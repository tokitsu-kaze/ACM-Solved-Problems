#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],x[MAX],flag[MAX];
int main()
{
	int n,m,i,add,cnt;
	char op[MAX];
	while(~scanf("%d%d",&n,&m))
	{
		add=0;
		mem(a,0);
		mem(b,0);
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			getchar();
			scanf("%c%d",&op[i],&x[i]);
			if(op[i]=='+')
			{
				add++;
				a[x[i]]++;
			}
			else b[x[i]]++;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			int temp=add-a[i]+b[i];
			if(n-temp==m)
			{
				cnt++;
				flag[i]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(op[i]=='+')
			{
				if(!flag[x[i]]) puts("Lie");
				else if(flag[x[i]]&&cnt==1) puts("Truth");
				else puts("Not defined");
			}
			else if(op[i]=='-')
			{
				if(!flag[x[i]]) puts("Truth");
				else if(flag[x[i]]&&cnt==1) puts("Lie");
				else puts("Not defined");
			}
		}
	}
	return 0;
}