////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-27 12:31:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2100
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int i,lena,lenb,res[222],flag,len;
	char a[222],b[222];
	while(~scanf("%s%s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		reverse(a,a+lena);
		reverse(b,b+lenb);
		while(lena>1&&a[lena-1]=='A') lena--;
		while(lenb>1&&b[lenb-1]=='A') lenb--;
		flag=0;
		a[lena]='\0';
		b[lenb]='\0';
		for(i=0;i<min(lena,lenb);i++)
		{
			res[i]=a[i]-'A'+b[i]-'A'+flag;
			flag=res[i]/26;
			res[i]%=26;
			len=i+1;
		}
		for(i=min(lena,lenb);i<max(lena,lenb);i++)
		{
			if(i<lena) res[i]=a[i]-'A'+flag;
			if(i<lenb) res[i]=b[i]-'A'+flag;
			flag=res[i]/26;
			res[i]%=26;
			len=i+1;
		}
		if(flag) res[len++]=flag;
		reverse(res,res+len);
		for(i=0;i<len;i++) putchar(res[i]+'A');
		puts("");
	}
	return 0;
}