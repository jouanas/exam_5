CXX = c++
NAME = a.out
CXXFLAGS = -Wall -Wextra -Werror 
SRCS = array_bag.cpp  main.cpp searchable_array_bag.cpp  searchable_tree_bag.cpp  tree_bag.cpp set.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER =  set.hpp array_bag.hpp searchable_array_bag.hpp  searchable_tree_bag.hpp bag.hpp  searchable_bag.hpp tree_bag.hpp
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re