start:
    MOV DX, 0xFFFF
    JMP delay
    
delay:
    DEC DX
    CMP DX, 0x0
    JE finalhalt
    JNE outerloop

outerloop:
    MOV CX, 0xFFFF
    CMP CX, 0
    JE delay
    JNE innerloop

innerloop:
    DEC CX
    CMP CX, 0
    JNE innerloop
    JE outerloop

finalhalt:
    HLT