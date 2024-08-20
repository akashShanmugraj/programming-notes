finalupdate:
    MOV WORD [0x5000], AX
    HLT

start:
    MOV BYTE [0x2000],0x4 ; a-value in AP
    MOV BYTE [0x2002],0x2 ; l-value in AP

    MOV BYTE [0x4000],0x4
    MOV BYTE [0x4002],0x6
    MOV BYTE [0x4004],0x8
    MOV BYTE [0x4006],0xB

    MOV AX, WORD [0x2000]
    MOV CX, WORD [0x2002]

    MOV SI, 0x3000
    MOV DI, 0x4000

aplabel:
    MOV WORD [SI], AX
    MOV DX, WORD [DI]
    CMP AX, DX
    JNE finalupdate
    ADD SI, 2
    ADD DI, 2
    ADD AX, CX
    JMP aplabel

