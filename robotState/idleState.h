/**
 * @file idleState.h
 * @brief IdleState class header file
 * 
 * It's a publicly derived class of RobotState class
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

#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_IDLESTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_IDLESTATE_H__

/* -- User-defined header files -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    /**
     * @brief IdleState class, it handles the transition from Idle state to
     *        other states.
     */
    class IdleState: public RobotState {
      public:
        /**
         * @brief IdleState class constructor
         */
        IdleState(): RobotState("IdleState") {}
        
        /**
         * @brief IdleState class destructor
         */
        virtual ~IdleState() {}
        
        /**
         * @brief handleMoton function, used to store the robot states and helps
         *        in transition from one state to another 
         * @param stack a variable of type stack of robotstate
         * @param travel a variable of type enum
         * @return none
         */
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // IdleState class
  } // state Namespace
} // stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_IDLESTATE_H__
