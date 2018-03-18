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

void	write_file(char *path)
{
	FILE *file;

	file = fopen(path, "w");

	int _size = GetWindowTextLength(hFile_cont);
	char *data = new char[_size + 1];
	GetWindowText(hFile_cont, data, _size);
	data[_size] = '\0';
	fwrite(data, _size, 1, file);
	fclose(file);
}

void	save_file(HWND hWnd)
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
	GetSaveFileName(&ofn);
	write_file(ofn.lpstrFile);
	free(file_name);
}
