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
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,n,m,k,i,j,flag,temp;
	char a[51][51];
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m>>k;
			temp=k;
			if(n%2==0&&k&1)
			{
				puts("NO");
				continue;
			} 
			mem(a,'.');
			flag=0;
			for(i=0;i<n/2&&k;i++)
			{
				for(j=i%2;j<m&&k;j++)
				{
					if(j%2!=i%2) continue;
					if(k!=1&&i!=n-1-i&&i+1!=n-1-i)
					{
						a[i][j]=a[n-1-i][j]='*';
						flag=1;
					}
					else break;
					k-=2;
				}
			}
	//		cout<<k<<endl;
			if(k==1)
			{
				if(m==1)
				{
					if(n&1)
					{
						if(n/2+1<temp) puts("NO");
						else
						{
							a[n/2][0]='*';
							for(i=0;i<n;i++)
							{
								for(j=0;j<m;j++)
								{
									cout<<a[i][j];
								}
								puts("");
							}
							continue;
						}
					}
					else puts("NO");
				}
			}
			if(n&1)
			{
				if(flag)
				{
					for(i=n/2,j=i%2;j<m&&k;j++)
					{
						if(j%2!=i%2) continue;
						a[i][j]='*';
						k--;
					}
				}
				else
				{
					for(i=n/2,j=0;j<m&&k;j++)
					{
						if(j%2) continue;
						a[i][j]='*';
						k--;
					}
				}
			}
	//		cout<<k<<endl;
			if(k) puts("NO");
			else
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						cout<<a[i][j];
					}
					puts("");
				}
			}
		}
	}
	return 0;
}
/*
483
19 1 7
*/