_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m

CC		= 	cc
NAME	= 	philo
INCLUDE = 	includes/
LIBFT	= 	../libft/libft.a
CFLAGS	= 	-Wall -Werror -Wextra -D_REENTRANT -g -DWin32
HEADER	= 	philo.h
RM		=	rm -rf
SRCS	= 	main.c \
			parsing.c \
			create_philo.c \
			utils.c \
			error.c \
			eat.c \
			check.c

OBJS_PATH = objs/
OBJS	= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lpthread
	@printf "\n${_GREEN}${_BOLD}[Philo OK]${_END}\n"

$(OBJS_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(LIBFT):
	$(MAKE) --no-print-directory -C ../libft

bonus :
	$(MAKE) --no-print-directory -C ./philo_bonus
	mv philo_bonus/bonus ./

clean:
	$(MAKE) -C ../libft clean
	$(RM) $(OBJS) 
	$(RM) $(OBJS_PATH)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re:	fclean all