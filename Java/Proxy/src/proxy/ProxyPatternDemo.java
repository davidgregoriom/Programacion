package proxy;

public class ProxyPatternDemo
{
    public static void main(String[] args)
    {
        IConnection proxyConnection = new ProxyConnection("https://mywebsite.com");
        proxyConnection.connect();
    }
}