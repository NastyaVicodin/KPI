SEGST   SEGMENT PARA STACK 'Stack'
DB	30 DUP(?)
SEGST   ENDS
;-------------------------------------
SEGDT   SEGMENT 
A	DB   5	;эти данные не используются в приведенной программе
B	DW 300	; и приведены для иллюстрации применения сегмента 
			;данных
SEGDT   ENDS
;-------------------------------------
SEGCOD  SEGMENT 
ASSUME CS:SEGCOD,SS:SEGST,DS:SEGDT
 BEGIN   PROC   FAR
PUSH	DS      ;сохранить содержимое DS в стеке
SUB	AX,AX	;обнулить регистр AX
MOV     AL,12H  ;занести в AL 12H
ADD     AX,4644H;прибавить число 4644Н к регистру АХ
MOV     BX,AX   ;занести содержимое AX в регистр BX
ADD     AX,BX   ;прибавить к содержимому AX BX
SUB     AX,BX   ;вычесть ВХ из регистра АХ
RET
BEGIN   ENDP
SEGCOD  ENDS
END	BEGIN