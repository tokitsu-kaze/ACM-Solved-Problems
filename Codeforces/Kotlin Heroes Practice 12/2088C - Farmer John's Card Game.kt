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
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var mp=Array(n){IntArray(m)}
		for(i in 0..n-1) mp[i]=readline_int().sorted().toIntArray()
		var ok=1
		var p=IntArray(n){0}
		for(i in 0..n-1)
		{
			if(mp[i][0]>=n)
			{
				ok=0
				break
			}
			else p[mp[i][0]]=i
		}
		if(ok==0)
		{
			println("-1")
			continue
		}
		for(j in 0..m-1)
		{
			for(i in 1..n-1)
			{
				if(mp[p[i-1]][j]>mp[p[i]][j]) ok=0
			}
		}
		if(ok==1)
		{
			for(i in 0..n-1) p[i]++
			println(p.joinToString(" "))
		}
		else println("-1")
	}
}
