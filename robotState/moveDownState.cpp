/* -- Includes -- */
/**
 * @file moveDownState.cpp
 * @brief MoveDownState class implementation file
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

/* -- User-defined header files -- */
#include "moveDownState.h"
#include "moveLeftState.h"
#include "moveRightState.h"
#include "moveUpState.h"
#include "idleState.h"

namespace stackfsm {
  namespace state {
    /**
     * @brief handleMoton function, used to store the robot states and helps
     *        in transition from one state to another 
     * @param stack a variable of type stack of robotstate
     * @param travel a variable of type enum
     * @return none
     */
    void MoveDownState::handleMotion(std::stack<RobotState*>& stack, Travel travel) {
      if(travel == LEFT) {
        if (!stack.empty()){
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveDownState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveLeftState();
            stack.push(nextState);
          }
        }
      } else if(travel == UP) {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveDownState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveUpState();
            stack.push(nextState);
          }
        }
      } else if(travel == RIGHT) {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveDownState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveRightState();
            stack.push(nextState);
          }
        }
      } else if(travel == DOWN) {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveDownState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveDownState();
            stack.push(nextState);
          }
        }
      } else {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveDownState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::IdleState();
            stack.push(nextState);
          }
        }
      }
    }
  } // namespace state
} // namespace stackfsm

