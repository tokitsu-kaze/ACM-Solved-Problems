////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-17 19:14:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
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
const double eps=1e-4;
const int MAX=(1L<<20)+10;
const ll mod=1e9+7;
int main()
{
	int i,j,k,len;
	char a[5111];
/*	mem(a,0);
	for(i=0;i<4096;i++) a[i]='s';*/
	while(gets(a))
	{
		len=strlen(a);
		j=0;
		for(i=0;i<len;i++)
		{
			if(j%16==0)
			{
				if(j) printf(" ");
				for(k=j-16;k<j;k++)
				{
					if(k<0) continue;
					if(a[k]>='a'&&a[k]<='z') putchar(a[k]-'a'+'A');
					else if(a[k]>='A'&&a[k]<='Z') putchar(a[k]-'A'+'a');
					else putchar(a[k]);
				}
				if(j) puts("");
				printf("%04x:",j);
			}
			if(j%2==0) printf(" ");
			printf("%2x",a[i]);
			++j;
		}
		while(j%16)
		{
			if(j%2==0) printf(" ");
			printf("  ");
			j++;
		}
		printf(" ");
		for(k=j-16;k<len;k++)
		{
			if(k<0) continue;
			if(a[k]>='a'&&a[k]<='z') putchar(a[k]-'a'+'A');
			else if(a[k]>='A'&&a[k]<='Z') putchar(a[k]-'A'+'a');
			else putchar(a[k]);
		}
		puts("");
	}
	return 0;
}