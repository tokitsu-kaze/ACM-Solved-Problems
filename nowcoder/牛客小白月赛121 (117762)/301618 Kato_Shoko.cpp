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
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(1<=n && n<=1e5)
	var s=readstring()
	require(s.length==n)
	var tmp="Kato_Shoko"
	var cnt=IntArray(256){0}
	for(it in tmp) cnt[it.toInt()]++
	for(it in s)
	{
		require(('a'<=it && it<='z')||
				('A'<=it && it<='Z')||
				('0'<=it && it<='9')||
				it=='_')
		cnt[it.toInt()]--
	}
	var ok=true
	for(it in tmp)
	{
		if(cnt[it.toInt()]>0) ok=false
	}
	if(ok) println("YES ${n-tmp.length}")
	else println("NO")
}

