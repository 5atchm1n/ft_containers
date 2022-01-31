
NAME = ft_containers

SRC = main.cpp \

CC = clang++

CPPSTD = -std=c++98

MEM = -fsanitize=address

INC = -I./containers -I./iterators

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} -c $< -o $@

re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean