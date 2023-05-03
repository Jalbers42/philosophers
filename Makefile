# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 15:23:02 by jalbers           #+#    #+#              #
#    Updated: 2023/04/26 11:34:29 by jalbers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

# Program for compiling C programs
CC := cc

# Extra flags to give to the C compiler
CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

MAIN := philo

# =============================================================================
#	MANDATORY PART
# =============================================================================

SRC := philosophers.c read_input.c create_philos_forks.c utils.c init_deinit.c state_msg_printf.c error_check.c take_release_forks.c life_philos.c

# =============================================================================
#	RULES
# =============================================================================

all: $(MAIN)

$(MAIN):
	$(CC) $(CFLAGS) $(SRC) -o $(MAIN)

# Clean object files (*.o) - not used on this project
clean:

# Clean object files (*.o) and the binary file
fclean: clean
	$(RM) $(MAIN)

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re: fclean all

# .PHONY rule in order to avoid relinking
.PHONY: all clean fclean re