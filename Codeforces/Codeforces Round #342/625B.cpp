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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
int pos[MAX],cnt;
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
void KMP(char *a,char *b,int lena,int lenb)
{
	int i,j,next[MAX];
	getnext(b,next,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==lenb)
		{
			pos[cnt++]=i-j;
		}
		if(j==-1||a[i]==b[j])
		{
			i++;
			j++;
		}
		else j=next[j];
	}
	if(j==lenb) pos[cnt++]=i-j;
}
int main()
{
	int i,j,lena,lenb,ans;
	char a[MAX],b[33];
	while(~scanf("%s%s",a,b))
	{
		mem(pos,0);
		cnt=0;
		ans=0;
		lena=strlen(a);
		lenb=strlen(b);
		KMP(a,b,lena,lenb);
	//	cout<<cnt<<endl;
		for(i=0,j=0;i<cnt&&j<cnt;)
		{
			int temp=pos[i]+lenb-1;
			while(pos[j]<=temp&&j<cnt) j++;
	//		cout<<j<<endl;
			ans++;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
ssss
ss
sirisiri
sir
google
apple
intellect
tell
*/