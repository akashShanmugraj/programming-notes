finalhalt:
HLT

update:
MOV WORD [SI],DX
ADD SI, 2
JMP chpt1

start:
MOV BYTE [0x1FFF],0x8 ; limit for fibonacci generation
MOV WORD [0x2000],0x0 ; first number
MOV WORD [0x2002],0x1 ; second number

MOV SI,0x2004
MOV CL,BYTE [0x1FFF]
MOV AX,WORD [0x2000]
MOV BX,WORD [0x2002]

chpt1:
CMP CL,0
JZ finalhalt

DEC CL
MOV DX, AX
ADD DX, BX
MOV AX, BX
