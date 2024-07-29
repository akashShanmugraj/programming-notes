finalhalt:
HLT

exponentandmultiply: ; find power(2, CL) (CL is the ith binary digit being traversed)
    ; base is 2
    ; power is in CL
    ; mulnum is in SI
    ; put exponent in BL
    ; add to AL
    MOV DL, CL
    MOV BL, AL
    MOV AL, 1
    
chpt2: ; exponent function
    CMP DL,0
    JE chpt3
    MUL BYTE [0x2004]
    DEC DL
    JMP chpt2

chpt3: ; exit function for exponent function - Multiply and Add
    ADD AL, BL
    JMP chpt4

zeroonechpt:
    CMP BYTE [SI],0
    JE chpt4
    JNE exponentandmultiply

start:
    MOV BYTE [0x2004], 2
    MOV BYTE [0x1999], 4 ;4 bits of binary
    MOV BYTE [0x2000], 0
    MOV BYTE [0x2001], 1
    MOV BYTE [0x2002], 0
    MOV BYTE [0x2003], 1

    MOV SI, 0x2000
    MOV CL, 0
    MOV DL, 0
    MOV AL, 0

chpt1: ; intialise, base case, call exponentandmultiply
    CMP CL, BYTE[0x1999]
    JE finalhalt
    JNE zeroonechpt

chpt4: ; exit function for start
    INC SI
    INC CL
    JMP chpt1

