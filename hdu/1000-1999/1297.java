////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-06 00:11:00
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:13568KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
    public static void main (String[] args)
    {
        BigInteger f[];
        int i,n;
        f=new BigInteger[1010];
        f[0]=new BigInteger("1");
        f[1]=new BigInteger("1");
        f[2]=new BigInteger("2");
        f[3]=new BigInteger("4");
        for(i=4;i<=1000;i++)
        {
            f[i]=f[i-1].add(f[i-2].add(f[i-4]));
        }
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext())
        {
            n=cin.nextInt();
            System.out.println(f[n]);
        }
    }

}