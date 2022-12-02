#include<bits/stdc++.h>
using namespace std;
int main(){
    long long *a=new long long;
    long long p=(long long&)a;
    mt19937 rng(p*time(0));
    for(int i=1;i<=10;i++)cout<<rng()%100001<<" ";
}
