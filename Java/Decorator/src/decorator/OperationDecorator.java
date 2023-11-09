package decorator;

public class OperationDecorator implements Operation
{
    private Operation operation;

    public OperationDecorator(Operation operation)
    {
        this.operation = operation;
    }

    @Override
    public double compute()
    {
        return operation.compute();
    }

    public Operation getOperation()
    {
        return operation;
    }
}