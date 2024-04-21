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
fun go()
{
	var t=readint()
	require(t>=1 && t<=500)
	var sumn=0
	var summ=0
	while(t-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(n>=1 && n<=5000)
		require(m>=2 && m<=5000)
		sumn+=n
		summ+=m
		require(sumn<=5000)
		require(summ<=5000)
		var a=readline_int()
		require(a.size==m)
		require(a[0]==1 && a[m-1]==1)
		var uppre=IntArray(n){1}
		var downpre=IntArray(n){1}
		for(i in 1..m-1)
		{
			require(a[i]>=1 && a[i]<=n)
			var updp=IntArray(n){0}
			var downdp=IntArray(n){0}
			if(a[i]==1)
			{
				for(j in 0..n-1)
				{
					if(downpre[j]==1)
					{
						updp[j]++
						if(j+a[i-1]<n) updp[j+a[i-1]]--
					}
					if(uppre[j]==1)
					{
						updp[j-a[i-1]+1]++
						if(j+1<n) updp[j+1]--
					}
				}
				for(j in 1..n-1) updp[j]+=updp[j-1]
				for(j in 0..n-1)
				{
					if(updp[j]>0) updp[j]=1
					downdp[j]=updp[j]
				}
			}
			else
			{
				for(j in 0..n-a[i])
				{
					downdp[j]=uppre[j]
					if(j-a[i-1]+1>=0) downdp[j]=downdp[j] or downpre[j-a[i-1]+1]
				}
				for(j in a[i]-1..n-1)
				{
					updp[j]=downpre[j]
					if(j+a[i-1]-1<n) updp[j]=updp[j] or uppre[j+a[i-1]-1]
				}
			}
			uppre=updp
			downpre=downdp
	/*		println("${i}")
			for(j in 0..n-1)
			{
				println("${uppre[j]} ${downpre[j]}")
			}*/
		}
		var ans=0
		for(i in 0..n-1) ans+=uppre[i] or downpre[i]
		println("${ans}")
	}
}

