package work;

public class Spot extends Graphical
{
	double x;
	double y;
	Spot(double a,double b)
	{
		x=a;
		y=b;
	}
	public void draw()
	{
		System.out.println("This is Spot!Coordinate is ("+x+","+y+")!");
	}
	void draw(int a)
	{
		System.out.print("("+x+","+y+")");
	}
}