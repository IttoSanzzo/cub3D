# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 21:52:16 by marcosv2          #+#    #+#              #
#    Updated: 2024/04/25 15:19:59 by marcosv2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comamad Miscs

NAME	= cub3D
LIBFT	= libft
MAKE	= make
C_COMP	= cc
C_FLAG	= -Wall -Werror -Wextra
C_REMO	= rm -rf
C_MDIR	= mkdir -p
C_PUTS	= printf
C_LIBX	= -lX11 -lXext -lmlx -lm

# Dirs

D_HDRS	= -I ./includes/
D_LBFT	= ./libft/
D_SRCS	= srcs/
D_OBJS	= objs/

# Sources & Objects

DS_MAIN	=	cb_main/
DS_PARS	=	cb_parse/
DS_UTIL	=	cb_utils/
DS_DRAW	=	cb_draw/
DS_RAY	=	cb_ray/
DS_MLX	=	cb_mlx/

N_MAIN	=	main.c				\
			cb_init.c			\
			cb_exit.c
N_PARS	=	cb_arguments.c		\
			cb_base_format.c	\
			cb_parse_elements.c	\
			cb_parse_map.c		\
			cb_layout_to_map.c
N_UTIL	=	cb_get_data.c		\
			cb_error.c			\
			cb_dist.c			\
			cb_upt_r.c			\
			cb_gpc.c			
N_DRAW	=	cb_ipp.c			\
			cb_rgb.c			\
			cbd_clrc.c			\
			cbd_rect.c			\
			cbd_dotp.c			\
			cbd_point.c			\
			cbd_line.c			\
			cbd_sline.c			\
			cbd_pov.c			\
			cbd_map.c
N_RAY	=	cb_move.c			\
			cb_ray.c			\
			cb_walls.c
N_MLX	=	cb_mlx_init.c		\
			cb_mlx_events.c		\
			cb_render.c			\

F_SRCS	= $(addprefix $(D_SRCS)$(DS_MAIN), $(N_MAIN))
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_PARS), $(N_PARS))
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_UTIL), $(N_UTIL))
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_DRAW), $(N_DRAW))
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_RAY), $(N_RAY))
F_SRCS	+= $(addprefix $(D_SRCS)$(DS_MLX), $(N_MLX))

#F_SRCS	+= $(addprefix $(D_SRCS)$(DS_), $(N_))

N_OBJS	=	$(N_MAIN:.c=.o)	\
			$(N_PARS:.c=.o)	\
			$(N_UTIL:.c=.o)	\
			$(N_DRAW:.c=.o)	\
			$(N_RAY:.c=.o)	\
			$(N_MLX:.c=.o)
F_OBJS	= $(addprefix $(D_OBJS), $(N_OBJS))

# Libft

N_LBFT	= libft.a
F_LBFT	= $(addprefix $(D_LBFT), $(N_LBFT))

# Colors
P_WHITE = \033[0m
P_LBLUE = \033[38;5;32m
P_DBLUE = \033[38;5;21m
P_PRPLE = \033[38;5;93m
P_NCYAN = \033[38;5;37m
P_MAGEN = \033[38;5;99m
P_GREEN = \033[38;5;40m
P_LGREN = \033[38;5;42m
P_NWINE = \033[38;5;88m

# Mandatory Rules

all		: $(NAME)

$(NAME)		: $(F_LBFT) $(D_OBJS) $(F_OBJS)
	@$(C_PUTS) "\n\t$(P_NCYAN)Finishing binary..: $(P_LBLUE)$(NAME)$(P_WHITE)\n"
	@$(C_COMP) $(C_FLAG) -o $@ $(F_OBJS) $(F_LBFT) $(C_LIBX)
	@$(C_PUTS) "$(P_GREEN)Done!$(P_WHITE)\n"

$(D_OBJS)%.o	: $(D_SRCS)*/%.c
	@$(C_PUTS) "\t$(P_PRPLE)Generating $(NAME)..: %-33.33s\r $(P_WHITE)" $@
	@$(C_COMP) $(C_FLAG) $(D_HDRS) -c $< -o $@ $(C_LIBX)

$(D_OBJS)	:
	@$(C_PUTS) "$(P_LGREN)Starting $(NAME) compilation...$(P_WHITE)"
	@$(C_PUTS) "\n\t$(P_MAGEN)Creating $(NAME) objects directory...$(P_WHITE)\n"
	@$(C_MDIR) $(D_OBJS)

$(F_LBFT)	:
	@clear
	@$(MAKE) all --no-print-directory -C $(D_LBFT)

bonus		: $(NAME)
	@$(C_PUTS) "$(P_GREEN)Bonus Done!$(P_WHITE)\n"

#confmlx	:
#@$(MAKE) all --no-print-directory -C ./minilibx-linux/

clean		:
#@$(MAKE) clean --no-print-directory -C ./minilibx-linux/
	@$(MAKE) clean --no-print-directory -C $(D_LBFT)
	@$(C_PUTS) "$(P_NWINE)Cleaning $(NAME) objects...$(P_WHITE)\n"
	@${C_REMO} $(D_OBJS)

fclean		:
#@$(MAKE) clean --no-print-directory -C ./minilibx-linux/
	@$(MAKE) fclean --no-print-directory -C $(D_LBFT)
	@$(C_PUTS) "$(P_NWINE)Cleaning $(NAME) objects...$(P_WHITE)\n"
	@${C_REMO} $(D_OBJS)
	@$(C_PUTS) "$(P_NWINE)Deleting $(NAME)...$(P_WHITE)\n"
	@${C_REMO} $(NAME)

re		: fclean all

# Test

val		:
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

uplibft	:
	@rm -rf ./libft/
	@git clone git@github.com:IttoSanzzo/libft.git
	@rm -rf ./libft/.git

setlib	:
	@cp ~/Downloads/minilibx-linux.tgz ./
	@tar zxvf minilibx-linux.tgz
	@${C_REMO} minilibx-linux.tgz
	@$(MAKE) --no-print-directory -C ./minilibx-linux/
	@$(C_PUTS) "$(P_GREEN)Done!$(P_WHITE)\n"

rmvlib	:
	@${C_REMO} ./minilibx-linux
	@$(C_PUTS) "$(P_GREEN)Done!$(P_WHITE)\n"

# Phony

.PHONY: all clean fclean re val uplibft setlib rmvlib confmlx bonus
