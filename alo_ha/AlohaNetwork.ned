network AlohaNetwork
{
    submodules:
        host[5]: AlohaHost;

    connections:
        host[0].out --> host[1].in;
        host[1].out --> host[2].in;
        host[2].out --> host[3].in;
        host[3].out --> host[4].in;
        host[4].out --> host[0].in;
}