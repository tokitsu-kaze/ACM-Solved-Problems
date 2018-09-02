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
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
bool check(string ans,char *a,char *b,int p,int la,int lb)
{
	int len,i;
	char temp[111];
	len=0;
	for(i=0;i<ans.length();i++) temp[len++]=ans[i];
	temp[len++]=a[p];
	for(i=la-1;i>=0;i--)
	{
		if(a[i]>='0'&&a[i]<='9'&&i!=p) temp[len++]=a[i];
	}
	temp[len]='\0';
	return strcmp(temp,b)>=0;
}
int main()
{
	int i,j,lena,lenb,p;
	char a[111],b[111],t;
	while(~scanf("%s%s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		sort(a,a+lena);
		if(lena>lenb)
		{
			if(a[0]=='0')
			{
				t='9'+1;
				for(i=0;i<lena;i++)
				{
					if(a[i]!='0'&&a[i]<t)
					{
						t=a[i];
						p=i;
					}
				}
				swap(a[0],a[p]);
			}
			puts(a);
		}
		else
		{
			string ans="";
			for(i=0;i<lenb;i++)
			{
				int flag=0;
				for(j=0;j<lena;j++)
				{
					if(a[j]==b[i])
					{
						if(check(ans,a,b,j,lena,lenb))
						{
							ans+=a[j];
							a[j]='#';
							flag=1;
						}	
						break;
					}
				}
				if(!flag)
				{
					t='9'+1;
					for(j=0;j<lena;j++)
					{
						if(a[j]>b[i]&&a[j]<t&&a[j]!='#')
						{
							t=a[j];
							p=j;
						}
					}
					ans+=a[p];
					a[p]='#';
					vector<char> res;
					for(j=0;j<lena;j++)
					{
						if(a[j]!='#')
						{
							res.pb(a[j]);
						}
					}
					sort(all(res));
					for(j=0;j<sz(res);j++)
					{
						ans+=res[j];
					}
					goto end;
				}
			}
			end:;
			cout<<ans<<"\n";
		}
	}
	return 0;
}