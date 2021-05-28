import rospy
import time
from rt2_assignment1.srv import Command

def main():
    rospy.init_node('user_interface')
    ui_client = rospy.ServiceProxy('/user_interface', Command)
    time.sleep(10)
    rate = rospy.Rate(20)
    x = int(input("Press 1 to start the robot \n"))
    while not rospy.is_shutdown():
        if (x == 1):
            ui_client("start")
            x = int(input("Press 0 to stop the robot at the next target, press -1 to stop it immediatly \n"))
        elif (x==0):
            print("Please wait, the robot is going to stop when the position will be reached")
            ui_client("stop")
            x = int(input("After the position is reached, press 1 to start again the robot \n"))
        elif (x==-1):
            print("the robot should stop now")
            ui_client("stop_now")
            x = int(input("robot stopped, press 1 to start it again \n"))            
            
if __name__ == '__main__':
    main()
