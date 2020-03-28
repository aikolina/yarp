/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

// Autogenerated by Thrift Compiler (0.12.0-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_SERVICE_DEMOEXTENDED_H
#define YARP_THRIFT_GENERATOR_SERVICE_DEMOEXTENDED_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <yarp/test/demo_common.h>
#include <yarp/test/Demo.h>

namespace yarp {
namespace test {

class DemoExtended :
        public Demo
{
public:
    // Constructor
    DemoExtended();

    virtual Point3D multiply_point(const Point3D& x, const double factor);

    // help method
    std::vector<std::string> help(const std::string& functionName = "--all") override;

    // read from ConnectionReader
    bool read(yarp::os::ConnectionReader& connection) override;
};

} // namespace yarp
} // namespace test

#endif // YARP_THRIFT_GENERATOR_SERVICE_DEMOEXTENDED_H