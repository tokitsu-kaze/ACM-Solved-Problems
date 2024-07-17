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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	var s=readstring()
	require(s.length==n)
	var cnt0=0
	var cnt1=0
	for(it in s)
	{
		if(it=='0') cnt0++
		else if(it=='1') cnt1++
		else require(false)
	}
	if(cnt0==n||cnt1==n) println("0")
	else if(cnt0==cnt1)
	{
		if(n==2) println("-1")
		else println("2")
	}
	else println("1")
}

