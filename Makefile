### MAKEFILE FOR CONTAINERS

## VARIABLES
# Makefile Rules

NAME = ft_containers

RBT_TEST = rbt_test

MAP_TEST = map_test

VEC_TEST = vector_test

VEC_FT = ft_vector

VEC_STD = std_vector

MAP_FT = ft_map

MAP_STD = std_map
# Makefile recipe specific Rules

OBJDIR = objs
MKDIR_P = mkdir -p

# Makefile colours

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
GREY="\033[0;37m"
RESET="\033[m"

# Compiler directives

CC = clang++
CPPSTD = -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

# Debug and Memory

DEBUG = -fstandalone-debug -g3

MEM = -fsanitize=address 

ifeq ($(NO_MEM),1)
MEM = 
endif

## SOURCE FILES
# Default
SRC = _containers_test/main3.cpp
# Reb Black Tree
_RBT_TEST = _containers_test/_test-rbt.cpp
# Map
_MAP_TEST = _containers_test/_test-map.cpp
# Vector
_VEC_TEST = _containers_test/_test-vector.cpp
# END

## INCLUDE FILES
# Global include
INC = -I./containers
# custom include
_INC_RBT_TEST = -I./containers/map/rbtree

## DEPENDECIES recipe
DEPS = ${OBJS:.o=.d}
VEC_DEPS = ${_VEC_TEST_OBJS:.o=.d}

## OBJS DIR recipe
OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_RBT_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_RBT_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})

# GLOBAL MAKE ALL

all : ${NAME}
# default recipe
${NAME} : ${OBJS}
	${CC} ${CXXFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

# object file recipe
${OBJDIR}/%.o:%.cpp
	@${MKDIR_P} ${@D}
	${CC} ${CXXFLAGS} ${_TEST} ${MEM} ${INC} $(DEBUG) $(_INC_RBT_TEST)  ${CPPSTD} -c $< -o $@

# END GLOBAL ALL

# TEST RED BLACK TREE
# generate tree exectutable
${RBT_TEST} : fclean ${_RBT_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_INC_RBT_TEST} ${MEM} ${CPPSTD} ${_RBT_TEST_OBJS} -o $@

# MAP

${MAP_FT} : ${MAP_TEST}

${MAP_STD}: _TEST=-D_NAMESPACE=std

${MAP_STD}: ${MAP_TEST}

# TEST MAP
# generate map exectutable

${MAP_TEST} : clean ${_MAP_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

LOG_DIR = log
BIN_DIR = bin
TEST_MAP = test_map

${TEST_MAP} : tclean
	@echo ${BLUE} "\n\t RUN VECTOR TESTS" ${RESET}
	@echo ${CYAN} "Make std_vector :\t" ${RESET}
	@make -s ${MAP_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@mv ${MAP_TEST} ${MAP_STD}
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${MAP_STD} > ${LOG_DIR}/std.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_vector:\t" ${RESET}
	@make -s ${MAP_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@mv ${MAP_TEST} ${MAP_FT}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${MAP_FT} > ${LOG_DIR}/ft.out 2> ${LOG_DIR}/mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/std.out ${LOG_DIR}/ft.out > ${LOG_DIR}/diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# VECTOR
# create make calls for ft and std

${VEC_FT} : ${VEC_TEST}

${VEC_STD} : _TEST=-D_NAMESPACE=std

${VEC_STD} : ${VEC_TEST}

# VECTOR
# generate vector exectutable

${VEC_TEST} : clean ${_VEC_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

LOG_DIR = log
BIN_DIR = bin
TEST_VECTOR = test_vector

${TEST_VECTOR} : tclean
	@echo ${BLUE} "\n\t RUN MAP TESTS" ${RESET}
	@echo ${CYAN} "Make std_map :\t" ${RESET}
	@make -s ${VEC_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@mv ${VEC_TEST} ${VEC_STD}
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${VEC_STD} > ${LOG_DIR}/std.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_vector :\t" ${RESET}
	@make -s ${VEC_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@mv ${VEC_TEST} ${VEC_FT}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${VEC_FT} > ${LOG_DIR}/ft.out 2> ${LOG_DIR}/mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/std.out ${LOG_DIR}/ft.out > ${LOG_DIR}/diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# VECTOR END

# COMMON RULES
re : fclean all

clean :
	@echo -n ${BLUE} "clean objs :\t\t" ${RESET}
	@rm -rf ${OBJDIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

fclean : clean tclean
	@echo -n ${BLUE} "clean binaries:\t" ${RESET}
	@rm -f  ${NAME} ${TEST_VECTOR} ${VEC_FT} ${VEC_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}

tclean : clean
	@echo -n ${BLUE} "clean test bin :\t" ${RESET}
	@rm -rf ${BIN_DIR} ${LOG_DIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

.PHONY : all clean fclean tclean

# ADD DEPENDECIES
-include ${DEPS}
