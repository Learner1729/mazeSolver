##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Maze_FinalProject
ConfigurationName      :=Debug
WorkspacePath          :=/home/ashishpatel/Documents/ENPM809Y
ProjectPath            :=/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=AshishPatel
Date                   :=20/05/19
CodeLitePath           :=/home/ashishpatel/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Maze_FinalProject.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_idleState.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) $(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix): robotState/robotState.cpp $(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/robotState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix): robotState/robotState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix) -MM robotState/robotState.cpp

$(IntermediateDirectory)/robotState_robotState.cpp$(PreprocessSuffix): robotState/robotState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_robotState.cpp$(PreprocessSuffix) robotState/robotState.cpp

$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix): robotState/moveDownState.cpp $(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/moveDownState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix): robotState/moveDownState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix) -MM robotState/moveDownState.cpp

$(IntermediateDirectory)/robotState_moveDownState.cpp$(PreprocessSuffix): robotState/moveDownState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveDownState.cpp$(PreprocessSuffix) robotState/moveDownState.cpp

$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix): robotState/moveLeftState.cpp $(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/moveLeftState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix): robotState/moveLeftState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix) -MM robotState/moveLeftState.cpp

$(IntermediateDirectory)/robotState_moveLeftState.cpp$(PreprocessSuffix): robotState/moveLeftState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveLeftState.cpp$(PreprocessSuffix) robotState/moveLeftState.cpp

$(IntermediateDirectory)/robotState_idleState.cpp$(ObjectSuffix): robotState/idleState.cpp $(IntermediateDirectory)/robotState_idleState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/idleState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_idleState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_idleState.cpp$(DependSuffix): robotState/idleState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_idleState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_idleState.cpp$(DependSuffix) -MM robotState/idleState.cpp

$(IntermediateDirectory)/robotState_idleState.cpp$(PreprocessSuffix): robotState/idleState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_idleState.cpp$(PreprocessSuffix) robotState/idleState.cpp

$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix): mobileRobot/tracked.cpp $(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/mobileRobot/tracked.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix): mobileRobot/tracked.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix) -MM mobileRobot/tracked.cpp

$(IntermediateDirectory)/mobileRobot_tracked.cpp$(PreprocessSuffix): mobileRobot/tracked.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_tracked.cpp$(PreprocessSuffix) mobileRobot/tracked.cpp

$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix): maze/maze.cpp $(IntermediateDirectory)/maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maze_maze.cpp$(DependSuffix): maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/maze_maze.cpp$(DependSuffix) -MM maze/maze.cpp

$(IntermediateDirectory)/maze_maze.cpp$(PreprocessSuffix): maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maze_maze.cpp$(PreprocessSuffix) maze/maze.cpp

$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix): mobileRobot/wheeled.cpp $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/mobileRobot/wheeled.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix): mobileRobot/wheeled.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix) -MM mobileRobot/wheeled.cpp

$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(PreprocessSuffix): mobileRobot/wheeled.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(PreprocessSuffix) mobileRobot/wheeled.cpp

$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix): mobileRobot/mobileRobot.cpp $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/mobileRobot/mobileRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix): mobileRobot/mobileRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix) -MM mobileRobot/mobileRobot.cpp

$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(PreprocessSuffix): mobileRobot/mobileRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(PreprocessSuffix) mobileRobot/mobileRobot.cpp

$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix): robotState/moveRightState.cpp $(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/moveRightState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix): robotState/moveRightState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix) -MM robotState/moveRightState.cpp

$(IntermediateDirectory)/robotState_moveRightState.cpp$(PreprocessSuffix): robotState/moveRightState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveRightState.cpp$(PreprocessSuffix) robotState/moveRightState.cpp

$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix): robotState/moveUpState.cpp $(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ashishpatel/Documents/ENPM809Y/Maze_FinalProject/robotState/moveUpState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix): robotState/moveUpState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix) -MM robotState/moveUpState.cpp

$(IntermediateDirectory)/robotState_moveUpState.cpp$(PreprocessSuffix): robotState/moveUpState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveUpState.cpp$(PreprocessSuffix) robotState/moveUpState.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


