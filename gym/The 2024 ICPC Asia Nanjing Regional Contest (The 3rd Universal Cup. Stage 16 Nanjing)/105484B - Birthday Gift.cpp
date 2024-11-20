#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt[3],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			if(!(i&1))
			{
				if(s[i]!='2') s[i]^=1;
			}
			cnt[s[i]-'0']++;
		}
		ans=abs(cnt[0]-cnt[1]);
		if(ans>=cnt[2]) ans-=cnt[2];
		else
		{
			ans=cnt[2]-ans;
			ans&=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
char s[MAX],tmp[MAX];
int cnt[MAX],vis[MAX];
int main()
{
	int T,n,i,j,tot,cnt2,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=0;i<=n;i++) cnt[i]=vis[i]=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(tot && tmp[tot]==s[i] && s[i]!='2') tot--;
			else tmp[++tot]=s[i];
		}
		for(i=1;i<=tot;i++) s[i]=tmp[i];
		n=tot;
		tot=cnt2=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='2')
			{
				cnt2++;
				continue;
			}
			if(cnt2==0)
			{
				tmp[++tot]=s[i];
				continue;
			}
		begin:;
			if(tot)
			{
				if(((cnt2&1) && s[i]==tmp[tot]) ||
				   ((!(cnt2&1)) && s[i]!=tmp[tot]))
				{
					while(tot && cnt2>0)
					{
						if(tmp[tot]!='2')
						{
							cnt2--;
							tot--;
						}
						else
						{
							cnt2+=cnt[tot];
							cnt[tot]=0;
							tot--;
							goto begin;
						}
					}
					if(tot) tmp[++tot]=s[i];
					else
					{
						if(cnt2>0) cnt2--;
						else tmp[++tot]=s[i];
					}
				}
				else
				{
					tmp[++tot]='2';
					cnt[tot]=cnt2;
					cnt2=0;
					tmp[++tot]=s[i];
				}
			}
			else
			{
				if(cnt2>0) cnt2--;
				else tmp[++tot]=s[i];
			}
		}
		n=0;
		for(i=1;i<=tot;i++)
		{
			if(tmp[i]=='2')
			{
				while(cnt[i]>0)
				{
					cnt[i]--;
					s[++n]='2';
				}
			}
			else s[++n]=tmp[i];
		}
		s[n+1]='\0';
//		puts(s+1);
		while(cnt2--) s[++n]='2';
		if(n && s[1]=='2')
		{
			tot=cnt2=0;
			for(i=1;i<=n;i++)
			{
				if(s[i]=='2') cnt2++;
				else
				{
					if(cnt2==0)
					{
						tot=0;
						for(j=i;j<=n;j++) tmp[++tot]=s[j];
						for(i=1;i<=tot;i++) s[i]=tmp[i];
						n=tot;
						break;
					}
					else cnt2--;
				}
			}
			if(cnt2)
			{
				printf("%d\n",cnt2&1);
				continue;
			}
		}
		if(n && s[n]=='2')
		{
			reverse(s+1,s+1+n);
			tot=cnt2=0;
			for(i=1;i<=n;i++)
			{
				if(s[i]=='2') cnt2++;
				else
				{
					if(cnt2==0)
					{
						tot=0;
						for(j=i;j<=n;j++) tmp[++tot]=s[j];
						for(i=1;i<=tot;i++) s[i]=tmp[i];
						n=tot;
						reverse(s+1,s+1+n);
						break;
					}
					else cnt2--;
				}
			}
			if(cnt2)
			{
				printf("%d\n",cnt2&1);
				continue;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(s[i]=='2')
			{
				if(i-1==n-i)
				{
					puts("1");
					goto end;
				}
				else if(i-1<n-i)
				{
					vis[1]++;
					vis[i+1+(i-1)+1]--;
				}
				else
				{
					vis[i-1-(n-i)]++;
					vis[n+1]--;
				}
			}
		}
		for(i=1;i<=n;i++) vis[i]+=vis[i-1];
		ans=0;
		for(i=1;i<=n;i++) ans+=(vis[i]==0);
		printf("%d\n",ans);
end:;
	}
	return 0;
}
*/
/*
5
0110101
01020102
0000021111
1012121010
0100202010

0122210101
01222101201
01021221010
4
1
3
*/
