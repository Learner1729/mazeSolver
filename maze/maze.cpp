/**
 * @file maze.cpp
 * @brief Maze class implementation file
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
#include <fstream> /* for reading the map file */
#include <cstdlib> /* for call system to stop */
#include <utility> /* for std::pair, std::make_pair */
#include <cstdlib> /* for abs function */

/* -- User-defined header files -- */
#include "maze.h"

/**
 * @brief Maze class parameterized constructor
 * @param mazeFileName_ a variable of type string, used to store the address
 *        of maze file
 * @param rows_ a variable of type size_t
 * @param cols_ a variable of type size_t
 */
Maze::Maze(const std::string file, const std::size_t rows=31,
  const std::size_t cols=46) : rows_{rows}, cols_{cols}, mazeFileName_{file} {
  if(createMaze()) {
    std::cout << "[LOG]: Map developed!!!\n";
  } else {
    std::cout << "[FAILED]: Sorry, Map can't be developed. Invalid file\n";
    exit(EXIT_FAILURE); // call the system to stop
  }
  if(initMobileRobot()) {
    std::cout << "[LOG]: Start and goal position of MobileRobots are "
      "initialized.\n";
  } else {
    std::cout << "[FAILED]: Problem with the MobileRobots initialization.\n";
    exit(EXIT_FAILURE); // call the system to stop
  }
}

/**
 * @brief Maze class destructor
 */
Maze::~Maze() {
  std::cout << "[LOG]: Maze Destroyed\n";
}

/**
 * @brief createMaze function, used to create Maze vector from text file
 * @param none
 * @return true, if maze vector is generated
 *         false, if maze vector is not been able to generate
 */
bool Maze::createMaze() {
  // resize the maze according to rows & columns
  maze_.resize(rows_, std::vector<char>(cols_));
  
  // ifstream is used for reading files
  // we will read from a file stored in mazeFileName_
  std::ifstream inputFile(mazeFileName_.c_str());
  
  // temporary variable to store a map as a string from the file
  std::string line{};
  std::size_t r{0}, c{0};
  
  // open the file stream
  if (inputFile.is_open()) {
    // read the maze from the file into a 2D vector
    while(std::getline(inputFile, line, '\n')){
      c = 0;
      for (auto mazeElement : line) {
        maze_.at(r).at(c) = mazeElement;
        c += 1;
      }
      r += 1;
    }
    // close the file stream
    inputFile.close();
    return true;
  } else {
    std::cerr << "[FAILED]: Couldn't open the file\n";
    return false;
  }
}

/**
 * @brief displayMaze function, used to display Maze on the terminal
 * @param none
 * @return none
 */
void Maze::displayMaze() {
  for(std::size_t i = 0; i < maze_.size(); ++i) {
    // printing coordinates
    if(i > 20) {
      std::cout << (rows_-1)-i << "  ";
    } else {
      std::cout << (rows_-1)-i << " ";
    }

    // printing maze
    for(std::size_t j = 0; j < maze_.at(0).size(); ++j) {
      std::cout << maze_.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }
  
  // printing coordinates
  std::cout << "   ";
  for(std::size_t k = 0; k < maze_.at(0).size(); ++k) {
    if (k < 10) {
      std::cout << k << " ";
    } else {
      std::cout << (k/10) << " ";
    }
  }
  std::cout << "\n                       ";
  for(std::size_t f = 10; f < maze_.at(0).size(); ++f) {
    std::cout << f%10 << " ";
  }
  std::cout << "\n";
}

/**
 * @brief checkCoordinates function, used to check whether the coordinates are
 *        not out of bound
 * @param row a variable of type size_t
 * @param column a variable of type size_t
 * @return true, if coordinate is not out of bound
 *         false, if coordinate is out of bound
 */
bool Maze::checkCoordinates(std::size_t row, std::size_t column) {
  if((row < rows_ && row >= 0) && (column < cols_ && column >= 0)) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief canMove function, used to check whether the location has an
 *        obstacle or not
 * @param row a variable of type size_t
 * @param column a variable of type size_t
 * @return true, if obstacle is not present
 *         false, if obstacle is present
 */
bool Maze::canMove(std::size_t row, std::size_t column) {
  if(maze_.at(row).at(column) != '#') {
    return true;
  } else {
    return false;
  }
}

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
bool Maze::isTarget(std::size_t row, std::size_t column, std::size_t currentY, std::size_t currentX) {
  if(row == currentY && column == currentX)
    return true;
  else
    return false;
}

/**
 * @brief initMobileRobot, a function to initialize mobile robot objects
 *        It gets called internally by the constructor.
 * @param none
 * @return true, if everything want well
 *         false, if encountered a problem
 */
bool Maze::initMobileRobot() {
  displayMaze();
  std::cout << "\nNote:"
            << "\ny_coordinate corresponds to rows in the map above."
            << "\nx_coordinate corresponds to columns in the map above."
            << "\n\n";
  std::pair<std::size_t, std::size_t> coordinateW, coordinateT, coordinateP, coordinateB;
  
  std::cout << "Enter the start position for the Wheeled x y: ";
  coordinateW = getCoordinates('w');
  
  std::cout << "Enter the start position for the Tracked x y: ";
  coordinateT = getCoordinates('t');
  
  while(true) {
    std::cout << "Enter the position for plate object x y: ";
    coordinateP = getCoordinates('p');
    if(coordinateP != coordinateW || coordinateP != coordinateT)
      break;
    std::cout << "Goal object coordinate has same coordinate to start position coordinate...\n";
  }
  
  while(true) {
    std::cout << "Enter the position for bottle object x y: ";
    coordinateB = getCoordinates('b');
    if(coordinateB != coordinateW || coordinateB != coordinateT)
      break;
    std::cout << "Goal object coordinate has same coordinate to start position coordinate...\n";
  }
  
  if(coordinateW == coordinateT)
    maze_.at(coordinateW.second).at(coordinateW.first) = 'S';
  
  if(coordinateP == coordinateB)
    maze_.at(coordinateP.second).at(coordinateP.first) = 'G';
  
  wheeledRobot_.setStartLocationX(coordinateW.first);
  wheeledRobot_.setStartLocationY(coordinateW.second);
  trackedRobot_.setStartLocationX(coordinateT.first);
  trackedRobot_.setStartLocationY(coordinateT.second);
    
  char character{}; 
  std::cout << "Please enter 'w' if you want wheeled robot to pick plate object or else enter other character: ";
  std::cin >> character;
  if(character == 'w' || character == 'W') {
    wheeledRobot_.setGoalLocationX(coordinateP.first);
    wheeledRobot_.setGoalLocationY(coordinateP.second);
    trackedRobot_.setGoalLocationX(coordinateB.first);
    trackedRobot_.setGoalLocationY(coordinateB.second);
    return true;
  } else {
    wheeledRobot_.setGoalLocationX(coordinateB.first);
    wheeledRobot_.setGoalLocationY(coordinateB.second);
    trackedRobot_.setGoalLocationX(coordinateP.first);
    trackedRobot_.setGoalLocationY(coordinateP.second);
    return true;
  }
}

/**
 * @brief findPath, finds path from start to goal position of a particular 
 *        robot
 * @param robot a variable of type character 
 * @return true, if path found
 *         false, if path doesn't exist
 */
bool Maze::findPath(char robot) {
  std::size_t xSCoordinate{}, ySCoordinate{}, xGCoordinate{}, yGCoordinate{};
  
  // vector to store visited Nodes
  std::vector<std::vector<bool>> visitedSet(rows_, std::vector<bool>(cols_, false));
  
  // this stack is used to store all possible action
  std::stack<Travel> trailStack;
  trailStack.push(IDLE);
  
  // a stack to store the coordinates
  std::pair<std::size_t, std::size_t> pairCoordinate;
  std::stack<std::pair<std::size_t, std::size_t>> trailStackCoordinate;
  
  // a variable to store the current coordinates
  std::size_t currentXCoordinate{}, currentYCoordinate{};
  
  // define the direction vectors for Down, Right, Up & Left
  std::vector<int> dx{0, 1, 0, -1};
  std::vector<int> dy{-1, 0, 1, 0};

  if(robot == 'w') {
    xSCoordinate = wheeledRobot_.getStartLocationX();
    ySCoordinate = wheeledRobot_.getStartLocationY();
    xGCoordinate = wheeledRobot_.getGoalLocationX();
    yGCoordinate = wheeledRobot_.getGoalLocationY();
  } else {
    xSCoordinate = trackedRobot_.getStartLocationX();
    ySCoordinate = trackedRobot_.getStartLocationY();
    xGCoordinate = trackedRobot_.getGoalLocationX();
    yGCoordinate = trackedRobot_.getGoalLocationY();
  }
  
  // mark the start coordinate as visited
  visitedSet.at(ySCoordinate).at(xSCoordinate) = true;
  
  pairCoordinate = std::make_pair(ySCoordinate, xSCoordinate);
  trailStackCoordinate.push(pairCoordinate);
  
  while(!trailStack.empty()) {
    // a variable used to store the status of robot stuck case
    bool stuck{true};
    
    std::size_t neighborX{}, neighborY{};
    
    pairCoordinate = trailStackCoordinate.top();
    currentYCoordinate = pairCoordinate.first;
    currentXCoordinate = pairCoordinate.second;

    // update the current stack
    if(robot == 'w')
      wheeledRobot_.handleMotion(trailStack.top());
    else
      trackedRobot_.handleMotion(trailStack.top());
    currentStackCoordinate_.push(trailStackCoordinate.top());
    
    // remove the coordinates from trail stack
    trailStack.pop();
    trailStackCoordinate.pop();
    
    // Exploring all four directions horizontally & vertically
    // DOWN -> RIGHT -> UP -> LEFT direction
    for(auto i=0; i<4; ++i) {
      neighborX = currentXCoordinate + dx.at(i);
      neighborY = currentYCoordinate + dy.at(i);
      if(checkCoordinates(neighborY, neighborX)) {
        if(!visitedSet.at(neighborY).at(neighborX)) {
          if(canMove(neighborY, neighborX)) {
            // Update the trailStack
            if(i == 0)
              trailStack.push(UP);
            else if(i == 1)
              trailStack.push(RIGHT);
            else if(i == 2)
              trailStack.push(DOWN);
            else
              trailStack.push(LEFT);
            
            pairCoordinate = std::make_pair(neighborY, neighborX);
            trailStackCoordinate.push(pairCoordinate);
            stuck = false;
            visitedSet.at(neighborY).at(neighborX) = true;
            
            // check whether the generated neighbor node is a goal node or not
            if(isTarget(neighborY, neighborX, yGCoordinate, xGCoordinate)) {
              if(robot == 'w') {
                wheeledRobot_.handleMotion(trailStack.top());
                wheeledRobot_.handleMotion(IDLE);
                wheeledRobot_.printStack(wheeledRobot_.getStack());
              } else {
                trackedRobot_.handleMotion(trailStack.top());
                trackedRobot_.handleMotion(IDLE);
                trackedRobot_.printStack(trackedRobot_.getStack());
              }
              currentStackCoordinate_.push(trailStackCoordinate.top());
              return true;
            }
          }
        }
      }
    }
    
    // loop used when there are no new neighbor node of the current node
    while(stuck) {
      if(trailStack.empty())
        return false;
      std::pair<std::size_t, std::size_t> topCurrent = currentStackCoordinate_.top();
      std::pair<std::size_t, std::size_t> topTrail = trailStackCoordinate.top();
      if(abs(topCurrent.first - topTrail.first) + abs(topCurrent.second - topTrail.second) == 1) {
        stuck = false;
        break;
      }
      if(robot == 'w')
        wheeledRobot_.removeOne();
      else
        trackedRobot_.removeOne();
      currentStackCoordinate_.pop();
    }
  }
  return false;
}

/**
 * @brief updateMaze function, used to draw a generated path
 * @param robot a variable of type character 
 * @return none
 */
void Maze::updateMaze(char character) {
  if(character == 'w') {
    character = '-';
  } else {
    character = '|';
  }
  while(!currentStackCoordinate_.empty()) {
    std::pair<std::size_t, std::size_t> val = currentStackCoordinate_.top();
    currentStackCoordinate_.pop();
    std::cout << "[Coordinate]: (" << val.second << ", " << (rows_ - 1) - val.first << ")" << "\n";
    if(character == '|') {
      if(maze_.at(val.first).at(val.second) == '-') {
        maze_.at(val.first).at(val.second) = '+';
        continue;
      }
    }
    if(maze_.at(val.first).at(val.second) == 'w' || maze_.at(val.first).at(val.second) == 'p' ||
       maze_.at(val.first).at(val.second) == 'b' || maze_.at(val.first).at(val.second) == 't' || 
       maze_.at(val.first).at(val.second) == 'S' || maze_.at(val.first).at(val.second) == 'G')
      continue;
    maze_.at(val.first).at(val.second) = character;
  }
}

/**
 * @brief getCoordinates function, used to get the coordinates from the user
 *        It gets called internally by initMobileRobot function.
 * @param name a variable of type character 
 * @return pair, x & y location of a coordinate
 */
std::pair<std::size_t, std::size_t> Maze::getCoordinates(char name) {
  std::pair<std::size_t, std::size_t> coordinate;
  std::size_t xCoordinate{}, yCoordinate{};
  // ask user for start position coordinates
  do {
    std::cin >> xCoordinate >> yCoordinate;
    // check for failed extraction
    if (std::cin.fail()) {
      // a) Put us back in 'normal' operation mode
      std::cin.clear();
      // b) remove the bad input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // c) request for input again
      std::cout << "Invalid Input, enter integers please.\n";
      std::cout << "Please re-enter the coordinates again: ";
    } else {
      std::cout << "Entered Coordinates (x,y): (" << xCoordinate
                << "," << yCoordinate << ")"
                << "\n";
      yCoordinate = (rows_ - 1) - yCoordinate;
      // check whether the entered cooridinates are valid or not
      if (checkCoordinates(yCoordinate, xCoordinate)) {
        if (maze_.at(yCoordinate).at(xCoordinate) != '#') {
          maze_.at(yCoordinate).at(xCoordinate) = name;
          coordinate = std::make_pair(xCoordinate, yCoordinate);
          break;
        } else {
          std::cout << "Invalid: Position is occupied.\n";
          std::cout << "Please re-enter the coordinates again: ";
        }
      } else {
        std::cout << "Invalid: Entered coordinates are outside the maze.\n";
        std::cout << "Please re-enter the coordinates again: ";
      }
      // remove any extraneous input so that it doesn't impact next input.
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (true);
  return coordinate;
}

/**
 * @brief emptyStack function, used to empty the currentStackCoordinate_ 
 *        used when path doesn't exist
 * @param none 
 * @return none
 */
void Maze::emptyStack(){
  while(!currentStackCoordinate_.empty())
    currentStackCoordinate_.pop();
}