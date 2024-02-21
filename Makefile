CC = cc
DEBFLAGS = -g #-fsanitize=address

SRCS_PATH	:=	srcs
OBJS_PATH	:=	objs

SRCS_FILES = so_long.c so_long_utils.c so_long_init.c so_long_moves.c \
			so_long_draw.c so_long_draw_walls.c so_long_frames.c \
			so_long_mlx_fnc.c so_long_map.c so_long_map_reading.c \
			so_long_bots.c so_long_bots_2.c so_long_load_pics.c \
			get_next_line.c get_next_line_utils.c so_long_exit.c \
			so_long_anims.c so_long_key.c

SRCS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

OBJS		=	$(addprefix $(OBJS_PATH)/, $(OBJS_FILES))

DEPS = so_long_lib.h

RM = rm -rf

MLXFLAGS = -lmlx -lX11 -lXext -lm -lz -lftprintf
MLXPATH = minilibx-linux
PRINTF = srcs/ft_printf

NAME = so_long

$(NAME): $(OBJS) | $(OBJS_PATH)
	$(CC) -I so_long_lib.h -L$(MLXPATH) -L$(PRINTF) $(OBJS) $(MLXFLAGS) -o $(NAME) $(DEBFLAGS)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) -I$(MLXPATH) -O3 -c $< -o $@ $(DEBFLAGS)

all: mlx $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

mlx:
	@echo "\n\n___________________________________"
	@echo "|                                 |"
	@echo "|              MLX                |"
	@echo "|                                 |"
	@echo "-----------------------------------\n"
	$(MAKE) -C minilibx-linux

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
