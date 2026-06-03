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
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_ll()
		var n=tmp_line[0].toInt()
		var s=tmp_line[1]
		var x=tmp_line[2].toInt()
		var a=readline_int()
		var tmp=mutableListOf<Long>()
		var mp:MutableMap<Long,Int> = mutableMapOf()
		var now=0L
		var ans=0L
		tmp.add(now+s)
		for(i in 0..n-1)
		{
			now+=a[i]
			if(a[i]>x)
			{
				tmp.clear()
				mp.clear()
			}
			else if(a[i]==x)
			{
				for(it in tmp) mp[it]=(mp[it]?:0)+1
				tmp.clear()
			}
			ans+=mp[now]?:0
			tmp.add(now+s)
		}
		println("${ans}")
	}
}
