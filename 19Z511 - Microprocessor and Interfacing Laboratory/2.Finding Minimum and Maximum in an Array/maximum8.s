; actual entry point of the program, must be present
jumpless:
JMP chpt1 ; jump to chpt1

jumpgreat:
MOV BL,AL ; store new minimum
JMP chpt1 ; jump to chpt1

finalhalt:
HLT ; halt program

start:
MOV BYTE [0x1FFF],0x8
MOV BYTE [0x2000],0x1
MOV BYTE [0x2001],0x2
MOV BYTE [0x2002],0x3
MOV BYTE [0x2003],0x0
MOV BYTE [0x2004],0x5
MOV BYTE [0x2005],0x2
MOV BYTE [0x2006],0x7
MOV BYTE [0x2007],0x8

MOV SI,0x2000 ; point to first element
MOV CL,BYTE [0x1FFF] ; number of elements
MOV BL,0

chpt1:
CMP CL,0 ; check if count is zero
JZ finalhalt ; if zero, jump to finalhalt
DEC CL ; decrement count
MOV AL,BYTE [SI] ; load first element
INC SI ; point to next element
CMP AL,BL ; compare with current minimum
JG jumpgreat ; if greater, jump to jumpgreat
JL jumpless ; if less, jump to jumpless