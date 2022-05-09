CXX = g++
INCLUDE_PATHS = C:\\Users\\inali\\Desktop\\CP\\template\\
CXXFLAGS = -O3 -Wall -std=c++17 -Wl,-stack,10485760 -I $(INCLUDE_PATHS) 

FOLDERS = \
		  FOLDER_Algebra\
		  FOLDER_Applications\
		  FOLDER_CommonInclude\
		  FOLDER_DP\
		  FOLDER_DS\
		  FOLDER_Flow\
		  FOLDER_Geometry\
		  FOLDER_Graph\
		  FOLDER_Heuristic\
		  FOLDER_Math\
		  FOLDER_Offline\
		  FOLDER_String\
		  FOLDER_Various

all:
	make $(FOLDERS)

$(FOLDERS) : 
	make -C ./$(@:FOLDER_%=%)
