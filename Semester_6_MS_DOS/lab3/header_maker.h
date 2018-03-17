#ifndef HEADER_MAKER_H
#define HEADER_MAKER_H

# include <windows.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdio.h>

# define FILE_MENU_OPEN 1
# define FILE_MENU_SAVE 2
# define FILE_MENU_EXIT 3
# define MAKE_HEADER 4
# define CLEAR_FIELD 5
# define FILE_MENU_HELP 6

extern char		*prog_name;
extern char		*author;
extern char		*comment_type;
extern char		*header;

extern HWND		hProg_name;
extern HWND		hAuthor;
extern HWND		hComment_type;
extern HWND		hHeader;
extern HWND		hFile_cont;
extern HWND		hSave;
extern HWND		hOpen;

extern HMENU	hMenu;
extern HBITMAP	hSaveImg;
extern HBITMAP	hOpenImg;

LRESULT CALLBACK	WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
LRESULT CALLBACK	DialogProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void				AddMenus(HWND);
void				AddControls(HWND);
void				loadImages();
void				registerDialogClass(HINSTANCE hInst);
void				displayDialog(HWND hWnd);
void				open_file(HWND hWnd);
void				display_file(char *path);
void				write_file(char *path);
void				save_file(HWND hWnd);
#endif
