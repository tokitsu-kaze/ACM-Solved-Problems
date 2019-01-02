import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] cargs) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        BigInteger ans=new BigInteger("1");
        for(int i=0;i<n;i++)
            ans=ans.multiply(s.nextBigInteger());
        System.out.println(ans);
    }
 
}