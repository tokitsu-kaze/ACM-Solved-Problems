   #include <stdio.h>
#include <iostream>
using namespace std;
int B[251*251];
int J[251*251];
int H[251*251];
int Y[251*251];
int N[251*251];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char G[251][251];
        int n,m;
        scanf("%d %d",&n,&m);
        int count1=0,count2=0,count3=0,count4=0,count5=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",G[i]);
        }

        int sum=0;
        for(int i=0; i<m; i++)
        {

            for(int j=i+1; j<m; j++)
            {
                count1=0;
                count2=0;
                count3=0;
                count4=0;
                count5=0;
                for(int k=0; k<n; k++)
                {

                    if(G[k][i]==G[k][j]&&G[k][j]=='B')
                        count1++;
                    if(G[k][i]==G[k][j]&&G[k][j]=='J')
                        count2++;
                    if(G[k][i]==G[k][j]&&G[k][j]=='H')
                        count3++;
                    if(G[k][i]==G[k][j]&&G[k][j]=='Y')
                        count4++;
                    if(G[k][i]==G[k][j]&&G[k][j]=='N')
                        count5++;
                }sum+=count1*(count1-1)/2+count2*(count2-1)/2+count3*(count3-1)/2+count4*(count4-1)/2+count5*(count5-1)/2;
            }

        }

        cout<<sum<<endl;
    }
}