#ifndef MAIN_H
#define MAIN_H
#include "compiler_common.h"

#define VAR_FLAG_DEFAULT 0
#define code(format, ...) \
    fprintf(yyout, "%*s" format "\n", scopeLevel << 2, "", __VA_ARGS__)
    //fprintf(yyout, "%*s" format "\n", scopeLevel << 2, "", __VA_ARGS__)
#define codeRaw(code) \
    fprintf(yyout, "%*s" code "\n", scopeLevel << 2, "")

#define iload(var) code("iload %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lload(var) code("lload %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fload(var) code("fload %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dload(var) code("dload %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define aload(var) code("aload %ld ; %s", (var)->symbol->addr, (var)->symbol->name)

#define istore(var) code("istore %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lstore(var) code("lstore %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fstore(var) code("fstore %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dstore(var) code("dstore %ld ; %s", (var)->symbol->addr, (var)->symbol->name)
#define astore(var) code("astore %ld ; %s", (var)->symbol->addr, (var)->symbol->name)

#define ldz(val) code("ldc %d", getBool(val))
#define ldb(val) code("ldc %d", getByte(val))
#define ldc(val) code("ldc %d", getChar(val))
#define lds(val) code("ldc %d", getShort(val))
#define ldi(val) code("ldc %d", getInt(val))
#define ldl(val) code("ldc_w %" PRId64, getLong(val))
#define ldf(val) code("ldc %.6f", getFloat(val))
#define ldd(val) code("ldc_w %lf", getDouble(val))
#define ldt(val) code("ldc \"%s\"", getString(val))

#define storeMatrix(var)                                                       \
  if ((var)->type == OBJECT_TYPE_FLOAT) {                                      \
    fstore(var);                                                               \
  } else if ((var)->type == OBJECT_TYPE_INT ||                                 \
             (var)->type == OBJECT_TYPE_BOOL) {                                \
    istore(var);                                                               \
  } else if ((var)->type == OBJECT_TYPE_LONG) {                                \
    lstore(var);                                                               \
  } else if ((var)->type == OBJECT_TYPE_DOUBLE) {                              \
    dstore(var);                                                               \
  } else if ((var)->type == OBJECT_TYPE_STR) {                                 \
    astore(var);                                                               \
  }
#define loadMatrix(var, array)                                                \
  if (array == 0) {                                                           \
    if ((var)->type == OBJECT_TYPE_FLOAT) {                                   \
      fload(var);                                                             \
    } else if ((var)->type == OBJECT_TYPE_INT ||                              \
               (var)->type == OBJECT_TYPE_BOOL) {                             \
      iload(var);                                                             \
    } else if ((var)->type == OBJECT_TYPE_LONG) {                             \
      lload(var);                                                             \
    } else if ((var)->type == OBJECT_TYPE_DOUBLE) {                           \
      dload(var);                                                             \
    } else if ((var)->type == OBJECT_TYPE_STR) {                              \
      aload(var);                                                             \
    }                                                                         \
  } else {                                                                    \
    aload(var);                                                               \
  }                                                                           


extern FILE* yyout;
extern FILE* yyin;
extern bool compileError;
extern int scopeLevel;
int yyparse();
int yylex();
int yylex_destroy();

void pushScope();
void dumpScope();

void pushFunParm(ObjectType variableType, char* variableName, int parmFlag);
void createFunction(ObjectType variableType, char* funcName);
void pushFunInParm(Object* b);

Object* findVariable(char* variableName,int findfunc);
Object* createVariable(ObjectType variableType, char* variableName, int variableFlag);

//Object* findVariable(char* variableName);
//bool initVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
//Object* createVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName, Object* value);

//void functionLocalsBegin();
//void functionParmPush(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
//void functionBegin(ObjectType returnType, LinkedList* arraySubscripts, char* funcName);
//bool functionEnd(ObjectType returnType);

//bool returnObject(Object* obj);
//bool breakLoop();

//void functionArgsBegin();
//void functionArgPush(Object* obj);
//void functionCall(char* funcName, Object* out);
void stdoutPrint();
//bool stdoutPrint(Object* obj);

int varAddrCheck(char * name,int findfunc);
int FuncAddr();
int checkCout();
void insertCout(int type);
void clearCout();
Object* typeCheck(char * name);
void Cast(int type);
void ExpressionType(char  operation,Object* leftType,Object *rightType,Object *output);
void IdentType(Object * output, char *name,int findfunc);
void addfuncpara(int type);
void funcsig(char * variableName);
Object* findFunction(char *name,char* type);
void coutExpr();
// Expressions
bool objectExpression(char op, Object* a, Object* b, Object* out);
bool objectExpBinary(char op, Object* a, Object* b, Object* out);
bool objectExpBoolean(char op, Object* a, Object* b, Object* out);
bool objectNotBinaryExpression(Object* a, Object* out);
bool objectNotBooleanExpression(Object* a, Object* out);
bool objectNegExpression(Object* a, Object* out);
bool objectIncAssign(Object* a, Object* out);
bool objectDecAssign(Object* a, Object* out);
bool objectCast(ObjectType variableType, Object* a, Object* out);
bool objectExpAssign(char op, Object* dest, Object* val, Object* out);
bool objectValueAssign(Object* dest, Object* val, Object* out);

bool ifBegin(Object* a);
bool ifEnd();
bool ifOnlyEnd();
bool elseBegin();
bool elseEnd();

bool whileBegin();
bool whileBodyBegin();
bool whileEnd();

bool forBegin();
bool forInitEnd();
bool forConditionEnd(Object* result);
bool forHeaderEnd();
bool foreachHeaderEnd(Object* obj);
bool forEnd();

bool arrayCreate(Object* out);
//bool objectArrayGet(Object* arr, LinkedList* arraySubscripts, Object* out);
//LinkedList* arraySubscriptBegin(Object* index);
//bool arraySubscriptPush(LinkedList* arraySubscripts, Object* index);
//bool arraySubscriptEnd(LinkedList* arraySubscripts);

#endif
