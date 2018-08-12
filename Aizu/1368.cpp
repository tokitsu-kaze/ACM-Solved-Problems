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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int mp[11][11],cnt;
void cale(char *s)
{
	int i,temp=0;
	for(i=0;i<4;i++)
	{
		temp=mp[temp][s[i]-'0'];
	}
	s[4]=temp+'0';
	s[5]='\0';
}
bool check(char *s)
{
	int i,temp=0;
	for(i=0;i<5;i++)
	{
		temp=mp[temp][s[i]-'0'];
	}
	if(temp==0) return 0;
	return 1;
}
void solve(char *s)
{
	int i,j;
	char temp;
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			if(s[i]==j+'0') continue;
			temp=s[i];
			s[i]=j+'0';
			if(check(s)==0)
			{
				cnt++;
				return;
			}
			s[i]=temp;
		}
	}
	for(i=0;i<4;i++)
	{
		if(s[i]==s[i+1]) continue;
		swap(s[i],s[i+1]);
		if(check(s)==0)
		{
			cnt++;
			return;
		}
		swap(s[i],s[i+1]);
	}
}
int main()
{
	int i,j;
	char s[11];
	while(~scanf("%d",&mp[0][0]))
	{
		for(i=1;i<10;i++) scanf("%d",&mp[0][i]);
		for(i=1;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		cnt=0;
		for(i=0;i<=9999;i++)
		{
			sprintf(s,"%04d",i);
			cale(s);
			solve(s);
		}
		printf("%d\n",cnt);
	}
	return 0;
}