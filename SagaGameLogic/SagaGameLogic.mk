##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SagaGameLogic
ConfigurationName      :=Debug
WorkspacePath          := "C:\Documents and Settings\Alfredo Barbosa\Meus documentos\Meus Projetos\Saga"
ProjectPath            := "C:\Documents and Settings\Alfredo Barbosa\Meus documentos\Meus Projetos\TFG_Project\trunk\SagaGameLogic"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alfredo Barbosa
Date                   :=11/4/2013
CodeLitePath           :="C:\Arquivos de programas\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="SagaGameLogic.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -std=c++11 -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Arquivos de programas\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/code_character$(ObjectSuffix) $(IntermediateDirectory)/code_stat$(ObjectSuffix) $(IntermediateDirectory)/code_level$(ObjectSuffix) $(IntermediateDirectory)/code_main$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/code_character$(ObjectSuffix): code/character.cpp $(IntermediateDirectory)/code_character$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Documents and Settings/Alfredo Barbosa/Meus documentos/Meus Projetos/TFG_Project/trunk/SagaGameLogic/code/character.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/code_character$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/code_character$(DependSuffix): code/character.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/code_character$(ObjectSuffix) -MF$(IntermediateDirectory)/code_character$(DependSuffix) -MM "code/character.cpp"

$(IntermediateDirectory)/code_character$(PreprocessSuffix): code/character.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/code_character$(PreprocessSuffix) "code/character.cpp"

$(IntermediateDirectory)/code_stat$(ObjectSuffix): code/stat.cpp $(IntermediateDirectory)/code_stat$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Documents and Settings/Alfredo Barbosa/Meus documentos/Meus Projetos/TFG_Project/trunk/SagaGameLogic/code/stat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/code_stat$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/code_stat$(DependSuffix): code/stat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/code_stat$(ObjectSuffix) -MF$(IntermediateDirectory)/code_stat$(DependSuffix) -MM "code/stat.cpp"

$(IntermediateDirectory)/code_stat$(PreprocessSuffix): code/stat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/code_stat$(PreprocessSuffix) "code/stat.cpp"

$(IntermediateDirectory)/code_level$(ObjectSuffix): code/level.cpp $(IntermediateDirectory)/code_level$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Documents and Settings/Alfredo Barbosa/Meus documentos/Meus Projetos/TFG_Project/trunk/SagaGameLogic/code/level.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/code_level$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/code_level$(DependSuffix): code/level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/code_level$(ObjectSuffix) -MF$(IntermediateDirectory)/code_level$(DependSuffix) -MM "code/level.cpp"

$(IntermediateDirectory)/code_level$(PreprocessSuffix): code/level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/code_level$(PreprocessSuffix) "code/level.cpp"

$(IntermediateDirectory)/code_main$(ObjectSuffix): code/main.cpp $(IntermediateDirectory)/code_main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Documents and Settings/Alfredo Barbosa/Meus documentos/Meus Projetos/TFG_Project/trunk/SagaGameLogic/code/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/code_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/code_main$(DependSuffix): code/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/code_main$(ObjectSuffix) -MF$(IntermediateDirectory)/code_main$(DependSuffix) -MM "code/main.cpp"

$(IntermediateDirectory)/code_main$(PreprocessSuffix): code/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/code_main$(PreprocessSuffix) "code/main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/code_character$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/code_character$(DependSuffix)
	$(RM) $(IntermediateDirectory)/code_character$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/code_stat$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/code_stat$(DependSuffix)
	$(RM) $(IntermediateDirectory)/code_stat$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/code_level$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/code_level$(DependSuffix)
	$(RM) $(IntermediateDirectory)/code_level$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/code_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/code_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/code_main$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../../Saga/.build-debug/SagaGameLogic"


