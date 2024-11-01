NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
SRC_DIR = ./src
INC_DIR = ./include
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = $(SRC_DIR)/push_swap.c
OBJS = $(SRCS:.c=.o)

LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

all: $(LIBFT) $(PRINTF) $(NAME)

# Compile libft
$(LIBFT):
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)

# Compile printf with root libft
$(PRINTF): $(LIBFT)
	@echo "Compiling ft_printf"
	@$(MAKE) -C $(PRINTF_DIR)

# Compile push_swap
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) created successfully"

# compile object files to output
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/include -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "Clean completed."

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "Full clean completed."

re: fclean all

.PHONY: all clean fclean re