C = gcc
CXX = g++
CXX_FLAGS = -std=c++14 -g -Wall
SOURCE_C = ocvTest.cxx
#OBJECTS_C = ctest.o cfunc.o
#SOURCE_CXX = Move.cxx
TARGET = cvtest
INCLUDE_FLAGS = -I . -I/usr/local/include/opencv4/
LDFLAGS_COMMON = 
LIBS =  -L/usr/local/lib -lm   -lpthread  -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio
#LIBS = -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm
all:

	$(CXX) $(CXX_FLAGS) $(INCLUDE_FLAGS) $(SOURCE_C) $(OBJECTS_C) $(LDFLAGS_COMMON) $(LIBS) -o $(TARGET) 

clean:
	rm -rf *.o $(TARGET)


#BIN = shaders
#CC = g++
#FLAGS = -Wall -pedantic
#INC = -I ../common/include
#LOC_LIB = ../common/linux_x86_64/libGLEW.a -lglfw
#SYS_LIB = -lGL -lm
#SRC = main.c gl_utils.c

#all:
 #       ${CC} ${FLAGS} -o ${BIN} ${SRC} ${INC} ${LOC_LIB} ${SYS_LIB}

