package ejemplo1;

public class StartState implements State
{
    @Override
    public void printCurrentState()
    {
        System.out.println("CURRENT STATE: Start Game");
    }
}