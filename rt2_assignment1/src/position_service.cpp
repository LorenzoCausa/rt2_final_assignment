/**
* \file position_service.cpp
* \brief This file is the position_service node
* \author Lorenzo Causa
* \version 1.0
* \date 28/05/2021
*
* \details
* 
*
* Services : <BR>
*    °/position_server
*
* Description :
*
* This node compute the random targets
*
*/

#include "ros/ros.h"
#include "rt2_assignment1/RandomPosition.h"


double randMToN(double M, double N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }


bool myrandom (rt2_assignment1::RandomPosition::Request &req, rt2_assignment1::RandomPosition::Response &res){
    res.x = randMToN(req.x_min, req.x_max);
    res.y = randMToN(req.y_min, req.y_max);
    res.theta = randMToN(-3.14, 3.14);
    return true;
}


int main(int argc, char **argv)
{
   ros::init(argc, argv, "random_position_server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/position_server", myrandom);
   ros::spin();

   return 0;
}
