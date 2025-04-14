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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var s=" "+readstring()
	var n=s.length-1
	var sum=Array(n+1){IntArray(3){0}}
	for(i in 1..n)
	{
		if(s[i]=='B') sum[i][0]++
		else if(s[i]=='S') sum[i][1]++
		else sum[i][2]++
		for(j in 0..2) sum[i][j]+=sum[i-1][j]
	}
	var q=readint()
	while(q-->0)
	{
		var tmp_line=readline_int()
		var l=tmp_line[0]
		var r=tmp_line[1]
		var res=mutableListOf<Int>()
		res.add(sum[r][0]-sum[l-1][0])
		res.add(sum[r][1]-sum[l-1][1])
		res.add(sum[r][2]-sum[l-1][2])
		res.sort()
		println("${res[0]+res[2]}")
	}
}

