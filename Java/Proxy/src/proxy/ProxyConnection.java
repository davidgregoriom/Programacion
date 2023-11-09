package proxy;

import java.util.Objects;

public class ProxyConnection implements IConnection
{
    private String url;
    private RealConnection realConnection;

    public ProxyConnection(String url)
    {
        this.url = url;
    }

    @Override
    public void connect()
    {
        if(Objects.isNull(realConnection))
        {
            realConnection = new RealConnection(url);
        }
        realConnection.connect();
    }
}