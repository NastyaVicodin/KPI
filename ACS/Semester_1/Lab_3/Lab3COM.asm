CODESG SEGMENT PARA 'Code'
ASSUME CS:CODESG, SS:CODESG, DS:CODESG
ORG 100H
main: jmp BEGIN
a dw 3
b dw 2
n dw 7
i dw (?)
BEGIN PROC NEAR
PUSH DS ;��������� ���������� DS � �����
SUB AX,AX ;�������� ������� AX
MOV AL,12H ;������� � AL 12H
ADD AX,4644H;��������� ����� 4644� � �������� ��
MOV BX,AX ;������� ���������� AX � ������� BX
ADD AX,BX ;��������� � ����������� AX BX
SUB AX,BX ;������� �� �� �������� ��
RET
BEGIN ENDP
CODESG ENDS
END MAIN