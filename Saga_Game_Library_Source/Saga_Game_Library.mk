##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Saga_Game_Library
ConfigurationName      :=Release
WorkspacePath          := "/home/michell/.codelite/My_Projects"
ProjectPath            := "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=michell
Date                   :=12/23/2013
CodeLitePath           :="/home/michell/.codelite"
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
ObjectsFileList        :="Saga_Game_Library.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro -lallegro_image -lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec 
ArLibs                 :=  "allegro -lallegro_image -lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -std=c++0x -O2 -Wall  -DSVN_REVISION=\"\"  $(Preprocessors)
CFLAGS   :=  -O2 -Wall  -DSVN_REVISION=\"\"  $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LC_MESSAGES:=C
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/Exception$(ObjectSuffix) $(IntermediateDirectory)/ResourceException$(ObjectSuffix) $(IntermediateDirectory)/IOException$(ObjectSuffix) $(IntermediateDirectory)/HardawareException$(ObjectSuffix) $(IntermediateDirectory)/FileException$(ObjectSuffix) $(IntermediateDirectory)/AddOnException$(ObjectSuffix) $(IntermediateDirectory)/AllegroAddON$(ObjectSuffix) $(IntermediateDirectory)/AudioAddON$(ObjectSuffix) $(IntermediateDirectory)/FontAddON$(ObjectSuffix) \
	$(IntermediateDirectory)/ImageAddON$(ObjectSuffix) $(IntermediateDirectory)/KeyboardAddON$(ObjectSuffix) $(IntermediateDirectory)/MouseAddON$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Exception$(ObjectSuffix): Exception.cpp $(IntermediateDirectory)/Exception$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/Exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exception$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exception$(DependSuffix): Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exception$(ObjectSuffix) -MF$(IntermediateDirectory)/Exception$(DependSuffix) -MM "Exception.cpp"

$(IntermediateDirectory)/Exception$(PreprocessSuffix): Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exception$(PreprocessSuffix) "Exception.cpp"

$(IntermediateDirectory)/ResourceException$(ObjectSuffix): ResourceException.cpp $(IntermediateDirectory)/ResourceException$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/ResourceException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ResourceException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ResourceException$(DependSuffix): ResourceException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ResourceException$(ObjectSuffix) -MF$(IntermediateDirectory)/ResourceException$(DependSuffix) -MM "ResourceException.cpp"

$(IntermediateDirectory)/ResourceException$(PreprocessSuffix): ResourceException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ResourceException$(PreprocessSuffix) "ResourceException.cpp"

$(IntermediateDirectory)/IOException$(ObjectSuffix): IOException.cpp $(IntermediateDirectory)/IOException$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/IOException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IOException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IOException$(DependSuffix): IOException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IOException$(ObjectSuffix) -MF$(IntermediateDirectory)/IOException$(DependSuffix) -MM "IOException.cpp"

$(IntermediateDirectory)/IOException$(PreprocessSuffix): IOException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IOException$(PreprocessSuffix) "IOException.cpp"

$(IntermediateDirectory)/HardawareException$(ObjectSuffix): HardawareException.cpp $(IntermediateDirectory)/HardawareException$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/HardawareException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HardawareException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HardawareException$(DependSuffix): HardawareException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HardawareException$(ObjectSuffix) -MF$(IntermediateDirectory)/HardawareException$(DependSuffix) -MM "HardawareException.cpp"

$(IntermediateDirectory)/HardawareException$(PreprocessSuffix): HardawareException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HardawareException$(PreprocessSuffix) "HardawareException.cpp"

$(IntermediateDirectory)/FileException$(ObjectSuffix): FileException.cpp $(IntermediateDirectory)/FileException$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/FileException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileException$(DependSuffix): FileException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileException$(ObjectSuffix) -MF$(IntermediateDirectory)/FileException$(DependSuffix) -MM "FileException.cpp"

$(IntermediateDirectory)/FileException$(PreprocessSuffix): FileException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileException$(PreprocessSuffix) "FileException.cpp"

$(IntermediateDirectory)/AddOnException$(ObjectSuffix): AddOnException.cpp $(IntermediateDirectory)/AddOnException$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/AddOnException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AddOnException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AddOnException$(DependSuffix): AddOnException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AddOnException$(ObjectSuffix) -MF$(IntermediateDirectory)/AddOnException$(DependSuffix) -MM "AddOnException.cpp"

$(IntermediateDirectory)/AddOnException$(PreprocessSuffix): AddOnException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AddOnException$(PreprocessSuffix) "AddOnException.cpp"

$(IntermediateDirectory)/AllegroAddON$(ObjectSuffix): AllegroAddON.cpp $(IntermediateDirectory)/AllegroAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/AllegroAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AllegroAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AllegroAddON$(DependSuffix): AllegroAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AllegroAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/AllegroAddON$(DependSuffix) -MM "AllegroAddON.cpp"

$(IntermediateDirectory)/AllegroAddON$(PreprocessSuffix): AllegroAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AllegroAddON$(PreprocessSuffix) "AllegroAddON.cpp"

$(IntermediateDirectory)/AudioAddON$(ObjectSuffix): AudioAddON.cpp $(IntermediateDirectory)/AudioAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/AudioAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AudioAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AudioAddON$(DependSuffix): AudioAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AudioAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/AudioAddON$(DependSuffix) -MM "AudioAddON.cpp"

$(IntermediateDirectory)/AudioAddON$(PreprocessSuffix): AudioAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AudioAddON$(PreprocessSuffix) "AudioAddON.cpp"

$(IntermediateDirectory)/FontAddON$(ObjectSuffix): FontAddON.cpp $(IntermediateDirectory)/FontAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/FontAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FontAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FontAddON$(DependSuffix): FontAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FontAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/FontAddON$(DependSuffix) -MM "FontAddON.cpp"

$(IntermediateDirectory)/FontAddON$(PreprocessSuffix): FontAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FontAddON$(PreprocessSuffix) "FontAddON.cpp"

$(IntermediateDirectory)/ImageAddON$(ObjectSuffix): ImageAddON.cpp $(IntermediateDirectory)/ImageAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/ImageAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageAddON$(DependSuffix): ImageAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageAddON$(DependSuffix) -MM "ImageAddON.cpp"

$(IntermediateDirectory)/ImageAddON$(PreprocessSuffix): ImageAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageAddON$(PreprocessSuffix) "ImageAddON.cpp"

$(IntermediateDirectory)/KeyboardAddON$(ObjectSuffix): KeyboardAddON.cpp $(IntermediateDirectory)/KeyboardAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/KeyboardAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KeyboardAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KeyboardAddON$(DependSuffix): KeyboardAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KeyboardAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/KeyboardAddON$(DependSuffix) -MM "KeyboardAddON.cpp"

$(IntermediateDirectory)/KeyboardAddON$(PreprocessSuffix): KeyboardAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KeyboardAddON$(PreprocessSuffix) "KeyboardAddON.cpp"

$(IntermediateDirectory)/MouseAddON$(ObjectSuffix): MouseAddON.cpp $(IntermediateDirectory)/MouseAddON$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TFG_Project/tfg_project/trunk/Saga_Game_Library_Src/MouseAddON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MouseAddON$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MouseAddON$(DependSuffix): MouseAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MouseAddON$(ObjectSuffix) -MF$(IntermediateDirectory)/MouseAddON$(DependSuffix) -MM "MouseAddON.cpp"

$(IntermediateDirectory)/MouseAddON$(PreprocessSuffix): MouseAddON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MouseAddON$(PreprocessSuffix) "MouseAddON.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Exception$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Exception$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Exception$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ResourceException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ResourceException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ResourceException$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/IOException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/IOException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/IOException$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/HardawareException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/HardawareException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/HardawareException$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FileException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FileException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FileException$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AddOnException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AddOnException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AddOnException$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AllegroAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AllegroAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AllegroAddON$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AudioAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AudioAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AudioAddON$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/FontAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/FontAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/FontAddON$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ImageAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ImageAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ImageAddON$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/KeyboardAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/KeyboardAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/KeyboardAddON$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MouseAddON$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MouseAddON$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MouseAddON$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../../../../../../../../home/michell/.codelite/My_Projects/.build-release/Saga_Game_Library"


