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
const val MAX=1e6.toInt()+10
/*------------------------------------------------------------*/
var l=IntArray(1)
var r=IntArray(1)
var bit=IntArray(1)
var ans=0
var n=0
fun dfs(x:Int)
{
	if(x<0)
	{
		var a=IntArray(bit.size)
		a[0]=0
		for(i in 1..n)
		{
			a[i]=a[i-1]+bit[i]
			if(a[i]<=1) return
		}
		ans++
		return
	}
	bit[l[x]]++
	bit[r[x]+1]--
	dfs(x-1)
	bit[l[x]]--
	bit[r[x]+1]++
	dfs(x-1)
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=2 && n<=1e5)
	require(m>=1 && m<=10)
	l=IntArray(m)
	r=IntArray(m)
	for(i in 0..m-1)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		l[i]=tmp_line[0]
		r[i]=tmp_line[1]
		require(l[i]>=1 && l[i]<=n-1)
		require(r[i]>=l[i]+1 && r[i]<=n)
	}
	bit=IntArray(n+5)
	ans=0
	dfs(m-1)
	println("${ans}")
}

