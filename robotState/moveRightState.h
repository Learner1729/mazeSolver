/**
 * @file moveRightState.h
 * @brief MoveRightState class header file
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

#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__

/* -- User-defined header files -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    /**
     * @brief IdleState class, it handles the transition from Right state to
     *        other states.
     */
    class MoveRightState: public RobotState{
      public:
        /**
         * @brief MoveRightState class constructor
         */
        MoveRightState():RobotState("MoveRightState") {}
        
        /**
         * @brief MoveRightState class destructor
         */
        virtual ~MoveRightState() {}
        
        /**
         * @brief handleMoton function, used to store the robot states and helps
         *        in transition from one state to another 
         * @param stack a variable of type stack of robotstate
         * @param travel a variable of type enum
         * @return none
         */
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // MoveRightState
  } // state Namespace
} // stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__
