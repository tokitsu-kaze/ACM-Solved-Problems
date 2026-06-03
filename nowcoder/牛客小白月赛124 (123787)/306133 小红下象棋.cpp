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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
var dir=arrayOf(
arrayOf(-1,-2),
arrayOf(-2,-1),
arrayOf(-2,1),
arrayOf(-1,2),
arrayOf(1,2),
arrayOf(2,1),
arrayOf(2,-1),
arrayOf(1,-2)
)
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var x=tmp_line[0]
		var y=tmp_line[1]
		var n=tmp_line[2]
		require(-1e9<=x && x<=1e9)
		require(-1e9<=y && y<=1e9)
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var f0=true
		var s=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
		for(i in 0..n-1)
		{
			tmp_line=readline_int()
			require(tmp_line.size==2)
			var xx=tmp_line[0]
			var yy=tmp_line[1]
			require(-1e9<=xx && xx<=1e9)
			require(-1e9<=yy && yy<=1e9)
			for(j in 0..7)
			{
				var nx=xx+dir[j][0]
				var ny=yy+dir[j][1]
				if(x==nx && y==ny) f0=false
				for(dx in -1..1)
				{
					for(dy in -1..1)
					{
						if(dx==0 && dy==0) continue
						if(x+dx==nx && y+dy==ny) s.add(Pair(dx,dy))
					}
				}
			}
		}
		var f1=false
		if(s.size<8) f1=true
		
		if(f0 && !f1) println("A")
		else if(!f0 && !f1) println("B")
		else println("C")
	}
}

