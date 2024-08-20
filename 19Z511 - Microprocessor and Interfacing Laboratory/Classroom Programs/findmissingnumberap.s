start:
    MOV BYTE [0x2000],0x4 ; a-value in AP
    MOV BYTE [0x2002],0x2 ; l-value in AP

    MOV AX, WORD [0x2000]
    MOV CX, WORD [0x2002]

    MOV SI, 0x3000

aplabel:
    MOV [SI], AX
    ADD SI, 2
    ADD AX, CX