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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	char s[55],a[]="AKIHABARA";
	int len,i,j,flag;
	while(~scanf("%s",s))
	{
		len=strlen(s);
		j=0;
		flag=0;
		for(i=0;i<len;i++)
		{
			if(a[j]=='\0')
			{
				flag=1;
				break;
			}
			if(s[i]!=a[j])
			{
				if(a[j]=='A') j++;
				else
				{
					flag=1;
					break;
				}
				if(s[i]!=a[j])
				{
					flag=1;
					break;
				}
			}
			j++;
	//		cout<<i<<endl;
		}
		if(a[j]=='A') j++;
		if(!flag&&a[j]=='\0') puts("YES");
		else puts("NO");
	}
	return 0;
}

