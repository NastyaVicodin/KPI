SEGST   SEGMENT PARA STACK 'Stack'
DB	30 DUP(?)
SEGST   ENDS
;-------------------------------------
SEGDT   SEGMENT 
A	DB   5	;��� ������ �� ������������ � ����������� ���������
B	DW 300	; � ��������� ��� ����������� ���������� �������� 
			;������
SEGDT   ENDS
;-------------------------------------
SEGCOD  SEGMENT 
ASSUME CS:SEGCOD,SS:SEGST,DS:SEGDT
 BEGIN   PROC   FAR
PUSH	DS      ;��������� ���������� DS � �����
SUB	AX,AX	;�������� ������� AX
MOV     AL,12H  ;������� � AL 12H
ADD     AX,4644H;��������� ����� 4644� � �������� ��
MOV     BX,AX   ;������� ���������� AX � ������� BX
ADD     AX,BX   ;��������� � ����������� AX BX
SUB     AX,BX   ;������� �� �� �������� ��
RET
BEGIN   ENDP
SEGCOD  ENDS
END	BEGIN