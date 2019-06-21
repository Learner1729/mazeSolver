/**
 * @file mobileRobot.h
 * @brief MobileRobot class header file
 * 
 * @copyright Copyright (c) 2019 ENPM809Y:Group 4
 *            This project is released under the MIT License.
 *
 * @author Mohammad Salman
 * @author Lih-Narn Wang
 * @author Kamesh Sarangan
 * @author Yashaarth Todi
 * @author Ashish Patel
 * 
 * @bug No known bugs.
 * @date 05-19-2019
 */

#ifndef __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__
#define __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__

/* -- C++ includes -- */
#include <stack>
#include <string>

/* -- User-defined header files -- */
#include "../robotState/robotState.h" /* for including RobotState class */
#include "../robotState/moveDownState.h"
#include "../robotState/moveLeftState.h"
#include "../robotState/moveUpState.h"
#include "../robotState/moveRightState.h"
#include "../robotState/idleState.h"
#include "../utils/travel.h" /*for including robot states */

/**
 * @brief MobileRobot class handles the properties and function of a robot
 */
class MobileRobot {
  public:
    /**
     * @brief MobileRobot class constructor
     */
    MobileRobot();
    
    /**
     * @brief MobileRobot class parameterized constructor
     * @param startX_ a variable of type size_t
     * @param startY_ a variable of type size_t
     * @param goalX_ a variable of type size_t
     * @param goalY_ a variable of type size_t
     */
    MobileRobot(std::size_t, std::size_t, std::size_t, std::size_t);
    
    /**
     * @brief setStartLocationX, used to set the X cooridnate of start position
     * @param val a variable of type size_t
     * @return none
     */
    inline void setStartLocationX(const std::size_t val) {
      startLocationX_ = val;
    }
    
    /**
     * @brief setStartLocationY, used to set the Y cooridnate of start position
     * @param val a variable of type size_t
     * @return none
     */
    inline void setStartLocationY(const std::size_t val) {
      startLocationY_ = val;
    }
  
    /**
     * @brief setGoalLocationX, used to set the X cooridnate of goal position
     * @param val a variable of type size_t
     * @return none
     */
    inline void setGoalLocationX(const std::size_t val) {
      goalLocationX_ = val;
    }
    
    /**
     * @brief setGoalLocationY, used to set the Y cooridnate of goal position
     * @param val a variable of type size_t
     * @return none
     */
    inline void setGoalLocationY(const std::size_t val) {
      goalLocationY_ = val;
    }

    /**
     * @brief getStartLocationX, used to get the X cooridnate of start position
     * @param none
     * @return startLocationX_ a variable of type size_t
     */
    inline std::size_t getStartLocationX() const {
      return startLocationX_;
    }
    
    /**
     * @brief getStartLocationY, used to get the Y cooridnate of start position
     * @param none
     * @return startLocationY_ a variable of type size_t
     */
    inline std::size_t getStartLocationY() const {
      return startLocationY_;
    }
    
    /**
     * @brief getGoalLocationX, used to get the X cooridnate of goal position
     * @param none
     * @return goalLocationX_ a variable of type size_t
     */
    inline std::size_t getGoalLocationX() const {
      return goalLocationX_;
    }
    
    /**
     * @brief getGoalLocationY, used to get the Y cooridnate of goal position
     * @param none
     * @return goalLocationY_ a variable of type size_t
     */
    inline std::size_t getGoalLocationY() const {
      return goalLocationY_;
    }
    
    /**
     * @brief handleMotion function, used to control robots movement
     * @param Travel a variable of type enum 
     * @return none
     */
    void handleMotion(Travel);
    
    /**
     * @brief printStack function, used to print the stack containing robots
     *        movement
     * @param s a stack of robots state
     * @return none
     */
    void printStack(std::stack<stackfsm::state::RobotState*>);
    
    /**
     * @brief getStack function, used to get the stack of robots movement
     * @param  none
     * @return stack_, a variable of type stack
     */
    inline std::stack<stackfsm::state::RobotState*> getStack() {
      return stack_;
    }
    
    /**
     * @brief removeOne function, used to remove the top element from the
     *        stack of robots movement
     * @param  none
     * @return none
     */
    inline void removeOne() {
      stack_.pop();
    }
    
    /**
     * @brief setStack function, used to set stack_ private variable of
     *        this class
     * @param  stack a variable of type stack of RobotStates
     * @return none
     */
    inline void setStack(std::stack<stackfsm::state::RobotState*> stack){
      stack_ = stack;
    }
    
    /**
     * @brief MobileRobot destructor
     */
    virtual ~MobileRobot();

  private:
    /**
     * @brief name_ a variable to store the name of the Mobile Robot object
     */
    const std::string name_;
    
    /**
     * @brief startLocationX_ a variable to store x-coordinate of start
     *        position of mobile robot
     * @brief startLocationY_ a variable to store y-coordinate of start
     *        position of mobile robot
     */
    std::size_t startLocationX_, startLocationY_;
    
    /**
     * @brief goalLocationX_ a variable to store x-coordinate of goal
     *        position of mobile robot
     * @brief goalLocationY_ a variable to store y-coordinate of goal
     *        position of mobile robot
     */
    std::size_t goalLocationX_, goalLocationY_;
    
    /**
     * @brief stack_ a variable to store robots movement
     */
    std::stack<stackfsm::state::RobotState*> stack_;
};

#endif // __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__
