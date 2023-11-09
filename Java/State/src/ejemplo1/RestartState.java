package ejemplo1;

public class RestartState implements State
{
    @Override
    public void printCurrentState()
    {
        System.out.println("CURRENT STATE: Restart Game");
    }
}