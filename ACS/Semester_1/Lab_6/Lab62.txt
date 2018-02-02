codseg segment  para 'code'
assume cs:codseg, ds:codseg, ss: codseg
    org 100h
main:   jmp begin
N DW 9;
begin proc near
      SUB CX,CX
      SUB AX,AX
      SUB BX,BX
      MOV CX,N
      A20 :
      MOV BX,1
      MOV AX,1
      A21 :
       SHL AX,1
       ADD DX,AX
       INC BX
       cmp CX,BX
       JAE A21
      LOOP A20
	RET
begin   endp
codseg  ends
    end main
