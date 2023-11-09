package decorator;

public class Multiplication extends OperationDecorator
{
    private double x;
    private double y;

    public Multiplication(Operation operation)
    {
        this(2, 2, operation);
    }

    public Multiplication(double x, double y, Operation operation)
    {
        super(operation);
        this.x = x;
        this.y = y;
    }

    @Override
    public double compute()
    {
        return x * y + super.getOperation().compute();
    }
}