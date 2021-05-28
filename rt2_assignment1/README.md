# First Assignment of the Research Track 2 course (Robotics Engineering / JEMARO, Unige)
# ACTION BRANCH (final assignment version)

The package contains the nodes and the simulation environment for controlling a mobile robot in the Gazebo simulation environment.
To launch the node, please run:
```
roslaunch rt2_assignment1 sim.launch
```
This is version for the assignment 2 of RT2 which means that the User Interface will not be runned from here becouse will be implemented with jupyter.

# ARCHITECTURE and MODIFICATIONS:

Now the go_to_point service is an action service, also we have an action client in the 
state_machine node, which can start the action and delete the current goal (in this way we can stop the robot).
The rest of the package is almost unchanged, it can be used the same launcher of the original code.
 
# COMMANDS:

we can stop immediatly the robot with the command -1, or, we can stop it 
when it reaches the last target with the command 0, (like when go_to_point was a normal service)
for restart the robot just enter the command 1.

We can also see the current state and position of the robot in the feedback of the action service, for doing that just run in the terminal:
```
rostopic echo /go_to_point/feedback
```
# DOCUMENTATION:

Doxygen documentation and rqt_graph in the folder doc of the package
