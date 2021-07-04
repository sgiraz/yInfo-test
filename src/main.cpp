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
    Network yarp;

    if(!yarp.checkNetwork())
    {
        yError() << "Cannot find yarp server";
        return EXIT_FAILURE;
    }

    uint64_t counter = 0; // a reference number
    double t = 0.001;     // time delay among each itearation

    //for (size_t j = 0; j < 10; j++)
    //{
        for (size_t i = 0; i < 10000; i++)
        {
            yInfo() << "---- [ Time delay ]:" << t << "Counter value: " << counter;
            counter++;
            yarp::os::Time::delay(t);
        }
        //t /= 10;
    //}
    



    return EXIT_SUCCESS;
}


