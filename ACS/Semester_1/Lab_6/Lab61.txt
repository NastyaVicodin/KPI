codseg segment
assume cs:codseg, ds:codseg, ss: codseg
	org 100h
main: 	jmp begin
N DW 9
A DW 5
begin proc near
	SUB AX,AX;	обнулить регистр AX
	SUB DX,DX;	обнулить регистр DX
	MOV CX,N;	занесем N в регистр AX
M1:
        INC AX;		увеличим содержимое АХ на 1
	MOV BX,AX;	занесем AX в регистр BX
	SHL BX,1;	умножим число без знака на 2
	ADD BX,1;	прибавим 1 к ВХ
	ADD BX,A;	прибавить к содержимому BX А
	ADD DX,BX;	прибавить к содержимому DX ВХ
	LOOP M1;
	RET
begin	endp
codseg	ends
	end main
