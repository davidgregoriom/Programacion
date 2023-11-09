package factory;

public class Triangle implements IShape
{
    @Override
    public void draw()
    {
        System.out.println("Draw triangle");
    }
}