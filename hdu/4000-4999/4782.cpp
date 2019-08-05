////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 20:03:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4782
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1856KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,cnt=0,cas=1;
	string last,ans,temp;
	scanf("%d",&n);
	while(cnt++<n)
	{
		ans="";
		while(1)
		{
			getline(cin,temp,'\n');
			temp=last+temp;
			ans=ans+' '+temp;
			int l=temp.length();
			int fl=ans.length();
			bool f=true;
			for(i=0;i<=l-7;i++)
			{
				if(temp.substr(i,7)=="</html>")
				{
					last=temp.substr(i+7,l-(i+7));
					ans=ans.substr(0,fl-(l-(i+7)));
					f=false;
					break;
				}
			}
			if(!f)break;
		}
		int l=ans.length(),dep=0;
		printf("Case #%d:\n",cas++);
		for(i=0;i<l;)
		{
			if(ans[i]=='<')
			{
				if(ans[i+1]!='/')dep++;
				while(ans[i]!='>'&&i<l)
				{
					printf("%c",ans[i]);
					i++;
				}
				if(ans[i-1]=='/') dep--;
				printf("%c\n",ans[i++]);
				while(ans[i]==' ') i++;
				if(ans[i]=='<'&&ans[i+1]=='/') dep--;
				for(j=0;j<dep;j++)
				{
					printf(" ");
				}
			}
			else
			{
				bool fs=false;
				int pre=1;
				while(ans[i]!='<'&&i<l)
				{
					if(ans[i]=='\t') ans[i]=' ';
					if(ans[i]==' ')
					{
						while(ans[i]==' ')
						{
							i++;
							if(ans[i]=='\t')ans[i]=' ';
						}
						i--;
					}
					if(ans[i]==' '&&(ans[i+1]=='<'||pre))
					{
						i++;
						continue;
					}
					pre=0;
					printf("%c",ans[i]);
					fs=true;
					i++;
				}
				if(fs) printf("\n");
				if(ans[i]=='<'&&ans[i+1]=='/') dep--;
				if(fs)
				{
					for(int j=0;j<dep;j++)
					{
						printf(" ");
					}
				}
			}
		}
	}
	return 0;
}
