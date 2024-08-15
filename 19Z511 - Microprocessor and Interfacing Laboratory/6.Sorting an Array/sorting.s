; Sort an array in ascending order
; Respective address locations are commented
; Loading of array can be done via instructions (FE8 thru FF8)
; or alternatively can be directly loaded using the SB command

start:
    MOV BYTE [0x1300], 0x5 ; FE8
    MOV BYTE [0x1301], 0x2 ; FEC
    MOV BYTE [0x1302], 0x7 ; FF0
    MOV BYTE [0x1303], 0x1 ; FF4
    MOV BYTE [0x1304], 0x9 ; FF8
    
    MOV BL, BYTE [0x1300] ; 1000
    DEC BL ; 1004

L1:
    MOV CL, BL ; 1006
    MOV DI, 0x1301 ; 1008
    MOV SI, 0x1302 ; 100C

L2:
    MOV AL, BYTE [DI] ; 1010
    MOV DL, BYTE [SI] ; 1012
    CMP AL, DL ; 1014
    
    JBE L3 ; 1016
    
    MOV BYTE [DI], DL ; 1018
    MOV BYTE [SI], AL ; 101A

L3:
    INC SI ; 101C
    INC DI ; 101D
    DEC CL ; 101F
    JNZ L2 ; 1020
    
    DEC BL ; 1022
    JNZ L1 ; 1024
    HLT ; 1026