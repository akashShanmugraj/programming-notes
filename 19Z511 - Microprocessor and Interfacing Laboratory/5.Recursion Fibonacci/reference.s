finalhalt: 1000
    HLT

update: 1001
    CMP DX, CX
    JG finalhalt
    MOV WORD [SI], DX
    MOV BX,DX
    ADD SI, 2
    JMP chpt1 100D

start:
    MOV BYTE [0x1FFF], 0x8 ; limit for fibonacci generation 1
    MOV WORD [0x2000], 0x0 ; first number
    MOV WORD [0x2002], 0x1 ; second number

    MOV SI, 0x2004 1010
    MOV CL, 0xe
    MOV AX, 0x0
    MOV BX, 0x1

chpt1: 101f
    MOV DX, AX
    ADD DX, BX
    MOV AX, BX
    JMP update