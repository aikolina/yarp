// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2006 Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
 *
 */

#ifndef _YARP2_SHMEMCARRIER_
#define _YARP2_SHMEMCARRIER_

#include <yarp/AbstractCarrier.h>
#include <yarp/ShmemTwoWayStream.h>

namespace yarp {
    class ShmemCarrier;
}

class yarp::ShmemCarrier : public AbstractCarrier {
public:
    ShmemCarrier() {
    }

    virtual Carrier *create() {
        return new ShmemCarrier();
    }

    virtual String getName() {
        return "shmem";
    }

    virtual int getSpecifierCode() {
        return 2;
    }

    virtual bool requireAck() {
        return true;
    }

    virtual bool isConnectionless() {
        return false;
    }

    virtual bool checkHeader(const Bytes& header) {
        return getSpecifier(header)%16 == getSpecifierCode();
    }

    virtual void getHeader(const Bytes& header) {
        createStandardHeader(getSpecifierCode(), header);
    }

    virtual void setParameters(const Bytes& header) {
    }

    virtual void becomeShmem(Protocol& proto, bool sender) {

        ShmemTwoWayStream *stream = new ShmemTwoWayStream();
        YARP_ASSERT(stream!=NULL);
        Address base;
        try {
            if (!sender) {
                ACE_INET_Addr anywhere((u_short)0, (ACE_UINT32)INADDR_ANY);
                base = Address(anywhere.get_host_addr(),
                               anywhere.get_port_number());
                stream->open(base,sender);
                int myPort = stream->getLocalAddress().getPort();
                proto.writeYarpInt(myPort);
                stream->accept();
                proto.takeStreams(NULL);
                proto.takeStreams(stream);
            } else {
                int altPort = proto.readYarpInt();
                String myName = proto.getStreams().getLocalAddress().getName();
                proto.takeStreams(NULL);
                base = Address(myName,altPort);
                stream->open(base,sender);
                proto.takeStreams(stream);
            }
        } catch (IOException e) {
            delete stream;
            stream = NULL;
            throw e;
        }
    }

    virtual void respondToHeader(Protocol& proto) {
        // i am the receiver
        becomeShmem(proto,false);
    }


    virtual void expectReplyToHeader(Protocol& proto) {
        // i am the sender
        becomeShmem(proto,true);
    }

};

#endif

