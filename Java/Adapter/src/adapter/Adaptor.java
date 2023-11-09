package adapter;

public class Adaptor implements Converter
{
    private Converter converter;

    public Adaptor(Converter converter)
    {
        this.converter = converter;
    }

    @Override
    public void convert()
    {
        converter.convert();
    }
}