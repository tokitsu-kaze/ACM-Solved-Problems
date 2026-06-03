import java.util.*
import kotlin.math.*
import kotlin.random.Random

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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var k=readint()
		var tmp_line=readline_int()
		var a1=tmp_line[0]
		var b1=tmp_line[1]
		tmp_line=readline_int()
		var a2=tmp_line[0]
		var b2=tmp_line[1]
		var a=a1+a2
		var b=b1+b2
		var ok=false
		if(b+k<a) ok=true
		if(b+k==a)
		{
			var cnt=0
			if(a1>b1) cnt++
			else if(a1<b1) cnt--
			if(a2>b2) cnt++
			else if(a2<b2) cnt--
			if(cnt>0) ok=true
		}
		if(ok) println("NO")
		else println("YES")
	}
}
