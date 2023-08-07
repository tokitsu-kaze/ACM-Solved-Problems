////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-04 20:50:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4930
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1712KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
string res[2][11];
void change(string &a)
{
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='3'&&a[i]<='9') a[i]=a[i]-'3'+'A';
		else if(a[i]=='T') a[i]='H';
		else if(a[i]=='J') a[i]='I';
		else if(a[i]=='Q') a[i]='J';
		else if(a[i]=='K') a[i]='K';
		else if(a[i]=='A') a[i]='L';
		else if(a[i]=='2') a[i]='M';
		else if(a[i]=='X') a[i]='N';
		else if(a[i]=='Y') a[i]='O';
	}
}
void work(string a,int f)
{
	int cnt[33],i;
	//1
	res[f][1]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i])
		{
			res[f][1]=string(1,i+'A');
			break;
		}
	}
	//2
	res[f][2]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=2)
		{
			res[f][2]=string(2,i+'A');
			break;
		}
	}
	//3
	res[f][3]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=3)
		{
			res[f][3]=string(3,i+'A');
			break;
		}
	}
	//4
	res[f][4]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=3)
		{
			cnt[i]=0;
			res[f][4]=string(3,i+'A');
			break;
		}
	}
	if(res[f][4].length()==3)
	{
		for(i=14;~i;i--)
		{
			if(cnt[i])
			{
				res[f][4]+=string(1,i+'A');
				break;
			}
		}
	}
	if(res[f][4].length()!=4) res[f][4]="";
	//5
	res[f][5]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=3)
		{
			cnt[i]=0;
			res[f][5]=string(3,i+'A');
			break;
		}
	}
	if(res[f][5].length()==3)
	{
		for(i=14;~i;i--)
		{
			if(cnt[i]>=2)
			{
				res[f][5]+=string(2,i+'A');
				break;
			}
		}
	}
	if(res[f][5].length()!=5) res[f][5]="";
	//6
	res[f][6]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=4)
		{
			cnt[i]=0;
			res[f][6]=string(4,i+'A');
			break;
		}
	}
	if(res[f][6].length()==4)
	{
		for(i=14;~i;i--)
		{
			if(cnt[i]>=2)
			{
				res[f][6]+=string(2,i+'A');
				break;
			}
		}
	}
	if(res[f][6].length()!=6) res[f][6]="";
	//7
	res[f][7]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	for(i=14;~i;i--)
	{
		if(cnt[i]>=4)
		{
			cnt[i]=0;
			res[f][7]=string(4,i+'A');
			break;
		}
	}
	//8
	res[f][8]="";
	mem(cnt,0);
	for(i=0;i<a.length();i++) cnt[a[i]-'A']++;
	if(cnt['N'-'A']&&cnt['O'-'A']) res[f][8]="XY";
}
//3456789TJQKA2XY
//ABCDEFGHIJKLMNO
int main()
{
	int t,i;
	scanf("%d",&t);
	string a,b,tmp;
	while(t--)
	{
		cin>>a>>b;
		change(a);
		change(b);
		work(a,0);
		work(b,1);
		sort(all(a));
		for(i=1;i<=8;i++)
		{
			tmp=res[0][i];
			sort(all(tmp));
			if(tmp==a)
			{
				puts("Yes");
				goto end;
			}
		}
		if(res[0][8].length()!=0)
		{
			puts("Yes");
			goto end;
		}
		if(res[1][8].length()!=0)
		{
			puts("No");
			goto end;
		}
		if(res[0][7].length()!=0)
		{
			if(res[1][7].length()!=0)
			{
				if(res[0][7]>res[1][7]) puts("Yes");
				else puts("No");
			}
			else puts("Yes");
			goto end;
		}
		else
		{
			if(res[1][7].length()!=0)
			{
				puts("No");
				goto end;
			}
		}
		
		for(i=1;i<=6;i++)
		{
			if(res[0][i].length()&&res[0][i]>=res[1][i])
			{
				puts("Yes");
				goto end;
			}
		}
		puts("No");
		end:;
	}
	return 0;
}
/*
100
33A
2
33A
22
33
22
5559T
9993
3333556
444488
*/