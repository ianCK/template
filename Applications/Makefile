CXX = g++
INCLUDE_PATHS = C:\\Users\\ianli\\Desktop\\CP\\template\\
CXXFLAGS = -O3 -Wall -std=c++17 -Wl,-stack,10485760 -I $(INCLUDE_PATHS) 

FOLDERS = \
		  FOLDER_Compile\
		  FOLDER_Export\
		  FOLDER_Factor\
		  FOLDER_FileMerger\
		  FOLDER_Generator\
		  FOLDER_Minifier

all :
	make $(FOLDERS)

$(FOLDERS) : 
	make -C ./$(@:FOLDER_%=%)
