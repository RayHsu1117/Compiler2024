    .source Main.j
    .class public Main
    .super java/lang/Object
    .method public static calculate_pi(I)F
    .limit stack 100
    .limit locals 100
    ldc 3.000000
    fstore 1 ; pi
    ldc 2.000000
    fstore 2 ; two
    iconst_1
    istore 3 ; add
        ldc 1
        istore 4 ; k
        loop0Start:
        iload 4 ; k
        iload 0 ; terms
        if_icmplt lessThanLabel0
        iconst_0
        goto endLabel0
        lessThanLabel0:
        iconst_1
        endLabel0:
        ifeq loop0End
        goto loopStmt0
        controlLoop0:
        iinc 4 1
        goto loop0Start
        loopStmt0:
        ldc 4
        i2f
        fload 2 ; two
        iload 4 ; k
        i2f
        fmul
        fload 2 ; two
        iload 4 ; k
        i2f
        fmul
        ldc 1.000000
        fadd
        fmul
        fload 2 ; two
        iload 4 ; k
        i2f
        fmul
        fload 2 ; two
        fadd
        fmul
        fdiv
        fstore 5 ; term
        iload 3 ; add
        ifeq elseBegin1
            fload 1 ; pi
            fload 5 ; term
            fadd
            fstore 1 ; pi
            iconst_0
            istore 3 ; add
            goto ifEnd1
        elseBegin1:
            fload 1 ; pi
            fload 5 ; term
            fsub
            fstore 1 ; pi
            iconst_1
            istore 3 ; add
        ifEnd1:
        goto controlLoop0
        loop0End:
    fload 1 ; pi
    freturn
    .end method
    .method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    ldc 100
    istore 1 ; terms
    iload 1 ; terms
    invokestatic Main/calculate_pi(I)F
    fstore 2 ; pi
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Approximation of Pi after "
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    iload 1 ; terms
    invokevirtual java/io/PrintStream/print(I)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc " terms: "
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    fload 2 ; pi
    invokevirtual java/io/PrintStream/print(F)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    invokevirtual java/io/PrintStream.println()V
    ldc 0
    return
    .end method
