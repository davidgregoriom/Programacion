package composite;

public class Developer implements Employee
{
    private String name;
    private double salary;
    private String position;

    public Developer(String name, double salary, String position)
    {
        this.name = name;
        this.salary = salary;
        this.position = position;
    }

    @Override
    public void printDetails()
    {
        System.out.println(String.format("Name: %s Salary: %.2f Position: %s", name, salary, position));
    }
}