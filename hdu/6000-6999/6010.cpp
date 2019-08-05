////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-11 19:49:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6010
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int judge(int y,int m,int d)
{
	int res;
	if(m==1||m==2) m+=12,y--;//1月2月当作前一年的13,14月
	if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3)) res=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
	else res=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return res+1;
}
int main()
{
	int t,y,m,d,h,mi,s,cas=1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-%d-%d %d:%d:%d",&y,&m,&d,&h,&mi,&s);
		printf("Case #%d: ",cas++);
		if(m>3&&m<11) puts("PDT");
		else if(m<3&&m>11) puts("PST");
		else
		{
	//		printf("%d\n",judge(y,m,d));
			int temp,cnt=0;
			temp=judge(y,m,1);
			for(i=1;;i++)
			{
				temp%=7;
				if(temp==0) cnt++;
				temp++;
				if(m==3&&cnt==2) break;
				if(m==11&&cnt==1) break;
			}
			if(i>d) m==3?puts("PDT"):puts("PST");
			else if(i<d) m==3?puts("PST"):puts("PDT");
			else
			{
				if(m==3)
				{
					if(h==2) puts("Neither");
					else if(h<2) puts("PST");
					else puts("PDT");
				}
				else
				{
					
					if(h>=1&&h<2) puts("Both");
					else if(h<1) puts("PDT");
					else puts("PST");
				}
			}
		}
	}
	return 0;
}
