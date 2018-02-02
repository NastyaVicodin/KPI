CODESG SEGMENT PARA 'Code'
ASSUME CS:CODESG, SS:CODESG, DS:CODESG
ORG 100H
main: jmp BEGIN
a dw 3
b dw 2
n dw 7
i dw (?)
BEGIN PROC NEAR
PUSH DS ;сохранить содержимое DS в стеке
SUB AX,AX ;обнулить регистр AX
MOV AL,12H ;занести в AL 12H
ADD AX,4644H;прибавить число 4644Н к регистру АХ
MOV BX,AX ;занести содержимое AX в регистр BX
ADD AX,BX ;прибавить к содержимому AX BX
SUB AX,BX ;вычесть ВХ из регистра АХ
RET
BEGIN ENDP
CODESG ENDS
END MAIN