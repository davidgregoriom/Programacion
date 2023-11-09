package ejemplo3;

public abstract class GameState
{
    MyGame myGame;

    public GameState(MyGame myGame)
    {
        this.myGame = myGame;
    }

    public abstract void getPoints();

    public abstract String getState();
}
