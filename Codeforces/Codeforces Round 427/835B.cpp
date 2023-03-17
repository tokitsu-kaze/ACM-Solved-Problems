#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[MAX];
int main()
{
	int k,i,ans,len,s;
	while(~scanf("%d",&k))
	{
		scanf("%s",a);
		len=strlen(a);
		sort(a,a+len);
		s=0;
		for(i=0;i<len;i++)
		{
			s+=a[i]-'0';
		}
		
		ans=0;
		i=0;
		while(s<k)
		{
			s+=(9-(a[i]-'0'));
			ans++;
			i++;
		}
	//	cout<<s<<endl;
		printf("%d\n",ans);
	}
	return 0;
}