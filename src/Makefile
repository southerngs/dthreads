INC_DIR = include
SRC_DIR = source

SRCS = $(SRC_DIR)/libdthread.cpp $(SRC_DIR)/xrun.cpp $(SRC_DIR)/xthread.cpp $(SRC_DIR)/xmemory.cpp $(SRC_DIR)/prof.cpp $(SRC_DIR)/real.cpp
DEPS = $(SRCS) $(INC_DIR)/xpersist.h $(INC_DIR)/xdefines.h $(INC_DIR)/xglobals.h $(INC_DIR)/xpersist.h $(INC_DIR)/xplock.h $(INC_DIR)/xrun.h $(INC_DIR)/warpheap.h $(INC_DIR)/xadaptheap.h $(INC_DIR)/xoneheap.h

INCLUDE_DIRS = -I$(INC_DIR) -I./Heap-Layers

all: libdthreads.so

# 64bit version
#CXX = g++ -march=core2 -mtune=core2 -msse3

#32 bit version.
CXX = ${HOME}/tools/llvm-3.2/bin/clang++ -march=core2 -mtune=core2 -msse3 -m32 -DSSE_SUPPORT 
#CXX = g++ -march=core2 -mtune=core2 -msse3 -m32 -DSSE_SUPPORT 

# Check deterministic schedule
# -DCHECK_SCHEDULE

# Get some characteristics about running.
# -DGET_CHARACTERISTICS
CFLAGS = -DNDEBUG -shared -fPIC -DLAZY_COMMIT -DLOCK_OWNERSHIP -DDETERM_MEMORY_ALLOC -D'CUSTOM_PREFIX(x)=grace\#\#x'
CFLAGS += -O0 -g
#CFLAGS += -O3

LIBS = -ldl -lpthread

libdthreads.so: $(SRCS) $(DEPS) Makefile
	$(CXX) $(CFLAGS) $(INCLUDE_DIRS) $(SRCS) -o libdthreads.so $(LIBS)

clean:
	rm -f libdthreads.so 

