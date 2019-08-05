////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-11 10:32:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1711
////Problem Title: 
////Run result: Accept
////Run time:1138MS
////Run memory:5680KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
void getnext(int *b,int *next1,int len)
{
	int i,j;
	i=0;
	j=next1[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j])
		{
			i++;
			j++;
			if(b[i]!=b[j]) next1[i]=j;
			else next1[i]=next1[j];
		}
		else j=next1[j];
	}
}
int next0[MAX];
int KMP(int *a,int *b,int lena,int lenb)
{
	int i,j;
	getnext(b,next0,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==-1||a[i]==b[j])
		{
			i++;
			j++;
		}
		else j=next0[j];
		if(j==lenb) return i-j+1;
	}
	return -1;
}
int a[MAX],b[MAX];
int main()
{
	int t,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		printf("%d\n",KMP(a,b,n,m));
	}
	return 0;
}
