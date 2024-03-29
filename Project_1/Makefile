# OBJECT FILES
MAIN_OBJ   = main.o
UNIT_OBJ   = unit_testing.o
PARSER_OBJ = ./opts/getopts.o
SORT_OBJS  = ./sortingAlg/quicksort.o ./sortingAlg/tablesort.o
SEARCH_OBJ = ./searchingAlg/binarySearch.o
UTILS_OBJ  = ./utils/utils.o
TMPL_OBJ   = ./templates/list.o
OBJECTS    = $(MAIN_OBJ) $(PARSER_OBJ) $(UTILS_OBJ) $(TMPL_OBJ) $(SORT_OBJS) $(SEARCH_OBJ)
TEST_OBJS  = $(UNIT_OBJ) $(PARSER_OBJ) $(UTILS_OBJ) $(TMPL_OBJ) $(SORT_OBJS) $(SEARCH_OBJ)

# SOURCES
MAIN_SRC   = main.cpp
UNIT_SRC   = unit_testing.cpp
PARSER_SRC = ./opts/getopts.cpp
SORT_SRCS  = ./sortingAlg/quicksort.cpp ./sortingAlg/tablesort.cpp
SEARCH_SRC = ./searchingAlg/binarySearch.cpp
UTILS_SRC  = ./sortingAlg/quicksort.cpp ./searchingAlg/binarySearch.cpp
TMPL_SRC   = ./templates/list.cpp
SOURCES    = $(UNIT_SRC) $(MAIN_SRCS) $(PARSER_SRC) $(UTILS_SRC) $(TMPL_SRC) $(SORT_SRCS) $(SEARCH_SRC)

# HEADERS
PARSER_HDR = ./opts/getopts.hpp
SORT_HDRS  = ./sortingAlg/quicksort.cpp ./sortingAlg/tablesort.cpp
SEARCH_HDR = ./searchingAlg/binarySearch.cpp
UTILS_HDR  = ./sortingAlg/quicksort.cpp ./searchingAlg/binarySearch.cpp
TMPL_HDR   = ./templates/list.hpp
HEADERS    = $(PARSER_HDR) $(SORT_HDRS) $(UTILS_HDR) $(TMPL_HDR) $(SEARCH_HDR)

# EXECUTABLES
MAIN_OUT   = main
TEST_OUT   = unit_testing

# FLAGS
CC         = g++
FLAGS      = -c
DEBUG      = -g3

# ------------------------------------------------- #

all: $(OBJECTS) $(TEST_OBJS) $(MAIN_OUT) $(TEST_OUT)

# Creating Executables
main : $(OBJECTS)
	@echo "\n\033[1;33mCompiling executables\033[0m";
	$(CC) $(DEBUG) -o $(MAIN_OUT) $(OBJECTS)

unit_testing : $(TEST_OBJS)
	@echo "\n\033[1;33mCompiling testing executables\033[0m";
	$(CC) $(DEBUG) -o $(TEST_OUT) $(TEST_OBJS)
	@echo "";

# ------------------------------------------------- #

# Creating Object Files
main.o : main.cpp
	@echo "\n\033[1;33mCompiling objects\033[0m";
	$(CC) $(DEBUG) -o main.o                        $(FLAGS) main.cpp

unit_testing.o : unit_testing.cpp
	@echo "\n\033[1;33mCompiling test objects\033[0m";
	$(CC) $(DEBUG) -o unit_testing.o                $(FLAGS) unit_testing.cpp

./opts/getopts.o : ./opts/getopts.cpp
	$(CC) $(DEBUG) -o ./opts/getopts.o              $(FLAGS) ./opts/getopts.cpp

./templates/list.o : ./templates/list.cpp
	$(CC) $(DEBUG) -o ./templates/list.o            $(FLAGS) ./templates/list.cpp

./utils/utils.o : ./utils/utils.cpp
	$(CC) $(DEBUG) -o ./utils/utils.o               $(FLAGS) ./utils/utils.cpp

./sortingAlg/quicksort.o : ./sortingAlg/quicksort.cpp
	$(CC) $(DEBUG) -o ./sortingAlg/quicksort.o      $(FLAGS) ./sortingAlg/quicksort.cpp

./sortingAlg/tablesort.o : ./sortingAlg/tablesort.cpp
	$(CC) $(DEBUG) -o ./sortingAlg/tablesort.o      $(FLAGS) ./sortingAlg/tablesort.cpp

./searchingAlg/binarySearch.o : ./searchingAlg/binarySearch.cpp
	$(CC) $(DEBUG) -o ./searchingAlg/binarySearch.o $(FLAGS) ./searchingAlg/binarySearch.cpp

# ------------------------------------------------- #

# Cleaning Files
clean:
	rm -f $(MAIN_OUT) $(TEST_OUT) $(OBJECTS) $(TEST_OBJS)

# ------------------------------------------------- #

# Counting Files
count:
	wc $(SOURCES) $(HEADERS)
