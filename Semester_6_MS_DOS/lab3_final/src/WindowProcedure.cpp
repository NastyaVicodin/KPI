//################################################
//
//    #             
//    #  #           Program: HeaderMaker
//    #  #          
//    ####   #       Author: Anastasia Lukyanenko
//    #  ## ##      
//    #  # # #       Created By HeaderMaker 
//       #   #      
//           #      
//
//################################################

#include "header_maker.h"

LRESULT CALLBACK DialogProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{
		case WM_COMMAND:
			switch(wp)
			{
				case 1:
					DestroyWindow(hWnd);
					break;
			}
			break ;
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break ;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int 	i;
	int 	j;
	char 	*str_bord;
	char 	*str_space;
	int		val;

	switch (msg)
	{
		case WM_COMMAND:
			switch(wp)
			{
				case FILE_MENU_EXIT:
					{
						val = MessageBoxW(hWnd, L"Are you sure?", L"Exit",
							MB_YESNO | MB_ICONQUESTION);
						if (val == IDYES)
							DestroyWindow(hWnd);
						break;
					}
				case FILE_MENU_OPEN:
					open_file(hWnd);
					break ;
				case FILE_MENU_SAVE:
					save_file(hWnd);
					break ;
				case FILE_MENU_HELP:
					displayDialog(hWnd);
					break ;
				case PASTE_INTO_FILE:
				{
					char *file_cont;

					header = (char *)malloc(sizeof(char) * 999999);
					file_cont = (char *)malloc(sizeof(char) * 999999);
					GetWindowText(hFile_cont, file_cont, 999999);
					GetWindowText(hHeader, header, 999999);

					strcat(header, "\r\n");
					strcat(header, file_cont);

					SetWindowText(hFile_cont, header);
					break ;
				}
				case CLEAR_FIELD:
				{
					SetWindowText(hHeader, "");
					break ;
				}
				case MAKE_HEADER:
					i = 0;
					prog_name = (char *)malloc(sizeof(char) * 101);
					author = (char *)malloc(sizeof(char) * 101);
					comment_type = (char *)malloc(sizeof(char) * 50);
					header = (char *)malloc(sizeof(char) * 1001);
					GetWindowText(hProg_name, prog_name, 100);
					GetWindowText(hAuthor, author, 100);
					GetWindowText(hComment_type, comment_type, 100);
					
					if (strcmp(prog_name, "") == 0 || strcmp(author, "") == 0
						|| strcmp(comment_type, "") == 0)
					{
						val = MessageBoxW(hWnd, L"Some fields are empty.", L"Error",
							MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
						switch(val)
						{
							case IDABORT:
								DestroyWindow(hWnd);
								break ;
							case IDRETRY:
								return 0;
							case IDIGNORE:
								break ;
						}
					}
					strcpy(header, comment_type);
					
					str_bord = (char *)malloc(sizeof(char) * 70);
					str_space = (char *)malloc(sizeof(char) * 70);
					while (j < 48)
						str_bord[j++] = '#';
					str_bord[j] = '\0';
					j = 0;
					while (j < 69)
						str_space[j++] = ' ';
					str_space[j] = '\0';
					
					while (i < 12)
					{
						if (i != 0)
							strcat(header, comment_type);
						if (i == 0 || i == 11)
							strcat(header, str_bord);
						if (i == 2)
							strcat(header, "    #             ");
						if (i == 3)
						{
							strcat(header, "    #  #          ");
							strcat(header, " Program: ");
							strcat(header, prog_name);
						}
						if (i == 4)
							strcat(header, "    #  #          ");
						if (i == 5)
						{
							strcat(header, "    ####   #      ");
							strcat(header, " Author: ");
							strcat(header, author);
						}
						if (i == 6)
							strcat(header, "    #  ## ##      ");
						if (i == 7)
						{
							strcat(header, "    #  # # #      ");
							strcat(header, " Created By HeaderMaker ");
						}
						if (i == 8)
							strcat(header, "       #   #      ");
						if (i == 9)
							strcat(header, "           #      ");
						strcat(header, "\r\n");
						i++;
					}
					SetWindowText(hHeader, header);
					
					free(str_space);
					free(str_bord);
					
					free(prog_name);
					free(author);
					free(comment_type);
					free(header);
					break ;
			}
			break ;
		case WM_CREATE:
			loadImages();
			AddMenus(hWnd);
			AddControls(hWnd);
			break ;
		case WM_DESTROY:
			PostQuitMessage(0);
			break ;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}