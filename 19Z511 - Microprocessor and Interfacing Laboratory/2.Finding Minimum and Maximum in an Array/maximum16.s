; actual entry point of the program, must be present
jumpless:
JMP chpt1 ; jump to chpt1

jumpgreat:
MOV BX,AX ; store new minimum
JMP chpt1 ; jump to chpt1

finalhalt:
HLT ; halt program

start:
MOV BYTE [0x1FFF],0x8
MOV WORD [0x2000],0x1234
MOV WORD [0x2002],0xABCD
MOV WORD [0x2004],0x5678
MOV WORD [0x2006],0x89EF
MOV WORD [0x2008],0x1357
MOV WORD [0x200A],0x2468
MOV WORD [0x200C],0xBDF0
MOV WORD [0x200E],0x7890

MOV SI,0x2000 ; point to first element
MOV CL,BYTE [0x1FFF] ; number of elements
MOV BX,0

chpt1:
CMP CL,0 ; check if count is zero
JZ finalhalt ; if zero, jump to finalhalt
DEC CL ; decrement count
MOV AX,BYTE [SI] ; load first element
INC SI ; point to next element
INC SI ; point to next element
CMP AX,BX ; compare with current minimum
JG jumpgreat ; if greater, jump to jumpgreat
JL jumpless ; if less, jump to jumpless