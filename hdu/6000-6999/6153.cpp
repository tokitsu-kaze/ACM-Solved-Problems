////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-19 17:33:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6153
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:15344KB
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int Next[MAX];
ll ans[MAX];
void getnext(char *b,int *Next,int len)
{
	int i,j;
	i=0;
	j=Next[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j])
		{
			i++;
			j++;
			if(b[i]!=b[j]) Next[i]=j;
			else Next[i]=Next[j];
		}
		else j=Next[j];
	}
}
void KMP(char *a,char *b,int lena,int lenb)
{
	int i,j,temp;
	getnext(b,Next,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==-1||a[i]==b[j])
		{
			if(j!=-1) ans[j]++;
			i++;
			j++;
		}
		else j=Next[j];
	}
}
int main()
{
	int t,lena,lenb,i;
	ll res,temp;
	char a[MAX],b[MAX];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",a,b);
		
		mem(ans,0);
		lena=strlen(a);
		lenb=strlen(b);
		reverse(a,a+lena);
		reverse(b,b+lenb);
		KMP(a,b,strlen(a),lenb);
		res=0;
		temp=-1;
		for(i=lenb-1;i>=0;i--)
		{
			if(Next[i]==-1)
			{
				if(temp!=-1) ans[i]+=temp;
				temp=ans[i];
			}
		}
		for(i=0;i<lenb;i++)
		{
			res+=ans[i]*(i+1);
			res%=mod;
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
100
aaaaa
aab
aaaaa
aaa
aaaaa
aa
abababab
aba

*/