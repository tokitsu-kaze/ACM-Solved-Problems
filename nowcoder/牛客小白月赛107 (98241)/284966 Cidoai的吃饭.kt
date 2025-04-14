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
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==4)
	var n=tmp_line[0]
	var a=tmp_line[1]
	var b=tmp_line[2]
	var c=tmp_line[3]
	require(n>=1 && n<=1e6)
	require(a>=1 && a<=1e6)
	require(b>=1 && b<=1e6)
	require(c>=1 && c<=1e6)
	var ans=0
	while(true)
	{
		if(n>=a) n-=a
		else if(n>=b) n-=b
		else if(n>=c) n-=c
		else break
		ans++
	}
	println("${ans}")
}

