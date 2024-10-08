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
	var T=readint()
	require(T>=1 && T<=1e5)
	while(T-->0)
	{
		var tmp_line=readline_ll()
		require(tmp_line.size==4)
		var a=tmp_line[0]
		var b=tmp_line[1]
		var x=tmp_line[2]
		var y=tmp_line[3]
		require(a>=1 && a<=1e9)
		require(b>=1 && b<=1e9)
		require(x>=1 && x<=1e9)
		require(y>=1 && y<=1e9)
		if(x<y) println("${x*a+y*b}")
		else println("${(a+b)*y}")
	}
}

