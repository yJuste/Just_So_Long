NAME = so_long

CC = cc
CFLAGS = -g # -fsanitize=address

MINILIBX = libmlx.a
PATH_MINILIBX = minilibx_macos

MLXFLAGS = -framework OpenGL -framework AppKit

PRINTF = libftprintf.a
PATH_PRINTF = Printf_fd

SRC =	ft_so_long.c				\
	ft_so_long_next.c			\
	ft_parse_map.c				\
	ft_check.c				\
	ft_lib.c				\
	ft_lib_2.c				\
	ft_split.c				\
	Get_Next_Line/get_next_line.c

OBJ = $(SRC:.c=.o)

NORMINETTE =	*.c		\
		*.h		\
		Get_Next_Line	\
		Printf_fd

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(PATH_PRINTF) -lftprintf -L $(PATH_MINILIBX) -lmlx $(MLXFLAGS)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

$(PRINTF):
	$(MAKE) -C $(PATH_PRINTF)

$(MINILIBX):
	$(MAKE) -C $(PATH_MINILIBX)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(PATH_PRINTF) clean
	@$(MAKE) -C $(PATH_MINILIBX) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@$(MAKE) -C $(PATH_MINILIBX) clean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 15 ft_so_long.h
	@echo $(RESET)

norm:
	@norminette $(NORMINETTE)

.PHONY: all clean fclean re rf s help norm
