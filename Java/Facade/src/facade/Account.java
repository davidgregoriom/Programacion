package facade;

public class Account
{
    private String accountNumber;
    private double savings;

    public Account() {}

    public Account(double savings)
    {
        this.accountNumber = "123";
        this.savings = savings;
    }

    public String getAccountNumber()
    {
        return accountNumber;
    }

    public double getSavings()
    {
        return savings;
    }
}