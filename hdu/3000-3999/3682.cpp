////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 15:57:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3682
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:9800KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e9+10;
const ll mod=1e9+7;
bool flag[1010][1010][3];// xy,yz,xz
vector<int> v;
int main()
{
	int t,n,m,i,j,c,d,ans;
	char a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(flag,0);
		v.clear();
		ans=0;
		for(i=0;i<m;i++)
		{
			getchar();
			scanf("%c=%d,%c=%d",&a,&c,&b,&d);
			if(a>b) swap(a,b);
			for(j=1;j<=n;j++)
			{
				int temp=0;
				if(a=='X'&&b=='Y')
				{
					temp=c*n*n+d*n+j;
				}
				else if(a=='Y'&&b=='Z')
				{
					temp=j*n*n+c*n+d;
				}
				else if(a=='X'&&b=='Z')
				{
					temp=c*n*n+j*n+d;
				}
				v.pb(temp);
			}
		}
		sort(all(v));
		printf("%d\n",unique(all(v))-v.begin());
	} 
	return 0;
}
/*
2
3 3
Y=1,Z=3
X=3,Y=1
X=3,Z=3
*/