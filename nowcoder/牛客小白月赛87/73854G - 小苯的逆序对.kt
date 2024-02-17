import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
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
class Fenwick_Tree <T:Number> (var n:Int)
{
	var bit=LongArray(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun insert(xx:Int,qv:T)
	{
		var x=xx
        var v=qv.toLong()
		while(x<=n)
		{
			bit[x]+=v
			x+=lowbit(x)
		}
	}
	fun get(xx:Int):Long
	{
		var res=0L
		var x=xx
		while(x>0)
		{
			res+=bit[x]
			x-=lowbit(x)
		}
		return res
	}
	fun ask(l:Int,r:Int):T
	{
        if(l>r) return 0 as T
        if(l-1<=0) return get(r) as T
		return (get(r)-get(l-1)) as T
	}
}
var flag=IntArray(MAX)
var mo=IntArray(MAX)
var prime=IntArray(MAX)
var tot=0
fun initmo(n:Int)
{
	tot=0
	mo[1]=1
	for(i in 2..n)
	{
		if(flag[i]==0)
		{
			prime[tot++]=i
			mo[i]=-1
		}
		for(j in 0..tot-1)
		{
			if(prime[j]*i>n) break
			flag[i*prime[j]]=1
			if(i%prime[j]==0)
			{
				mo[prime[j]*i]=0
				break
			}
			mo[prime[j]*i]=-mo[i]
		}
	}
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	initmo(n)
	var a=readline_int()
	var pos=IntArray(n+5)
	for(i in 0..n-1) pos[a[i]]=i+1
	a.sort()
	for(i in 0..n-1) require(a[i]==i+1)
	var tr=Fenwick_Tree<Int>(n)
	var ans=0L
	for(i in 1..n)
	{
		var x=i
		var now=0L
		while(x<=n)
		{
			now+=tr.ask(pos[x],n)
			tr.insert(pos[x],1)
			x+=i
		}
		ans+=now*mo[i]
		x=i
		while(x<=n)
		{
			tr.insert(pos[x],-1)
			x+=i
		}
	}
	println("${ans}")
}

