package facade;

public class WithdrawalValidator
{
    public int validate(double accountAmount, double withdrawalAmount)
    {
        if(accountAmount < withdrawalAmount) return 0;
        else if(accountAmount - withdrawalAmount < 20) return 1;
        return 2;
    }
}