; 7 8 0
; 4 6 3
; 3 6 3
start: 
    MOV BYTE [0x2000], 7
    MOV BYTE [0x2001], 8
    MOV BYTE [0x2002], 0

    MOV BYTE [0x2003], 4
    MOV BYTE [0x2004], 6
    MOV BYTE [0x2005], 3

    MOV BYTE [0x2006], 3
    MOV BYTE [0x2007], 6
    MOV BYTE [0x2008], 3

    MOV CX, 3
    MOV DX, 0
    MOV WORD [0x5000], 2000
    MOV WORD [0x5004], 3
    MOV SI, 0x2000

    ; calling rowsum
    MOV BX, 0
    MOV DI, 0x3000
    
    JMP rscall

colsumstart:
    MOV AX, 0
    MOV BX, 0
    MOV CX, WORD [0x5004]
    MOV DX, 0

    MOV WORD [DI], 3008

    JMP cscall

; row sum at 3000, 3002, 3004
; col sum at 3008, 300A, 300C
; dia sum at 3010, 3014

rscall:
    MOV AX, 0
    JMP rsloop

    
remainingrscall:
    MOV CX, WORD [0x5004]
    MOV WORD [DI], AX 
    INC DI
    INC DI

    INC DX
    CMP DX, CX
    JNE rscall
    JE colsumstart

rsloop:
    MOV BL, BYTE [SI]
    ADD AX, BX
    INC SI

    DEC CX
    CMP CX, 0
    JNZ rsloop
    JZ remainingrscall

cscall:
    MOV AX, 0
    JMP rsloop


csloop:
    
