/**
 * @file travel.h
 * @brief Declaring enumerated types used in code
 * 
 * It basically represents the a predefined states of robot used in the code.
 * Enumerated types are incredibly useful for code documentation and 
 * readability purposes.
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

#ifndef __MAZE_FINALPROJECT_UTILS_TRAVEL_H___
#define __MAZE_FINALPROJECT_UTILS_TRAVEL_H___

/**
 * @breif An enumeration is a distinct type whose value is restricted to a range of values,
 * which may include several explicitly named constants ("enumerators").
 */
enum Travel {
  UP, // 0
  RIGHT, // 1
  DOWN, // 2
  LEFT, // 3
  IDLE // 4
};

const std::string input_arr[] = {"UP", "RIGHT", "DOWN", "LEFT", "IDLE"};

#endif // __MAZE_FINALPROJECT_UTILS_TRAVEL_H___
