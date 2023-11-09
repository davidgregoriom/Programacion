package abstracfactory;

public class BasicKeyboard implements IHardware{
    @Override
    public void create()
    {
        System.out.println("Create basic keyboard");
    }
}
