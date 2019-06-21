/**
 * @file mobileRobot.cpp
 * @brief MobileRobot class implementation file
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

/* -- C++ includes -- */
#include <iostream>
#include <stack>
#include <string>

/* -- User-defined header files -- */
#include "mobileRobot.h"

/**
 * @brief Maze class constructor
 */
MobileRobot::MobileRobot() {
  std::cout << "[LOG]: MobileRobot object created using default constructor\n";
}

/**
 * @brief Maze class parameterized constructor
 * @param startX_ a variable of type size_t
 * @param startY_ a variable of type size_t
 * @param goalX_ a variable of type size_t
 * @param goalY_ a variable of type size_t
 */
MobileRobot::MobileRobot(std::size_t startX, std::size_t startY,
std::size_t goalX, std::size_t goalY)
: startLocationX_(startX), startLocationY_(startY), goalLocationX_(goalX), 
goalLocationY_(goalY){
  std::cout << "[LOG]: MobileRobot object created using parameterized "
    << "constructor\n";
}

/**
 * @brief handleMotion function, used to control robots movement
 * @param Travel a variable of type enum 
 * @return none
 */
void MobileRobot::handleMotion(Travel travel) {
  stackfsm::state::RobotState* state = new stackfsm::state::IdleState();
  if(stack_.empty()) {
    state -> handleMotion(stack_, travel);
  } else {
    stack_.top() -> handleMotion(stack_, travel);
  }
}

/**
 * @brief printStack function, used to print the stack containing robots
 *        movement
 * @param s a stack of robots state
 * @return none
 */
void MobileRobot::printStack(std::stack<stackfsm::state::RobotState*> s) {
  while(!s.empty()) {
    std::cout << "[STACK]: " << s.top()-> getName() << "\n";
    s.pop();
  }
}

/**
 * @brief MobileRobot destructor
 */
MobileRobot::~MobileRobot() {
  std::cout << "[LOG]: MobileRobot object destroyed\n";
}

