# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 15:23:02 by jalbers           #+#    #+#              #
#    Updated: 2023/04/24 10:17:43 by jalbers          ###   ########.fr        #
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

SRC := philosophers.c read_input.c create_philos.c utils.c init.c state_change.c error_check.c philo_actions.c

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