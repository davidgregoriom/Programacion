package abstracfactory;

public class GamingMouse implements IHardware{
    @Override
    public void create()
    {
        System.out.println("Create gaming mouse");
    }
}