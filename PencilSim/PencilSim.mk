##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PencilSim
ConfigurationName      :=Debug
WorkspacePath          :=/home/dan/Documents/PencilSim
ProjectPath            :=/home/dan/Documents/PencilSim/PencilSim
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Dan
Date                   :=27/05/17
CodeLitePath           :=/home/dan/.codelite
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
ObjectsFileList        :="PencilSim.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./Catch/include/ 
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
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Paper.cpp$(ObjectSuffix) $(IntermediateDirectory)/PaperTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/PencilTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pencil.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Paper.cpp$(ObjectSuffix): Paper.cpp $(IntermediateDirectory)/Paper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dan/Documents/PencilSim/PencilSim/Paper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Paper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Paper.cpp$(DependSuffix): Paper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Paper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Paper.cpp$(DependSuffix) -MM Paper.cpp

$(IntermediateDirectory)/Paper.cpp$(PreprocessSuffix): Paper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Paper.cpp$(PreprocessSuffix) Paper.cpp

$(IntermediateDirectory)/PaperTest.cpp$(ObjectSuffix): PaperTest.cpp $(IntermediateDirectory)/PaperTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dan/Documents/PencilSim/PencilSim/PaperTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PaperTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PaperTest.cpp$(DependSuffix): PaperTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PaperTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PaperTest.cpp$(DependSuffix) -MM PaperTest.cpp

$(IntermediateDirectory)/PaperTest.cpp$(PreprocessSuffix): PaperTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PaperTest.cpp$(PreprocessSuffix) PaperTest.cpp

$(IntermediateDirectory)/PencilTest.cpp$(ObjectSuffix): PencilTest.cpp $(IntermediateDirectory)/PencilTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dan/Documents/PencilSim/PencilSim/PencilTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PencilTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PencilTest.cpp$(DependSuffix): PencilTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PencilTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PencilTest.cpp$(DependSuffix) -MM PencilTest.cpp

$(IntermediateDirectory)/PencilTest.cpp$(PreprocessSuffix): PencilTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PencilTest.cpp$(PreprocessSuffix) PencilTest.cpp

$(IntermediateDirectory)/Pencil.cpp$(ObjectSuffix): Pencil.cpp $(IntermediateDirectory)/Pencil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dan/Documents/PencilSim/PencilSim/Pencil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pencil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pencil.cpp$(DependSuffix): Pencil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pencil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pencil.cpp$(DependSuffix) -MM Pencil.cpp

$(IntermediateDirectory)/Pencil.cpp$(PreprocessSuffix): Pencil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pencil.cpp$(PreprocessSuffix) Pencil.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


