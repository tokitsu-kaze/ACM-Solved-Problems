import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
		mid=(l+r) shr 1
		if(a[mid].toLong()>=target.toLong()) r=mid
		else l=mid+1
	}
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=1000)
	var res=mutableListOf<Int>()
	for(i in 1..n)
	{
		var tmp_line=readline_int()
		var h=tmp_line[0]
		var m=tmp_line[1]
		require(h>=3 && h<=23)
		require(m>=0 && m<=59)
		res.add(h*60+m-1)
		res.add(h*60+m-3)
		res.add(h*60+m-5)
	}
	res.sort()
	var ans=mutableListOf<Int>()
	for(i in 0..res.size-1)
	{
		if(i==0||res[i]!=res[i-1]) ans.add(res[i])
	}
	println(ans.size)
	for(it in ans) println("${it/60} ${it%60}")
}

