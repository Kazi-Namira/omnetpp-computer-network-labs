#include <omnetpp.h>
using namespace omnetpp;

class Host : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Host);

void Host::initialize()
{
    // Only the first host generates the initial message
    if (getIndex() == 0) {
        cMessage *msg = new cMessage("Initial Message");
        scheduleAt(simTime() + 1.0, msg); // send after 1 second
    }
}

void Host::handleMessage(cMessage *msg)
{
    // Log message receipt
    EV << "Host[" << getIndex() << "] received message at time "
       << simTime() << endl;

    // Forward the message to the next host
    send(msg, "out");
}
