finalhalt:
    MOV BYTE [0x2004], AL
    HLT

start:
    MOV BYTE [0x2000], 0x2
    MOV BYTE [0x2001], 0x10

    MOV SI, 0x2000
    MOV AL, BYTE [SI]
    INC SI
    MOV BL, BYTE [SI]
    MOV DL, AL
    MOV AL, 1
    
    ; base in ax, power in bx

chpt1:
    CMP BL,0
    JE finalhalt
    MUL DL
    DEC BL
    JMP chpt1

