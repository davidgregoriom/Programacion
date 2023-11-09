package ejemplo3;

public class AddPointState extends GameState
{
    public AddPointState(MyGame myGame)
    {
        super(myGame);
    }

    @Override
    public void getPoints()
    {
        myGame.setPoints(myGame.points() + 1);
        System.out.println("Added 1 point");
    }

    @Override
    public String getState()
    {
        return "Add Point State";
    }
}