/* Definition section */
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #define printToken(token, value) (value ? printf("%-8s \t %s\n", token, (char*)value) : printf("%s\n", token))

    FILE* fout;
%}

%x COUT_CONTENT
%x COMMENT
%x MULTI_COMMENT

/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
FLOAT_LIT {digit}+"."{digit}+
/* Rules section */
%%
"int"       { printToken("INT_T", NULL);}
"main"      { printToken("IDENT", yytext); }
"string"    { printToken("STR_T", NULL); }
"endl"      { printToken("IDENT", yytext); }
"return"    { printToken("RETURN", NULL); }
"if"        { printToken("IF", NULL); }
"else"      { printToken("ELSE", NULL); }
"while"      { printToken("WHILE", NULL); }
"for"        { printToken("FOR", NULL); }
"auto"      { printToken("AUTO_T", NULL); }
"break"    { printToken("BREAK", NULL); }
"void"      { printToken("VOID_T", NULL); }
\"([^\"\\]|\\.)*\"       { printToken("STRING_LIT", yytext); }


[0-9]+                   { printToken("INT_LIT", yytext); }

\<\<                      { printToken("SHL", NULL); }
">>"                      { printToken("SHR", NULL); }
","                        {printToken("','",NULL);}
"("                       { printToken("'('", NULL); }
")"                       { printToken("')'", NULL); }
"["                       { printToken("'['", NULL); }
"]"                       { printToken("']'", NULL); }
"{"                       { printToken("'{'", NULL); }
"}"                       { printToken("'}'", NULL); }
":"                       { printToken("':'", NULL); }
";"                       { printToken("';'", NULL); }
"&"                       { printToken("BAN", NULL); }
"|"                       { printToken("BOR", NULL); }
"~"                       { printToken("BNT", NULL); }
"^"                       { printToken("BXO", NULL); }
"+"                       { printToken("ADD", NULL); }
"-"                       { printToken("SUB", NULL); }
"*"                       { printToken("MUL", NULL); }
"/"                       { printToken("DIV", NULL); }
"%"                       { printToken("MOD", NULL); }
"!"                       { printToken("NOT", NULL); }
">"                       { printToken("GTR", NULL); }
"<"                       { printToken("LES", NULL); }
">="                       { printToken("GEQ", NULL); }
"<="                       { printToken("LEQ", NULL); }
"=="                       { printToken("EQL", NULL); }
"!="                       { printToken("NEQ", NULL); }
"&&"                       { printToken("LAN", NULL); }
"||"                       { printToken("LOR", NULL); }
"="                       { printToken("VAL_ASSIGN", NULL); }
"+="                       { printToken("ADD_ASSIGN", NULL); }
"-="                       { printToken("SUB_ASSIGN", NULL); }
"*="                       { printToken("MUL_ASSIGN", NULL); }
"/="                       { printToken("DIV_ASSIGN", NULL); }
"%="                       { printToken("REM_ASSIGN", NULL); }
">>="                       { printToken("SHR_ASSIGN", NULL); }
"<<="                       { printToken("SHL_ASSIGN", NULL); }
"&="                       { printToken("BAN_ASSIGN", NULL); }
"|="                       { printToken("BOR_ASSIGN", NULL); }
"++"                       { printToken("INC_ASSIGN", NULL); }
"--"                       { printToken("DEC_ASSIGN", NULL); }
"true"                       { printToken("BOOL_LIT", yytext); }
"false"                       { printToken("BOOL_LIT", yytext); }
"float"                    {printToken("FLOAT_T",NULL);}
"bool"                    {printToken("BOOL_T",NULL);}
{FLOAT_LIT}                {printToken("FLOAT_LIT",yytext);}
"\n"                      { yylineno++; }
";"                       { printToken("';'", NULL); }

[ \t\n]                  { /* Ignoring whitespace */ }

"//"([^'\n\r]*)    { printToken("COMMENT", yytext); }
"/*"+[^*\n]*         {printf("MULTI_COMMENT \t %s",yytext);BEGIN(MULTI_COMMENT);}

<MULTI_COMMENT>{
    
    "*"+[^*/\n]*   { yymore(); }
    
    [^*\n]*       { yymore();}
    
    "*"+"/"    { printf("%s\n",yytext);BEGIN(INITIAL); }
    "\n"    {yymore();yylineno++;}
}
"cout"      { printToken("COUT", NULL);}
[a-zA-Z_][a-zA-Z0-9_]*  { printToken("IDENT", yytext); }
  
["][^'\\][a-zA-Z0-9_]*["]    { printToken("STRING_LIT", yytext); }
['][^'\\][a-zA-Z0-9_]*[']          { printToken("CHAR_LIT", yytext); }
<<EOF>>     { static int once = 0; if (once++) {yyterminate();} }


%%
/*  C Code section */
int yywrap(void) {
    return 1;
}

int main(int argc, char* argv[]) {
    char *inputFileName = NULL;
    if (argc == 2) {
        yyin = fopen(inputFileName = argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", inputFileName);
        exit(1);
    }

    yylex();
    printf("\nTotal line: %d\n", yylineno);

    fclose(yyin);
    return 0;
}