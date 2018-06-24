////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 19:11:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1867
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2456KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
void getnext(char *b,int *next,int len)
{
	int i,j;
	i=0;
	j=next[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j])
		{
			i++;
			j++;
			if(b[i]!=b[j]) next[i]=j;
			else next[i]=next[j];
		}
		else j=next[j];
	}
}
int KMP(char *a,char *b,int lena,int lenb)
{
	int i,j,next[MAX];
	getnext(b,next,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==-1||(j<lenb&&a[i]==b[j]))
		{
			i++;
			j++;
		}
		else j=next[j];
	}
	return j==-1?0:j;
}
int main()
{
	int lena,lenb,sufa,sufb;
	char a[MAX],b[MAX],c[MAX],d[MAX];
	while(~scanf("%s%s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		sufa=KMP(a,b,lena,lenb);
		sufb=KMP(b,a,lenb,lena);
//		cout<<sufa<<" "<<sufb<<endl;
		if(sufa>sufb) printf("%s%s\n",a,b+sufa);
		else if(sufa<sufb) printf("%s%s\n",b,a+sufb);
		else
		{
			strcpy(c,a);
			strcat(c,b+sufa);
			strcpy(d,b);
			strcat(d,a+sufb);
			if(strcmp(c,d)<0) puts(c);
			else puts(d);
		}
	}
	return 0;
}