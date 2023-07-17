# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 12:27:46 by ohayek            #+#    #+#              #
#    Updated: 2023/07/17 12:27:47 by ohayek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC		= client
NAMES		= server
BONUS_NAMEC	= client_bonus
BONUS_NAMES	= server_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCSC		= client.c
SRCSS		= server.c
BONUS_SRCSC	= ft_atoi.c client_bonus.c
BONUS_SRCSS	= server_bonus.c
OBJSC		= $(SRCSC:.c=.o)
OBJSS		= $(SRCSS:.c=.o)
BONUS_OBJSC	= $(BONUS_SRCSC:.c=.o)
BONUS_OBJSS	= $(BONUS_SRCSS:.c=.o)

all: $(NAMEC) $(NAMES)

$(NAMEC): $(SRCSC)
	$(CC) $(SRCSC) -o $(NAMEC) $(CFLAGS)

$(NAMES): $(SRCSS)
	$(CC) $(SRCSS) -o $(NAMES) $(CFLAGS)

bonus: $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC): $(BONUS_SRCSC)
	$(CC) $(BONUS_SRCSC) -o $(BONUS_NAMEC) $(CFLAGS)

$(BONUS_NAMES): $(BONUS_SRCSS)
	$(CC) $(BONUS_SRCSS) -o $(BONUS_NAMES) $(CFLAGS)


clean:
	$(RM) $(OBJSC) $(OBJSS) $(BONUS_OBJSC) $(BONUS_OBJSS)

fclean: clean
	$(RM) $(NAMEC) $(NAMES) $(BONUS_NAMEC) $(BONUS_NAMES)

re: fclean all

.PHONY: all clean fclean re