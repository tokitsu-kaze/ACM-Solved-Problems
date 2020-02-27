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
		var ans=0
		b-=a
		if(b>0)
		{
			if(b%2==1) ans=1
			else ans=2
		}
		if(b<0)
		{
			b=b*(-1)
			if(b%2==1) ans=2
			else ans=1
		}
		println("${ans}")
	}
}
