fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var t=readint()
	while(t-->0)
	{
		var tmp=readline_int()
		var a=tmp[0]
		var b=tmp[1]
		var c=tmp[2]
		var ans=1000000000
		var x=a
		var y=b
		var z=c
		var i=1
		while(i<=2*a)
		{
			var j=i
			while(j<=2*b)
			{
				var k=j
				while(k<=2*c)
				{
					var now=0
					if(a-i>=0) now+=a-i
					else now-=a-i
					if(b-j>=0) now+=b-j
					else now-=b-j
					if(c-k>=0) now+=c-k
					else now-=c-k
					if(now<ans)
					{
						ans=now
						x=i
						y=j
						z=k
					}
					k+=j
				}
				j+=i
			}
			i++
		}
		println("${ans}")
		println("${x} ${y} ${z}")
	}
}