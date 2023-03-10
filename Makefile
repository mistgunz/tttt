NAME = so_long

ROOT_DIR ?= $(shell pwd)
SRCS_DIR = ${ROOT_DIR}/Sources/
SRCS = $(addprefix ${SRCS_DIR}, main.c map.c display.c move.c move_utils.c check_mappath.c check_map.c)
OBJS = $(SRCS:.c=.o)

// MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT			=		./libft/libft.a
MLXLIB			=		./mlx/libmlx.a
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit
MLIBFT			=		$(MAKE) -C libft
MMLX			=		$(MAKE) -C mlx


CC = gcc
OPTIONS = -c
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all: lib $(NAME)

lib:
			@$(MLIBFT) all
			@$(MMLX) all

%.o:		%.c ./libft/libft.h Makefile so_long.h
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLXLIB} ${MINILBX}
			@echo compil done!

clean:
			${RM} ${OBJS}
			cd libft && make clean
			cd mlx && make clean

fclean:		clean
			@${RM} ${NAME}
			@cd libft && make fclean
			@cd mlx && make clean


re: fclean all

.PHONY: re fclean clean all libft
