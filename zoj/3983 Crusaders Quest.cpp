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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int flag[5];
void solve(int &ans,int now,char *a)
{
	char temp[15];
	int i,j;
	ans=0;
	mem(temp,0);
	while(1)
	{
		int tag=0;
		a[now]='\0';
		for(i=0;i<now-2;i++)
		{
			if(a[i]==a[i+1]&&a[i+1]==a[i+2])
			{
				if(a[i]=='g') flag[1]=1;
				else if(a[i]=='a') flag[2]=1;
				else flag[3]=1;
				tag=1;
				ans++;
				now=0;
				for(j=0;j<i;j++) temp[now++]=a[j];
				strcat(temp,a+i+3);
				strcpy(a,temp);
				now=strlen(a);
				mem(temp,0);
				break;
			}
		}
		if(!tag) break;
	}
}
int work(char x,char *a)
{
	int cnt=0,i,res;
	char temp[15];
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=x) temp[cnt++]=a[i];
	}
	temp[cnt]='\0';
	solve(res,cnt,temp);
	return res;
}
int main()
{
	int t,i,ans;
	char a[15];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		mem(flag,0);
		solve(ans,9,a);
		if(flag[1]+flag[2]+flag[3]==1) ans++;
		else if(flag[1]+flag[2]+flag[3]==0) ans+=max(work('g',a),max(work('a',a),work('o',a)));
		printf("%d\n",ans==0?1:ans);
	}
	return 0;
}
/*
100
ggagaoaoo
*/