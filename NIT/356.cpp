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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2000+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	ll t,i,len=2000;
	char a[2010];
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=5;
	printf("%lld\n",t);
	t--;
	for(i=0;i<len;i++) a[i]='a';
	a[len]='\0';
	puts(a);
	while(t--)
	{
		for(i=0;i<len;i++)
		{
			a[i]=rand()%26+'a';
		}
		a[len]='\0';
		puts(a);
	}
	return 0;
}
*/
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char a[2010];
	int i,j,len,t,res[33],now;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		len=strlen(a);
		ans=0;
		for(i=0;i<len;i++)
		{
			mem(res,0);
			now=0;
			for(j=i;j<len;j++)
			{
				now+=res[a[j]-'a'];
				res[a[j]-'a']++;
				ans=max(ans,now*1.0/(j-i+1));
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}