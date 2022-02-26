
NAME = ft_containers

RBT_TEST = rbt_test

MAP_TEST = map_test

VEC_TEST = vector_test

SRC = main3.cpp \

_RBT_TEST = _containers_test/_test-rbt.cpp
_MAP_TEST = _containers_test/_test-map.cpp
_VEC_TEST = _containers_test/_test-vector.cpp

CC = clang++

CPPSTD = -std=c++98

CFLAGS = -Wall -Wextra -Werror -MMD -MP

MEM = -fsanitize=address -g3 
DEBUG = -fstandalone-debug

INC = -I./containers -I./iterators -I./

_INC_RBT_TEST = -I./containers/map/rbtree

OBJDIR = objs

DEPS = ${OBJS:.o=.d}

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})

_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})

_RBT_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_RBT_TEST:.cpp=.o})

_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})

all : ${NAME}

${VEC_TEST} : fclean ${_VEC_TEST_OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

${RBT_TEST} : fclean ${_RBT_TEST_OBJS}
	${CC} ${CFLAGS} ${_INC_RBT_TEST} ${MEM} ${CPPSTD} ${_RBT_TEST_OBJS} -o $@

${MAP_TEST} : fclean ${_MAP_TEST_OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INC} $(_INC_RBT_TEST) ${MEM} ${CPPSTD} -c $< -o $@

re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME} ${RBT_TEST} ${MAP_TEST}

.PHONY : all clean fclean

-include ${DEPS}
