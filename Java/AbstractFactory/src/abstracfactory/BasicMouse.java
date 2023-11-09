package abstracfactory;



public class BasicMouse implements IHardware{
    @Override
    public void create()
    {
        System.out.println("Create basic mouse");
    }
}
