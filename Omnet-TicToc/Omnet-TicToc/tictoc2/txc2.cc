/*
 * txc2.cc
 *
 *  Created on: 2020Äê4ÔÂ29ÈÕ
 *      Author: njust
 */

#include <string.h>
    #include <omnetpp.h>

    using namespace omnetpp;

    /**
     * In this class we add some debug messages to Txc1. When you run the
     * simulation in the OMNeT++ GUI Tkenv, the output will appear in
     * the main text window, and you can also open separate output windows
     * for `tic' and `toc'.
     */
    class Txc2 : public cSimpleModule
    {
      protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
    };

    Define_Module(Txc2);

    void Txc2::initialize()
    {
        if (strcmp("tic", getName()) == 0) {
            // The `ev' object works like `cout' in C++.
            EV << "Sending initial message\n";
            cMessage *msg = new cMessage("tictocMsg");
            send(msg, "out");
        }
    }

    void Txc2::handleMessage(cMessage *msg)
    {
        // msg->getName() is name of the msg object, here it will be "tictocMsg".
        EV << "Received message `" << msg->getName() << "', sending it out again\n";
        send(msg, "out");
    }



