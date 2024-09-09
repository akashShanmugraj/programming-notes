start:
    MOV BYTE [0x4040], 65
    MOV BYTE [0x4041], 65
    MOV BYTE [0x4042], 66
    MOV BYTE [0x4043], 67
    MOV BYTE [0x4044], 67
    MOV BYTE [0x4045], 67
    MOV BYTE [0x4046], 65
    MOV BYTE [0x4047], 65
    MOV BYTE [0x4048], 67
    MOV BYTE [0x4049], 67
    MOV BYTE [0x404A], 65
    MOV BYTE [0x404B], 65
    MOV BYTE [0x404C], 66
    MOV BYTE [0x404D], 66
    MOV BYTE [0x404E], 66
    MOV BYTE [0x404F], 69

    MOV SI, 0x4040 
    MOV DI, 0x3030
    
    MOV CL, 1
    MOV AL, BYTE [SI]

iter:
    INC SI
    CMP AL, 36
    CMP AL, BYTE [SI] 
    JE incanditer
    MOV BYTE [DI], CL
    INC DI
    MOV BYTE [DI], AL
    INC DI
    MOV CL, 1
    MOV AL, BYTE [SI]
    JMP iter

incanditer:
    INC CL
    JMP iter

patchwork:
    CMP AL, 36
    JE finalhalt
    JNE iteradd


finalhalt:
    MOV BYTE [DI], CL
    INC DI
    MOV BYTE [DI], AL
    INC DI
    MOV BYTE [DI], 36
    HLT


    JMP patchwork
