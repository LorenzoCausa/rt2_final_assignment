/**
* \file state_machine.cpp
* \brief This file is the state_machine node
* \author Lorenzo Causa
* \version 1.0
* \date 28/05/2021
*
* \details
* 
*
* Services : <BR>
*    °/user_interface
*
* Clients : <BR>
*   °/position_server
*
* ActionClients : <BR>
*    °/go_to_point
*
* Description :
*
* This node asks for the random target,calls the go_to_point action and receive command from the user interface
*
*/

#include "ros/ros.h"
#include "rt2_assignment1/Command.h"
#include "rt2_assignment1/Position.h"
#include "rt2_assignment1/RandomPosition.h"
#include <rt2_assignment1/go_to_pointAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>


bool start = false;
bool user_interface(rt2_assignment1::Command::Request &req, rt2_assignment1::Command::Response &res){
    if (req.command == "start"){
    	start = true;
    }
    if(req.command == "stop") {
    	start = false;
    }
    if(req.command == "stop_now"){
		actionlib::SimpleActionClient<rt2_assignment1::go_to_pointAction> a_client_p("/go_to_point", true); //action client (no way to make it global)
		a_client_p.cancelAllGoals();	
		start=false;
	}	
    return true;
}


int main(int argc, char **argv)
{
   ros::init(argc, argv, "state_machine");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/user_interface", user_interface);
   ros::ServiceClient client_rp = n.serviceClient<rt2_assignment1::RandomPosition>("/position_server");
   actionlib::SimpleActionClient<rt2_assignment1::go_to_pointAction> a_client_p("/go_to_point", true); //action client
      
   a_client_p.waitForServer();
   
   rt2_assignment1::RandomPosition rp;
   rp.request.x_max = 5.0;
   rp.request.x_min = -5.0;
   rp.request.y_max = 5.0;
   rp.request.y_min = -5.0;
   rt2_assignment1::Position p;
   
   rt2_assignment1::go_to_pointGoal goal;
   
   while(ros::ok()){
   	ros::spinOnce();
   	if (start){
   		client_rp.call(rp);
   		goal.x = rp.response.x;
   		goal.y = rp.response.y;
   		goal.theta = rp.response.theta;
   		std::cout << "Going to the position: x= " << goal.x<< " y= " <<goal.y << " theta = " <<goal.theta << std::endl;
   		a_client_p.sendGoal(goal);
   		while((a_client_p.getState().toString()!=("SUCCEEDED"))&&(a_client_p.getState().toString()!=("PREEMPTED"))){
				ros::spinOnce();
				usleep(10000);
			}
   		if(a_client_p.getState().toString()==("SUCCEEDED")) std::cout << "robot reached the target \n";
   		if(a_client_p.getState().toString()==("PREEMPTED")) std::cout << "robot goal preempted \n";
   	}
   }
   return 0;
}
