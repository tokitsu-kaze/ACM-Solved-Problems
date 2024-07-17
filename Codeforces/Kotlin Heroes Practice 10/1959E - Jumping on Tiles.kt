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
	var t=readint()
	while(t-->0)
	{
		var s=readstring()
		var n=s.length
		var S=s[0]
		var T=s[n-1]
		if(S>T) S=T.also{T=S}
		var res=Array(26){mutableListOf<Int>()}
		for(i in 0..n-1)
		{
			if(s[i]>=S&&s[i]<=T) res[s[i]-'a'].add(i+1)
		}
		var ans=mutableListOf<Int>()
		if(s[0]==T)
		{
			for(i in T downTo S)
			{
				for(it in res[i-'a']) ans.add(it)
			}
		}
		else
		{
			for(i in S..T)
			{
				for(it in res[i-'a']) ans.add(it)
			}
		}
		println("${T-S} ${ans.size}")
		println(ans.joinToString(" "))
	}
}
