/**
 * @file tracked.cpp
 * @brief Tracked class header file
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

#ifndef __MAZE_FINALPROJECT_MOBILEROBOT_TRACKED_H__
#define __MAZE_FINALPROJECT_MOBILEROBOT_TRACKED_H__

/* -- User-defined header files -- */
#include "mobileRobot.h" /* for including base class: mobileRobot */

/**
 * @brief Tracked class is a publicly derived class of MobileRobot class
 *        Can be used to declare specific attributes regarding Tracked Robot
 */
class Tracked : public MobileRobot {
  public:
    /**
     * @brief Tracked class constructor
     */
    Tracked();
    
    /**
     * @brief Tracked class destructor
     */
    virtual ~Tracked();
};

#endif // __MAZE_FINALPROJECT_MOBILEROBOT_TRACKED_H__
