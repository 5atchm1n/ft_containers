
NAME = ft_containers

RBT_TEST = rbt_test

SRC = main3.cpp \

_RBT_TEST = _test-rbt.cpp

CC = clang++

CPPSTD = -std=c++98

CFLAGS = -Wall -Wextra -Werror -MMD -MP

MEM = -fsanitize=address -g

INC = -I./containers -I./iterators -I./

_INC_RBT_TEST = -I./containers/map/base

OBJDIR = objs

DEPS = ${OBJS:.o=.d}

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})

_RBT_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_RBT_TEST:.cpp=.o})

all : ${NAME}

${RBT_TEST} : fclean ${_RBT_TEST_OBJS}
	${CC} ${CFLAGS} ${_INC_RBT_TEST} ${MEM} ${CPPSTD} ${_RBT_TEST_OBJS} -o $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INC} $(_INC_RBT_TEST) ${MEM} ${CPPSTD} -c $< -o $@

re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME} ${RBT_TEST}

.PHONY : all clean fclean

-include ${DEPS}