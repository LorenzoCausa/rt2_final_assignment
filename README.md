# Final Assignment of the Research Track 2 course (Robotics Engineering / JEMARO, Unige)

This repository contains the package "rt2_assignment1" which contains the nodes and the simulation environment for controlling a mobile robot in the Gazebo simulation environment, and the user interface implemented with jupyter for interact with it.

# Ros package rt2_assignment1
This package is almost the same as the action branch of the previous assignment, it has some small changes but the general behavior is the same.

More details on this package are in its README.

# Jupyter user_interface
This Jupyter file allow us to interact with the simulation in a much more friendly way, he user interface is able of:

- starting/stopping the robot “random position” behaviour by using buttons 
- setting the linear and angular velocity by using two Sliders
- directly controlling the robot movements by using 5 buttons (forward, turn right, backward, turn left, stop)

Also, it displays graphical information to the user:

- line plot for visualizing cmd_vel vs. actual velocity
- bar plot displaying the number of reached targets and cancelled targets
- histogram and boxplot showing the time required to reach targets
- xy graph showing the robot’s position and the orientation

# How to run it

1) Please run:
```
roslaunch rt2_assignment1 sim.launch
```
2) Open with jupyter lab "user_interface.ipynb" (it's in the folder notebooks)
3) Run the kernel (python3) in jupyter 
4) Now you are ready to play

AGGIUNGI DOCUMENTAZIONE
