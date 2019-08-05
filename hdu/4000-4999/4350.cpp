////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-20 15:30:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4350
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1688KB
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
	int t,n,l,r,i,j,a[55],pos[55],temp[55],len,k,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		for(i=1;i<=52;i++)
		{
			scanf("%d",&a[i]);
			pos[i]=i;
		}
		scanf("%d%d%d",&n,&l,&r);
		len=r-l+1;
		n%=r;
		for(j=1;j<=n;j++)
		{
			for(i=l;i<=r;i++)
			{
				temp[i]=pos[i];
			}
			for(i=r,k=1;i>=len;i--,k++)
			{
				pos[i]=pos[l-k];
			}
			for(i=1;i<=len;i++)
			{
				pos[i]=temp[l-1+i];
			}
/*			cout<<j<<endl;
			for(i=1;i<=52;i++)
			{
				cout<<a[pos[i]]<<" ";
			}
			puts("\n");*/
		}
		printf("Case #%d:",cas++);
		for(i=1;i<=52;i++)
		{
			printf(" %d",a[pos[i]]);
		}
		puts("");
	}
	return 0;
}
/*
1
13 2 10 50 1 28 37 32 30 46 19 47 33 41 24 52 27 42 49 18 9 48 23 35 31 8 7 12 6 5 3 22 43 36 51 40 26 4 44 
17 39 38 15 14 25 16 29 20 21 45 11 34
104 31 52
*/