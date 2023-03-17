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
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int bit1[5010],bit2[5010],bit3[5010];
int main()
{
	int i,j,ans,a,b,len;
	char s[5010];
	while(~scanf("%s",s+1))
	{
		mem(bit1,0);
		mem(bit2,0);
		mem(bit3,0);
		len=strlen(s+1);
		a=b=0;
		for(i=1;i<=len;i++)
		{
			if(s[i]=='a') bit1[i]++;
			else bit3[i]++;
			bit1[i]+=bit1[i-1];
			bit3[i]+=bit3[i-1];
		}
		for(i=len;i>=1;i--)
		{
			if(s[i]=='a') bit2[i]++;
			bit2[i]+=bit2[i+1];
		}
		ans=0;
		for(i=1;i<=len;i++)
		{
			for(j=i+1;j<=len;j++)
			{
				ans=max(ans,bit1[i]+bit2[j]+bit3[j]-bit3[i-1]);
			}
			ans=max(ans,bit1[i]+bit2[i+1]);
			ans=max(ans,bit3[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}