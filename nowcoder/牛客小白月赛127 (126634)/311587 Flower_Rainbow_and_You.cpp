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
	var s=arrayOf("Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet")
	var st=TreeSet<Int>()
	var cnt=readline_int()
	require(cnt.size==7)
	var mx=-1
	var mxpos=0
	for(i in 0..6)
	{
		require(0<=cnt[i] && cnt[i]<=100)
		st.add(cnt[i])
		if(cnt[i]>mx)
		{
			mx=cnt[i]
			mxpos=i
		}
	}
	require(st.size==7)
	println(s[mxpos])
}

