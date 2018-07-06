package work;

public class Employee
{
	private String name;
	private double salary; 
	public Employee(String name,double salary)
	{
		this.name=name;
		this.salary=salary;
	}
	public String getdate()
	{
		return "Name:"+name+"\nSalary:"+salary;
	}
}