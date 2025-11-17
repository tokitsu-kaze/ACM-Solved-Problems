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
fun ck(a:Long,b:Long,c:Long):Int
{
	var res=mutableListOf<Long>()
	res.add(a)
	res.add(b)
	res.add(c)
	res.sort()
	if(res[0]+res[1]>res[2]) return 1
	return 0
}
fun go()
{
	var tmp_line=readline_ll()
	require(tmp_line.size==3)
	var a=tmp_line[0]
	var b=tmp_line[1]
	var c=tmp_line[2]
	require(a>=1 && a<=2e9)
	require(b>=1 && b<=2e9)
	require(c>=1 && c<=2e9)
	var ra=ck(a,b,c)
	var rb=ck(a*2,b,c) or ck(a,b*2,c) or ck(a,b,c*2)
	if(rb==1) println("Yes");
	else println("No")
}

