/**
 * @file robotState.h
 * @brief RobotState class header file
 * 
 * It's a base class for all robot states in an environment
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

#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__

#include <stack>
#include <string>

/* -- User-defined header files -- */
#include "../utils/travel.h"

/**
 * @brief Namespace stackfsm::state used to encapsulate the RobotStates, it
 *        basically used to differentiate FSM with rest of the code.
 */
namespace stackfsm { 
  namespace state {
    /**
     * @brief RobotState class, it handles all types of Robot State transition.
     */
    class RobotState {
      public:
        /**
         * @brief RobotState class parameterized constructor
         */
        RobotState(std::string name = "RobotState"):name_{name}{}
      
        /**
         * @brief RobotState class destructor
         */
        virtual ~RobotState(){}
        
        /**
         * @brief handleMoton function, used to store the robot states and helps
         *        in transition from one state to another. This method gets over
         *        -ride in derived classes for specific state transition
         * @param stack a variable of type stack of robotstate
         * @param travel a variable of type enum
         * @return none
         */
        virtual void handleMotion(std::stack<RobotState*>&, Travel) {}
      
        /**
         * @brief getName function, used to access the private variable 
         * @param none
         * @return name_, a variable of type string
         */
        inline std::string getName() {
          return name_;
        }
  
      protected:
        /**
         * @brief name_ a variable to store the name of the state
         */
        std::string name_;
    }; // RobotState
  } // state Namespace
} // stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__
