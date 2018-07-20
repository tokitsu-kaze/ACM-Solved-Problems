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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
char s[MAX],a[MAX],b[MAX],res[MAX];
int main()
{
	int i,j,cnt[33],x[33],y[33],ans[2],tmp,maxx,tot,len;
	while(~scanf("%s%s%s",s,a,b))
	{
		mem(cnt,0);
		mem(x,0);
		mem(y,0);
		len=strlen(s);
		for(i=0;i<len;i++) cnt[s[i]-'a']++;
		len=strlen(a);
		for(i=0;i<len;i++) x[a[i]-'a']++;
		len=strlen(b);
		for(i=0;i<len;i++) y[b[i]-'a']++;
		mem(ans,0);
		maxx=INF;
		for(j=0;j<26;j++)
		{
			if(x[j]) maxx=min(maxx,cnt[j]/x[j]);
		}
		assert(maxx<=strlen(s));
	//	cout<<maxx<<endl;
		for(i=0;i<=maxx;i++)
		{
			tmp=INF;
			for(j=0;j<26;j++)
			{
				if(y[j]) tmp=min(tmp,(cnt[j]-i*x[j])/y[j]);
			}
			if(i+tmp>ans[0]+ans[1])
			{
				ans[0]=i;
				ans[1]=tmp;
			}
		}
	//	cout<<ans[0]+ans[1]<<endl;
		for(i=0;i<ans[0];i++) printf("%s",a);
		for(i=0;i<ans[1];i++) printf("%s",b);
		tot=0;
		for(j=0;j<26;j++)
		{
			cnt[j]-=x[j]*ans[0]+y[j]*ans[1];
			assert(cnt[j]>=0);
			while(cnt[j]--) res[tot++]=j+'a';
		}
		res[tot]='\0';
		puts(res);
	}
	return 0;
}