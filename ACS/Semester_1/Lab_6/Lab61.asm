codseg segment
assume cs:codseg, ds:codseg, ss: codseg
	org 100h
main: 	jmp begin
N DW 9
A DW 5
begin proc near
	SUB AX,AX;	�������� ������� AX
	SUB DX,DX;	�������� ������� DX
	MOV CX,N;	������� N � ������� AX
M1:
        INC AX;		�������� ���������� �� �� 1
	MOV BX,AX;	������� AX � ������� BX
	SHL BX,1;	������� ����� ��� ����� �� 2
	ADD BX,1;	�������� 1 � ��
	ADD BX,A;	��������� � ����������� BX �
	ADD DX,BX;	��������� � ����������� DX ��
	LOOP M1;
	RET
begin	endp
codseg	ends
	end main
