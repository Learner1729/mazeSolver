/**
 * @file maze.h
 * @brief Maze class header file
 * 
 * It contains attributes and methods to read, create, display & update maze.
 * It also contains the algorithm for finding path from start position to goal
 * position.
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
 * @bug Bug 1: Explained in presentation. Its related to findPath function
 * @date 05-19-2019
 */

#ifndef __MAZE_FINALPROJECT_MAZE_MAZE_H__
#define __MAZE_FINALPROJECT_MAZE_MAZE_H__

/* -- C++ includes -- */
#include <iostream>
#include <vector>
#include <stack>

/* -- User-defined header files -- */
#include "../mobileRobot/mobileRobot.h"
#include "../utils/travel.h"

/**
 * @brief Maze class handles maze and path finding algorithm.
 */
class Maze {
  public:
    /**
     * @brief Maze class parameterized constructor
     * @param mazeFileName_ a variable of type string, used to store the address
     *        of maze file
     * @param rows_ a variable of type size_t
     * @param cols_ a variable of type size_t
     */
    Maze(const std::string, const std::size_t, const std::size_t);
    
    /**
     * @brief Maze class destructor
     */
    ~Maze();
    
    /**
     * @brief createMaze function, used to create Maze vector from text file
     * @param none
     * @return true, if maze vector is generated
     *         false, if maze vector is not been able to generate
     */
    bool createMaze();
    
    /**
     * @brief displayMaze function, used to display Maze on the terminal
     * @param none
     * @return none
     */
    void displayMaze();
    
    /**
     * @brief checkCoordinates function, used to check whether the coordinates
     *        are not out of bound
     * @param row a variable of type size_t
     * @param column a variable of type size_t
     * @return true, if coordinate is not out of bound
     *         false, if coordinate is out of bound
     */
    bool checkCoordinates(std::size_t, std::size_t);
    
    /**
     * @brief canMove function, used to check whether the location has an 
     *        obstacle or not
     * @param row a variable of type size_t
     * @param column a variable of type size_t
     * @return true, if obstacle is not present
     *         false, if obstacle is present
     */
    bool canMove(std::size_t, std::size_t);
    
    /**
     * @brief isTarget function, used to check whether the robot has reached to
     *        the goal position or not
     * @param row a variable of type size_t
     * @param column a variable of type size_t
     * @param currentY a variable of type size_t
     * @param currentX a variable of type size_t
     * @return true, if the robot has reached the goal position
     *         false, if the robot has not reached the goal position
     */
    bool isTarget(std::size_t, std::size_t, std::size_t, std::size_t);
    
    /**
     * @brief initMobileRobot, a function to initialize mobile robot objects.
     *        It gets called internally by the constructor.
     * @param none
     * @return true, if everything want well
     *         false, if encountered a problem
     */
    bool initMobileRobot();
    
    /**
     * @brief findPath, finds path from start to goal position of a particular 
     *        robot
     * @param robot a variable of type character 
     * @return true, if path found
     *         false, if path doesn't exist
     */
    bool findPath(char);
    
    /**
     * @brief updateMaze function, used to draw a generated path
     * @param robot a variable of type character 
     * @return none
     */
    void updateMaze(char);
    
    /**
     * @brief emptyStack function, used to empty the currentStackCoordinate_ 
     *        used when path doesn't exist
     * @param none 
     * @return none
     */
    void emptyStack();
    
    /**
     * @brief getCoordinates function, used to get the coordinates from the user
     *        It gets called internally by initMobileRobot function.
     * @param name a variable of type character 
     * @return pair, x & y location of a coordinate
     */
    std::pair<std::size_t, std::size_t> getCoordinates(char);
  
  private:
    /**
     * @brief rows_ & cols_ declare variables to store the width and height of
     *        the maze
     */
    const std::size_t rows_, cols_;
    
    /**
     * @brief mazeFileNames_ declare a variable to store the file address of
     *        maze text file.
     */
    const std::string mazeFileName_;
    
    /**
     * @brief maze_ a 2D vector to store the maze
     */
    std::vector<std::vector<char>> maze_;
    
    /**
     * @brief trackedRobot_ a mobileRobot object
     */
    MobileRobot trackedRobot_;
    
    /**
     * @brief wheeledRobot_ a mobileRobot object
     */
    MobileRobot wheeledRobot_;
    
    /**
     * @brief currentStackCoordinate_ a stack to store the path of the robot
     */
    std::stack<std::pair<std::size_t, std::size_t>> currentStackCoordinate_;
};

#endif // __MAZE_FINALPROJECT_MAZE_MAZE_H__
