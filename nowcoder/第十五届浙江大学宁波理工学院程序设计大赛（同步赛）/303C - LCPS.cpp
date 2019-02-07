#include <bits/stdc++.h>
using namespace std;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
	//	freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Palindrome_Tree
{
	int len[MAX],next[MAX][26],fail[MAX],last,s[MAX],tot,n;
	int l[MAX];
	bool flag[MAX];
	int newnode(int l)
	{
		mem(next[tot],0);
		fail[tot]=0; 
		len[tot]=l;
		return tot++;
	}
	void init()
	{
		tot=n=last=0;
		newnode(0);
		newnode(-1);
		s[0]=-1;
		fail[0]=1;
	}
	int get_fail(int x)
	{
		while(s[n-len[x]-1]!=s[n]) x=fail[x];
		return x;
	}
	void add(int t,int p)//attention the type of t is int
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!next[now][t])
		{
			id=newnode(len[now]+2);
			l[id]=p-len[id]+1;
			fail[id]=next[get_fail(fail[now])][t];
			next[now][t]=id;
		}
		last=next[now][t];
	}
	int work(char *str,int Len,VI &a,VI &b)
	{
		int i,id,now,mx,t;
		n=now=0;
		s[0]=-1;
		mx=0;
		a.clear();
		b.clear();
		flag[0]=flag[1]=1;
		for(i=2;i<=tot;i++) flag[i]=0;
		for(i=1;i<=Len;i++)
		{
			t=str[i]-'a';
			s[++n]=t;
			while(now!=1&&(!next[now][t]||s[n-len[now]-1]!=s[n])) now=fail[now];
			if(next[now][t])
			{
				id=next[now][t];
				if(len[id]>mx)
				{
					mx=len[id];
					flag[id]=1;
					a.clear();
					a.pb(l[id]);
					b.clear();
					b.pb(i-mx+1);
				}
				else if(len[id]==mx&&!flag[id])
				{
					flag[id]=1;
					a.pb(l[id]);
					b.pb(i-mx+1);
				}
				now=next[now][t];
			}
			else now=0;
		}
		return mx;
	}
}pam; //pam.init(); 
char a[MAX],b[MAX];
void brute_force(int n);
void go()
{
	int t,n,i,ans,pos;
	ll sum_n=0;
	scanf("%d",&t);
	assert(t<=40);
	while(t--)
	{
		scanf("%d",&n);
		assert(n>=1&&n<=500000);
		sum_n+=n;
		scanf("%s",a+1);
		scanf("%s",b+1);
		assert(strlen(a+1)==n);
		assert(strlen(b+1)==n);
	//	brute_force(n);
		pam.init();
		string c;
		c=" ";
		for(i=1;i<=n;i++)
		{
			assert(a[i]>='a'&&a[i]<='z');
			assert(b[i]>='a'&&b[i]<='z');
			pam.add(a[i]-'a',i);
			c+=a[i];
		}
		VI res[2];
		ans=pam.work(b,n,res[0],res[1]);
		assert(sz(res[0])==sz(res[1]));
		if(ans==0)
		{
			puts("0");
			continue;
		}
		string now,tmp;
		now=c.substr(res[0][0],ans);
		pos=0;
		for(i=1;i<sz(res[0]);i++)
		{
			tmp=c.substr(res[0][i],ans);
			if(tmp<now)
			{
				now=tmp;
				pos=i;
			}
		}
		printf("%d\n",ans);
		printf("%d %d\n",res[0][pos],res[0][pos]+ans-1);
		printf("%d %d\n",res[1][pos],res[1][pos]+ans-1);
	/*	sort(all(res[0]));
		sort(all(res[1]));
		debug(ans)
		debug(res[0])
		debug(res[1])*/
	}
	assert(sum_n<=2000000);
	debug(sum_n)
}


void brute_force(int n)
{
	debug("brute_force")
	int i,j,mx;
	string s1,s2,t1,t2;
	t1=t2=" ";
	t1+=a+1;
	t2+=b+1;
	for(mx=n;mx;mx--)
	{
		map<string,int> mp;
		VI res[2];
		for(i=1;i+mx-1<=n;i++)
		{
			s1=t1.substr(i,mx);
			s2=s1;
			reverse(all(s2));
			if(s1==s2&&!mp.count(s1)) mp[s1]=i;
		}
		for(i=1;i+mx-1<=n;i++)
		{
			s1=t2.substr(i,mx);
			s2=s1;
			reverse(all(s2));
			if(s1==s2&&mp.count(s1)&&mp[s1]!=-1)
			{
				res[0].pb(mp[s1]);
				res[1].pb(i);
				mp[s1]=-1;
			}
		}
		if(sz(res[0]))
		{
			
			int ans=mx,pos;
			string now,tmp;
			now=t1.substr(res[0][0],ans);
			pos=0;
			for(i=1;i<sz(res[0]);i++)
			{
				tmp=t1.substr(res[0][i],ans);
				if(tmp<now)
				{
					now=tmp;
					pos=i;
				}
			}
			printf("%d\n",ans);
			printf("%d %d\n",res[0][pos],res[0][pos]+ans-1);
			printf("%d %d\n",res[1][pos],res[1][pos]+ans-1);
	/*		debug(t1.substr(res[0][pos],ans))
			debug(t2.substr(res[1][pos],ans))
			sort(all(res[0]));
			sort(all(res[1]));
			debug(mx)
			debug(res[0])
			debug(res[1])*/
			return;
		}
	}
	puts("0");
}