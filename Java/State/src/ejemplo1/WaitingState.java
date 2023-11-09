package ejemplo1;

public class WaitingState implements State
{
    @Override
    public void printCurrentState()
    {
        System.out.println("CURRENT STATE: Waiting user decision");
    }
}