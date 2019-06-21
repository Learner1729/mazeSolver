/**
 * @file main.cpp
 * @brief Final Project: Solving a Maze
 * 
 * This project presents a software module for Solving a Maze. It also contains
 * a path finding algorithm which is used to solve a maze. The module uses three
 * main classes one for Mobile Robot, one for handling Maze & path search 
 * algorithm and finally, robot state class. There are five derived class from
 * RobotState class for each robot state & two derived class from MobileRobot
 * class for specific type of Robot i.e. Tracked & Wheeled Robot class. It uses
 * the concept of Finite State Machine & Stack i.e. Pushdown Automata for going
 * from one state to other & storing the previous moves.
 * 
 * The found path is the most feasible path by following a particular direction
 * (Present case: NESW direction). Also, the algorithm uses the euclidean
 * distance to move from one position to the next by a step. Once the path is
 * found it gets displayed on the terminal.
 * 
 * If the path doesn't exit for both the robots, the user has to provide new 
 * coordinates.
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

/* -- C++ Includes -- */
#include <iostream>
#include <vector> /* for vector variables */
#include <limits> /* for std::numeric_limits<std::streamsize() */

/* -- User-defined header files -- */
#include "maze/maze.h"

/**
 * @brief Main function, its a entry point of the program
 * 
 * The function is used to initialize the map of the environment, mobileRobot
 * objects and call the algorithm to search the path from robot start position
 * to target goal position.
 *
 * @return 0 Exit success
 */
int main() {
  // a local variable to pass in the maze file
  std::string fileLocation = "../maze/maze.txt";

  // a local variable to keep the track of PATH not found for mobile robots
  // maximum value: 2 & minimum value: 0
  auto count{0};

  do {
    count = 0;
    // create a Maze object using parameterized constructor
    Maze obj(fileLocation, 31, 46);
    std::cout << "\n\n";

    // display the maze after initializing everything
    obj.displayMaze();

    std::cout << "[LOG]: Finding the path for wheeled robot...\n";

    // a variable to store the PATH status for wheelRobot
    bool wheeledRobotStatus = obj.findPath('w');
    if (wheeledRobotStatus) {
      std::cout << "[LOG]: Path found for wheeledRobot\n";
      obj.updateMaze('w');  // update the maze
      obj.displayMaze();    // display the maze
    } else {
      std::cout << "[LOG]: Sorry, path doesn't exit for Wheeled Robot\n";
      obj.emptyStack();   // empty the currentCoordinate_ Stack of Maze class
      count += 1;         // update the count
    }

    std::cout << "[LOG]: Finding the path for tracked robot...\n";

    // a variable to store the PATH status for wheelRobot
    bool trackedRobotStatus = obj.findPath('t');
    if (trackedRobotStatus) {
      std::cout << "[LOG]: Path found for tracked robot\n";
      obj.updateMaze('t');  // update the maze
      obj.displayMaze();    // display the maze
    } else {
      std::cout << "[LOG]: Sorry, path doesn't exit for tracked robot\n";
      obj.emptyStack();     // empty the currentCoordinate_ Stack of Maze class
      count += 1;           // update the count
    }

    if (count == 2)
      std::cout << "[LOG]: Sorry there are no solutions exit for both robots, "
        "please re-enter new coordinates...\n";
  } while (count == 2);  // repeat if path doesn't exit for both robots
  return 0;
}
