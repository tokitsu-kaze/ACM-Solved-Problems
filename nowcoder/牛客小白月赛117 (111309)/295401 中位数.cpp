import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=1610612741//1e9.toInt()+7
/*------------------------------------------------------------*/
fun qpow(aa:Long,bb:Long,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1L) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
const val mod_phi=mod-1
var comb=Array(6002){IntArray(6002)}
fun init_comb(n:Int,m:Int)
{
	comb[0][0]=1;
	for(i in 1..n)
	{
		comb[i][0]=1;
		for(j in 1..m)
		{
			var tmp=0L+comb[i-1][j]+comb[i-1][j-1];
			if(tmp>=mod_phi) tmp-=mod_phi;
			comb[i][j]=tmp.toInt()
		}
	}
}
fun C(n:Int,m:Int):Int
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=6e3)
	init_comb(n,n)
	var fac=LongArray(n+1){0}
	fac[0]=1
	for(i in 1..n) fac[i]=fac[i-1]*i%mod_phi
	var ans=1L
	for(i in 1..n)
	{
		var k=0L
		for(j in 1..n)
		{
			k=(k+fac[j]*fac[n-j+1]%mod_phi*C(i-1,j/2)%mod_phi*C(n-i,(j+1)/2-1))%mod_phi
		}
		ans=(ans*qpow(i.toLong(),k,mod))%mod
	}
	println("${ans}")
}

