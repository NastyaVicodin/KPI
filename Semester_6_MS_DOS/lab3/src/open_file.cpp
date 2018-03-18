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

void	display_file(char *path)
{
	FILE *file;

	file = fopen(path, "rb");
	fseek(file, 0, SEEK_END);
	int _size = ftell(file);
	rewind(file);

	char *data = new char[_size + 1];
	fread(data, _size, 1, file);
	data[_size] = '\0';

	SetWindowText(hFile_cont, data);
	fclose(file);
}

void	open_file(HWND hWnd)
{
	OPENFILENAME ofn;

	char	*file_name;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	file_name = (char *)malloc(sizeof(char) * 500);
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = file_name;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = 500;
	ofn.lpstrFilter = "All files\0*.*\0Source Files\0*.CPP\0Text Files\0*.TXT\0";
	ofn.nFilterIndex = 1;
	GetOpenFileName(&ofn);
	display_file(ofn.lpstrFile);
	free(file_name);
}
