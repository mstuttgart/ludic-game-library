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
Date                   :=07/03/14
CodeLitePath           :="/home/michell/.codelite"
LinkerName             :=/usr/bin/g++-4.8 
SharedObjectLinkerName :=/usr/bin/g++-4.8 -shared -fPIC
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
ObjectsFileList        :="Saga_Game_Library.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro $(LibrarySwitch)allegro_image $(LibrarySwitch)allegro_primitives $(LibrarySwitch)allegro_ttf $(LibrarySwitch)allegro_font $(LibrarySwitch)allegro_audio $(LibrarySwitch)allegro_acodec $(LibrarySwitch)allegro_color $(LibrarySwitch)tinyxml 
ArLibs                 :=  "allegro" "allegro_image" "allegro_primitives" "allegro_ttf" "allegro_font" "allegro_audio" "allegro_acodec" "allegro_color" "tinyxml" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-4.8 
CC       := /usr/bin/gcc-4.8 
CXXFLAGS := -pg -g -W -std=c++0x  -g -W -Wall -std=c++0x -O0 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/allegro_starter.cpp$(ObjectSuffix) $(IntermediateDirectory)/resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/image_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/animation.cpp$(ObjectSuffix) $(IntermediateDirectory)/util.cpp$(ObjectSuffix) $(IntermediateDirectory)/tile.cpp$(ObjectSuffix) $(IntermediateDirectory)/font_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/tiled_layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/animated_sprite.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/static_sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/sgl_exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/font.cpp$(ObjectSuffix) $(IntermediateDirectory)/color.cpp$(ObjectSuffix) $(IntermediateDirectory)/resource_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/bouding_box.cpp$(ObjectSuffix) $(IntermediateDirectory)/keyboard_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/mouse_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/time_handler.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/vector2_d.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene.cpp$(ObjectSuffix) $(IntermediateDirectory)/tmx_loader.cpp$(ObjectSuffix) $(IntermediateDirectory)/tmx_layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/tmx_tile_set.cpp$(ObjectSuffix) $(IntermediateDirectory)/tmx_tile_map.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio.cpp$(ObjectSuffix) $(IntermediateDirectory)/frame.cpp$(ObjectSuffix) $(IntermediateDirectory)/tmx_object.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/tmx_object_group.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_default.cpp$(ObjectSuffix) $(IntermediateDirectory)/geometrics.cpp$(ObjectSuffix) $(IntermediateDirectory)/video.cpp$(ObjectSuffix) $(IntermediateDirectory)/config_file_stream.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_sample.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_stream_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_stream.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_sample_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/listener.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/key_listener.cpp$(ObjectSuffix) $(IntermediateDirectory)/display_listener.cpp$(ObjectSuffix) $(IntermediateDirectory)/my_scene.cpp$(ObjectSuffix) $(IntermediateDirectory)/event.cpp$(ObjectSuffix) $(IntermediateDirectory)/key_event.cpp$(ObjectSuffix) $(IntermediateDirectory)/display_event.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/mouse_event.cpp$(ObjectSuffix) $(IntermediateDirectory)/mouse_listener.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/collision_mask.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) $(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) \
	$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/allegro_starter.cpp$(ObjectSuffix): allegro_starter.cpp $(IntermediateDirectory)/allegro_starter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/allegro_starter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/allegro_starter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/allegro_starter.cpp$(DependSuffix): allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/allegro_starter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/allegro_starter.cpp$(DependSuffix) -MM "allegro_starter.cpp"

$(IntermediateDirectory)/allegro_starter.cpp$(PreprocessSuffix): allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/allegro_starter.cpp$(PreprocessSuffix) "allegro_starter.cpp"

$(IntermediateDirectory)/resource.cpp$(ObjectSuffix): resource.cpp $(IntermediateDirectory)/resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource.cpp$(DependSuffix): resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/resource.cpp$(DependSuffix) -MM "resource.cpp"

$(IntermediateDirectory)/resource.cpp$(PreprocessSuffix): resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resource.cpp$(PreprocessSuffix) "resource.cpp"

$(IntermediateDirectory)/image_resource.cpp$(ObjectSuffix): image_resource.cpp $(IntermediateDirectory)/image_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/image_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/image_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/image_resource.cpp$(DependSuffix): image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/image_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/image_resource.cpp$(DependSuffix) -MM "image_resource.cpp"

$(IntermediateDirectory)/image_resource.cpp$(PreprocessSuffix): image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/image_resource.cpp$(PreprocessSuffix) "image_resource.cpp"

$(IntermediateDirectory)/animation.cpp$(ObjectSuffix): animation.cpp $(IntermediateDirectory)/animation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/animation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animation.cpp$(DependSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/animation.cpp$(DependSuffix) -MM "animation.cpp"

$(IntermediateDirectory)/animation.cpp$(PreprocessSuffix): animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animation.cpp$(PreprocessSuffix) "animation.cpp"

$(IntermediateDirectory)/util.cpp$(ObjectSuffix): util.cpp $(IntermediateDirectory)/util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util.cpp$(DependSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/util.cpp$(DependSuffix) -MM "util.cpp"

$(IntermediateDirectory)/util.cpp$(PreprocessSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util.cpp$(PreprocessSuffix) "util.cpp"

$(IntermediateDirectory)/tile.cpp$(ObjectSuffix): tile.cpp $(IntermediateDirectory)/tile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tile.cpp$(DependSuffix): tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tile.cpp$(DependSuffix) -MM "tile.cpp"

$(IntermediateDirectory)/tile.cpp$(PreprocessSuffix): tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tile.cpp$(PreprocessSuffix) "tile.cpp"

$(IntermediateDirectory)/font_resource.cpp$(ObjectSuffix): font_resource.cpp $(IntermediateDirectory)/font_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/font_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/font_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/font_resource.cpp$(DependSuffix): font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/font_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/font_resource.cpp$(DependSuffix) -MM "font_resource.cpp"

$(IntermediateDirectory)/font_resource.cpp$(PreprocessSuffix): font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/font_resource.cpp$(PreprocessSuffix) "font_resource.cpp"

$(IntermediateDirectory)/tiled_layer.cpp$(ObjectSuffix): tiled_layer.cpp $(IntermediateDirectory)/tiled_layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tiled_layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tiled_layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tiled_layer.cpp$(DependSuffix): tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tiled_layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tiled_layer.cpp$(DependSuffix) -MM "tiled_layer.cpp"

$(IntermediateDirectory)/tiled_layer.cpp$(PreprocessSuffix): tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tiled_layer.cpp$(PreprocessSuffix) "tiled_layer.cpp"

$(IntermediateDirectory)/layer.cpp$(ObjectSuffix): layer.cpp $(IntermediateDirectory)/layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/layer.cpp$(DependSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/layer.cpp$(DependSuffix) -MM "layer.cpp"

$(IntermediateDirectory)/layer.cpp$(PreprocessSuffix): layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/layer.cpp$(PreprocessSuffix) "layer.cpp"

$(IntermediateDirectory)/animated_sprite.cpp$(ObjectSuffix): animated_sprite.cpp $(IntermediateDirectory)/animated_sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/animated_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animated_sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animated_sprite.cpp$(DependSuffix): animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animated_sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/animated_sprite.cpp$(DependSuffix) -MM "animated_sprite.cpp"

$(IntermediateDirectory)/animated_sprite.cpp$(PreprocessSuffix): animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animated_sprite.cpp$(PreprocessSuffix) "animated_sprite.cpp"

$(IntermediateDirectory)/sprite.cpp$(ObjectSuffix): sprite.cpp $(IntermediateDirectory)/sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprite.cpp$(DependSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sprite.cpp$(DependSuffix) -MM "sprite.cpp"

$(IntermediateDirectory)/sprite.cpp$(PreprocessSuffix): sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprite.cpp$(PreprocessSuffix) "sprite.cpp"

$(IntermediateDirectory)/static_sprite.cpp$(ObjectSuffix): static_sprite.cpp $(IntermediateDirectory)/static_sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/static_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/static_sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/static_sprite.cpp$(DependSuffix): static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/static_sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/static_sprite.cpp$(DependSuffix) -MM "static_sprite.cpp"

$(IntermediateDirectory)/static_sprite.cpp$(PreprocessSuffix): static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/static_sprite.cpp$(PreprocessSuffix) "static_sprite.cpp"

$(IntermediateDirectory)/sgl_exception.cpp$(ObjectSuffix): sgl_exception.cpp $(IntermediateDirectory)/sgl_exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/sgl_exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sgl_exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sgl_exception.cpp$(DependSuffix): sgl_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sgl_exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sgl_exception.cpp$(DependSuffix) -MM "sgl_exception.cpp"

$(IntermediateDirectory)/sgl_exception.cpp$(PreprocessSuffix): sgl_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sgl_exception.cpp$(PreprocessSuffix) "sgl_exception.cpp"

$(IntermediateDirectory)/font.cpp$(ObjectSuffix): font.cpp $(IntermediateDirectory)/font.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/font.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/font.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/font.cpp$(DependSuffix): font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/font.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/font.cpp$(DependSuffix) -MM "font.cpp"

$(IntermediateDirectory)/font.cpp$(PreprocessSuffix): font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/font.cpp$(PreprocessSuffix) "font.cpp"

$(IntermediateDirectory)/color.cpp$(ObjectSuffix): color.cpp $(IntermediateDirectory)/color.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/color.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/color.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/color.cpp$(DependSuffix): color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/color.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/color.cpp$(DependSuffix) -MM "color.cpp"

$(IntermediateDirectory)/color.cpp$(PreprocessSuffix): color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/color.cpp$(PreprocessSuffix) "color.cpp"

$(IntermediateDirectory)/resource_manager.cpp$(ObjectSuffix): resource_manager.cpp $(IntermediateDirectory)/resource_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/resource_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resource_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource_manager.cpp$(DependSuffix): resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resource_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/resource_manager.cpp$(DependSuffix) -MM "resource_manager.cpp"

$(IntermediateDirectory)/resource_manager.cpp$(PreprocessSuffix): resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resource_manager.cpp$(PreprocessSuffix) "resource_manager.cpp"

$(IntermediateDirectory)/bouding_box.cpp$(ObjectSuffix): bouding_box.cpp $(IntermediateDirectory)/bouding_box.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/bouding_box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bouding_box.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bouding_box.cpp$(DependSuffix): bouding_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bouding_box.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bouding_box.cpp$(DependSuffix) -MM "bouding_box.cpp"

$(IntermediateDirectory)/bouding_box.cpp$(PreprocessSuffix): bouding_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bouding_box.cpp$(PreprocessSuffix) "bouding_box.cpp"

$(IntermediateDirectory)/keyboard_manager.cpp$(ObjectSuffix): keyboard_manager.cpp $(IntermediateDirectory)/keyboard_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/keyboard_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/keyboard_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/keyboard_manager.cpp$(DependSuffix): keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/keyboard_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/keyboard_manager.cpp$(DependSuffix) -MM "keyboard_manager.cpp"

$(IntermediateDirectory)/keyboard_manager.cpp$(PreprocessSuffix): keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/keyboard_manager.cpp$(PreprocessSuffix) "keyboard_manager.cpp"

$(IntermediateDirectory)/mouse_manager.cpp$(ObjectSuffix): mouse_manager.cpp $(IntermediateDirectory)/mouse_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/mouse_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mouse_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mouse_manager.cpp$(DependSuffix): mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mouse_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mouse_manager.cpp$(DependSuffix) -MM "mouse_manager.cpp"

$(IntermediateDirectory)/mouse_manager.cpp$(PreprocessSuffix): mouse_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mouse_manager.cpp$(PreprocessSuffix) "mouse_manager.cpp"

$(IntermediateDirectory)/time_handler.cpp$(ObjectSuffix): time_handler.cpp $(IntermediateDirectory)/time_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/time_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/time_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/time_handler.cpp$(DependSuffix): time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/time_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/time_handler.cpp$(DependSuffix) -MM "time_handler.cpp"

$(IntermediateDirectory)/time_handler.cpp$(PreprocessSuffix): time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/time_handler.cpp$(PreprocessSuffix) "time_handler.cpp"

$(IntermediateDirectory)/vector2_d.cpp$(ObjectSuffix): vector2_d.cpp $(IntermediateDirectory)/vector2_d.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/vector2_d.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vector2_d.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vector2_d.cpp$(DependSuffix): vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vector2_d.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vector2_d.cpp$(DependSuffix) -MM "vector2_d.cpp"

$(IntermediateDirectory)/vector2_d.cpp$(PreprocessSuffix): vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vector2_d.cpp$(PreprocessSuffix) "vector2_d.cpp"

$(IntermediateDirectory)/audio_resource.cpp$(ObjectSuffix): audio_resource.cpp $(IntermediateDirectory)/audio_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_resource.cpp$(DependSuffix): audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_resource.cpp$(DependSuffix) -MM "audio_resource.cpp"

$(IntermediateDirectory)/audio_resource.cpp$(PreprocessSuffix): audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_resource.cpp$(PreprocessSuffix) "audio_resource.cpp"

$(IntermediateDirectory)/scene.cpp$(ObjectSuffix): scene.cpp $(IntermediateDirectory)/scene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene.cpp$(DependSuffix): scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene.cpp$(DependSuffix) -MM "scene.cpp"

$(IntermediateDirectory)/scene.cpp$(PreprocessSuffix): scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene.cpp$(PreprocessSuffix) "scene.cpp"

$(IntermediateDirectory)/tmx_loader.cpp$(ObjectSuffix): tmx_loader.cpp $(IntermediateDirectory)/tmx_loader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_loader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_loader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_loader.cpp$(DependSuffix): tmx_loader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_loader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_loader.cpp$(DependSuffix) -MM "tmx_loader.cpp"

$(IntermediateDirectory)/tmx_loader.cpp$(PreprocessSuffix): tmx_loader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_loader.cpp$(PreprocessSuffix) "tmx_loader.cpp"

$(IntermediateDirectory)/tmx_layer.cpp$(ObjectSuffix): tmx_layer.cpp $(IntermediateDirectory)/tmx_layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_layer.cpp$(DependSuffix): tmx_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_layer.cpp$(DependSuffix) -MM "tmx_layer.cpp"

$(IntermediateDirectory)/tmx_layer.cpp$(PreprocessSuffix): tmx_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_layer.cpp$(PreprocessSuffix) "tmx_layer.cpp"

$(IntermediateDirectory)/tmx_tile_set.cpp$(ObjectSuffix): tmx_tile_set.cpp $(IntermediateDirectory)/tmx_tile_set.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_tile_set.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_tile_set.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_tile_set.cpp$(DependSuffix): tmx_tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_tile_set.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_tile_set.cpp$(DependSuffix) -MM "tmx_tile_set.cpp"

$(IntermediateDirectory)/tmx_tile_set.cpp$(PreprocessSuffix): tmx_tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_tile_set.cpp$(PreprocessSuffix) "tmx_tile_set.cpp"

$(IntermediateDirectory)/tmx_tile_map.cpp$(ObjectSuffix): tmx_tile_map.cpp $(IntermediateDirectory)/tmx_tile_map.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_tile_map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_tile_map.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_tile_map.cpp$(DependSuffix): tmx_tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_tile_map.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_tile_map.cpp$(DependSuffix) -MM "tmx_tile_map.cpp"

$(IntermediateDirectory)/tmx_tile_map.cpp$(PreprocessSuffix): tmx_tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_tile_map.cpp$(PreprocessSuffix) "tmx_tile_map.cpp"

$(IntermediateDirectory)/audio.cpp$(ObjectSuffix): audio.cpp $(IntermediateDirectory)/audio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio.cpp$(DependSuffix): audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio.cpp$(DependSuffix) -MM "audio.cpp"

$(IntermediateDirectory)/audio.cpp$(PreprocessSuffix): audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio.cpp$(PreprocessSuffix) "audio.cpp"

$(IntermediateDirectory)/frame.cpp$(ObjectSuffix): frame.cpp $(IntermediateDirectory)/frame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/frame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/frame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/frame.cpp$(DependSuffix): frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/frame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/frame.cpp$(DependSuffix) -MM "frame.cpp"

$(IntermediateDirectory)/frame.cpp$(PreprocessSuffix): frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/frame.cpp$(PreprocessSuffix) "frame.cpp"

$(IntermediateDirectory)/tmx_object.cpp$(ObjectSuffix): tmx_object.cpp $(IntermediateDirectory)/tmx_object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_object.cpp$(DependSuffix): tmx_object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_object.cpp$(DependSuffix) -MM "tmx_object.cpp"

$(IntermediateDirectory)/tmx_object.cpp$(PreprocessSuffix): tmx_object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_object.cpp$(PreprocessSuffix) "tmx_object.cpp"

$(IntermediateDirectory)/tmx_object_group.cpp$(ObjectSuffix): tmx_object_group.cpp $(IntermediateDirectory)/tmx_object_group.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tmx_object_group.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tmx_object_group.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tmx_object_group.cpp$(DependSuffix): tmx_object_group.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tmx_object_group.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tmx_object_group.cpp$(DependSuffix) -MM "tmx_object_group.cpp"

$(IntermediateDirectory)/tmx_object_group.cpp$(PreprocessSuffix): tmx_object_group.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tmx_object_group.cpp$(PreprocessSuffix) "tmx_object_group.cpp"

$(IntermediateDirectory)/main_default.cpp$(ObjectSuffix): main_default.cpp $(IntermediateDirectory)/main_default.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/main_default.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_default.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_default.cpp$(DependSuffix): main_default.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_default.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_default.cpp$(DependSuffix) -MM "main_default.cpp"

$(IntermediateDirectory)/main_default.cpp$(PreprocessSuffix): main_default.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_default.cpp$(PreprocessSuffix) "main_default.cpp"

$(IntermediateDirectory)/geometrics.cpp$(ObjectSuffix): geometrics.cpp $(IntermediateDirectory)/geometrics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/geometrics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/geometrics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/geometrics.cpp$(DependSuffix): geometrics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/geometrics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/geometrics.cpp$(DependSuffix) -MM "geometrics.cpp"

$(IntermediateDirectory)/geometrics.cpp$(PreprocessSuffix): geometrics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/geometrics.cpp$(PreprocessSuffix) "geometrics.cpp"

$(IntermediateDirectory)/video.cpp$(ObjectSuffix): video.cpp $(IntermediateDirectory)/video.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/video.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/video.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/video.cpp$(DependSuffix): video.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/video.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/video.cpp$(DependSuffix) -MM "video.cpp"

$(IntermediateDirectory)/video.cpp$(PreprocessSuffix): video.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/video.cpp$(PreprocessSuffix) "video.cpp"

$(IntermediateDirectory)/config_file_stream.cpp$(ObjectSuffix): config_file_stream.cpp $(IntermediateDirectory)/config_file_stream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/config_file_stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/config_file_stream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/config_file_stream.cpp$(DependSuffix): config_file_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/config_file_stream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/config_file_stream.cpp$(DependSuffix) -MM "config_file_stream.cpp"

$(IntermediateDirectory)/config_file_stream.cpp$(PreprocessSuffix): config_file_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/config_file_stream.cpp$(PreprocessSuffix) "config_file_stream.cpp"

$(IntermediateDirectory)/audio_sample.cpp$(ObjectSuffix): audio_sample.cpp $(IntermediateDirectory)/audio_sample.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_sample.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_sample.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_sample.cpp$(DependSuffix): audio_sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_sample.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_sample.cpp$(DependSuffix) -MM "audio_sample.cpp"

$(IntermediateDirectory)/audio_sample.cpp$(PreprocessSuffix): audio_sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_sample.cpp$(PreprocessSuffix) "audio_sample.cpp"

$(IntermediateDirectory)/audio_stream_resource.cpp$(ObjectSuffix): audio_stream_resource.cpp $(IntermediateDirectory)/audio_stream_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_stream_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_stream_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_stream_resource.cpp$(DependSuffix): audio_stream_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_stream_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_stream_resource.cpp$(DependSuffix) -MM "audio_stream_resource.cpp"

$(IntermediateDirectory)/audio_stream_resource.cpp$(PreprocessSuffix): audio_stream_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_stream_resource.cpp$(PreprocessSuffix) "audio_stream_resource.cpp"

$(IntermediateDirectory)/audio_stream.cpp$(ObjectSuffix): audio_stream.cpp $(IntermediateDirectory)/audio_stream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_stream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_stream.cpp$(DependSuffix): audio_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_stream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_stream.cpp$(DependSuffix) -MM "audio_stream.cpp"

$(IntermediateDirectory)/audio_stream.cpp$(PreprocessSuffix): audio_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_stream.cpp$(PreprocessSuffix) "audio_stream.cpp"

$(IntermediateDirectory)/audio_sample_resource.cpp$(ObjectSuffix): audio_sample_resource.cpp $(IntermediateDirectory)/audio_sample_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/audio_sample_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_sample_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_sample_resource.cpp$(DependSuffix): audio_sample_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_sample_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_sample_resource.cpp$(DependSuffix) -MM "audio_sample_resource.cpp"

$(IntermediateDirectory)/audio_sample_resource.cpp$(PreprocessSuffix): audio_sample_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_sample_resource.cpp$(PreprocessSuffix) "audio_sample_resource.cpp"

$(IntermediateDirectory)/listener.cpp$(ObjectSuffix): listener.cpp $(IntermediateDirectory)/listener.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/listener.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/listener.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/listener.cpp$(DependSuffix): listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/listener.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/listener.cpp$(DependSuffix) -MM "listener.cpp"

$(IntermediateDirectory)/listener.cpp$(PreprocessSuffix): listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/listener.cpp$(PreprocessSuffix) "listener.cpp"

$(IntermediateDirectory)/key_listener.cpp$(ObjectSuffix): key_listener.cpp $(IntermediateDirectory)/key_listener.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/key_listener.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/key_listener.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/key_listener.cpp$(DependSuffix): key_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/key_listener.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/key_listener.cpp$(DependSuffix) -MM "key_listener.cpp"

$(IntermediateDirectory)/key_listener.cpp$(PreprocessSuffix): key_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/key_listener.cpp$(PreprocessSuffix) "key_listener.cpp"

$(IntermediateDirectory)/display_listener.cpp$(ObjectSuffix): display_listener.cpp $(IntermediateDirectory)/display_listener.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/display_listener.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/display_listener.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/display_listener.cpp$(DependSuffix): display_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/display_listener.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/display_listener.cpp$(DependSuffix) -MM "display_listener.cpp"

$(IntermediateDirectory)/display_listener.cpp$(PreprocessSuffix): display_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/display_listener.cpp$(PreprocessSuffix) "display_listener.cpp"

$(IntermediateDirectory)/my_scene.cpp$(ObjectSuffix): my_scene.cpp $(IntermediateDirectory)/my_scene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/my_scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/my_scene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/my_scene.cpp$(DependSuffix): my_scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/my_scene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/my_scene.cpp$(DependSuffix) -MM "my_scene.cpp"

$(IntermediateDirectory)/my_scene.cpp$(PreprocessSuffix): my_scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/my_scene.cpp$(PreprocessSuffix) "my_scene.cpp"

$(IntermediateDirectory)/event.cpp$(ObjectSuffix): event.cpp $(IntermediateDirectory)/event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event.cpp$(DependSuffix): event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event.cpp$(DependSuffix) -MM "event.cpp"

$(IntermediateDirectory)/event.cpp$(PreprocessSuffix): event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event.cpp$(PreprocessSuffix) "event.cpp"

$(IntermediateDirectory)/key_event.cpp$(ObjectSuffix): key_event.cpp $(IntermediateDirectory)/key_event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/key_event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/key_event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/key_event.cpp$(DependSuffix): key_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/key_event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/key_event.cpp$(DependSuffix) -MM "key_event.cpp"

$(IntermediateDirectory)/key_event.cpp$(PreprocessSuffix): key_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/key_event.cpp$(PreprocessSuffix) "key_event.cpp"

$(IntermediateDirectory)/display_event.cpp$(ObjectSuffix): display_event.cpp $(IntermediateDirectory)/display_event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/display_event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/display_event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/display_event.cpp$(DependSuffix): display_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/display_event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/display_event.cpp$(DependSuffix) -MM "display_event.cpp"

$(IntermediateDirectory)/display_event.cpp$(PreprocessSuffix): display_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/display_event.cpp$(PreprocessSuffix) "display_event.cpp"

$(IntermediateDirectory)/scene_manager.cpp$(ObjectSuffix): scene_manager.cpp $(IntermediateDirectory)/scene_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/scene_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_manager.cpp$(DependSuffix): scene_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_manager.cpp$(DependSuffix) -MM "scene_manager.cpp"

$(IntermediateDirectory)/scene_manager.cpp$(PreprocessSuffix): scene_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_manager.cpp$(PreprocessSuffix) "scene_manager.cpp"

$(IntermediateDirectory)/mouse_event.cpp$(ObjectSuffix): mouse_event.cpp $(IntermediateDirectory)/mouse_event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/mouse_event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mouse_event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mouse_event.cpp$(DependSuffix): mouse_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mouse_event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mouse_event.cpp$(DependSuffix) -MM "mouse_event.cpp"

$(IntermediateDirectory)/mouse_event.cpp$(PreprocessSuffix): mouse_event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mouse_event.cpp$(PreprocessSuffix) "mouse_event.cpp"

$(IntermediateDirectory)/mouse_listener.cpp$(ObjectSuffix): mouse_listener.cpp $(IntermediateDirectory)/mouse_listener.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/mouse_listener.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mouse_listener.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mouse_listener.cpp$(DependSuffix): mouse_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mouse_listener.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mouse_listener.cpp$(DependSuffix) -MM "mouse_listener.cpp"

$(IntermediateDirectory)/mouse_listener.cpp$(PreprocessSuffix): mouse_listener.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mouse_listener.cpp$(PreprocessSuffix) "mouse_listener.cpp"

$(IntermediateDirectory)/collision_mask.cpp$(ObjectSuffix): collision_mask.cpp $(IntermediateDirectory)/collision_mask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/collision_mask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/collision_mask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/collision_mask.cpp$(DependSuffix): collision_mask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/collision_mask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/collision_mask.cpp$(DependSuffix) -MM "collision_mask.cpp"

$(IntermediateDirectory)/collision_mask.cpp$(PreprocessSuffix): collision_mask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/collision_mask.cpp$(PreprocessSuffix) "collision_mask.cpp"

$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix): gzip/decompressor.cpp $(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/gzip/decompressor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix): gzip/decompressor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix) -MM "gzip/decompressor.cpp"

$(IntermediateDirectory)/gzip_decompressor.cpp$(PreprocessSuffix): gzip/decompressor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gzip_decompressor.cpp$(PreprocessSuffix) "gzip/decompressor.cpp"

$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix): base64/base64.cpp $(IntermediateDirectory)/base64_base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/base64/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix): base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix) -MM "base64/base64.cpp"

$(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix): base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix) "base64/base64.cpp"

$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix): zlib/adler32.c $(IntermediateDirectory)/zlib_adler32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/adler32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix): zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix) -MM "zlib/adler32.c"

$(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix): zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix) "zlib/adler32.c"

$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix): zlib/compress.c $(IntermediateDirectory)/zlib_compress.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/compress.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_compress.c$(DependSuffix): zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_compress.c$(DependSuffix) -MM "zlib/compress.c"

$(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix): zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix) "zlib/compress.c"

$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix): zlib/crc32.c $(IntermediateDirectory)/zlib_crc32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/crc32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix): zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix) -MM "zlib/crc32.c"

$(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix): zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix) "zlib/crc32.c"

$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix): zlib/deflate.c $(IntermediateDirectory)/zlib_deflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/deflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix): zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix) -MM "zlib/deflate.c"

$(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix): zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix) "zlib/deflate.c"

$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix): zlib/gzclose.c $(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/gzclose.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix): zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix) -MM "zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix): zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix) "zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix): zlib/gzlib.c $(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/gzlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix): zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix) -MM "zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix): zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix) "zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix): zlib/gzread.c $(IntermediateDirectory)/zlib_gzread.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/gzread.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix): zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix) -MM "zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix): zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix) "zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix): zlib/gzwrite.c $(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/gzwrite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix): zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix) -MM "zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix): zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix) "zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix): zlib/infback.c $(IntermediateDirectory)/zlib_infback.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/infback.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_infback.c$(DependSuffix): zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_infback.c$(DependSuffix) -MM "zlib/infback.c"

$(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix): zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix) "zlib/infback.c"

$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix): zlib/inffast.c $(IntermediateDirectory)/zlib_inffast.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/inffast.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix): zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix) -MM "zlib/inffast.c"

$(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix): zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix) "zlib/inffast.c"

$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix): zlib/inflate.c $(IntermediateDirectory)/zlib_inflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/inflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix): zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix) -MM "zlib/inflate.c"

$(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix): zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix) "zlib/inflate.c"

$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix): zlib/inftrees.c $(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/inftrees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix): zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix) -MM "zlib/inftrees.c"

$(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix): zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix) "zlib/inftrees.c"

$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix): zlib/trees.c $(IntermediateDirectory)/zlib_trees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/trees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_trees.c$(DependSuffix): zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_trees.c$(DependSuffix) -MM "zlib/trees.c"

$(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix): zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix) "zlib/trees.c"

$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix): zlib/uncompr.c $(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/uncompr.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix): zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix) -MM "zlib/uncompr.c"

$(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix): zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix) "zlib/uncompr.c"

$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix): zlib/zutil.c $(IntermediateDirectory)/zlib_zutil.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/zlib/zutil.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix): zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix) -MM "zlib/zutil.c"

$(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix): zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix) "zlib/zutil.c"

$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix): tinyxml/tinystr.cpp $(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinystr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix): tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix) -MM "tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinystr.cpp$(PreprocessSuffix): tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(PreprocessSuffix) "tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix): tinyxml/tinyxml.cpp $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix): tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix) -MM "tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(PreprocessSuffix): tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(PreprocessSuffix) "tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix): tinyxml/tinyxmlerror.cpp $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxmlerror.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix): tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix) -MM "tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(PreprocessSuffix): tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(PreprocessSuffix) "tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix): tinyxml/tinyxmlparser.cpp $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/TCC_Project/tfg_project/trunk/Saga_Game_Library_Source/tinyxml/tinyxmlparser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix): tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix) -MM "tinyxml/tinyxmlparser.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(PreprocessSuffix): tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(PreprocessSuffix) "tinyxml/tinyxmlparser.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/allegro_starter.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/allegro_starter.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/image_resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/image_resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/image_resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/animation.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/animation.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/animation.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/util.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/util.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/util.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tile.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tile.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tile.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/font_resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/font_resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/font_resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tiled_layer.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/layer.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/layer.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/layer.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/animated_sprite.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sprite.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sprite.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sprite.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/static_sprite.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/sgl_exception.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/font.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/font.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/font.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/color.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/color.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/color.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/resource_manager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bouding_box.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/keyboard_manager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mouse_manager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/time_handler.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/time_handler.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/time_handler.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vector2_d.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scene.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scene.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scene.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_loader.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_loader.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_loader.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_layer.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_layer.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_layer.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_set.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_set.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_set.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_map.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_map.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_tile_map.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/frame.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/frame.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/frame.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object_group.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object_group.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tmx_object_group.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main_default.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main_default.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main_default.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/geometrics.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/geometrics.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/geometrics.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/video.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/video.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/video.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/config_file_stream.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/config_file_stream.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/config_file_stream.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream_resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream_resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream_resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_stream.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample_resource.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample_resource.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/audio_sample_resource.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/listener.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/listener.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/listener.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/key_listener.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/key_listener.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/key_listener.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/display_listener.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/display_listener.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/display_listener.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/my_scene.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/my_scene.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/my_scene.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/event.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/event.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/event.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/key_event.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/key_event.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/key_event.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/display_event.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/display_event.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/display_event.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scene_manager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scene_manager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scene_manager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mouse_event.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mouse_event.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mouse_event.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/mouse_listener.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/mouse_listener.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/mouse_listener.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/collision_mask.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/collision_mask.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/collision_mask.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gzip_decompressor.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../../../../IDEs/Codelite/My Projects/.build-debug/Saga_Game_Library"


