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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	var a=readline_int()
	require(a.size==n)
	for(i in 0..n-1)
	{
		require(a[i]>=0 && a[i]<=2e9)
		if(i>0) require(a[i]>a[i-1])
	}
	if(n==1) println("-1")
	else if(n%2==0) println("${n/2}")
	else println("${(n-3)/2+2}")
}

