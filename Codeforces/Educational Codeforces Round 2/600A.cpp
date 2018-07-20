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
char s[MAX];
string a[MAX],b[MAX],temp;
int main()
{
	int i,len,cnt1,cnt2,flag;
	while(~scanf("%s",s))
	{
		len=strlen(s);
		cnt1=cnt2=0;
		temp.clear();
		flag=0;
		for(i=0;i<len;i++)
		{
			if(s[i]!=','&&s[i]!=';')
			{
				if(s[i]>='a'&&s[i]<='z') flag=1;
				else if(s[i]>='A'&&s[i]<='Z') flag=1;
				else if(s[i]=='.') flag=1;
				temp+=s[i];
			}
			else
			{
				if(sz(temp)==0) flag=1;
				else if(temp[0]=='0'&&sz(temp)>1) flag=1;
				if(flag) b[cnt2++]=temp;
				else a[cnt1++]=temp;
				temp.clear();
				flag=0;
			}
		}
		if(sz(temp)==0) flag=1;
		else if(temp[0]=='0'&&sz(temp)>1) flag=1;
		if(flag) b[cnt2++]=temp;
		else a[cnt1++]=temp;
		temp.clear();
		flag=0;
		if(cnt1)
		{
			printf("\"");
			for(i=0;i<cnt1;i++)
			{
				cout<<a[i];
				if(i!=cnt1-1) putchar(',');
			}
			printf("\"");
			puts("");
		}
		else puts("-");
		if(cnt2)
		{
			printf("\"");
			for(i=0;i<cnt2;i++)
			{
				cout<<b[i];
				if(i!=cnt2-1) putchar(',');
			}
			printf("\"");
			puts("");
		}
		else puts("-");
	}
	return 0;
}