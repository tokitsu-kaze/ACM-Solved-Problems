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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
var a=IntArray(7)
fun cal(x:Int):Int
{
	var cnt=0
	a[3]=x
	for(i in 1..3)
	{
		if(a[i]+a[i+1]==a[i+2]) cnt++
	}
	return cnt
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		a[1]=tmp_line[0]
		a[2]=tmp_line[1]
		a[4]=tmp_line[2]
		a[5]=tmp_line[3]
		println("${max(cal(a[1]+a[2]),cal(a[5]-a[4]))}")
	}
}
