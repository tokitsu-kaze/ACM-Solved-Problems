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
const val MAX=1e6.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=2 && n<=1000)
	var a=readline_int()
	require(a.size==n)
	var cnt=IntArray(MAX){0}
	for(it in a)
	{
		require(it>=1 && it<=1e6)
		cnt[it]++
	}
	var s=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
	var vis=IntArray(MAX){0}
	for(i in 1..MAX-1)
	{
		if(cnt[i]>0) s.add(Pair(cnt[i],i))
	}
	for(i in 0..n-1)
	{
		s.remove(Pair(cnt[a[i]],a[i]))
		cnt[a[i]]--
		a[i]++
		cnt[a[i]]++
		s.add(Pair(cnt[a[i]],a[i]))
		for(j in 0..n-1)
		{
			if(i==j) continue
			s.remove(Pair(cnt[a[j]],a[j]))
			cnt[a[j]]--
			a[j]--
			cnt[a[j]]++
			s.add(Pair(cnt[a[j]],a[j]))
			
			vis[s.last().second]=1
			
			s.remove(Pair(cnt[a[j]],a[j]))
			cnt[a[j]]--
			a[j]++
			cnt[a[j]]++
			s.add(Pair(cnt[a[j]],a[j]))
		}
		s.remove(Pair(cnt[a[i]],a[i]))
		cnt[a[i]]--
		a[i]--
		cnt[a[i]]++
		s.add(Pair(cnt[a[i]],a[i]))
	}
	var res=mutableListOf<Int>()
	for(i in 0..MAX-1)
	{
		if(vis[i]==1) res.add(i)
	}
	println(res.joinToString(" "))
}
