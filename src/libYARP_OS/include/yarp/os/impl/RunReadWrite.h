// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2007-2009 RobotCub Consortium
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#ifndef __RUN_READ_WRITE_H__
#define __RUN_READ_WRITE_H__

#include <string>
#include <yarp/os/Port.h>
#include <yarp/os/Semaphore.h>
#include <yarp/os/PortReader.h>
#include <yarp/os/ConstString.h>

///////////////////////////////////////////

class RunWrite
{
public:
    RunWrite(){}
    ~RunWrite(){}

    int loop(const char* wPortName);
    static void close();

protected:
    std::string getStdin();

    static yarp::os::Port mWPort;
    static yarp::os::ConstString mWPortName;
};

///////////////////////////////////////////

class RunRead : public yarp::os::PortReader
{
public:
    RunRead(){}
    ~RunRead(){}

    int loop(const char* rPortName);
    static void close(){ mDone.post(); }
    virtual bool read(yarp::os::ConnectionReader& reader);

protected:
    std::string getStdin();

    static yarp::os::Semaphore mDone;
    static yarp::os::Port mRPort;
    static yarp::os::ConstString mRPortName;
};

///////////////////////////////////////////

class RunReadWrite : public yarp::os::PortReader
{
public:
    RunReadWrite(){}
    ~RunReadWrite(){}

    int loop(const char* rPortName,const char* wPortName);
    static void close();
    virtual bool read(yarp::os::ConnectionReader& reader);

protected:
    std::string getStdin();

    static bool mClosed;
    static yarp::os::Semaphore mDone;
    static yarp::os::Port mRPort;
    static yarp::os::Port mWPort;
    static yarp::os::ConstString mRPortName;
    static yarp::os::ConstString mWPortName;
};

#endif
