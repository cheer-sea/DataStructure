int ExpEvaluation() {
    InitStack(&OPTR);
    InitStack(&OVS);

    push(&OPTR, '#');
    
    ch = getchar();
    while(ch != '#' || GetTop(&OPTR)!= '#') {
        if (!In(ch, OPSet)) { // 不是操作符，是操作数
            n = GetNumber(ch);
            push(&OVS, n);
            ch = getchar();
        } 
        else {   
            switch(Compare(ch, GetTop(OPTR))) { 
                case '>':
                    Push(&OPTR, ch);
                    ch = getchar();
                    break;
                case '=':
                case '<':
                    Pop(&OVS, &b);
                    Pop(&OVS, &a)
                    v = Execute(a, op, b);
                    Push(&OVS, v);
                    break;
            }
        }
    v = GetTop(OVS);
    return v;
}