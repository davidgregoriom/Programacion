package abstracfactory;

public class HardwareFactory
{
    private HardwareFactory() {}

    public static IHardware create(String type, boolean isGaming)
    {
        String itemType = isGaming ? "gaming" : "basic";
        switch (type)
        {
            case "mouse":
                return MouseFactory.create(itemType);
            case "keyboard":
                return KeyboardFactory.create(itemType);
            default:
                throw new UnsupportedOperationException();
        }
    }
}