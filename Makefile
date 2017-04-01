# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/03/26 21:35:34 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
FLAGS = -Wall -Wextra # @TODO : Add -Werror Flag
LINKS = -lm -lmlx -framework OpenGL -framework AppKit
LIBFTA = libft.a
LIBFTDIR = ./libft
OBJDIR = ./objs/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = color.c create_img.c dot_product.c intersect_sphere.c main.c \
	operation.c ray.c raytrace.c sphere.c vector.c
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

makelibft:
	@make -C $(LIBFTDIR)

$(NAME): makelibft obj $(OBJS)
	@gcc $(OBJS) $(LINKS) $(LIBFT) -lm -o $(NAME)
	@echo "$(GREEN)----------RTv1 compiled-----------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)-----RTv1 removed completely------$(NC)"

re: fclean all
