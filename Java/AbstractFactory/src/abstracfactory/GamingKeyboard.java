package abstracfactory;


public class GamingKeyboard implements IHardware{
    @Override
    public void create()
    {
        System.out.println("Create gaming keyboard");
    }
}
