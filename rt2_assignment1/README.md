# First Assignment of the Research Track 2 course (Robotics Engineering / JEMARO, Unige)
# Action Branch (final assignment version)

The package contains the nodes and the simulation environment for controlling a mobile robot in the Gazebo simulation environment.
To launch the node, please run:
```
roslaunch rt2_assignment1 sim.launch
```
This is version for the assignment 2 of RT2 which means that the User Interface will not be runned from here becouse will be implemented with jupyter.

# Architecture and Modifications:
Now the go_to_point service is an action service, also we have an action client in the 
state_machine node, which can start the action and delete the current goal (in this way we can stop the robot).
The rest of the package is almost unchanged, it can be used the same launcher of the original code.

For this version (final assignment version) a subscriber has also been added to the topic /velocities in the go_to_point node,
with this topic we can set the angular and linear speeds of the robot.

# User Interface:
The user interface is now on jupyter, all the commands can be sent from there

We can also see the current state and position of the robot in the feedback of the action service, for doing that just run in the terminal:
```
rostopic echo /go_to_point/feedback
```
# Documentation:
Doxygen documentation and rqt_graph in the folder doc of the package
