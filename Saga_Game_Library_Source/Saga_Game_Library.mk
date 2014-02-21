##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Saga_Game_Library
ConfigurationName      :=Release
WorkspacePath          := "/media/Dados/Arquivos/Documentos/IDEs/Codelite/My Projects"
ProjectPath            := "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Michell Stuttgart
Date                   :=02/20/14
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
CXXFLAGS := -std=c++0x -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/allegro_starter$(ObjectSuffix) $(IntermediateDirectory)/video_manager$(ObjectSuffix) $(IntermediateDirectory)/resource_map$(ObjectSuffix) $(IntermediateDirectory)/resource$(ObjectSuffix) $(IntermediateDirectory)/image_resource$(ObjectSuffix) $(IntermediateDirectory)/image$(ObjectSuffix) $(IntermediateDirectory)/exception$(ObjectSuffix) $(IntermediateDirectory)/animation$(ObjectSuffix) $(IntermediateDirectory)/sprite$(ObjectSuffix) \
	$(IntermediateDirectory)/point$(ObjectSuffix) $(IntermediateDirectory)/util$(ObjectSuffix) $(IntermediateDirectory)/surface$(ObjectSuffix) $(IntermediateDirectory)/tile$(ObjectSuffix) $(IntermediateDirectory)/tile_set$(ObjectSuffix) $(IntermediateDirectory)/layer$(ObjectSuffix) $(IntermediateDirectory)/tile_map$(ObjectSuffix) $(IntermediateDirectory)/collision_rect$(ObjectSuffix) $(IntermediateDirectory)/collision_circle$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix) \
	$(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/allegro_starter$(ObjectSuffix): allegro_starter.cpp $(IntermediateDirectory)/allegro_starter$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/allegro_starter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/allegro_starter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/allegro_starter$(DependSuffix): allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/allegro_starter$(ObjectSuffix) -MF$(IntermediateDirectory)/allegro_starter$(DependSuffix) -MM "allegro_starter.cpp"

$(IntermediateDirectory)/allegro_starter$(PreprocessSuffix): allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/allegro_starter$(PreprocessSuffix) "allegro_starter.cpp"

$(IntermediateDirectory)/video_manager$(ObjectSuffix): video_manager.cpp $(IntermediateDirectory)/video_manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/video_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/video_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/video_manager$(DependSuffix): video_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/video_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/video_manager$(DependSuffix) -MM "video_manager.cpp"

$(IntermediateDirectory)/video_manager$(PreprocessSuffix): video_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/video_manager$(PreprocessSuffix) "video_manager.cpp"

$(IntermediateDirectory)/resource_map$(ObjectSuffix): resource_map.cpp $(IntermediateDirectory)/resource_map$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/resource_map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resource_map$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource_map$(DependSuffix): resource_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resource_map$(ObjectSuffix) -MF$(IntermediateDirectory)/resource_map$(DependSuffix) -MM "resource_map.cpp"

$(IntermediateDirectory)/resource_map$(PreprocessSuffix): resource_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resource_map$(PreprocessSuffix) "resource_map.cpp"

$(IntermediateDirectory)/resource$(ObjectSuffix): resource.cpp $(IntermediateDirectory)/resource$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource$(DependSuffix): resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resource$(ObjectSuffix) -MF$(IntermediateDirectory)/resource$(DependSuffix) -MM "resource.cpp"

$(IntermediateDirectory)/resource$(PreprocessSuffix): resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resource$(PreprocessSuffix) "resource.cpp"

$(IntermediateDirectory)/image_resource$(ObjectSuffix): image_resource.cpp $(IntermediateDirectory)/image_resource$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/image_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/image_resource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/image_resource$(DependSuffix): image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/image_resource$(ObjectSuffix) -MF$(IntermediateDirectory)/image_resource$(DependSuffix) -MM "image_resource.cpp"

$(IntermediateDirectory)/image_resource$(PreprocessSuffix): image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/image_resource$(PreprocessSuffix) "image_resource.cpp"

$(IntermediateDirectory)/image$(ObjectSuffix): image.cpp $(IntermediateDirectory)/image$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/image$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/image$(DependSuffix): image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/image$(ObjectSuffix) -MF$(IntermediateDirectory)/image$(DependSuffix) -MM "image.cpp"

$(IntermediateDirectory)/image$(PreprocessSuffix): image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/image$(PreprocessSuffix) "image.cpp"

$(IntermediateDirectory)/exception$(ObjectSuffix): exception.cpp $(IntermediateDirectory)/exception$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/exception$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/exception$(DependSuffix): exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/exception$(ObjectSuffix) -MF$(IntermediateDirectory)/exception$(DependSuffix) -MM "exception.cpp"

$(IntermediateDirectory)/exception$(PreprocessSuffix): exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/exception$(PreprocessSuffix) "exception.cpp"

$(IntermediateDirectory)/animation$(ObjectSuffix): animation.cpp $(IntermediateDirectory)/animation$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/animation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animation$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animation$(DependSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animation$(ObjectSuffix) -MF$(IntermediateDirectory)/animation$(DependSuffix) -MM "animation.cpp"

$(IntermediateDirectory)/animation$(PreprocessSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animation$(PreprocessSuffix) "animation.cpp"

$(IntermediateDirectory)/sprite$(ObjectSuffix): sprite.cpp $(IntermediateDirectory)/sprite$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprite$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprite$(DependSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprite$(ObjectSuffix) -MF$(IntermediateDirectory)/sprite$(DependSuffix) -MM "sprite.cpp"

$(IntermediateDirectory)/sprite$(PreprocessSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprite$(PreprocessSuffix) "sprite.cpp"

$(IntermediateDirectory)/point$(ObjectSuffix): point.cpp $(IntermediateDirectory)/point$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/point.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/point$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/point$(DependSuffix): point.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/point$(ObjectSuffix) -MF$(IntermediateDirectory)/point$(DependSuffix) -MM "point.cpp"

$(IntermediateDirectory)/point$(PreprocessSuffix): point.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/point$(PreprocessSuffix) "point.cpp"

$(IntermediateDirectory)/util$(ObjectSuffix): util.cpp $(IntermediateDirectory)/util$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util$(DependSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util$(ObjectSuffix) -MF$(IntermediateDirectory)/util$(DependSuffix) -MM "util.cpp"

$(IntermediateDirectory)/util$(PreprocessSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util$(PreprocessSuffix) "util.cpp"

$(IntermediateDirectory)/surface$(ObjectSuffix): surface.cpp $(IntermediateDirectory)/surface$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/surface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/surface$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/surface$(DependSuffix): surface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/surface$(ObjectSuffix) -MF$(IntermediateDirectory)/surface$(DependSuffix) -MM "surface.cpp"

$(IntermediateDirectory)/surface$(PreprocessSuffix): surface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/surface$(PreprocessSuffix) "surface.cpp"

$(IntermediateDirectory)/tile$(ObjectSuffix): tile.cpp $(IntermediateDirectory)/tile$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tile$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tile$(DependSuffix): tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tile$(ObjectSuffix) -MF$(IntermediateDirectory)/tile$(DependSuffix) -MM "tile.cpp"

$(IntermediateDirectory)/tile$(PreprocessSuffix): tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tile$(PreprocessSuffix) "tile.cpp"

$(IntermediateDirectory)/tile_set$(ObjectSuffix): tile_set.cpp $(IntermediateDirectory)/tile_set$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tile_set.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tile_set$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tile_set$(DependSuffix): tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tile_set$(ObjectSuffix) -MF$(IntermediateDirectory)/tile_set$(DependSuffix) -MM "tile_set.cpp"

$(IntermediateDirectory)/tile_set$(PreprocessSuffix): tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tile_set$(PreprocessSuffix) "tile_set.cpp"

$(IntermediateDirectory)/layer$(ObjectSuffix): layer.cpp $(IntermediateDirectory)/layer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/layer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/layer$(DependSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/layer$(ObjectSuffix) -MF$(IntermediateDirectory)/layer$(DependSuffix) -MM "layer.cpp"

$(IntermediateDirectory)/layer$(PreprocessSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/layer$(PreprocessSuffix) "layer.cpp"

$(IntermediateDirectory)/tile_map$(ObjectSuffix): tile_map.cpp $(IntermediateDirectory)/tile_map$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tile_map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tile_map$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tile_map$(DependSuffix): tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tile_map$(ObjectSuffix) -MF$(IntermediateDirectory)/tile_map$(DependSuffix) -MM "tile_map.cpp"

$(IntermediateDirectory)/tile_map$(PreprocessSuffix): tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tile_map$(PreprocessSuffix) "tile_map.cpp"

$(IntermediateDirectory)/collision_rect$(ObjectSuffix): collision_rect.cpp $(IntermediateDirectory)/collision_rect$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/collision_rect.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/collision_rect$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/collision_rect$(DependSuffix): collision_rect.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/collision_rect$(ObjectSuffix) -MF$(IntermediateDirectory)/collision_rect$(DependSuffix) -MM "collision_rect.cpp"

$(IntermediateDirectory)/collision_rect$(PreprocessSuffix): collision_rect.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/collision_rect$(PreprocessSuffix) "collision_rect.cpp"

$(IntermediateDirectory)/collision_circle$(ObjectSuffix): collision_circle.cpp $(IntermediateDirectory)/collision_circle$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/collision_circle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/collision_circle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/collision_circle$(DependSuffix): collision_circle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/collision_circle$(ObjectSuffix) -MF$(IntermediateDirectory)/collision_circle$(DependSuffix) -MM "collision_circle.cpp"

$(IntermediateDirectory)/collision_circle$(PreprocessSuffix): collision_circle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/collision_circle$(PreprocessSuffix) "collision_circle.cpp"

$(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix): tinyxml/tinystr.cpp $(IntermediateDirectory)/tinyxml_tinystr$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinystr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinystr$(DependSuffix): tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinystr$(DependSuffix) -MM "tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinystr$(PreprocessSuffix): tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinystr$(PreprocessSuffix) "tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix): tinyxml/tinyxml.cpp $(IntermediateDirectory)/tinyxml_tinyxml$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxml$(DependSuffix): tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxml$(DependSuffix) -MM "tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml$(PreprocessSuffix): tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxml$(PreprocessSuffix) "tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix): tinyxml/tinyxmlerror.cpp $(IntermediateDirectory)/tinyxml_tinyxmlerror$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxmlerror.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlerror$(DependSuffix): tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlerror$(DependSuffix) -MM "tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror$(PreprocessSuffix): tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(PreprocessSuffix) "tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix): tinyxml/tinyxmlparser.cpp $(IntermediateDirectory)/tinyxml_tinyxmlparser$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxmlparser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlparser$(DependSuffix): tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlparser$(DependSuffix) -MM "tinyxml/tinyxmlparser.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser$(PreprocessSuffix): tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(PreprocessSuffix) "tinyxml/tinyxmlparser.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource_map$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource_map$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource_map$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/image$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/image$(DependSuffix)
	$(RM) $(IntermediateDirectory)/image$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/exception$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/exception$(DependSuffix)
	$(RM) $(IntermediateDirectory)/exception$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/animation$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/animation$(DependSuffix)
	$(RM) $(IntermediateDirectory)/animation$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/point$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/point$(DependSuffix)
	$(RM) $(IntermediateDirectory)/point$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/util$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/util$(DependSuffix)
	$(RM) $(IntermediateDirectory)/util$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/surface$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/surface$(DependSuffix)
	$(RM) $(IntermediateDirectory)/surface$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/layer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/layer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/layer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/collision_rect$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/collision_rect$(DependSuffix)
	$(RM) $(IntermediateDirectory)/collision_rect$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/collision_circle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/collision_circle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/collision_circle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../../../../IDEs/Codelite/My Projects/.build-release/Saga_Game_Library"


