/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"
    ObjectType currentVarType;
    int yydebug = 1;
    int array_element_num=0;
    Object* obj;
    int autotype=0;
%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to specify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT STR_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <b_var> BOOL_LIT

%token '(' ')'
%token '[' ']'
%token ':'

/* Nonterminal with return, which need to specify type */
%type <object_val> Expression
%type <object_val> LORExpression
%type <object_val> LANExpression
%type <object_val> BitwiseExpression
%type <object_val> RelationalExpression
%type <object_val> ShiftExpression
%type <object_val> AdditiveExpression
%type <object_val> MultiplicativeExpression
%type <object_val> CastExpression
%type <object_val> UnaryExpression
%type <object_val> PrimaryExpression
%type <object_val> Callfunction
/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

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
    | IDENT VAL_ASSIGN Expression {if(currentVarType==1){currentVarType=$3.type;} createVariable(currentVarType, $<s_var>1, 0); }
    | IdentList ',' IDENT  VAL_ASSIGN Expression {if(currentVarType==1){currentVarType=$5.type;} createVariable(currentVarType, $<s_var>3, 0); }
    | IDENT  '[' INT_LIT  ']' {printf("INT_LIT %d\n", $<i_var>3);printf("create array: %d\n",array_element_num); createVariable(currentVarType, $<s_var>1, 0); }
    | IdentList ',' IDENT  '[' INT_LIT ']' { createVariable(currentVarType, $<s_var>3, 0); }
    | IDENT  '[' INT_LIT ']' '[' INT_LIT ']' {printf("INT_LIT %d\n", $<i_var>3);printf("INT_LIT %d\n", $<i_var>4); createVariable(currentVarType, $<s_var>1, 0); }
    | IdentList ',' IDENT  '[' INT_LIT ']' '[' INT_LIT ']' {printf("INT_LIT %d\n", $<i_var>5);printf("INT_LIT %d\n", $<i_var>8); createVariable(currentVarType, $<s_var>3, 0); }
    | IDENT  '[' INT_LIT  ']' {printf("INT_LIT %d\n", $<i_var>3);}  VAL_ASSIGN '{' InitializerList '}' {printf("create array: %d\n",array_element_num); createVariable(currentVarType, $<s_var>1, 0);  }
    | IdentList ',' IDENT '[' INT_LIT ']' VAL_ASSIGN '{' InitializerList '}' { createVariable(currentVarType, $<s_var>3, 0); } 

;

InitializerList
    : InitializerList ',' Expression {array_element_num++;}
    | Expression {array_element_num++;}
    |
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); } {pushScope();addfuncpara($<var_type>1);} FunctionParameterStmtList {funcsig($2);} ')' '{' StmtList '}' { dumpScope(); }
;
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;
FunctionParameterStmt
    : VARIABLE_T IDENT '[' ']' {addfuncpara($<var_type>1*10); pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); }
    | VARIABLE_T IDENT  {addfuncpara($<var_type>1); pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); }
;

/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt

;
Stmt
    : ';'
    | COUT CoutParmListStmt ';' { stdoutPrint(); clearCout();}
    | RETURN Expression ';' { printf("RETURN\n"); }
    | RETURN ';' {printf("RETURN\n");}
    | IDENT { varAddrCheck($<s_var>1,0); } IdentAssign ';'
    | IFStmt
    | FOR {printf("FOR\n");} '(' {pushScope();} For ')' '{'  StmtList '}' { dumpScope(); }
    | WHILE { printf("WHILE\n"); } '(' Expression ')' { pushScope(); } '{' StmtList '}' { dumpScope(); }
    | BREAK ';'  {printf("BREAK\n");}
    | CONTINUE ';'
    | ArrayAssignmentStmt ';'
    | DefineVariableStmt {array_element_num=0;}
    | Callfunction ';'

;

For
    : F1 ';' F2 ';' F3
    | VARIABLE_T IDENT ':' IDENT {obj=findVariable($4,0);createVariable(obj->type, $<s_var>2, 0);varAddrCheck($4,0);}
;
F1
    : VARIABLE_T F1_List1 { currentVarType = $<var_type>1; }
    | F1_List2
    |
F1_List1
    : F1_List1 ',' IDENT VAL_ASSIGN Expression { createVariable(currentVarType, $<s_var>3, 0);}
    | IDENT VAL_ASSIGN Expression { createVariable(currentVarType, $<s_var>1, 0);}
F1_List2
    : F1_List2 ',' IDENT VAL_ASSIGN Expression 
    | IDENT VAL_ASSIGN Expression 
F2 
    : Expression
    |
F3
    : IDENT {varAddrCheck($<s_var>1,0);} IdentAssign 
    |

IFStmt
    : IF '(' Expression ')' { printf("IF\n"); pushScope(); } '{' StmtList '}' { dumpScope(); } ElseStmt
    | IF '(' Expression ')' { printf("IF\n"); } StmtList ElseStmt
;
ElseStmt
    : ELSE { printf("ELSE\n"); pushScope(); } '{' StmtList '}' { dumpScope(); }
    | ELSE { printf("ELSE\n"); } IFStmt
    |
;

IdentAssign
    : VAL_ASSIGN Expression  {printf("EQL_ASSIGN\n");}
    | ADD_ASSIGN Expression  {printf("ADD_ASSIGN\n");}
    | SUB_ASSIGN Expression  {printf("SUB_ASSIGN\n");}
    | MUL_ASSIGN Expression  {printf("MUL_ASSIGN\n");}
    | DIV_ASSIGN Expression  {printf("DIV_ASSIGN\n");}
    | SHR_ASSIGN Expression  {printf("SHR_ASSIGN\n");}
    | SHL_ASSIGN Expression  {printf("SHL_ASSIGN\n");}
    | BOR_ASSIGN Expression  {printf("BOR_ASSIGN\n");}
    | BAN_ASSIGN Expression  {printf("BAN_ASSIGN\n");}
    | BXO_ASSIGN Expression  {printf("BXO_ASSIGN\n");}
    | REM_ASSIGN Expression  {printf("REM_ASSIGN\n");}
    | INC_ASSIGN {printf("INC_ASSIGN\n");}
    | DEC_ASSIGN {printf("DEC_ASSIGN\n");}

ArrayAssignmentStmt
    : IDENT  '[' Expression ']' { varAddrCheck($1,0);} VAL_ASSIGN Expression { printf("EQL_ASSIGN\n");}
    | IDENT  '[' Expression ']' '[' Expression ']' { varAddrCheck($1,0); } VAL_ASSIGN Expression {printf("EQL_ASSIGN\n");}
;

CoutParmListStmt
    : CoutParmListStmt SHL Expression { insertCout($<object_val>3.type); }
    | SHL Expression { insertCout($<object_val>2.type); }
;



Expression
    : LORExpression 
;

Callfunction
    : IDENT '('  Funcparameter ')'  { varAddrCheck($<s_var>1,1); IdentType(&$<object_val>$, $<s_var>1,1); obj = findVariable($<s_var>1,1);printf("call: %s%s\n",$<s_var>1,obj->symbol->func_sig);}
    
Funcparameter
    : FuncparameterList
    |
FuncparameterList
    : FuncparameterList ',' Expression
    | Expression
LORExpression
    : LORExpression LOR LANExpression { printf("LOR\n"); ExpressionType('l',&$<object_val>1,&$<object_val>3,&$<object_val>$); }
    | LANExpression
;
LANExpression
    : LANExpression LAN BitwiseExpression { printf("LAN\n"); ExpressionType('l',&$<object_val>1,&$<object_val>3,&$<object_val>$); } 
    | BitwiseExpression
    

BitwiseExpression
    : BitwiseExpression BOR RelationalExpression { printf("BOR\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | BitwiseExpression BXO RelationalExpression { printf("BXO\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$);}  
    | BitwiseExpression BAN RelationalExpression { printf("BAN\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | BitwiseExpression BNT RelationalExpression { printf("BNT\n"); ExpressionType('b',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | RelationalExpression
;


RelationalExpression
    : RelationalExpression EQL ShiftExpression { printf("EQL\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | RelationalExpression NEQ ShiftExpression { printf("NEQ\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | RelationalExpression LES ShiftExpression { printf("LES\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | RelationalExpression LEQ ShiftExpression { printf("LEQ\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);}
    | RelationalExpression GTR ShiftExpression { printf("GTR\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | RelationalExpression GEQ ShiftExpression { printf("GEQ\n"); ExpressionType('r',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | ShiftExpression
;
ShiftExpression
    : ShiftExpression SHR AdditiveExpression {printf("SHR\n");ExpressionType('s',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | AdditiveExpression
;

AdditiveExpression
    : AdditiveExpression  ADD  MultiplicativeExpression { printf("ADD\n"); ExpressionType('m',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | AdditiveExpression SUB MultiplicativeExpression { printf("SUB\n"); ExpressionType('m',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | MultiplicativeExpression
;

MultiplicativeExpression
    : MultiplicativeExpression MUL CastExpression { printf("MUL\n"); ExpressionType('m',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | MultiplicativeExpression DIV CastExpression { printf("DIV\n"); ExpressionType('m',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | MultiplicativeExpression REM CastExpression { printf("REM\n"); ExpressionType('s',&$<object_val>1,&$<object_val>3,&$<object_val>$);} 
    | CastExpression
;
CastExpression
    : '(' VARIABLE_T ')' CastExpression {Cast($<var_type>2); $<object_val>$.type = $<var_type>2;} 
    | UnaryExpression
;
UnaryExpression
    : NOT UnaryExpression { printf("NOT\n"); $<object_val>$.type = $<object_val>2.type;} 
    | BNT UnaryExpression { printf("BNT\n"); $<object_val>$.type = $<object_val>2.type;} 
    | SUB UnaryExpression { printf("NEG\n"); $<object_val>$.type = $<object_val>2.type;} 
    | PrimaryExpression
;

PrimaryExpression
    : INT_LIT { printf("INT_LIT %d\n", $<i_var>1); $<object_val>$.type = OBJECT_TYPE_INT ; }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_var>1); $<object_val>$.type = OBJECT_TYPE_FLOAT ; }
    | BOOL_LIT { printf("BOOL_LIT %s\n", $<b_var>1 ? "TRUE" : "FALSE"); $<object_val>$.type = OBJECT_TYPE_BOOL ;}
    | IDENT { varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0); }
    | STR_LIT { printf("STR_LIT \"%s\"\n", $<s_var>1); $<object_val>$.type = OBJECT_TYPE_STR; }
    | '(' Expression ')'  { $$ = $<object_val>2; }
    | IDENT '[' Expression ']' { varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0); }
    | IDENT '[' Expression ']' '[' Expression ']' { varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0); }
    | Callfunction 
;



%%
/* C code section */
//{printf("Type = %d ",$<object_val>$.type);printf("curr expression = %d\n",$$.type);}  printf("Type = %d ",$<object_val>$.type);printf("curr expression = %d\n",$$.type);
//build/out/compiler  input/subtask0X-xxx/testcase0X.cpp
