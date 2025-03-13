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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
fun cal(n:Int):Long
{
	return 1L*n*(n+1)*(n+1)/2-1L*n*(n+1)/2*(2*n+1)/3
}
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e5)
	while(T-->0)
	{
		var m=readll()
		require(m>=1 && m<=1e18)
		var l=1
		var r=2e6.toInt()
		while(l<r)
		{
			var mid=(l+r) shr 1
			if(cal(mid+1)<=m) l=mid+1
			else r=mid
		}
		println("${l+1}")
	}
}

