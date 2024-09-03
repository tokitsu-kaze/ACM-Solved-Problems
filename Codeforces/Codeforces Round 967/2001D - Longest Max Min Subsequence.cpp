#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
int a[MAX],cnt[MAX],res[MAX],tot,sufcnt[MAX];
bool vis[MAX];
int main()
{
	int t,n,i,j,ans,now,pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=vis[i]=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]==1) ans++;
		}
		for(i=1;i<=n;i++) cnt[i]=0;
		now=0;
		for(i=n;i;i--)
		{
			cnt[a[i]]++;
			if(cnt[a[i]]==1) now++;
			if(now==ans)
			{
				pos=i;
				now--;
				break;
			}
		}
		set<int> s;
		for(i=1;i<=n;i++) cnt[i]=sufcnt[i]=0;
		for(i=pos+1;i<=n;i++) sufcnt[a[i]]++;
		for(i=1;i<=pos;i++)
		{
			if(!cnt[a[i]]) s.insert(a[i]);
			cnt[a[i]]++;
		}
		tot=0;
		i=1;
		j=pos+1;
//		cout<<i<<" "<<j<<endl;
		while(tot<ans)
		{
			if(tot&1) res[++tot]=*s.begin();
			else res[++tot]=*s.rbegin();
			s.erase(res[tot]);
			vis[res[tot]]=1;
			if(sufcnt[res[tot]]) now--;
			while(i<j&&a[i]!=res[tot])
			{
				cnt[a[i]]--;
				if(cnt[a[i]]==0) s.erase(a[i]);
				i++;
			}
			cnt[a[i]]--;
			i++;
			while(i<j&&tot+now<ans-1&&(vis[a[i]]||sufcnt[a[i]]))
			{
				cnt[a[i]]--;
				if(cnt[a[i]]==0) s.erase(a[i]);
				i++;
			}
			while(j<=n)
			{
				if(now+tot<=ans-1) break;
				if(!vis[a[j]]&&sufcnt[a[j]]==1) now--;
				sufcnt[a[j]]--;
				cnt[a[j]]++;
				if(cnt[a[j]]==1 && !vis[a[j]]) s.insert(a[j]);
				j++;
			}
//			cout<<i<<" "<<j<<" "<<tot<<endl;
//			cout<<"s: ";for(auto &it:s) cout<<it<<" ";puts("");
		}
		printf("%d\n",ans);
		for(i=1;i<=ans;i++) printf("%d%c",res[i]," \n"[i==ans]);
	}
	return 0;
}

