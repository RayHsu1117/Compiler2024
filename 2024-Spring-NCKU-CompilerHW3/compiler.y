%{
    #include "compiler_util.h"
    #include "main.h"

    ObjectType currentVarType;
    int yydebug = 1;
    int array_element_num = 0;
    Object* obj;
    int autotype = 0;
    int mainreturn = 0;
    int operatecheck=0;
    int label = 0;
    int nestlabel =0;
    int nestlabelout = 0;
    int neststack[10]={0};
    int neststacknum=0;
    int coutnum=0;
    int loop = 0;
    int loopStmt = 0;
    int mainfunction = 0;
    int functionreturn = 0;
    int array = 0;
    int broken = 0;
    int inIF = 0;
    void returncheck(int type){
       if(mainfunction==1){
           codeRaw("return");
       }
       else{
         if(type==OBJECT_TYPE_INT||type==OBJECT_TYPE_BOOL){
               codeRaw("ireturn");
         }
         else if(type==OBJECT_TYPE_FLOAT){
             codeRaw("freturn");
         }
         else{
             codeRaw("return");
         } 
       } 
    }
    char* arraytype(int type){
        char *output;
       if(type==OBJECT_TYPE_INT){
         output="int";  
       }
       else if(type==OBJECT_TYPE_FLOAT){
         output= "float";
       }
       else if(type==OBJECT_TYPE_BOOL){
         output= "bool";
       }
       else if(type==OBJECT_TYPE_STR){
         output= "string";
       }
       return output;
    }
%}

%union {
    ObjectType var_type;

    bool b_var;
    char c_var;
    int32_t i_var;
    int64_t l_var;
    float f_var;
    double d_var;
    char *s_var;

    Object object_val;
}

%token COUT SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE
%token '(' ')' '[' ']' ':'
%token <var_type> VARIABLE_T
%token <b_var> BOOL_LIT
%token <c_var> CHAR_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <s_var> STR_LIT
%token <s_var> IDENT

%type <object_val> Expression LORExpression LANExpression BitwiseExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression CastExpression UnaryExpression PrimaryExpression Callfunction

%nonassoc THEN ELSE


%%
Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
;

DefineVariableStmt
    : VARIABLE_T { currentVarType = $<var_type>1; } IdentList ';'
;

IdentList
    : IDENT { createVariable(currentVarType, $<s_var>1, 0); }
    | IdentList ','  IDENT { createVariable(currentVarType, $<s_var>3, 0); } 
    | IDENT VAL_ASSIGN Expression {if(currentVarType==1){currentVarType=$3.type;} createVariable(currentVarType, $<s_var>1, 0); storeMatrix(findVariable($1,0));}
    | IdentList ',' IDENT  VAL_ASSIGN Expression {if(currentVarType==1){currentVarType=$5.type;} createVariable(currentVarType, $<s_var>3, 0);storeMatrix(findVariable($3,0)); }
    | IDENT  '[' Expression  ']' {printf("create array: %d\n",array_element_num); createVariable(currentVarType, $<s_var>1, 0); obj =findVariable($1,0); code("newarray %s",arraytype(obj->type));astore(findVariable($1,0));}
    | IdentList ',' IDENT  '[' Expression ']' { createVariable(currentVarType, $<s_var>3, 0);  obj =findVariable($3,0); code("newarray %s",arraytype(obj->type));}
    | IDENT  '[' Expression ']' '[' Expression ']' {createVariable(currentVarType, $<s_var>1, 0); codeRaw("multianewarray [[I 2");astore(findVariable($1,0));}
    | IdentList ',' IDENT  '[' Expression ']' '[' Expression ']' { createVariable(currentVarType, $<s_var>3, 0); codeRaw("multianewarray [[I 2");astore(findVariable($3,0));}
    | IDENT  '[' Expression  ']' {createVariable(currentVarType, $<s_var>1, 0); obj =findVariable($1,0); code("newarray %s",arraytype(obj->type));}  VAL_ASSIGN '{' InitializerList '}' {printf("create array: %d\n",array_element_num); astore(findVariable($1,0)); }
    | IdentList ',' IDENT '[' Expression ']' VAL_ASSIGN '{' InitializerList '}' { createVariable(currentVarType, $<s_var>3, 0); } 

;

InitializerList
    : InitializerList ',' {codeRaw("dup");code("ldc %d",array_element_num);} Expression {codeRaw("iastore"); array_element_num++; }
    | {codeRaw("dup");code("ldc %d",array_element_num);}Expression {codeRaw("iastore"); array_element_num++; }
    |
;
ArrayAssignmentStmt
    : ArrayIdent '[' Expression ']' {/* varAddrCheck($1,0); */} VAL_ASSIGN Expression {codeRaw("iastore");/* astore(findVariable($1,0)); */}
    | ArrayIdent '[' Expression ']' {codeRaw("aaload");} '[' Expression ']' { /*varAddrCheck($1,0); */} VAL_ASSIGN Expression {codeRaw("iastore"); /*astore(findVariable($1,0));*/}
;
//fprintf(yyout, "%*s.method public static main([Ljava/lang/String;)V\n", scopeLevel << 2, "");
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); } {pushScope(); addfuncpara($<var_type>1);if(strcmp("main",$2)==0){mainfunction=1;} functionreturn=0;} FunctionParameterStmtList { funcsig($2); } ')' '{'  {obj=findVariable($2,1); code(".method public static %s%s",$2,obj->symbol->func_sig); fprintf(yyout, "%*s.limit stack 100\n", scopeLevel << 2, ""); fprintf(yyout, "%*s.limit locals 100\n", scopeLevel << 2, ""); } StmtList '}' {if(functionreturn==0){codeRaw("return");} fprintf(yyout, "%*s.end method\n", scopeLevel << 2, ""); dumpScope(); functionreturn=0;}
;
//fprintf(yyout, "%*sreturn\n", scopeLevel << 2, "");
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;

FunctionParameterStmt
    : VARIABLE_T IDENT '[' ']' { addfuncpara($<var_type>1 * 10); pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); }
    | VARIABLE_T IDENT { addfuncpara($<var_type>1); pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); }
;

StmtList 
    : StmtList Stmt
    | Stmt
;




Stmt
    : ';'
    | COUT  CoutParmListStmt ';' { if(coutnum==1){coutExpr();}stdoutPrint(); clearCout();coutnum=0;}
    | RETURN  Expression ';' {functionreturn=1;returncheck($2.type);if(inIF==1){if(broken==1){code("elseBegin%d:",neststack[neststacknum]);code("ifEnd%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);code("ifEnd%d:",neststack[neststacknum-1]);inIF=0;}} }
    | RETURN ';' {functionreturn=1; codeRaw("return"); }
    | IdentAssign ';' 
    | IFStmt
    | FOR  '(' { pushScope(); } For ')' '{' {code("loopStmt%d:",nestlabel);neststack[neststacknum]=nestlabel;neststacknum++;nestlabel++;} StmtList '}' {code("goto controlLoop%d",neststack[neststacknum-1]);code("loop%dEnd:",neststack[neststacknum-1]);neststacknum--; dumpScope(); }
    | WHILE { code("loop%dStart:",nestlabel); neststack[neststacknum]=nestlabel;neststacknum++;nestlabel++;} '(' Expression ')' { code("ifeq loop%dEnd",neststack[neststacknum-1]);pushScope(); } '{' StmtList '}' { code("goto loop%dStart",neststack[neststacknum-1]);code("loop%dEnd:",neststack[neststacknum-1]);neststacknum--;dumpScope(); }
    | BREAK ';' { code("goto loop%dEnd",neststack[neststacknum-2]);neststacknum--; broken=1;}
    | CONTINUE ';'
    | ArrayAssignmentStmt ';'
    | DefineVariableStmt { array_element_num=0; }
    | Callfunction ';'
;

For
    : F1 ';' { code("loop%dStart:",nestlabel); } F2 {code("ifeq loop%dEnd",nestlabel);code("goto loopStmt%d",nestlabel);} ';' {code("controlLoop%d:",nestlabel);} F3 { code("goto loop%dStart",nestlabel);}
    | VARIABLE_T IDENT ':' IDENT { obj=findVariable($4,0); createVariable(obj->type, $<s_var>2, 0); varAddrCheck($4,0); }
;

F1
    : VARIABLE_T F1_List1 { currentVarType = $<var_type>1; }
    | F1_List2
    |
F1_List1
    : F1_List1 ',' IDENT VAL_ASSIGN Expression { createVariable(currentVarType, $<s_var>3, 0);  storeMatrix(findVariable($3,0));}
    | IDENT VAL_ASSIGN Expression { createVariable(currentVarType, $<s_var>1, 0);  storeMatrix(findVariable($1,0));}
F1_List2
    : F1_List2 ',' IDENT VAL_ASSIGN Expression { storeMatrix(findVariable($3,0));}
    | IDENT VAL_ASSIGN Expression { storeMatrix(findVariable($1,0));}
F2 
    : Expression 
    |
F3
    : IdentAssign 
    |

IFStmt
    : IF '(' Expression ')' {inIF=1; code("ifeq elseBegin%d",nestlabel);neststack[neststacknum]=nestlabel;nestlabel++;neststacknum++; pushScope(); } '{' StmtList '}' {if(broken==1){code("goto ifEnd%d",neststack[neststacknum]);}else{code("goto ifEnd%d",neststack[neststacknum-1]);} dumpScope(); } {inIF=0;}ElseStmt {if(broken==1){code("ifEnd%d:",neststack[neststacknum]);}else{code("ifEnd%d:",neststack[neststacknum-1]);}neststacknum--;broken=0;}
    | IF '(' Expression ')' {inIF=1;code("ifeq elseBegin%d",nestlabel);neststack[neststacknum]=nestlabel;nestlabel++;neststacknum++; } StmtList {inIF=0;} ElseStmt {if(broken==1){code("ifEnd%d:",neststack[neststacknum]);}else{code("ifEnd%d:",neststack[neststacknum-1]);}neststacknum--;broken=0;}
;
ElseStmt
    : ELSE {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);} pushScope(); } '{' StmtList '}' { dumpScope(); }
    | ELSE {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);}} IFStmt 
    | {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);}}
;

IdentAssign
    : IDENT { varAddrCheck($<s_var>1,0);} VAL_ASSIGN Expression {obj = findVariable($1,0);if($4.type==OBJECT_TYPE_INT&&obj->type==OBJECT_TYPE_FLOAT){codeRaw("i2f");}else if($4.type==OBJECT_TYPE_FLOAT&&obj->type==OBJECT_TYPE_INT){codeRaw("f2i");} storeMatrix(findVariable($1,0)); }
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} ADD_ASSIGN Expression {  if($4.type==OBJECT_TYPE_INT){codeRaw("iadd");}else if($4.type==OBJECT_TYPE_FLOAT){codeRaw("fadd");}storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} SUB_ASSIGN Expression {  if($4.type==OBJECT_TYPE_INT){codeRaw("isub");}else if($4.type==OBJECT_TYPE_FLOAT){codeRaw("fsub");}storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} MUL_ASSIGN Expression {  if($4.type==OBJECT_TYPE_INT){codeRaw("imul");}else if($4.type==OBJECT_TYPE_FLOAT){codeRaw("fmul");}storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} DIV_ASSIGN Expression {  if($4.type==OBJECT_TYPE_INT){codeRaw("idiv");}else if($4.type==OBJECT_TYPE_FLOAT){codeRaw("fdiv");}storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} SHR_ASSIGN Expression {  codeRaw("ishr");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);loadMatrix(findVariable($1,0),array);loadMatrix(findVariable($1,0),array);} SHL_ASSIGN Expression {  codeRaw("ishl");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} BOR_ASSIGN Expression {  codeRaw("ior");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} BAN_ASSIGN Expression {  codeRaw("iand");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} BXO_ASSIGN Expression {  codeRaw("ixor");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);loadMatrix(findVariable($1,0),array);} REM_ASSIGN Expression {  codeRaw("irem");storeMatrix(findVariable($1,0));}
    | IDENT { varAddrCheck($<s_var>1,0);} INC_ASSIGN {obj=findVariable($1,0); code("iinc %ld %d",obj->symbol->addr,1); }
    | IDENT { varAddrCheck($<s_var>1,0);} DEC_ASSIGN { obj=findVariable($1,0); code("iinc %ld %d",obj->symbol->addr,-1); }
;


//if(operatecheck==1){coutExpr();}
CoutParmListStmt
    : CoutParmListStmt SHL {coutExpr();codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");} Expression { insertCout($<object_val>4.type);coutnum++;}
    | SHL {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");} Expression { insertCout($<object_val>3.type); coutnum++;}
;

Expression
    : LORExpression 
;

Callfunction
    : IDENT '(' Funcparameter ')' { varAddrCheck($<s_var>1,1); IdentType(&$<object_val>$, $<s_var>1,1); obj = findVariable($<s_var>1,1); printf("call: %s%s\n",$<s_var>1,obj->symbol->func_sig); code("invokestatic Main/%s%s",$1,obj->symbol->func_sig);}
    
Funcparameter
    : FuncparameterList
    |
FuncparameterList
    : FuncparameterList ',' Expression
    | Expression
;

LORExpression
    : LORExpression LOR LANExpression { printf("LOR\n"); ExpressionType('l',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("ior"); operatecheck=1;}
    | LANExpression
;

LANExpression
    : LANExpression LAN BitwiseExpression { printf("LAN\n"); ExpressionType('l',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("iand");operatecheck=1;} 
    | BitwiseExpression
;

BitwiseExpression
    : BitwiseExpression BOR RelationalExpression { printf("BOR\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("ior");operatecheck=1;} 
    | BitwiseExpression BXO RelationalExpression { printf("BXO\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("ixor");operatecheck=1;}  
    | BitwiseExpression BAN RelationalExpression { printf("BAN\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("iand");operatecheck=1;} 
    | BitwiseExpression BNT RelationalExpression { printf("BNT\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;} 
    | RelationalExpression
;

RelationalExpression
    : RelationalExpression EQL ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;code("if_icmpeq EqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label);code("EqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;} 
    | RelationalExpression NEQ ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;code("if_icmpne notEqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label);code("notEqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;} 
    | RelationalExpression LES ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;code("if_icmplt lessThanLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label); code("lessThanLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;} 
    | RelationalExpression LEQ ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;}
    | RelationalExpression GTR ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;if($1.type==OBJECT_TYPE_INT&&$3.type==$1.type){code("if_icmpgt greaterThanLabel%d",label);}else{codeRaw("fcmpg");code("ifgt greaterThanLabel%d",label);}codeRaw("iconst_0");code("goto endLabel%d",label); code("greaterThanLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;} 
    | RelationalExpression GEQ ShiftExpression {  ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$); operatecheck=1;code("if_icmpge greaterThanOrEqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label); code("greaterThanOrEqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;} 
    | ShiftExpression
;

ShiftExpression
    : ShiftExpression SHR AdditiveExpression { ExpressionType('s',&$<object_val>1,&$<object_val>3,&$<object_val>$); codeRaw("ishr");operatecheck=1;} 
    | AdditiveExpression
;

AdditiveExpression
    : AdditiveExpression ADD MultiplicativeExpression { ExpressionType('m',&$1,&$3,&$$);operatecheck=1; if($$.type==OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");}} 
    | AdditiveExpression SUB MultiplicativeExpression { ExpressionType('m',&$1,&$3,&$$);operatecheck=1; if($$.type==OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");}} 
    | MultiplicativeExpression
;

MultiplicativeExpression
    : MultiplicativeExpression MUL CastExpression { ExpressionType('m',&$1,&$3,&$$);operatecheck=1; if($$.type==OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");}} 
    | MultiplicativeExpression DIV CastExpression { ExpressionType('m',&$1,&$3,&$$);operatecheck=1; if($$.type==OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");}} 
    | MultiplicativeExpression REM CastExpression { ExpressionType('s',&$1,&$3,&$$);operatecheck=1; codeRaw("irem");} 
    | CastExpression
;

CastExpression
    : '(' VARIABLE_T ')' CastExpression { Cast($<var_type>2); $$.type = $2; if($$.type==OBJECT_TYPE_INT&&$4.type==OBJECT_TYPE_FLOAT){codeRaw("f2i");}else if($$.type==OBJECT_TYPE_FLOAT&&$4.type==OBJECT_TYPE_INT){codeRaw("i2f");}else{codeRaw("i2f");}} 
    | UnaryExpression
;

UnaryExpression
    : NOT UnaryExpression { $$.type = $2.type;operatecheck=1;codeRaw("iconst_1");codeRaw("ixor");} 
    | BNT UnaryExpression { $$.type = $2.type; operatecheck=1;codeRaw("iconst_m1");codeRaw("ixor");} 
    | SUB UnaryExpression { $$.type = $2.type; operatecheck=1;if($$.type==OBJECT_TYPE_INT){codeRaw("ineg");}else{codeRaw("fneg");}} 
    | PrimaryExpression
;

PrimaryExpression
    : INT_LIT {  $<object_val>$.type = OBJECT_TYPE_INT; if(functionreturn != 1){fprintf(yyout, "%*sldc %d\n", scopeLevel << 2, "", $<i_var>1);} }
    | FLOAT_LIT { $<object_val>$.type = OBJECT_TYPE_FLOAT; fprintf(yyout, "%*sldc %f\n", scopeLevel << 2, "", $<f_var>1); }
    | BOOL_LIT { $<object_val>$.type = OBJECT_TYPE_BOOL; if($1){codeRaw("iconst_1");}else{codeRaw("iconst_0");}}
    | IDENT { varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0);if(strcmp("endl",$1)==0){codeRaw("invokevirtual java/io/PrintStream.println()V");}else{loadMatrix(findVariable($1,0),array);} }
    | STR_LIT {  $<object_val>$.type = OBJECT_TYPE_STR; fprintf(yyout, "%*sldc \"%s\"\n", scopeLevel << 2, "", $<s_var>1); }
    | CHAR_LIT {  $<object_val>$.type = OBJECT_TYPE_CHAR;  fprintf(yyout, "%*sldc \"%c\"\n", scopeLevel << 2, "", $<c_var>1);}
    | '(' Expression ')' { $$ = $<object_val>2; }
    | ArrayIdent  '[' Expression ']' { codeRaw("iaload");}
    | ArrayIdent  '[' Expression ']' {codeRaw("aaload");} '[' Expression ']' { codeRaw("iaload"); }
    | Callfunction
;
ArrayIdent
  : IDENT {array=1; varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0);loadMatrix(findVariable($1,0),array);array=0;}
%%
//fprintf(yyout, "%*siload %s\n", scopeLevel << 2, "", $<s_var>1);
//varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0);
