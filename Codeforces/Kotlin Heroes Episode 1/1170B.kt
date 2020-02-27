fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun main()
{
	var n=readint();
	var a=readline();
	var x=0
	var y=0
	var ans=0
	for(it in a)
	{
		if(it<minOf(x,y)) ans++
		if(x==0) x=it
		else if(y==0) y=it
		else
		{
			if(it>y) y=it;
		}
		if(x<y) x=y.also{y=x}
	}
	println("${ans}")

}