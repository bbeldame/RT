# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/04/13 19:33:45 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
FLAGS = -Wall -Wextra # @todo : Add -Werror Flag
MLX = ./minilibX/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
LINKS = -L ./minilibX -lm -lmlx -framework OpenGL -framework AppKit
LIBFTA = libft.a
LIBFTDIR = ./libft
OBJDIR = ./objs/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = color.c create_img.c main.c operation.c \
	ray.c raytrace.c sphere.c vector.c hooks.c plane.c \
	parse.c cylinder.c
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
	@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -I $(MLX) -o $@ -c $<

makelibft:
	@make -C $(LIBFTDIR)

makemlx:
	@make -sC $(MLX)

$(NAME): makelibft makemlx obj $(OBJS)
	@gcc $(OBJS) $(LINKS) $(LIBFT) -lm -o $(NAME)
	@echo "$(GREEN)----------RTv1 compiled-----------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)
	@make --silent clean -C $(MLX)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)-----RTv1 removed completely------$(NC)"

re: fclean all
