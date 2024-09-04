/*
 * txc5.cc
 *
 *  Created on: 2020Äê4ÔÂ29ÈÕ
 *      Author: njust
 */




#include <stdio.h>
    #include <string.h>
    #include <omnetpp.h>

    using namespace omnetpp;

    /**
     * In this step you'll learn how to add input parameters to the simulation:
     * we'll turn the "magic number" 10 into a parameter.
     */
    class Txc5 : public cSimpleModule
    {
      private:
        int counter;

      protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
    };

  Define_Module(Txc5);


    void Txc5::initialize()
    {
        // Initialize the counter with the "limit" module parameter, declared
        // in the NED file (tictoc4.ned).
        counter = par("limit");

        // we no longer depend on the name of the module to decide
        // whether to send an initial message
        if (par("sendMsgOnInit").boolValue() == true) {
            EV << "Sending initial message\n";
            cMessage *msg = new cMessage("tictocMsg");
            send(msg, "out");
        }
    }

    void Txc5::handleMessage(cMessage *msg)
    {
        counter--;
        if (counter == 0) {
            EV << getName() << "'s counter reached zero, deleting message\n";
            delete msg;
        }
        else {
            EV << getName() << "'s counter is " << counter << ", sending back message\n";
            send(msg, "out");
        }
    }




