package factory;

public class ShapeFactory
{
    private ShapeFactory() {}

    public static IShape create(String type)
    {
        switch (type)
        {
            case "triangle":
                return new Triangle();
            case "circle":
                return new Circle();
            default:
                throw new UnsupportedOperationException();
        }
    }
}

