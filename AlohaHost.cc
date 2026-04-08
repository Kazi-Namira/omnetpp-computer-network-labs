#include <omnetpp.h>
using namespace omnetpp;

class AlohaHost : public cSimpleModule
{
  private:
    cMessage *sendEvent;

    int packetsSent = 0;

    // ⭐ Shared across all hosts
    static int totalSuccess;
    static int totalSent;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

Define_Module(AlohaHost);

// ⭐ Initialize static variables
int AlohaHost::totalSuccess = 0;
int AlohaHost::totalSent = 0;

// Initialization
void AlohaHost::initialize()
{
    sendEvent = new cMessage("sendEvent");

    scheduleAt(simTime() + uniform(0, 2), sendEvent);
}

// Message handling
void AlohaHost::handleMessage(cMessage *msg)
{
    if (msg == sendEvent)
    {
        cMessage *pkt = new cMessage("packet");

        send(pkt, "out");

        packetsSent++;
        totalSent++;   // ⭐ global count

        // Simulate collision
        if (uniform(0,1) > 0.3)
        {
            totalSuccess++;   // ⭐ global success
            EV << "SUCCESS at time " << simTime() << endl;
        }
        else
        {
            EV << "COLLISION at time " << simTime() << endl;
        }

        scheduleAt(simTime() + exponential(1), sendEvent);
    }
    else
    {
        delete msg;
    }
}

// Final results
void AlohaHost::finish()
{
    // Print only once (from first host)
    if (getIndex() == 0)
    {
        double simTimeVal = simTime().dbl();

        double throughput = 0;
        if (simTimeVal > 0)
            throughput = totalSuccess / simTimeVal;

        EV << "\n===== FINAL NETWORK RESULTS =====" << endl;
        EV << "Total Packets Sent: " << totalSent << endl;
        EV << "Successful Packets: " << totalSuccess << endl;
        EV << "Throughput: " << throughput << endl;

        recordScalar("Total Packets Sent", totalSent);
        recordScalar("Total Packets Successful", totalSuccess);
        recordScalar("Throughput", throughput);
    }
}
