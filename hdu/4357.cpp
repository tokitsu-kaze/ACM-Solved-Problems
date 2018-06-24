////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-20 16:01:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4357
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	int t,i,len,cas=1,s1,s2;
	char a[66],b[66];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		printf("Case #%d: ",cas++);
		if(strcmp(a,b)==0)
		{
			puts("YES");
			continue;
		}
		len=strlen(a);
		if(len==1)
		{
			puts("NO");
			continue;
		}
		else if(len==2)
		{
			int flag=0;
			for(i=0;i<=26;i++)
			{
				swap(a[0],a[1]);
				if(a[0]=='z') a[0]='a';
				else a[0]++;
				if(a[1]=='z') a[1]='a';
				else a[1]++;
				if(strcmp(a,b)==0)
				{
					flag=1;
					break;
				}
			}
			if(flag) puts("YES");
			else puts("NO");
			continue;
		}
		s1=s2=0;
		for(i=0;i<len;i++)
		{
			s1+=a[i]-'0';
			s2+=b[i]-'0';
		}
		if(abs(s1-s2)%2==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
