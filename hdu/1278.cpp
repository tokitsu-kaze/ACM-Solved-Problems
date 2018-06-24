////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-12 20:52:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1278
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1720KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=6e5+10;
const ll mod=1e9+7;
char mp[210][210];
int m,n,i,j,k;
int row,col;
char str[210];
int s1[210],s2[210],s3[210],s4[210],s5[210];
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		row=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&s1[i]);
			row+=s1[i];
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&s2[i]);
			row+=s2[i];
		}
		for(i=0;i<n;i++) scanf("%d",&s3[i]);
		for(i=0;i<n;i++) scanf("%d",&s4[i]);
		for(i=0,k=0;i<n;i++)
		{
			for(j=0;j<s4[i];j++) s5[k++]=s3[i];
		}
		col=k;
		mem(mp,0);
		mem(str,0);
		for(i=0,k=0;i<m;i++)
		{
			for(j=0;j<s1[i];j++) str[k++]='1';
			for(j=0;j<s2[i];j++) str[k++]='0';
		}
		for(i=row-1;i>=0;i--) mp[i][0]=str[row-1-i];
		for(i=0;i<col;i++)
		{
			for(j=0;j<row;j++) mp[j][i+1]=mp[(j+s5[i]+row)%row][i];
		}
		int flag=0;
		for(i=0;i<row;i++)
		{
			if(mp[i][0]!=mp[i][col])
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("Can not make beautilful cloth !");
		else
		{
			for(i=0;i<row;i++)
			{
				mp[i][col]='\0';
				puts(mp[i]);
			}
		}
	}
	return 0;
}