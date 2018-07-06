package work;

public class Land_Water extends Land implements Drive_Device
{
	public Land_Water(double weight, double height, double length)
	{
		super(weight, height, length);
		// TODO Auto-generated constructor stub
	}
	public void drivedevice()
	{
		System.out.println("水陆坦克驱动装置：履带+螺旋桨、喷水推进器");
	}
}
