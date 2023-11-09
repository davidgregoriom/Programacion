package ejemplo3;

public class LosePointState extends GameState
{
    public LosePointState(MyGame myGame)
    {
        super(myGame);
    }

    @Override
    public void getPoints()
    {
        myGame.setPoints(myGame.points() - 1);
        System.out.println("Lose 1 point");
    }

    @Override
    public String getState()
    {
        return "Lose Point State";
    }
}
