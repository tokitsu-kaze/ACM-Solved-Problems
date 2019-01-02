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
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	char s[11];
	friend bool operator<(node a,node b)
	{
		if(a.s[0]==b.s[0])
		{
			if(a.s[1]==b.s[1]) return a.s[2]<b.s[2];
			return a.s[1]<b.s[1];
		}
		return a.s[0]<b.s[0];
	}
}a[133];
bool cmp(char a,char b){return a>b;}
int tot;
void init()
{
	int i;
	tot=0;
	for(i=0;i<1000;i+=8)
	{
		sprintf(a[tot++].s,"%03d",i);
		sort(a[tot-1].s,a[tot-1].s+3,cmp);
		a[tot-1].s[3]='\0';
//		puts(a[tot-1].s);
	}
	sort(a,a+tot);
}
void go()
{
	int t;
	int len,i,j,bit[11],pos,x;
	char s[1111],temp[11],ans[11];
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		mem(bit,0);
		len=strlen(s);
		if(len<=3)
		{
			int res=-1;
			sort(s,s+len);
			do
			{
				x=atoi(s);
				if(x%8==0) res=x;
			}
			while(next_permutation(s,s+len));
			printf("%d\n",res);
			continue;
		}
		for(i=0;i<len;i++)
		{
			bit[s[i]-'0']++;
		}
		if(bit[0]>=3)
		{
			for(i=9;i>=0;i--)
			{
				while(bit[i]>0)
				{
					bit[i]--;
					printf("%d",i);
				}
			}
			puts("");
			continue;
		}
		pos=-1;
		for(i=0;i<tot;i++)
		{
			int tag=0;
			for(j=0;j<3;j++) bit[a[i].s[j]-'0']--;
			for(j=0;j<3;j++)
			{
				if(bit[a[i].s[j]-'0']<0) tag=1;
				bit[a[i].s[j]-'0']++;
			}
			if(!tag)
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
		{
			puts("-1");
			continue;
		}
		strcpy(temp,a[pos].s);
		sort(temp,temp+3);
		temp[3]='\0';
		for(i=0;i<3;i++) bit[temp[i]-'0']--;
		for(i=9;i>=0;i--)
		{
			while(bit[i]--)
			{
				printf("%d",i);
			}
		}
		do
		{
			x=atoi(temp);
			if(x%8==0) strcpy(ans,temp);
		}
		while(next_permutation(temp,temp+3));
		ans[3]='\0';
		puts(ans);
	}
}