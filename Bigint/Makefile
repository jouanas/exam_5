CXX = c++
NAME = bigint
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp bigint.cpp  
OBJS = $(SRCS:.cpp=.o)
HEADER = bigint.hpp 
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re