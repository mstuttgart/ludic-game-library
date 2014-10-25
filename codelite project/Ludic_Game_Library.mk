##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Ludic_Game_Library
ConfigurationName      :=Debug
WorkspacePath          := "/media/Dados/Arquivos/Documentos/IDEs/Codelite/My Projects"
ProjectPath            := "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/codelite project"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Michell Stuttgart
Date                   :=08/29/14
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
ObjectsFileList        :="Ludic_Game_Library.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro $(LibrarySwitch)allegro_image $(LibrarySwitch)allegro_primitives $(LibrarySwitch)allegro_ttf $(LibrarySwitch)allegro_font $(LibrarySwitch)allegro_audio $(LibrarySwitch)allegro_acodec $(LibrarySwitch)allegro_color 
ArLibs                 :=  "allegro" "allegro_image" "allegro_primitives" "allegro_ttf" "allegro_font" "allegro_audio" "allegro_acodec" "allegro_color" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-4.8 
CC       := /usr/bin/gcc-4.8 
CXXFLAGS := -pg -g -W -std=c++0x  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_allegro_starter.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_animated_sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_animation.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio_sample.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio_stream.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ludic_collision_mask.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_color.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_config_file_stream.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_font.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_font_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_frame.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_geometrics.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_image_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_keyboard_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_layer.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ludic_resource.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_resource_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_static_sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_tile.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_tiled_layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_time_handler.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_tmx_layer.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_tmx_loader.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_util.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_vector2_d.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_video.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_collision_box.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_ludic_exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) $(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) \
	$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix): ../src/base64/base64.cpp $(IntermediateDirectory)/base64_base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/base64/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix): ../src/base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base64_base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/base64_base64.cpp$(DependSuffix) -MM "../src/base64/base64.cpp"

$(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix): ../src/base64/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base64_base64.cpp$(PreprocessSuffix) "../src/base64/base64.cpp"

$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix): ../src/gzip/decompressor.cpp $(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/gzip/decompressor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix): ../src/gzip/decompressor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gzip_decompressor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gzip_decompressor.cpp$(DependSuffix) -MM "../src/gzip/decompressor.cpp"

$(IntermediateDirectory)/gzip_decompressor.cpp$(PreprocessSuffix): ../src/gzip/decompressor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gzip_decompressor.cpp$(PreprocessSuffix) "../src/gzip/decompressor.cpp"

$(IntermediateDirectory)/ludic_allegro_starter.cpp$(ObjectSuffix): ../src/ludic/allegro_starter.cpp $(IntermediateDirectory)/ludic_allegro_starter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/allegro_starter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_allegro_starter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_allegro_starter.cpp$(DependSuffix): ../src/ludic/allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_allegro_starter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_allegro_starter.cpp$(DependSuffix) -MM "../src/ludic/allegro_starter.cpp"

$(IntermediateDirectory)/ludic_allegro_starter.cpp$(PreprocessSuffix): ../src/ludic/allegro_starter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_allegro_starter.cpp$(PreprocessSuffix) "../src/ludic/allegro_starter.cpp"

$(IntermediateDirectory)/ludic_animated_sprite.cpp$(ObjectSuffix): ../src/ludic/animated_sprite.cpp $(IntermediateDirectory)/ludic_animated_sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/animated_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_animated_sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_animated_sprite.cpp$(DependSuffix): ../src/ludic/animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_animated_sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_animated_sprite.cpp$(DependSuffix) -MM "../src/ludic/animated_sprite.cpp"

$(IntermediateDirectory)/ludic_animated_sprite.cpp$(PreprocessSuffix): ../src/ludic/animated_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_animated_sprite.cpp$(PreprocessSuffix) "../src/ludic/animated_sprite.cpp"

$(IntermediateDirectory)/ludic_animation.cpp$(ObjectSuffix): ../src/ludic/animation.cpp $(IntermediateDirectory)/ludic_animation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/animation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_animation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_animation.cpp$(DependSuffix): ../src/ludic/animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_animation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_animation.cpp$(DependSuffix) -MM "../src/ludic/animation.cpp"

$(IntermediateDirectory)/ludic_animation.cpp$(PreprocessSuffix): ../src/ludic/animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_animation.cpp$(PreprocessSuffix) "../src/ludic/animation.cpp"

$(IntermediateDirectory)/ludic_audio_resource.cpp$(ObjectSuffix): ../src/ludic/audio_resource.cpp $(IntermediateDirectory)/ludic_audio_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio_resource.cpp$(DependSuffix): ../src/ludic/audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio_resource.cpp$(DependSuffix) -MM "../src/ludic/audio_resource.cpp"

$(IntermediateDirectory)/ludic_audio_resource.cpp$(PreprocessSuffix): ../src/ludic/audio_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio_resource.cpp$(PreprocessSuffix) "../src/ludic/audio_resource.cpp"

$(IntermediateDirectory)/ludic_audio_sample.cpp$(ObjectSuffix): ../src/ludic/audio_sample.cpp $(IntermediateDirectory)/ludic_audio_sample.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio_sample.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio_sample.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio_sample.cpp$(DependSuffix): ../src/ludic/audio_sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio_sample.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio_sample.cpp$(DependSuffix) -MM "../src/ludic/audio_sample.cpp"

$(IntermediateDirectory)/ludic_audio_sample.cpp$(PreprocessSuffix): ../src/ludic/audio_sample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio_sample.cpp$(PreprocessSuffix) "../src/ludic/audio_sample.cpp"

$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(ObjectSuffix): ../src/ludic/audio_sample_resource.cpp $(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio_sample_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(DependSuffix): ../src/ludic/audio_sample_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(DependSuffix) -MM "../src/ludic/audio_sample_resource.cpp"

$(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(PreprocessSuffix): ../src/ludic/audio_sample_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio_sample_resource.cpp$(PreprocessSuffix) "../src/ludic/audio_sample_resource.cpp"

$(IntermediateDirectory)/ludic_audio_stream.cpp$(ObjectSuffix): ../src/ludic/audio_stream.cpp $(IntermediateDirectory)/ludic_audio_stream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio_stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio_stream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio_stream.cpp$(DependSuffix): ../src/ludic/audio_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio_stream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio_stream.cpp$(DependSuffix) -MM "../src/ludic/audio_stream.cpp"

$(IntermediateDirectory)/ludic_audio_stream.cpp$(PreprocessSuffix): ../src/ludic/audio_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio_stream.cpp$(PreprocessSuffix) "../src/ludic/audio_stream.cpp"

$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(ObjectSuffix): ../src/ludic/audio_stream_resource.cpp $(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio_stream_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(DependSuffix): ../src/ludic/audio_stream_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(DependSuffix) -MM "../src/ludic/audio_stream_resource.cpp"

$(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(PreprocessSuffix): ../src/ludic/audio_stream_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio_stream_resource.cpp$(PreprocessSuffix) "../src/ludic/audio_stream_resource.cpp"

$(IntermediateDirectory)/ludic_collision_mask.cpp$(ObjectSuffix): ../src/ludic/collision_mask.cpp $(IntermediateDirectory)/ludic_collision_mask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/collision_mask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_collision_mask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_collision_mask.cpp$(DependSuffix): ../src/ludic/collision_mask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_collision_mask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_collision_mask.cpp$(DependSuffix) -MM "../src/ludic/collision_mask.cpp"

$(IntermediateDirectory)/ludic_collision_mask.cpp$(PreprocessSuffix): ../src/ludic/collision_mask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_collision_mask.cpp$(PreprocessSuffix) "../src/ludic/collision_mask.cpp"

$(IntermediateDirectory)/ludic_color.cpp$(ObjectSuffix): ../src/ludic/color.cpp $(IntermediateDirectory)/ludic_color.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/color.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_color.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_color.cpp$(DependSuffix): ../src/ludic/color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_color.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_color.cpp$(DependSuffix) -MM "../src/ludic/color.cpp"

$(IntermediateDirectory)/ludic_color.cpp$(PreprocessSuffix): ../src/ludic/color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_color.cpp$(PreprocessSuffix) "../src/ludic/color.cpp"

$(IntermediateDirectory)/ludic_config_file_stream.cpp$(ObjectSuffix): ../src/ludic/config_file_stream.cpp $(IntermediateDirectory)/ludic_config_file_stream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/config_file_stream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_config_file_stream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_config_file_stream.cpp$(DependSuffix): ../src/ludic/config_file_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_config_file_stream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_config_file_stream.cpp$(DependSuffix) -MM "../src/ludic/config_file_stream.cpp"

$(IntermediateDirectory)/ludic_config_file_stream.cpp$(PreprocessSuffix): ../src/ludic/config_file_stream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_config_file_stream.cpp$(PreprocessSuffix) "../src/ludic/config_file_stream.cpp"

$(IntermediateDirectory)/ludic_font.cpp$(ObjectSuffix): ../src/ludic/font.cpp $(IntermediateDirectory)/ludic_font.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/font.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_font.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_font.cpp$(DependSuffix): ../src/ludic/font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_font.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_font.cpp$(DependSuffix) -MM "../src/ludic/font.cpp"

$(IntermediateDirectory)/ludic_font.cpp$(PreprocessSuffix): ../src/ludic/font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_font.cpp$(PreprocessSuffix) "../src/ludic/font.cpp"

$(IntermediateDirectory)/ludic_font_resource.cpp$(ObjectSuffix): ../src/ludic/font_resource.cpp $(IntermediateDirectory)/ludic_font_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/font_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_font_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_font_resource.cpp$(DependSuffix): ../src/ludic/font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_font_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_font_resource.cpp$(DependSuffix) -MM "../src/ludic/font_resource.cpp"

$(IntermediateDirectory)/ludic_font_resource.cpp$(PreprocessSuffix): ../src/ludic/font_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_font_resource.cpp$(PreprocessSuffix) "../src/ludic/font_resource.cpp"

$(IntermediateDirectory)/ludic_frame.cpp$(ObjectSuffix): ../src/ludic/frame.cpp $(IntermediateDirectory)/ludic_frame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/frame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_frame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_frame.cpp$(DependSuffix): ../src/ludic/frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_frame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_frame.cpp$(DependSuffix) -MM "../src/ludic/frame.cpp"

$(IntermediateDirectory)/ludic_frame.cpp$(PreprocessSuffix): ../src/ludic/frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_frame.cpp$(PreprocessSuffix) "../src/ludic/frame.cpp"

$(IntermediateDirectory)/ludic_geometrics.cpp$(ObjectSuffix): ../src/ludic/geometrics.cpp $(IntermediateDirectory)/ludic_geometrics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/geometrics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_geometrics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_geometrics.cpp$(DependSuffix): ../src/ludic/geometrics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_geometrics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_geometrics.cpp$(DependSuffix) -MM "../src/ludic/geometrics.cpp"

$(IntermediateDirectory)/ludic_geometrics.cpp$(PreprocessSuffix): ../src/ludic/geometrics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_geometrics.cpp$(PreprocessSuffix) "../src/ludic/geometrics.cpp"

$(IntermediateDirectory)/ludic_image_resource.cpp$(ObjectSuffix): ../src/ludic/image_resource.cpp $(IntermediateDirectory)/ludic_image_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/image_resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_image_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_image_resource.cpp$(DependSuffix): ../src/ludic/image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_image_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_image_resource.cpp$(DependSuffix) -MM "../src/ludic/image_resource.cpp"

$(IntermediateDirectory)/ludic_image_resource.cpp$(PreprocessSuffix): ../src/ludic/image_resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_image_resource.cpp$(PreprocessSuffix) "../src/ludic/image_resource.cpp"

$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(ObjectSuffix): ../src/ludic/keyboard_manager.cpp $(IntermediateDirectory)/ludic_keyboard_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/keyboard_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(DependSuffix): ../src/ludic/keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(DependSuffix) -MM "../src/ludic/keyboard_manager.cpp"

$(IntermediateDirectory)/ludic_keyboard_manager.cpp$(PreprocessSuffix): ../src/ludic/keyboard_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_keyboard_manager.cpp$(PreprocessSuffix) "../src/ludic/keyboard_manager.cpp"

$(IntermediateDirectory)/ludic_layer.cpp$(ObjectSuffix): ../src/ludic/layer.cpp $(IntermediateDirectory)/ludic_layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_layer.cpp$(DependSuffix): ../src/ludic/layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_layer.cpp$(DependSuffix) -MM "../src/ludic/layer.cpp"

$(IntermediateDirectory)/ludic_layer.cpp$(PreprocessSuffix): ../src/ludic/layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_layer.cpp$(PreprocessSuffix) "../src/ludic/layer.cpp"

$(IntermediateDirectory)/ludic_resource.cpp$(ObjectSuffix): ../src/ludic/resource.cpp $(IntermediateDirectory)/ludic_resource.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/resource.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_resource.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_resource.cpp$(DependSuffix): ../src/ludic/resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_resource.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_resource.cpp$(DependSuffix) -MM "../src/ludic/resource.cpp"

$(IntermediateDirectory)/ludic_resource.cpp$(PreprocessSuffix): ../src/ludic/resource.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_resource.cpp$(PreprocessSuffix) "../src/ludic/resource.cpp"

$(IntermediateDirectory)/ludic_resource_manager.cpp$(ObjectSuffix): ../src/ludic/resource_manager.cpp $(IntermediateDirectory)/ludic_resource_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/resource_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_resource_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_resource_manager.cpp$(DependSuffix): ../src/ludic/resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_resource_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_resource_manager.cpp$(DependSuffix) -MM "../src/ludic/resource_manager.cpp"

$(IntermediateDirectory)/ludic_resource_manager.cpp$(PreprocessSuffix): ../src/ludic/resource_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_resource_manager.cpp$(PreprocessSuffix) "../src/ludic/resource_manager.cpp"

$(IntermediateDirectory)/ludic_sprite.cpp$(ObjectSuffix): ../src/ludic/sprite.cpp $(IntermediateDirectory)/ludic_sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_sprite.cpp$(DependSuffix): ../src/ludic/sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_sprite.cpp$(DependSuffix) -MM "../src/ludic/sprite.cpp"

$(IntermediateDirectory)/ludic_sprite.cpp$(PreprocessSuffix): ../src/ludic/sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_sprite.cpp$(PreprocessSuffix) "../src/ludic/sprite.cpp"

$(IntermediateDirectory)/ludic_static_sprite.cpp$(ObjectSuffix): ../src/ludic/static_sprite.cpp $(IntermediateDirectory)/ludic_static_sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/static_sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_static_sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_static_sprite.cpp$(DependSuffix): ../src/ludic/static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_static_sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_static_sprite.cpp$(DependSuffix) -MM "../src/ludic/static_sprite.cpp"

$(IntermediateDirectory)/ludic_static_sprite.cpp$(PreprocessSuffix): ../src/ludic/static_sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_static_sprite.cpp$(PreprocessSuffix) "../src/ludic/static_sprite.cpp"

$(IntermediateDirectory)/ludic_tile.cpp$(ObjectSuffix): ../src/ludic/tile.cpp $(IntermediateDirectory)/ludic_tile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tile.cpp$(DependSuffix): ../src/ludic/tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tile.cpp$(DependSuffix) -MM "../src/ludic/tile.cpp"

$(IntermediateDirectory)/ludic_tile.cpp$(PreprocessSuffix): ../src/ludic/tile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tile.cpp$(PreprocessSuffix) "../src/ludic/tile.cpp"

$(IntermediateDirectory)/ludic_tiled_layer.cpp$(ObjectSuffix): ../src/ludic/tiled_layer.cpp $(IntermediateDirectory)/ludic_tiled_layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tiled_layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tiled_layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tiled_layer.cpp$(DependSuffix): ../src/ludic/tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tiled_layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tiled_layer.cpp$(DependSuffix) -MM "../src/ludic/tiled_layer.cpp"

$(IntermediateDirectory)/ludic_tiled_layer.cpp$(PreprocessSuffix): ../src/ludic/tiled_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tiled_layer.cpp$(PreprocessSuffix) "../src/ludic/tiled_layer.cpp"

$(IntermediateDirectory)/ludic_time_handler.cpp$(ObjectSuffix): ../src/ludic/time_handler.cpp $(IntermediateDirectory)/ludic_time_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/time_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_time_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_time_handler.cpp$(DependSuffix): ../src/ludic/time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_time_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_time_handler.cpp$(DependSuffix) -MM "../src/ludic/time_handler.cpp"

$(IntermediateDirectory)/ludic_time_handler.cpp$(PreprocessSuffix): ../src/ludic/time_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_time_handler.cpp$(PreprocessSuffix) "../src/ludic/time_handler.cpp"

$(IntermediateDirectory)/ludic_tmx_layer.cpp$(ObjectSuffix): ../src/ludic/tmx_layer.cpp $(IntermediateDirectory)/ludic_tmx_layer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tmx_layer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tmx_layer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tmx_layer.cpp$(DependSuffix): ../src/ludic/tmx_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tmx_layer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tmx_layer.cpp$(DependSuffix) -MM "../src/ludic/tmx_layer.cpp"

$(IntermediateDirectory)/ludic_tmx_layer.cpp$(PreprocessSuffix): ../src/ludic/tmx_layer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tmx_layer.cpp$(PreprocessSuffix) "../src/ludic/tmx_layer.cpp"

$(IntermediateDirectory)/ludic_tmx_loader.cpp$(ObjectSuffix): ../src/ludic/tmx_loader.cpp $(IntermediateDirectory)/ludic_tmx_loader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tmx_loader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tmx_loader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tmx_loader.cpp$(DependSuffix): ../src/ludic/tmx_loader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tmx_loader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tmx_loader.cpp$(DependSuffix) -MM "../src/ludic/tmx_loader.cpp"

$(IntermediateDirectory)/ludic_tmx_loader.cpp$(PreprocessSuffix): ../src/ludic/tmx_loader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tmx_loader.cpp$(PreprocessSuffix) "../src/ludic/tmx_loader.cpp"

$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(ObjectSuffix): ../src/ludic/tmx_tile_map.cpp $(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tmx_tile_map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(DependSuffix): ../src/ludic/tmx_tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(DependSuffix) -MM "../src/ludic/tmx_tile_map.cpp"

$(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(PreprocessSuffix): ../src/ludic/tmx_tile_map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tmx_tile_map.cpp$(PreprocessSuffix) "../src/ludic/tmx_tile_map.cpp"

$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(ObjectSuffix): ../src/ludic/tmx_tile_set.cpp $(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/tmx_tile_set.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(DependSuffix): ../src/ludic/tmx_tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(DependSuffix) -MM "../src/ludic/tmx_tile_set.cpp"

$(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(PreprocessSuffix): ../src/ludic/tmx_tile_set.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_tmx_tile_set.cpp$(PreprocessSuffix) "../src/ludic/tmx_tile_set.cpp"

$(IntermediateDirectory)/ludic_util.cpp$(ObjectSuffix): ../src/ludic/util.cpp $(IntermediateDirectory)/ludic_util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_util.cpp$(DependSuffix): ../src/ludic/util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_util.cpp$(DependSuffix) -MM "../src/ludic/util.cpp"

$(IntermediateDirectory)/ludic_util.cpp$(PreprocessSuffix): ../src/ludic/util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_util.cpp$(PreprocessSuffix) "../src/ludic/util.cpp"

$(IntermediateDirectory)/ludic_vector2_d.cpp$(ObjectSuffix): ../src/ludic/vector2_d.cpp $(IntermediateDirectory)/ludic_vector2_d.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/vector2_d.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_vector2_d.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_vector2_d.cpp$(DependSuffix): ../src/ludic/vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_vector2_d.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_vector2_d.cpp$(DependSuffix) -MM "../src/ludic/vector2_d.cpp"

$(IntermediateDirectory)/ludic_vector2_d.cpp$(PreprocessSuffix): ../src/ludic/vector2_d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_vector2_d.cpp$(PreprocessSuffix) "../src/ludic/vector2_d.cpp"

$(IntermediateDirectory)/ludic_video.cpp$(ObjectSuffix): ../src/ludic/video.cpp $(IntermediateDirectory)/ludic_video.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/video.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_video.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_video.cpp$(DependSuffix): ../src/ludic/video.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_video.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_video.cpp$(DependSuffix) -MM "../src/ludic/video.cpp"

$(IntermediateDirectory)/ludic_video.cpp$(PreprocessSuffix): ../src/ludic/video.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_video.cpp$(PreprocessSuffix) "../src/ludic/video.cpp"

$(IntermediateDirectory)/ludic_collision_box.cpp$(ObjectSuffix): ../src/ludic/collision_box.cpp $(IntermediateDirectory)/ludic_collision_box.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/collision_box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_collision_box.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_collision_box.cpp$(DependSuffix): ../src/ludic/collision_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_collision_box.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_collision_box.cpp$(DependSuffix) -MM "../src/ludic/collision_box.cpp"

$(IntermediateDirectory)/ludic_collision_box.cpp$(PreprocessSuffix): ../src/ludic/collision_box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_collision_box.cpp$(PreprocessSuffix) "../src/ludic/collision_box.cpp"

$(IntermediateDirectory)/ludic_ludic_exception.cpp$(ObjectSuffix): ../src/ludic/ludic_exception.cpp $(IntermediateDirectory)/ludic_ludic_exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/ludic_exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_ludic_exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_ludic_exception.cpp$(DependSuffix): ../src/ludic/ludic_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_ludic_exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_ludic_exception.cpp$(DependSuffix) -MM "../src/ludic/ludic_exception.cpp"

$(IntermediateDirectory)/ludic_ludic_exception.cpp$(PreprocessSuffix): ../src/ludic/ludic_exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_ludic_exception.cpp$(PreprocessSuffix) "../src/ludic/ludic_exception.cpp"

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): ../src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "../src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "../src/main.cpp"

$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix): ../src/ludic/audio.cpp $(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/ludic/audio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix): ../src/ludic/audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ludic_audio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ludic_audio.cpp$(DependSuffix) -MM "../src/ludic/audio.cpp"

$(IntermediateDirectory)/ludic_audio.cpp$(PreprocessSuffix): ../src/ludic/audio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ludic_audio.cpp$(PreprocessSuffix) "../src/ludic/audio.cpp"

$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix): ../src/tinyxml/tinystr.cpp $(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/tinyxml/tinystr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix): ../src/tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinystr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinystr.cpp$(DependSuffix) -MM "../src/tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinystr.cpp$(PreprocessSuffix): ../src/tinyxml/tinystr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinystr.cpp$(PreprocessSuffix) "../src/tinyxml/tinystr.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix): ../src/tinyxml/tinyxml.cpp $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/tinyxml/tinyxml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix): ../src/tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(DependSuffix) -MM "../src/tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxml.cpp$(PreprocessSuffix): ../src/tinyxml/tinyxml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxml.cpp$(PreprocessSuffix) "../src/tinyxml/tinyxml.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix): ../src/tinyxml/tinyxmlerror.cpp $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/tinyxml/tinyxmlerror.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix): ../src/tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(DependSuffix) -MM "../src/tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(PreprocessSuffix): ../src/tinyxml/tinyxmlerror.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlerror.cpp$(PreprocessSuffix) "../src/tinyxml/tinyxmlerror.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix): ../src/tinyxml/tinyxmlparser.cpp $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/tinyxml/tinyxmlparser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix): ../src/tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(DependSuffix) -MM "../src/tinyxml/tinyxmlparser.cpp"

$(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(PreprocessSuffix): ../src/tinyxml/tinyxmlparser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml_tinyxmlparser.cpp$(PreprocessSuffix) "../src/tinyxml/tinyxmlparser.cpp"

$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix): ../src/zlib/adler32.c $(IntermediateDirectory)/zlib_adler32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/adler32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix): ../src/zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_adler32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_adler32.c$(DependSuffix) -MM "../src/zlib/adler32.c"

$(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix): ../src/zlib/adler32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_adler32.c$(PreprocessSuffix) "../src/zlib/adler32.c"

$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix): ../src/zlib/compress.c $(IntermediateDirectory)/zlib_compress.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/compress.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_compress.c$(DependSuffix): ../src/zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_compress.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_compress.c$(DependSuffix) -MM "../src/zlib/compress.c"

$(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix): ../src/zlib/compress.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_compress.c$(PreprocessSuffix) "../src/zlib/compress.c"

$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix): ../src/zlib/crc32.c $(IntermediateDirectory)/zlib_crc32.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/crc32.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix): ../src/zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_crc32.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_crc32.c$(DependSuffix) -MM "../src/zlib/crc32.c"

$(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix): ../src/zlib/crc32.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_crc32.c$(PreprocessSuffix) "../src/zlib/crc32.c"

$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix): ../src/zlib/deflate.c $(IntermediateDirectory)/zlib_deflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/deflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix): ../src/zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_deflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_deflate.c$(DependSuffix) -MM "../src/zlib/deflate.c"

$(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix): ../src/zlib/deflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_deflate.c$(PreprocessSuffix) "../src/zlib/deflate.c"

$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix): ../src/zlib/gzclose.c $(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/gzclose.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix): ../src/zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzclose.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzclose.c$(DependSuffix) -MM "../src/zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix): ../src/zlib/gzclose.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzclose.c$(PreprocessSuffix) "../src/zlib/gzclose.c"

$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix): ../src/zlib/gzlib.c $(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/gzlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix): ../src/zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzlib.c$(DependSuffix) -MM "../src/zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix): ../src/zlib/gzlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzlib.c$(PreprocessSuffix) "../src/zlib/gzlib.c"

$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix): ../src/zlib/gzread.c $(IntermediateDirectory)/zlib_gzread.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/gzread.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix): ../src/zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzread.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzread.c$(DependSuffix) -MM "../src/zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix): ../src/zlib/gzread.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzread.c$(PreprocessSuffix) "../src/zlib/gzread.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix): ../src/zlib/gzwrite.c $(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/gzwrite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix): ../src/zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_gzwrite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_gzwrite.c$(DependSuffix) -MM "../src/zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix): ../src/zlib/gzwrite.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_gzwrite.c$(PreprocessSuffix) "../src/zlib/gzwrite.c"

$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix): ../src/zlib/infback.c $(IntermediateDirectory)/zlib_infback.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/infback.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_infback.c$(DependSuffix): ../src/zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_infback.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_infback.c$(DependSuffix) -MM "../src/zlib/infback.c"

$(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix): ../src/zlib/infback.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_infback.c$(PreprocessSuffix) "../src/zlib/infback.c"

$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix): ../src/zlib/inffast.c $(IntermediateDirectory)/zlib_inffast.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/inffast.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix): ../src/zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inffast.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inffast.c$(DependSuffix) -MM "../src/zlib/inffast.c"

$(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix): ../src/zlib/inffast.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inffast.c$(PreprocessSuffix) "../src/zlib/inffast.c"

$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix): ../src/zlib/inflate.c $(IntermediateDirectory)/zlib_inflate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/inflate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix): ../src/zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inflate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inflate.c$(DependSuffix) -MM "../src/zlib/inflate.c"

$(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix): ../src/zlib/inflate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inflate.c$(PreprocessSuffix) "../src/zlib/inflate.c"

$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix): ../src/zlib/inftrees.c $(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/inftrees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix): ../src/zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_inftrees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_inftrees.c$(DependSuffix) -MM "../src/zlib/inftrees.c"

$(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix): ../src/zlib/inftrees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_inftrees.c$(PreprocessSuffix) "../src/zlib/inftrees.c"

$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix): ../src/zlib/trees.c $(IntermediateDirectory)/zlib_trees.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/trees.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_trees.c$(DependSuffix): ../src/zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_trees.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_trees.c$(DependSuffix) -MM "../src/zlib/trees.c"

$(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix): ../src/zlib/trees.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_trees.c$(PreprocessSuffix) "../src/zlib/trees.c"

$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix): ../src/zlib/uncompr.c $(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/uncompr.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix): ../src/zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_uncompr.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_uncompr.c$(DependSuffix) -MM "../src/zlib/uncompr.c"

$(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix): ../src/zlib/uncompr.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_uncompr.c$(PreprocessSuffix) "../src/zlib/uncompr.c"

$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix): ../src/zlib/zutil.c $(IntermediateDirectory)/zlib_zutil.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/Dados/Arquivos/Documentos/Desenvolvimento/Ludic-Game-Library/src/zlib/zutil.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix): ../src/zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/zlib_zutil.c$(ObjectSuffix) -MF$(IntermediateDirectory)/zlib_zutil.c$(DependSuffix) -MM "../src/zlib/zutil.c"

$(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix): ../src/zlib/zutil.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/zlib_zutil.c$(PreprocessSuffix) "../src/zlib/zutil.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../../../IDEs/Codelite/My Projects/.build-debug/Ludic_Game_Library"


