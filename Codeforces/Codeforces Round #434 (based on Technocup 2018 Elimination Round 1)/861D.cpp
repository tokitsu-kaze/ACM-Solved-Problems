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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[70010][11];
map<string,int> mp;
int main()
{
	int n,i,j,k,flag,cnt;
	char s[11];
	while(~scanf("%d",&n))
	{
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			set<string> st;
			set<string> ::iterator it;
			for(j=0;j<9;j++)
			{
				cnt=0;
				for(k=j;k<9;k++)
				{
					s[cnt++]=a[i][k];
					s[cnt]='\0';
					st.insert(s);
				}
			}
			for(it=st.begin();it!=st.end();it++)
			{
				mp[*it]++;
			}
		}
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=1;j<=9;j++)
			{
				if(flag) break;
				for(k=0;k<9;k++)
				{
					if(k+j-1>=9) break;
					strcpy(s,a[i]+k);
					s[j]='\0';
	//				puts(s);
					if(mp[s]==1)
					{
						puts(s);
						flag=1;
						break;
					}
				}
			}
		}
	}
	return 0;
}