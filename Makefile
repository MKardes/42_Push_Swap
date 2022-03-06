NAME = libft.a
LIBFT = libft

all: $(NAME)

$(NAME): $(LIBFT)
	make -C $(LIBFT)
	cp libft/libft.a .

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f libft.a

.PHONY: clean
