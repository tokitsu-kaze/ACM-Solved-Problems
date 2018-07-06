package work;

public class Land implements Drive_Device
{
	double weight, height,length;
	public Land(double weight,double height,double length)
	{
		this.weight=weight;
		this.height=height;
		this.length=length;
	}
	public void drivedevice()
	{
		System.out.println("陆地坦克驱动装置：履带");
	}
}
