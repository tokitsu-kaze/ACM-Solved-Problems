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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun qpow(aa:Long,bb:Long,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1L)==1L) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e4)
	var sumlen=0
	while(T-->0)
	{
		var n=readll()
		require(n>=1 && n<=1e18)
		var s=readstring()
		for(it in s) require(it==s[0])
		var len=s.length
		require(len>=1 && len<=1e5)
		sumlen+=len
		require(sumlen<=2e5)
		var ans=qpow(2,n,mod)
		ans=qpow(ans,len.toLong(),mod)
		ans=(ans-1+mod)%mod
		println("${ans}")
	}
}
