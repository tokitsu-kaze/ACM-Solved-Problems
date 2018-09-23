#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#include<iostream>  
using namespace std;
typedef long long ll;  
const ll mod=1e9+7;
ll dp[2222][4444];  
int m;  
void dfs(int s,int ss,int x,int n) {  
    if(x>m-1) {
        dp[n+1][ss]+=dp[n][s];  
        dp[n+1][ss]%=mod;
        return;  
    }  
    if(s&(1<<x)) {
        dfs(s,ss,x+1,n);  
        return;  
    }  
    dfs(s,ss|(1<<x),x+1,n);
    if(x<=m-2&&!(s&(1<<(x+1)))) { 
        dfs(s,ss,x+2,n);
    }  
    return;  
}  
int main()  
{  
    int n;  
    while(~scanf("%d%d",&n,&m)) {  
        if(m==0||n==0||(m*n)&1) {  
            printf("0\n");  
            continue;  
        }  
        if(m==1||n==1) {  
            if(n==1) {  
                printf("%d\n",m&1?0:1);  
                continue;  
            }  
            if(m==1) {  
                printf("%d\n",n&1?0:1);  
                continue;  
            }  
        }  
    //    if(n<m) swap(n,m);  
        memset(dp,0,sizeof dp);  
        dp[0][0]=1;  
        for(int i=0;i<n;i++)  
            for(int j=0;j<(1<<m);j++)  {  
                if(dp[i][j]) {  
                    dfs(j,0,0,i);  
                }  
            }  
        printf("%lld\n",dp[n][0]%mod);  
    }  
    return 0;  
} 