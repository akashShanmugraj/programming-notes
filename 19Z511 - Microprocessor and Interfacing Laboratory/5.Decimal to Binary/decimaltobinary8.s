start:
    MOV BYTE [0x1300], 0x5
    
    MOV SI, 0x200F
    MOV AL, BYTE [0x1300]
    MOV CL, 0x2

divisionlabel:
    DIV CL ; remainder in AH, quotient in AL
    MOV BYTE [SI], AH
    DEC SI
    CMP AL, 0x0
    MOV AH, 0x0
    JNZ divisionlabel
    HLT