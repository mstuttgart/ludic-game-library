##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Saga_Game_Library
ConfigurationName      :=Debug
WorkspacePath          := "/media/Dados/Arquivos/Documentos/IDEs/Codelite/My Projects"
ProjectPath            := "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Michell Stuttgart
Date                   :=04/08/14
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
Libs                   := $(LibrarySwitch)allegro -lallegro_image -lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec -lallegro_color 
ArLibs                 :=  "allegro -lallegro_image -lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_audio -lallegro_acodec -lallegro_color" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -pg -g -W -std=c++0x  -pg -g -W -Wall -std=c++0x -O0 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/allegro_starter$(ObjectSuffix) $(IntermediateDirectory)/video_manager$(ObjectSuffix) $(IntermediateDirectory)/resource$(ObjectSuffix) $(IntermediateDirectory)/image_resource$(ObjectSuffix) $(IntermediateDirectory)/animation$(ObjectSuffix) $(IntermediateDirectory)/util$(ObjectSuffix) $(IntermediateDirectory)/tile$(ObjectSuffix) $(IntermediateDirectory)/tile_set$(ObjectSuffix) $(IntermediateDirectory)/tile_map$(ObjectSuffix) $(IntermediateDirectory)/font_resource$(ObjectSuffix) \
	$(IntermediateDirectory)/tiled_layer$(ObjectSuffix) $(IntermediateDirectory)/layer$(ObjectSuffix) $(IntermediateDirectory)/animated_sprite$(ObjectSuffix) $(IntermediateDirectory)/sprite$(ObjectSuffix) $(IntermediateDirectory)/static_sprite$(ObjectSuffix) $(IntermediateDirectory)/sgl_exception$(ObjectSuffix) $(IntermediateDirectory)/font$(ObjectSuffix) $(IntermediateDirectory)/color$(ObjectSuffix) $(IntermediateDirectory)/resource_manager$(ObjectSuffix) $(IntermediateDirectory)/bouding_box$(ObjectSuffix) \
	$(IntermediateDirectory)/keyboard_manager$(ObjectSuffix) $(IntermediateDirectory)/mouse_manager$(ObjectSuffix) $(IntermediateDirectory)/time_handler$(ObjectSuffix) $(IntermediateDirectory)/event_manager$(ObjectSuffix) $(IntermediateDirectory)/event_source$(ObjectSuffix) $(IntermediateDirectory)/vector2_d$(ObjectSuffix) $(IntermediateDirectory)/audio_resource$(ObjectSuffix) $(IntermediateDirectory)/sample$(ObjectSuffix) $(IntermediateDirectory)/stream$(ObjectSuffix) $(IntermediateDirectory)/application$(ObjectSuffix) \
	$(IntermediateDirectory)/scene$(ObjectSuffix) $(IntermediateDirectory)/mainApp$(ObjectSuffix) $(IntermediateDirectory)/io_data_stream$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinystr$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxml$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlerror$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlparser$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
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

$(IntermediateDirectory)/animation$(ObjectSuffix): animation.cpp $(IntermediateDirectory)/animation$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/animation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animation$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animation$(DependSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animation$(ObjectSuffix) -MF$(IntermediateDirectory)/animation$(DependSuffix) -MM "animation.cpp"

$(IntermediateDirectory)/animation$(PreprocessSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animation$(PreprocessSuffix) "animation.cpp"

$(IntermediateDirectory)/util$(ObjectSuffix): util.cpp $(IntermediateDirectory)/util$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util$(DependSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util$(ObjectSuffix) -MF$(IntermediateDirectory)/util$(DependSuffix) -MM "util.cpp"

$(IntermediateDirectory)/util$(PreprocessSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util$(PreprocessSuffix) "util.cpp"

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

$(IntermediateDirectory)/tile_map$(ObjectSuffix): tile_map.cpp $(IntermediateDirectory)/tile_map$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tile_map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tile_map$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tile_map$(DependSuffix): tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tile_map$(ObjectSuffix) -MF$(IntermediateDirectory)/tile_map$(DependSuffix) -MM "tile_map.cpp"

$(IntermediateDirectory)/tile_map$(PreprocessSuffix): tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tile_map$(PreprocessSuffix) "tile_map.cpp"

$(IntermediateDirectory)/font_resource$(ObjectSuffix): font_resource.cpp $(IntermediateDirectory)/font_resource$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/font_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/font_resource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/font_resource$(DependSuffix): font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/font_resource$(ObjectSuffix) -MF$(IntermediateDirectory)/font_resource$(DependSuffix) -MM "font_resource.cpp"

$(IntermediateDirectory)/font_resource$(PreprocessSuffix): font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/font_resource$(PreprocessSuffix) "font_resource.cpp"

$(IntermediateDirectory)/tiled_layer$(ObjectSuffix): tiled_layer.cpp $(IntermediateDirectory)/tiled_layer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tiled_layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tiled_layer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tiled_layer$(DependSuffix): tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tiled_layer$(ObjectSuffix) -MF$(IntermediateDirectory)/tiled_layer$(DependSuffix) -MM "tiled_layer.cpp"

$(IntermediateDirectory)/tiled_layer$(PreprocessSuffix): tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tiled_layer$(PreprocessSuffix) "tiled_layer.cpp"

$(IntermediateDirectory)/layer$(ObjectSuffix): layer.cpp $(IntermediateDirectory)/layer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/layer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/layer$(DependSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/layer$(ObjectSuffix) -MF$(IntermediateDirectory)/layer$(DependSuffix) -MM "layer.cpp"

$(IntermediateDirectory)/layer$(PreprocessSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/layer$(PreprocessSuffix) "layer.cpp"

$(IntermediateDirectory)/animated_sprite$(ObjectSuffix): animated_sprite.cpp $(IntermediateDirectory)/animated_sprite$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/animated_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animated_sprite$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animated_sprite$(DependSuffix): animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animated_sprite$(ObjectSuffix) -MF$(IntermediateDirectory)/animated_sprite$(DependSuffix) -MM "animated_sprite.cpp"

$(IntermediateDirectory)/animated_sprite$(PreprocessSuffix): animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animated_sprite$(PreprocessSuffix) "animated_sprite.cpp"

$(IntermediateDirectory)/sprite$(ObjectSuffix): sprite.cpp $(IntermediateDirectory)/sprite$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprite$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprite$(DependSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprite$(ObjectSuffix) -MF$(IntermediateDirectory)/sprite$(DependSuffix) -MM "sprite.cpp"

$(IntermediateDirectory)/sprite$(PreprocessSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprite$(PreprocessSuffix) "sprite.cpp"

$(IntermediateDirectory)/static_sprite$(ObjectSuffix): static_sprite.cpp $(IntermediateDirectory)/static_sprite$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/static_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/static_sprite$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/static_sprite$(DependSuffix): static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/static_sprite$(ObjectSuffix) -MF$(IntermediateDirectory)/static_sprite$(DependSuffix) -MM "static_sprite.cpp"

$(IntermediateDirectory)/static_sprite$(PreprocessSuffix): static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/static_sprite$(PreprocessSuffix) "static_sprite.cpp"

$(IntermediateDirectory)/sgl_exception$(ObjectSuffix): sgl_exception.cpp $(IntermediateDirectory)/sgl_exception$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sgl_exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sgl_exception$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sgl_exception$(DependSuffix): sgl_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sgl_exception$(ObjectSuffix) -MF$(IntermediateDirectory)/sgl_exception$(DependSuffix) -MM "sgl_exception.cpp"

$(IntermediateDirectory)/sgl_exception$(PreprocessSuffix): sgl_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sgl_exception$(PreprocessSuffix) "sgl_exception.cpp"

$(IntermediateDirectory)/font$(ObjectSuffix): font.cpp $(IntermediateDirectory)/font$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/font.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/font$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/font$(DependSuffix): font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/font$(ObjectSuffix) -MF$(IntermediateDirectory)/font$(DependSuffix) -MM "font.cpp"

$(IntermediateDirectory)/font$(PreprocessSuffix): font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/font$(PreprocessSuffix) "font.cpp"

$(IntermediateDirectory)/color$(ObjectSuffix): color.cpp $(IntermediateDirectory)/color$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/color.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/color$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/color$(DependSuffix): color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/color$(ObjectSuffix) -MF$(IntermediateDirectory)/color$(DependSuffix) -MM "color.cpp"

$(IntermediateDirectory)/color$(PreprocessSuffix): color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/color$(PreprocessSuffix) "color.cpp"

$(IntermediateDirectory)/resource_manager$(ObjectSuffix): resource_manager.cpp $(IntermediateDirectory)/resource_manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/resource_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resource_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource_manager$(DependSuffix): resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resource_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/resource_manager$(DependSuffix) -MM "resource_manager.cpp"

$(IntermediateDirectory)/resource_manager$(PreprocessSuffix): resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resource_manager$(PreprocessSuffix) "resource_manager.cpp"

$(IntermediateDirectory)/bouding_box$(ObjectSuffix): bouding_box.cpp $(IntermediateDirectory)/bouding_box$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/bouding_box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bouding_box$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bouding_box$(DependSuffix): bouding_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bouding_box$(ObjectSuffix) -MF$(IntermediateDirectory)/bouding_box$(DependSuffix) -MM "bouding_box.cpp"

$(IntermediateDirectory)/bouding_box$(PreprocessSuffix): bouding_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bouding_box$(PreprocessSuffix) "bouding_box.cpp"

$(IntermediateDirectory)/keyboard_manager$(ObjectSuffix): keyboard_manager.cpp $(IntermediateDirectory)/keyboard_manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/keyboard_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/keyboard_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/keyboard_manager$(DependSuffix): keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/keyboard_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/keyboard_manager$(DependSuffix) -MM "keyboard_manager.cpp"

$(IntermediateDirectory)/keyboard_manager$(PreprocessSuffix): keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/keyboard_manager$(PreprocessSuffix) "keyboard_manager.cpp"

$(IntermediateDirectory)/mouse_manager$(ObjectSuffix): mouse_manager.cpp $(IntermediateDirectory)/mouse_manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/mouse_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mouse_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mouse_manager$(DependSuffix): mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mouse_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/mouse_manager$(DependSuffix) -MM "mouse_manager.cpp"

$(IntermediateDirectory)/mouse_manager$(PreprocessSuffix): mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mouse_manager$(PreprocessSuffix) "mouse_manager.cpp"

$(IntermediateDirectory)/time_handler$(ObjectSuffix): time_handler.cpp $(IntermediateDirectory)/time_handler$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/time_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/time_handler$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/time_handler$(DependSuffix): time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/time_handler$(ObjectSuffix) -MF$(IntermediateDirectory)/time_handler$(DependSuffix) -MM "time_handler.cpp"

$(IntermediateDirectory)/time_handler$(PreprocessSuffix): time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/time_handler$(PreprocessSuffix) "time_handler.cpp"

$(IntermediateDirectory)/event_manager$(ObjectSuffix): event_manager.cpp $(IntermediateDirectory)/event_manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/event_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_manager$(DependSuffix): event_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_manager$(ObjectSuffix) -MF$(IntermediateDirectory)/event_manager$(DependSuffix) -MM "event_manager.cpp"

$(IntermediateDirectory)/event_manager$(PreprocessSuffix): event_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_manager$(PreprocessSuffix) "event_manager.cpp"

$(IntermediateDirectory)/event_source$(ObjectSuffix): event_source.cpp $(IntermediateDirectory)/event_source$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/event_source.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_source$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_source$(DependSuffix): event_source.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_source$(ObjectSuffix) -MF$(IntermediateDirectory)/event_source$(DependSuffix) -MM "event_source.cpp"

$(IntermediateDirectory)/event_source$(PreprocessSuffix): event_source.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_source$(PreprocessSuffix) "event_source.cpp"

$(IntermediateDirectory)/vector2_d$(ObjectSuffix): vector2_d.cpp $(IntermediateDirectory)/vector2_d$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/vector2_d.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vector2_d$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vector2_d$(DependSuffix): vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vector2_d$(ObjectSuffix) -MF$(IntermediateDirectory)/vector2_d$(DependSuffix) -MM "vector2_d.cpp"

$(IntermediateDirectory)/vector2_d$(PreprocessSuffix): vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vector2_d$(PreprocessSuffix) "vector2_d.cpp"

$(IntermediateDirectory)/audio_resource$(ObjectSuffix): audio_resource.cpp $(IntermediateDirectory)/audio_resource$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_resource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_resource$(DependSuffix): audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_resource$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_resource$(DependSuffix) -MM "audio_resource.cpp"

$(IntermediateDirectory)/audio_resource$(PreprocessSuffix): audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_resource$(PreprocessSuffix) "audio_resource.cpp"

$(IntermediateDirectory)/sample$(ObjectSuffix): sample.cpp $(IntermediateDirectory)/sample$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sample.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sample$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sample$(DependSuffix): sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sample$(ObjectSuffix) -MF$(IntermediateDirectory)/sample$(DependSuffix) -MM "sample.cpp"

$(IntermediateDirectory)/sample$(PreprocessSuffix): sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sample$(PreprocessSuffix) "sample.cpp"

$(IntermediateDirectory)/stream$(ObjectSuffix): stream.cpp $(IntermediateDirectory)/stream$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stream$(DependSuffix): stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stream$(ObjectSuffix) -MF$(IntermediateDirectory)/stream$(DependSuffix) -MM "stream.cpp"

$(IntermediateDirectory)/stream$(PreprocessSuffix): stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stream$(PreprocessSuffix) "stream.cpp"

$(IntermediateDirectory)/application$(ObjectSuffix): application.cpp $(IntermediateDirectory)/application$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/application$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/application$(DependSuffix): application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/application$(ObjectSuffix) -MF$(IntermediateDirectory)/application$(DependSuffix) -MM "application.cpp"

$(IntermediateDirectory)/application$(PreprocessSuffix): application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/application$(PreprocessSuffix) "application.cpp"

$(IntermediateDirectory)/scene$(ObjectSuffix): scene.cpp $(IntermediateDirectory)/scene$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene$(DependSuffix): scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene$(ObjectSuffix) -MF$(IntermediateDirectory)/scene$(DependSuffix) -MM "scene.cpp"

$(IntermediateDirectory)/scene$(PreprocessSuffix): scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene$(PreprocessSuffix) "scene.cpp"

$(IntermediateDirectory)/mainApp$(ObjectSuffix): mainApp.cpp $(IntermediateDirectory)/mainApp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/mainApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainApp$(DependSuffix): mainApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainApp$(ObjectSuffix) -MF$(IntermediateDirectory)/mainApp$(DependSuffix) -MM "mainApp.cpp"

$(IntermediateDirectory)/mainApp$(PreprocessSuffix): mainApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainApp$(PreprocessSuffix) "mainApp.cpp"

$(IntermediateDirectory)/io_data_stream$(ObjectSuffix): io_data_stream.cpp $(IntermediateDirectory)/io_data_stream$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/io_data_stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/io_data_stream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/io_data_stream$(DependSuffix): io_data_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/io_data_stream$(ObjectSuffix) -MF$(IntermediateDirectory)/io_data_stream$(DependSuffix) -MM "io_data_stream.cpp"

$(IntermediateDirectory)/io_data_stream$(PreprocessSuffix): io_data_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/io_data_stream$(PreprocessSuffix) "io_data_stream.cpp"

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
	$(RM) $(IntermediateDirectory)/allegro_starter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/video_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/image_resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/animation$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/animation$(DependSuffix)
	$(RM) $(IntermediateDirectory)/animation$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/util$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/util$(DependSuffix)
	$(RM) $(IntermediateDirectory)/util$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile_set$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile_map$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/font_resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/font_resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/font_resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/layer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/layer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/layer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite$(DependSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sprite$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite$(DependSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/font$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/font$(DependSuffix)
	$(RM) $(IntermediateDirectory)/font$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/color$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/color$(DependSuffix)
	$(RM) $(IntermediateDirectory)/color$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/time_handler$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/time_handler$(DependSuffix)
	$(RM) $(IntermediateDirectory)/time_handler$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/event_manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/event_manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/event_manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/event_source$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/event_source$(DependSuffix)
	$(RM) $(IntermediateDirectory)/event_source$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sample$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sample$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sample$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/stream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/application$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/application$(DependSuffix)
	$(RM) $(IntermediateDirectory)/application$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scene$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scene$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scene$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mainApp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mainApp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mainApp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/io_data_stream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/io_data_stream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/io_data_stream$(PreprocessSuffix)
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
	$(RM) "../../../../../IDEs/Codelite/My Projects/.build-debug/Saga_Game_Library"


