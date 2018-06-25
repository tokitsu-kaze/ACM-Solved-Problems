////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-03 19:06:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6077
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1708KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
map<string,int> mp;
void init()
{
	mp["1111110"]=0;
	mp["0000110"]=1;
	mp["1011011"]=2;
	mp["1001111"]=3;
	mp["0100111"]=4;
	mp["1101101"]=5;
	mp["1111101"]=6;
	mp["1000110"]=7;
	mp["1111111"]=8;
	mp["1101111"]=9;
}
char a[22][22];
int change(int x)
{
	int cnt=0;
	char temp[11];
	temp[cnt++]=(a[0][x+1]=='X')+'0';
	temp[cnt++]=(a[1][x]=='X')+'0';
	temp[cnt++]=(a[4][x]=='X')+'0';
	temp[cnt++]=(a[6][x+1]=='X')+'0';
	temp[cnt++]=(a[4][x+3]=='X')+'0';
	temp[cnt++]=(a[1][x+3]=='X')+'0';
	temp[cnt++]=(a[3][x+1]=='X')+'0';
	temp[cnt]='\0';
//	cout<<temp<<endl;
	return mp[temp];
}
int main()
{
	int t,i;
	init();
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<7;i++)
		{
			scanf("%s",a[i]);
		}
		printf("%d%d:%d%d\n",change(0),change(5),change(12),change(17));
	}
	return 0;
}