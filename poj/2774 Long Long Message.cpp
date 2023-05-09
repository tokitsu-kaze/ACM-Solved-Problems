#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct SA
{
	int s[MAX],n,SZ;
	int c[MAX],rk[MAX],tp[MAX];
	void init(char *ss) //s[1..n]
	{
		SZ=0;
		n=strlen(ss+1);
		for(int i=1;i<=n;i++)
		{
			s[i]=ss[i];
			SZ=max(SZ,s[i]);
		}
	}
	void get_sa(int *sa,int *height)
	{
		int m,i,j,k,now;
		m=SZ;
		for(i=1;i<=m;i++) c[i]=0;
		for(i=1;i<=n;i++) c[rk[i]=s[i]]++;
		for(i=2;i<=m;i++) c[i]+=c[i-1]; 
		for(i=n;i;i--) sa[c[rk[i]]--]=i; 
		for(k=1;k<=n;k<<=1)
		{
			now=0;
			for(i=n-k+1;i<=n;i++) tp[++now]=i;
			for(i=1;i<=n;i++)
			{
				if(sa[i]>k) tp[++now]=sa[i]-k;
			}
			for(i=1;i<=m;i++) c[i]=0;
			for(i=1;i<=n;i++) c[rk[i]]++;
			for(i=2;i<=m;i++) c[i]+=c[i-1];
			for(i=n;i;i--)
			{
				sa[c[rk[tp[i]]]--]=tp[i];
				tp[i]=0;
			}
			swap(rk,tp);
			rk[sa[1]]=1;
			now=1;
			for(i=2;i<=n;i++)
			{
				if(!(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+k]==tp[sa[i-1]+k])) now++;
				rk[sa[i]]=now;
			}
			if(now==n) break;
			m=now;
		}
		height[1]=0;
		k=0;
		for(i=1;i<=n;i++)  
		{
			if(rk[i]==1) continue;
			if(k) k--;
			j=sa[rk[i]-1];
			while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]) k++;
			height[rk[i]]=k;
		}
	}
}da;
char s[MAX],a[MAX],b[MAX];
int sa[MAX],h[MAX];
void go()
{
	int lena,lenb,i,ans;
	while(~scanf("%s",a+1))
	{
		scanf("%s",b+1);
		lena=strlen(a+1);
		lenb=strlen(b+1);
		for(i=1;i<=lena;i++) s[i]=a[i];
		s[lena+1]='$';
		for(i=1;i<=lenb;i++) s[i+lena+1]=b[i];
		s[lena+lenb+2]='\0';
		da.init(s);
		da.get_sa(sa,h);
		ans=0;
		for(i=2;i<=lena+lenb+1;i++)
		{
			if((sa[i]>=lena+1&&sa[i-1]<=lena)||(sa[i]<=lena&&sa[i-1]>=lena+1)) ans=max(ans,h[i]);
		}
		printf("%d\n",ans);
	}
}
