package abstracfactory;

public class MouseFactory
{
    private MouseFactory() {}

    public static IHardware create(String type)
    {
        switch (type)
        {
            case "gaming":
                return new GamingMouse();
            case "basic":
                return new BasicMouse();
            default:
                throw new UnsupportedOperationException();
        }
    }
}