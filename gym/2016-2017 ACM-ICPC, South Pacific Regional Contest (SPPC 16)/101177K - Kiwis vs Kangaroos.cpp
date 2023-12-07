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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	int a[333],b[333],i,ans1,ans2;
	string s1="KANGAROO",s2="KIWIBIRD";
	char s[111];
	mem(a,0);
	mem(b,0);
	for(i=0;i<s1.length();i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z') a[s1[i]-'A'+'a']++;
		else a[s1[i]]++;
	}
	for(i=0;i<s2.length();i++)
	{
		if(s2[i]>='A'&&s2[i]<='Z') b[s2[i]-'A'+'a']++;
		else b[s2[i]]++;
	}
	while(~scanf("%s",s))
	{
		ans1=ans2=0;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
			ans1+=a[s[i]];
			ans2+=b[s[i]];
		}
	//	cout<<ans1<<" "<<ans2<<endl;
		if(ans1>ans2) puts("Kangaroos");
		else if(ans1<ans2) puts("Kiwis");
		else puts("Feud continues");
	}
	return 0;
}