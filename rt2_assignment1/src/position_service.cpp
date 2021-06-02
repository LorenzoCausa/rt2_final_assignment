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
* This node compute the random targets that the robot will reach
*
*/

#include "ros/ros.h"
#include "rt2_assignment1/RandomPosition.h"


double randMToN(double M, double N)
 { /**
    * function that compute a random number between 'M' and 'N'
    */
    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
 }


bool myrandom (rt2_assignment1::RandomPosition::Request &req, rt2_assignment1::RandomPosition::Response &res){
   /**
    * callback of the position_server service,it returns 2 radom position (X and Y) and a random orientation (theta)
    */
    res.x = randMToN(req.x_min, req.x_max);
    res.y = randMToN(req.y_min, req.y_max);
    res.theta = randMToN(-3.14, 3.14);
    return true;
}


int main(int argc, char **argv)
{
   /**
    * main of the position_service node
    */
   ros::init(argc, argv, "random_position_server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/position_server", myrandom);
   ros::spin();

   return 0;
}
