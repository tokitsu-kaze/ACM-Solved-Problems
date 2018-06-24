////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-07 19:43:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4414
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,k,ans,cnt[4];
	char mp[55][55];
	while(~scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==0||j==0||i==n-1||j==n-1) continue;
				if(mp[i][j]=='#')
				{
					mem(cnt,0);
					int flag=0;
					k=i-1;
					while(k>=0)
					{
						if(mp[k][j]=='#');
						else break;
						if(mp[k][j-1]=='#'||mp[k][j+1]=='#') goto end;
						if(flag==0) flag++;
						k--;
						cnt[0]++;
					}
					k=i+1;
					while(k<n)
					{
						if(mp[k][j]=='#');
						else break;
						if(mp[k][j-1]=='#'||mp[k][j+1]=='#') goto end;
						if(flag==1) flag++;
						k++;
						cnt[1]++;
					}
					k=j-1;
					while(k>=0)
					{
						if(mp[i][k]=='#');
						else break;
						if(mp[i-1][k]=='#'||mp[i+1][k]=='#') goto end;
						if(flag==2) flag++;
						k--;
						cnt[2]++;
					}
					k=j+1;
					while(k<n)
					{
						if(mp[i][k]=='#');
						else break;
						if(mp[i-1][k]=='#'||mp[i+1][k]=='#') goto end;
						if(flag==3) flag++;
						k++;
						cnt[3]++;
					}
					if(flag==4&&cnt[0]==cnt[1]&&cnt[0]==cnt[2]&&cnt[0]==cnt[3]) ans++;
				}
				end:;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}