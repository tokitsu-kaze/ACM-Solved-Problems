////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-28 18:32:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4731
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1784KB
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=2008;
char s[MAX];
int top;
int main()
{
	int t,i,x,n,cas=1,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&n);
		printf("Case #%d: ",cas++);
		if(x==1)
		{
			for(i=1;i<=n;i++)
			{
				putchar('a');
			}
			puts("");
		}
		else if(x==2)
		{
			if(n==1) puts("a");
			else if(n==2) puts("ab");
			else if(n==3) puts("aab");
			else if(n==4) puts("aabb");
			else if(n==5) puts("aaaba");
			else if(n==6) puts("aaabab");
			else if(n==7) puts("aaababb");
			else if(n==8) puts("aaababbb");
			else
			{
				strcpy(s,"aaaababb");
				n-=8;
				top=8;
				for(i=1;i<=n;i++)
				{
					if(i%6==5)
					{
						s[top-2]='b';
						s[top++]='b';
					}
					else if(i%6==0) s[top++]='b';
					else s[top++]='a';
				}
				s[top]='\0';
				puts(s);
			}
		}
		else
		{
			flag=0;
			for(i=1;i<=n;i++)
			{
				putchar('a'+flag);
				flag++;
				if(flag>=3) flag=0;
			}
			puts("");
		}
	}
	return 0;
}