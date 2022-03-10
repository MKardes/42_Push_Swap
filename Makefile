NAME = libft.a
LIBFT = libft

all: $(NAME)
	gcc *.c libft.a

$(NAME): $(LIBFT)
	make -C $(LIBFT)
	cp libft/libft.a .

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

.PHONY: clean
