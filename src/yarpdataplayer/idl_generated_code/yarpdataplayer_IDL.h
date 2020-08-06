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

#ifndef YARP_THRIFT_GENERATOR_SERVICE_YARPDATAPLAYER_IDL_H
#define YARP_THRIFT_GENERATOR_SERVICE_YARPDATAPLAYER_IDL_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

/**
 * yarpdataplayer_IDL
 * Interface.
 */
class yarpdataplayer_IDL :
        public yarp::os::Wire
{
public:
    // Constructor
    yarpdataplayer_IDL();

    /**
     * Steps the player once. The player will be stepped
     * until all parts have sent data
     * @return true/false on success/failure
     */
    virtual bool step();

    /**
     * Sets the frame number to the user desired frame.
     * @param name specifies the name of the loaded data
     * @param frameNum specifies the frame number the user
     *  would like to skip to
     * @return true/false on success/failure
     */
    virtual bool setFrame(const std::string& name, const std::int32_t frameNum);

    /**
     * Gets the frame number the user is requesting
     * @param name specifies the name of the data to modify
     *  would like to skip to
     * @return i32 returns the current frame index
     */
    virtual std::int32_t getFrame(const std::string& name);

    /**
     * Loads a dataset from a path
     * @return true/false on success/failure
     */
    virtual bool load(const std::string& path);

    /**
     * Get slider percentage
     * @return i32 percentage
     */
    virtual std::int32_t getSliderPercentage();

    /**
     * Plays the dataSets
     * @return true/false on success/failure
     */
    virtual bool play();

    /**
     * Pauses the dataSets
     * @return true/false on success/failure
     */
    virtual bool pause();

    /**
     * Stops the dataSets
     * @return true/false on success/failure
     */
    virtual bool stop();

    /**
     * Quit the module.
     * @return true/false on success/failure
     */
    virtual bool quit();

    // help method
    virtual std::vector<std::string> help(const std::string& functionName = "--all");

    // read from ConnectionReader
    bool read(yarp::os::ConnectionReader& connection) override;
};

#endif // YARP_THRIFT_GENERATOR_SERVICE_YARPDATAPLAYER_IDL_H
