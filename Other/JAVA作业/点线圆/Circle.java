package work;

public class Circle extends Graphical
{
	double r;
	Spot Center;
	Circle(Spot c,double r)
	{
		Center=c;
		this.r=r;
	}
	
	public void draw()
	{
		System.out.print("This is circle!The center of a circle is");
		Center.draw(1);
		System.out.println(", the radius is "+r);
	}
}
