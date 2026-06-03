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
fun lower_bound_pos(a:LongArray,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
fun go()
{
	var tmp_line=readline_int()
	var n=tmp_line[0]
	var q=tmp_line[1]
	var a=readline_int()
	var x=readline_ll()
	var sum=LongArray(n)
	sum[0]=1L
	for(i in 1..n-1)
	{
		if(a[i]==a[i-1]) sum[i]=sum[i-1]+2
		else sum[i]=sum[i-1]+abs(a[i]-a[i-1])
	}
//	println(sum.joinToString(" "))
	var ans=mutableListOf<Int>()
	for(it in x)
	{
		var pos=lower_bound_pos(sum,it)
		if(pos==n) ans.add(-1)
		else
		{
			if(sum[pos]==it) ans.add(a[pos])
			else
			{
				if(a[pos-1]==a[pos]) ans.add(0)
				else
				{
					var tmp=sum[pos]-it
					if(a[pos-1]<a[pos]) ans.add(a[pos]-tmp.toInt())
					else ans.add(a[pos]+tmp.toInt())
				}
			}
		}
	}
	println(ans.joinToString(" "))
}
/*
4 3 2 1 0/2 1 2 3 4 5 6 7 8 9
a:   4 1 1 5 9
sum: 1 4 6 10 14

7 16
4 3 2 1 1 5 9
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

a:   4 3 2 1 1 5 9
sum: 1 2 3 4 6 10 14
*/
