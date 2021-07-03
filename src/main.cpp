/*
 * Copyright (C) 2021 iCub Facility
 * Authors: Simone Girardi
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <yarp/os/LogStream.h>
#include <yarp/os/Network.h>

using namespace yarp::os;

int main(int argc, char * argv[])
{
    yInfo()<<"Main starting...";
    Network yarp;

    if(!yarp.checkNetwork())
    {
        yError() << "Cannot find yarp server";
        return EXIT_FAILURE;
    }

    uint64_t counter = 0;

    for (size_t i = 0; i < 100; i++)
    {
        yWarning() << "Before counter increment: " << counter;
        counter++;
        yInfo() << "After counter increment: " << counter;
        yarp::os::Time::delay(0.1); // wait 0.1s
        yInfo() << "--------------------------------";
    }
    
    yInfo()<<"Main returning...";
    return EXIT_SUCCESS;
}


