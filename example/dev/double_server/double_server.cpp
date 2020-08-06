/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */


#include <yarp/os/Network.h>
#include <yarp/os/Property.h>

#include <yarp/dev/PolyDriver.h>

#include <cstdio>

using yarp::dev::PolyDriver;
using yarp::os::Network;
using yarp::os::Property;

int main(int argc, char* argv[])
{
    YARP_UNUSED(argc);
    YARP_UNUSED(argv);

    Network yarp;

    Property config;
    config.fromString("(device grabberDual) (subdevice ffmpeg_grabber) (name /dev1/image) (name2 /dev1/sound)");

    PolyDriver dd(config);
    if (!dd.isValid()) {
        printf("Failed to create and configure device 1\n");
        return 1;
    }

    Property config2;
    config2.fromString("(device grabberDual) (subdevice ffmpeg_grabber) (name /dev2/image) (name2 /dev2/sound)");

    PolyDriver dd2(config2);
    if (!dd2.isValid()) {
        printf("Failed to create and configure device 2\n");
        return 1;
    }

    while (true) {
        printf("Sending data...");
        yarp::os::Time::delay(5);
    }

    return 0;
}
