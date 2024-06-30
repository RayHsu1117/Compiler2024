#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


#include "main.h"

//#include "value_operation.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)



const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_BYTE] = "byte",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_SHORT] = "short",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_LONG] = "long",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_DOUBLE] = "double",
    [OBJECT_TYPE_STR] = "string",
};
const char* objectJavaTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "V",
    [OBJECT_TYPE_VOID] = "V",
    [OBJECT_TYPE_BOOL] = "Z",
    [OBJECT_TYPE_BYTE] = "B",
    [OBJECT_TYPE_CHAR] = "C",
    [OBJECT_TYPE_SHORT] = "S",
    [OBJECT_TYPE_INT] = "I",
    [OBJECT_TYPE_LONG] = "J",
    [OBJECT_TYPE_FLOAT] = "F",
    [OBJECT_TYPE_DOUBLE] = "D",
    [OBJECT_TYPE_STR] = "Ljava/lang/String;",
};


struct Node{
    Object *obj;
    struct Node *next;
};
typedef struct Node SymbolTable;
#define MAX_SCOPE_LEVEL 16
SymbolTable *scopes[MAX_SCOPE_LEVEL], *TailPtr; //TailPtr points to the asshole of the SymbolTable.
int numofscope[MAX_SCOPE_LEVEL];
int funcpara[20] ={0};
int funcparanum = 0;
#define MAX_COUT 16
int CoutList[MAX_COUT];
int functype[20] = {0};
char* yyInputFileName;
bool compileError;

int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddr = 0;
ObjectType variableIdentType;
int funcAddr = 0;

int cout_num = 0;
int totalindex = 0;

char* yyInputFileName;
bool compileError;

void Cast(int type){
    printf("Cast to %s\n", objectTypeName[type]);
}
void addfuncpara(int type){
  funcpara[funcparanum]=type;
 // printf("type =%d\n",type);
  funcparanum++;
}

void funcsig(char * variableName){
 // printf("SIG\n");
  char sig[50]="(";
 // printf("SIG = %s\n",sig);
 // printf("funcnum = %d\n",funcparanum);
  for(int i=1;i<funcparanum;i++){
      //printf("%s -> ",sig);
      switch(funcpara[i]){
        case 4: //int
          strcat(sig,"I");
          break;
        case 40: //int
          strcat(sig,"[I");
          break;
        case 6: //float
          strcat(sig,"F");
          break;
        case 60: //float[]
          strcat(sig,"[F");
          break;
        case 8://bool
          strcat(sig,"Z");
          break;
        case 80: //bool[]
          strcat(sig,"[Z");
          break;
        case 9: //string
          strcat(sig,"Ljava/lang/String;");
          break;
        case 90: //string []
          strcat(sig,"[Ljava/lang/String;");
          break;
        case 11: //void
          strcat(sig,"V");
          break;  
      }
  }
  strcat(sig,")");
 // printf("%s -> \n",sig);
 if(strcmp(variableName,"main")==0){funcpara[0]=2;}
  switch(funcpara[0]){
        case 4: //int
          strcat(sig,"I");
          break;
        case 40: //int
          strcat(sig,"[I");
          break;
        case 6: //float
          strcat(sig,"F");
          break;
        case 60: //float[]
          strcat(sig,"[F");
          break;
        case 8://bool
          strcat(sig,"Z");
          break;
        case 80: //bool[]
          strcat(sig,"[Z");
          break;
        case 9: //string
          strcat(sig,"Ljava/lang/String;");
          break;
        case 90: //string []
          strcat(sig,"[Ljava/lang/String;");
          break;
        case 2: //void
          strcat(sig,"V");
          break;  
  }
 // printf("%s\n",sig);
  
  for (SymbolTable *ptr = scopes[0]->next; ptr != NULL; ptr = ptr->next) {
        
       // printf("scope[%d]name=%s\n",i,ptr->obj->symbol->name);
        if(strcmp(ptr->obj->symbol->name,variableName)==0){
            ptr->obj->symbol->func_sig = (char *)malloc((strlen(sig)+1)*sizeof(char));
            strcpy(ptr->obj->symbol->func_sig,sig);
            break;
        }
      }
  for(int i=0;i<funcparanum;i++){
    funcpara[i] = 0;
  }
  funcparanum = 0;
}


int varAddrCheck(char * name,int findfunc){
 // printf("ident name = %s\n",name);
  if(strcmp(name,"endl")==0){
      //insertCout(9);
    //  printf("IDENT (name=%s, address=%d)\n", name, -1);
      return -1;
  }
  else{
      Object* temp = findVariable(name,findfunc);
      if(temp!=NULL){
        //  printf("IDENT (name=%s, address=%ld)\n", name, temp->symbol->addr);
          return temp->symbol->addr;
      }
      else
          return 0;
  }
}

int FuncAddr(){
    return funcAddr;
}

void pushScope() {
    scopeLevel++;
    TailPtr = scopes[scopeLevel];
    
    printf("> Create symbol table (scope level %d)\n",scopeLevel);
    variableAddr = 0;
}

void dumpScope() {
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);
    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n", "Index","Name", "Type", "Addr", "Lineno", "Func_sig");
    
      for (SymbolTable *current = scopes[scopeLevel]->next; current != NULL; current = current->next) {
        printf("%-10d", current->obj->symbol->index);
        printf("%-20s", current->obj->symbol->name);
        printf("%-10s", objectTypeName[current->obj->type]);
        printf("%-10ld", current->obj->symbol->addr);
        printf("%-10d", current->obj->symbol->lineno);
        printf("%-10s", current->obj->symbol->func_sig);
        printf("\n");
      }
    scopes[scopeLevel]->obj = NULL;
    scopes[scopeLevel]->next= NULL;
    numofscope[scopeLevel] = 0;
    scopeLevel--;
    if(scopeLevel > -1){
        TailPtr = scopes[scopeLevel];
        while(TailPtr->next != NULL){
            TailPtr = TailPtr->next;
        }
    }
    if(scopeLevel==0){
      totalindex=0;
    }
}

Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    Object* varObj = (Object*)malloc(sizeof(Object));
    varObj->type = variableType;
    varObj->symbol = (SymbolData*)malloc(sizeof(SymbolData));
    varObj->symbol->name = variableName;
     if(variableType == OBJECT_TYPE_FUNCTION){
         varObj->symbol->index=funcAddr;
         varObj->symbol->addr = -1;
         varObj->symbol->func_sig = "([Ljava/lang/String;)I";
         printf("> Insert `%s` (addr: %ld) to scope level %d\n",variableName,varObj->symbol->addr,scopeLevel);
         funcAddr++;
         
        // totalindex++;
         numofscope[scopeLevel]++;
     }
     else{
         varObj->symbol->index = variableAddr;
         varObj->symbol->addr = totalindex;
         varObj->symbol->func_sig ="-";
         printf("> Insert `%s` (addr: %d) to scope level %d\n",variableName,totalindex,scopeLevel);
         totalindex++;
         variableAddr++;
         numofscope[scopeLevel]++;
     }
    //obj->symbol->addr = variableAddr;
    //varObj->symbol->lineno = yylineno;
    //printf("Creating successfully0.\n");
    TailPtr->next = (SymbolTable *)malloc(sizeof(SymbolTable));
    //printf("Creating successfully1.\n");
    TailPtr = TailPtr->next;
    //printf("Creating successfully2.\n");
    TailPtr->obj = varObj;
    //printf("Creating successfully3.\n");
    TailPtr->next = NULL;
    //printf("Creating successfully4.\n");
    
    return varObj;
}

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    createVariable(variableType, variableName, variableFlag);
    
}

void createFunction(ObjectType variableType, char* funcName) {
    printf("func: %s\n",funcName);
    functype[funcAddr]=variableType;
    createVariable(10, funcName, -1);


    
}

void ExpressionType(char  operation,Object* leftType,Object *rightType,Object *output){
    switch(operation){
      case 'l':{
          output->type = OBJECT_TYPE_BOOL;
          break;
      }
      case 'b':{
          output->type = OBJECT_TYPE_INT;
          break;
      }
      case 'r':{
          output->type = OBJECT_TYPE_BOOL;
          break;
      }
      case 's':{  //%
          output->type = OBJECT_TYPE_INT;
          break;
      }
      case 'm':{
          if(leftType->type==OBJECT_TYPE_FLOAT || rightType->type==OBJECT_TYPE_FLOAT){
            output->type = OBJECT_TYPE_FLOAT;
          }
          else {
            output->type = OBJECT_TYPE_INT;
          }
          break;
      }

    }
   //printf("out->type = %d\n",output->type);
}

void IdentType(Object * output, char *name,int findfunc){
    Object *varObj = findVariable(name,findfunc);
    if(strcmp(name, "endl") == 0){
        output->type = OBJECT_TYPE_STR;
        return;
    }
    if(varObj != NULL){
        if(varObj->type == 10){
          int i=0;
          for (SymbolTable *ptr = scopes[0]->next; ptr != NULL; ptr = ptr->next) { 
         // printf("scope[%d]name=%s\n",i,ptr->obj->symbol->name);
            if(strcmp(ptr->obj->symbol->name,name)==0){
                output->type = functype[i];
            }
            i++;
          }
        }
        else{
          output->type = varObj->type;
        }
        //printf("\n%s\n\n", objectTypeName[varObj->type]);
    }
    else{
        output->type = 0;
    }
}
Object* findVariable(char* variableName,int findfunc) {
    /*if(numofscope[scopeLevel]==0){
      return NULL;
    }*/
  //  printf("scopeLevel = %d\n",scopeLevel);
    if(findfunc==1){
      for (SymbolTable *ptr = scopes[0]->next; ptr != NULL; ptr = ptr->next) {
       // printf("scope[%d]name=%s\n",i,ptr->obj->symbol->name);
        if(strcmp(ptr->obj->symbol->name,variableName)==0){
            return ptr->obj;
        }
      }
    }
    else{
      for(int i = 1; i <= scopeLevel; i++){
        //if(scopes[scopeLevel]==NULL){printf("scope = NULL");}
        for (SymbolTable *ptr = scopes[i]->next; ptr != NULL; ptr = ptr->next) {
         // printf("scope[%d]name=%s\n",i,ptr->obj->symbol->name);
          if(strcmp(ptr->obj->symbol->name,variableName)==0){
              
              return ptr->obj;
          }
        }
      }
    }
  //  printf("Variable not found.\n");
    return NULL;
}


void pushFunInParm(Object* variable) {


}

void stdoutPrint() {
    printf("cout ");
    for(int i=0;i<cout_num;i++){
      printf("%s",objectTypeName[CoutList[i]]);
      if(i<cout_num-1){
          printf(" ");
        }
    }
    printf("\n"); 
}


void insertCout(int type){
    CoutList[cout_num]=type;
    cout_num++;  
}
void clearCout() {
    for(int i=0;i<MAX_COUT;i++){
      CoutList[i]=0;
    }
    cout_num=0;
}
void coutExpr(){
 // printf("List Expr---------------\n");
 // for(int i=0;i<cout_num;i++){
 //   printf("%d ",CoutList[i]);
 // }printf("\n");
  if(cout_num==0){
    return;
  }
  int type=CoutList[cout_num-1];
 // printf("------cout type-----%d\n",type);
  if(type==OBJECT_TYPE_INT){
    codeRaw("invokevirtual java/io/PrintStream/print(I)V");
  }
  else if(type==OBJECT_TYPE_FLOAT){
    codeRaw("invokevirtual java/io/PrintStream/print(F)V");
  }
  else if(type==OBJECT_TYPE_BOOL){
    codeRaw("invokevirtual java/io/PrintStream/print(Z)V");
  }
  else if(type==OBJECT_TYPE_STR || OBJECT_TYPE_CHAR){
    codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
  }
}

int main(int argc, char* argv[]) {
    char* outputFileName = NULL;
    if (argc == 3) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = fopen(outputFileName = argv[2], "w");
    } else if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = stdout;
    } else {
        printf("require input file");
        exit(1);
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }
    if (!yyout) {
        printf("file `%s` doesn't exists or cannot be opened\n", outputFileName);
        exit(1);
    }
    for(int i=0;i<MAX_SCOPE_LEVEL;i++){
        scopes[i] = (SymbolTable *)malloc(sizeof(SymbolTable));
    }
    codeRaw(".source Main.j");
    codeRaw(".class public Main");
    codeRaw(".super java/lang/Object");
    scopeLevel = -1;

    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}
