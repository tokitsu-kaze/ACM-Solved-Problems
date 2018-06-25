////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-30 11:20:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5198
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	int len,i,flag;
	char s[111],a[111],b[111],c[111];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		if(len%3)
		{
			puts("NO");
			continue;
		}
		strcpy(a,s);
		strcpy(b,s+len/3);
		strcpy(c,s+len/3*2);
		a[len/3]='\0';
		b[len/3]='\0';
	/*	puts(a);
		puts(b);
		puts(c);*/
		flag=0;
		for(i=0;i<len/3-1;i++)
		{
			if(a[i]!=a[i+1]) flag=1;
			if(b[i]!=b[i+1]) flag=1;
			if(c[i]!=c[i+1]) flag=1;
		}
		if(strcmp(a,b)==0||strcmp(a,c)==0||strcmp(b,c)==0||flag) puts("NO");
		else puts("YES");
	}
	return 0;
}