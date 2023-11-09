package template;

public class MediocreDesktop extends DesktopTemplate
{
    @Override
    public boolean addExtraRam()
    {
        return true;
    }

    @Override
    public boolean addGraphicCard()
    {
        return true;
    }

    @Override
    public boolean addSSD()
    {
        return false;
    }

    @Override
    public boolean addExtraCooler()
    {
        return false;
    }
}