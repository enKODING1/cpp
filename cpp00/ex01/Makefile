CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = phonebook

SOURCES = main.cpp PhoneBook.cpp Contact.cpp
INCLUDES = -I.
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES)  -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re