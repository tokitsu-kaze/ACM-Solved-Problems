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
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
class Fenwick_Tree <T:Number> (var n:Int)
{
	var bit=LongArray(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun upd(xx:Int,qv:T)
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
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	var sumq=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var q=tmp_line[1]
		require(1<=n && n<=2e5)
		require(1<=q && q<=2e5)
		sumn+=n
		sumq+=q
		require(sumn<=2e5)
		require(sumq<=2e5)
		var v=readline_int()
		require(v.size==n)
		for(it in v) require(1<=it && it<=9)
		var tra=Fenwick_Tree<Int>(n+1)
		var trb=Fenwick_Tree<Int>(n+1)
		var trc=Fenwick_Tree<Int>(n+1)
		var trd=Fenwick_Tree<Int>(n+1)
		for(i in 0..n-1)
		{
			var tmp=v[i]%9
			if(tmp==0 || tmp==3 || tmp==6) tra.upd(i+1,1)
			else if(tmp==1 || tmp==8) trb.upd(i+1,1)
			else if(tmp==2 || tmp==7) trc.upd(i+1,1)
			else trd.upd(i+1,1)
		}
		var cntop2=0
		while(q-->0)
		{
			tmp_line=readline_int()
			require(tmp_line.size==3)
			var op=tmp_line[0]
			require(op==1 || op==2)
			if(op==1)
			{
				var i=tmp_line[1]
				var x=tmp_line[2]
				require(1<=i && i<=n)
				require(1<=x && x<=9)
				i--
				
				var tmp=v[i]%9
				if(tmp==0 || tmp==3 || tmp==6) tra.upd(i+1,-1)
				else if(tmp==1 || tmp==8) trb.upd(i+1,-1)
				else if(tmp==2 || tmp==7) trc.upd(i+1,-1)
				else trd.upd(i+1,-1)
				
				v[i]=x
				
				tmp=v[i]%9
				if(tmp==0 || tmp==3 || tmp==6) tra.upd(i+1,1)
				else if(tmp==1 || tmp==8) trb.upd(i+1,1)
				else if(tmp==2 || tmp==7) trc.upd(i+1,1)
				else trd.upd(i+1,1)
			}
			else
			{
				cntop2++
				var l=tmp_line[1]
				var r=tmp_line[2]
				require(1<=l && l<=r && r<=n)
				var a=tra.ask(l,r)
				var b=trb.ask(l,r)
				var c=trc.ask(l,r)
				var d=trd.ask(l,r)
				if(a<0 || a%3!=0) println("No")
				else if((4*b-2*c+d)<0 || (4*b-2*c+d)%9!=0) println("No")
				else if((b+4*c-2*d)<0 || (b+4*c-2*d)%9!=0) println("No")
				else if((-2*b+c+4*d)<0 || (-2*b+c+4*d)%9!=0) println("No")
				else println("Yes")
			}
		}
		require(cntop2>0)
	}
}
/*
A: {0,3,6}  x^2 mod 9 == 0
B: {1,8}    x^2 mod 9 == 1
C: {2,7}    x^2 mod 9 == 4
D: {4,5}    x^2 mod 9 == 7

AAA, BBD, BCC, CDD

3w=a
2x+y=b
2y+z=c
x+2z=d

w=a/3
x=(4b-2c+d)/9
y=(b+4c-2d)/9
z=(-2b+c+4d)/9

*/
