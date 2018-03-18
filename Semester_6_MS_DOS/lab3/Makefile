#################################################
#
#    #             
#    #  #           Program: HeaderMaker
#    #  #          
#    ####   #       Author: Anastasia Lukyanenko
#    #  ## ##      
#    #  # # #       Created By HeaderMaker 
#       #   #      
#           #      
#
#################################################

NAME = program
SRC = 	src/WindowProcedure.cpp					\
		src/open_file.cpp 						\
		src/save_file.cpp 						\
		src/header_maker.cpp 					\
		src/AddControls.cpp 					\
		src/AddMenus.cpp 						\
		src/dialog_window.cpp

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -lcomdlg32 -lstdc++
