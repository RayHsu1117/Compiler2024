/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./compiler.y"

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

#line 129 "./build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BNT = 8,                        /* BNT  */
  YYSYMBOL_BXO = 9,                        /* BXO  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUB = 11,                       /* SUB  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_REM = 14,                       /* REM  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GTR = 16,                       /* GTR  */
  YYSYMBOL_LES = 17,                       /* LES  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LEQ = 19,                       /* LEQ  */
  YYSYMBOL_EQL = 20,                       /* EQL  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LAN = 22,                       /* LAN  */
  YYSYMBOL_LOR = 23,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 24,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 29,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 30,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 31,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 32,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 33,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 34,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 35,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 36,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_VARIABLE_T = 49,                /* VARIABLE_T  */
  YYSYMBOL_BOOL_LIT = 50,                  /* BOOL_LIT  */
  YYSYMBOL_CHAR_LIT = 51,                  /* CHAR_LIT  */
  YYSYMBOL_INT_LIT = 52,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 53,                 /* FLOAT_LIT  */
  YYSYMBOL_STR_LIT = 54,                   /* STR_LIT  */
  YYSYMBOL_IDENT = 55,                     /* IDENT  */
  YYSYMBOL_THEN = 56,                      /* THEN  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '{'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_Program = 62,                   /* Program  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 64,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 65,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 66,        /* DefineVariableStmt  */
  YYSYMBOL_67_2 = 67,                      /* $@2  */
  YYSYMBOL_IdentList = 68,                 /* IdentList  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_InitializerList = 70,           /* InitializerList  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_ArrayAssignmentStmt = 73,       /* ArrayAssignmentStmt  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_75_7 = 75,                      /* $@7  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_FunctionDefStmt = 77,           /* FunctionDefStmt  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_80_11 = 80,                     /* $@11  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_FunctionParameterStmtList = 82, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 83,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 84,                  /* StmtList  */
  YYSYMBOL_Stmt = 85,                      /* Stmt  */
  YYSYMBOL_86_13 = 86,                     /* $@13  */
  YYSYMBOL_87_14 = 87,                     /* $@14  */
  YYSYMBOL_88_15 = 88,                     /* $@15  */
  YYSYMBOL_89_16 = 89,                     /* $@16  */
  YYSYMBOL_For = 90,                       /* For  */
  YYSYMBOL_91_17 = 91,                     /* $@17  */
  YYSYMBOL_92_18 = 92,                     /* $@18  */
  YYSYMBOL_93_19 = 93,                     /* $@19  */
  YYSYMBOL_F1 = 94,                        /* F1  */
  YYSYMBOL_F1_List1 = 95,                  /* F1_List1  */
  YYSYMBOL_F1_List2 = 96,                  /* F1_List2  */
  YYSYMBOL_F2 = 97,                        /* F2  */
  YYSYMBOL_F3 = 98,                        /* F3  */
  YYSYMBOL_IFStmt = 99,                    /* IFStmt  */
  YYSYMBOL_100_20 = 100,                   /* $@20  */
  YYSYMBOL_101_21 = 101,                   /* $@21  */
  YYSYMBOL_102_22 = 102,                   /* $@22  */
  YYSYMBOL_103_23 = 103,                   /* $@23  */
  YYSYMBOL_104_24 = 104,                   /* $@24  */
  YYSYMBOL_ElseStmt = 105,                 /* ElseStmt  */
  YYSYMBOL_106_25 = 106,                   /* $@25  */
  YYSYMBOL_107_26 = 107,                   /* $@26  */
  YYSYMBOL_IdentAssign = 108,              /* IdentAssign  */
  YYSYMBOL_109_27 = 109,                   /* $@27  */
  YYSYMBOL_110_28 = 110,                   /* $@28  */
  YYSYMBOL_111_29 = 111,                   /* $@29  */
  YYSYMBOL_112_30 = 112,                   /* $@30  */
  YYSYMBOL_113_31 = 113,                   /* $@31  */
  YYSYMBOL_114_32 = 114,                   /* $@32  */
  YYSYMBOL_115_33 = 115,                   /* $@33  */
  YYSYMBOL_116_34 = 116,                   /* $@34  */
  YYSYMBOL_117_35 = 117,                   /* $@35  */
  YYSYMBOL_118_36 = 118,                   /* $@36  */
  YYSYMBOL_119_37 = 119,                   /* $@37  */
  YYSYMBOL_120_38 = 120,                   /* $@38  */
  YYSYMBOL_121_39 = 121,                   /* $@39  */
  YYSYMBOL_CoutParmListStmt = 122,         /* CoutParmListStmt  */
  YYSYMBOL_123_40 = 123,                   /* $@40  */
  YYSYMBOL_124_41 = 124,                   /* $@41  */
  YYSYMBOL_Expression = 125,               /* Expression  */
  YYSYMBOL_Callfunction = 126,             /* Callfunction  */
  YYSYMBOL_Funcparameter = 127,            /* Funcparameter  */
  YYSYMBOL_FuncparameterList = 128,        /* FuncparameterList  */
  YYSYMBOL_LORExpression = 129,            /* LORExpression  */
  YYSYMBOL_LANExpression = 130,            /* LANExpression  */
  YYSYMBOL_BitwiseExpression = 131,        /* BitwiseExpression  */
  YYSYMBOL_RelationalExpression = 132,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 133,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 134,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 135, /* MultiplicativeExpression  */
  YYSYMBOL_CastExpression = 136,           /* CastExpression  */
  YYSYMBOL_UnaryExpression = 137,          /* UnaryExpression  */
  YYSYMBOL_PrimaryExpression = 138,        /* PrimaryExpression  */
  YYSYMBOL_139_42 = 139,                   /* $@42  */
  YYSYMBOL_ArrayIdent = 140                /* ArrayIdent  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    49,
      50,    51,    52,    53,    54,    55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    92,    93,    97,    98,   102,   103,   107,
     107,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     119,   120,   125,   125,   126,   126,   127,   130,   130,   131,
     131,   131,   135,   135,   135,   135,   135,   139,   140,   141,
     145,   146,   150,   151,   158,   159,   160,   161,   162,   163,
     164,   164,   164,   165,   165,   165,   166,   167,   168,   169,
     170,   174,   174,   174,   174,   175,   179,   180,   181,   183,
     184,   186,   187,   189,   190,   192,   193,   196,   196,   196,
     196,   197,   197,   197,   200,   200,   201,   201,   202,   206,
     206,   207,   207,   208,   208,   209,   209,   210,   210,   211,
     211,   212,   212,   213,   213,   214,   214,   215,   215,   216,
     216,   217,   217,   218,   218,   224,   224,   225,   225,   229,
     233,   236,   237,   239,   240,   244,   245,   249,   250,   254,
     255,   256,   257,   258,   262,   263,   264,   265,   266,   267,
     268,   272,   273,   277,   278,   279,   283,   284,   285,   286,
     290,   291,   295,   296,   297,   298,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   310,   311,   314
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM", "NOT",
  "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "BREAK", "CONTINUE", "'('", "')'", "'['", "']'", "':'", "VARIABLE_T",
  "BOOL_LIT", "CHAR_LIT", "INT_LIT", "FLOAT_LIT", "STR_LIT", "IDENT",
  "THEN", "';'", "','", "'{'", "'}'", "$accept", "Program", "$@1",
  "GlobalStmtList", "GlobalStmt", "DefineVariableStmt", "$@2", "IdentList",
  "$@3", "InitializerList", "$@4", "$@5", "ArrayAssignmentStmt", "$@6",
  "$@7", "$@8", "FunctionDefStmt", "$@9", "$@10", "$@11", "$@12",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@13", "$@14", "$@15", "$@16", "For", "$@17", "$@18", "$@19", "F1",
  "F1_List1", "F1_List2", "F2", "F3", "IFStmt", "$@20", "$@21", "$@22",
  "$@23", "$@24", "ElseStmt", "$@25", "$@26", "IdentAssign", "$@27",
  "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36",
  "$@37", "$@38", "$@39", "CoutParmListStmt", "$@40", "$@41", "Expression",
  "Callfunction", "Funcparameter", "FuncparameterList", "LORExpression",
  "LANExpression", "BitwiseExpression", "RelationalExpression",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "CastExpression", "UnaryExpression", "PrimaryExpression", "$@42",
  "ArrayIdent", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-168)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    21,   -35,  -227,   -47,   -35,  -227,  -227,  -227,     1,
      26,  -227,  -227,   -15,   -28,  -227,    72,    72,  -227,    40,
       6,   310,   310,   310,   298,  -227,  -227,  -227,  -227,  -227,
      19,  -227,  -227,    76,    75,    34,   180,    96,    74,    13,
    -227,  -227,  -227,    55,    58,   -13,    48,    49,  -227,    72,
    -227,  -227,  -227,    61,    64,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,   -11,    72,    72,    65,     6,
      70,    72,  -227,  -227,    83,    62,    75,    34,   180,   180,
     180,   180,    96,    96,    96,    96,    96,    96,    74,    13,
      13,  -227,  -227,  -227,    84,    72,   109,  -227,    87,    89,
    -227,    78,  -227,  -227,    72,    92,    93,    82,    -9,  -227,
    -227,  -227,    98,  -227,     8,    86,    72,   262,    72,    11,
      72,     8,    95,   145,   103,   108,  -227,   276,   101,   102,
    -227,   341,  -227,  -227,   104,     7,  -227,  -227,   105,   107,
     120,   126,  -227,  -227,  -227,    36,  -227,  -227,     0,    72,
    -227,   123,  -227,   118,  -227,  -227,   152,   153,   164,   166,
     163,   161,   176,   181,   183,   179,   186,   182,   188,  -227,
    -227,  -227,  -227,  -227,    72,  -227,    72,  -227,    72,  -227,
    -227,   171,   -43,    72,  -227,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,  -227,  -227,   175,  -227,
    -227,    72,   159,   170,   202,   187,   174,   169,   190,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
     193,  -227,   177,   262,   -20,   184,    72,   189,  -227,   173,
    -227,   216,   195,   262,   262,    72,   191,   196,  -227,  -227,
      72,   221,   194,    72,    72,    33,   212,  -227,  -227,   228,
     262,  -227,  -227,    72,   262,  -227,   209,  -227,   225,  -227,
      72,   114,   206,  -227,   218,  -227,  -227,   205,   229,  -227,
    -227,  -227,  -227,   244,   212,   262,  -227,   214,    72,  -227,
     240,   363,  -227,  -227,  -227,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     7,     8,     0,
       0,     5,    32,    11,     0,    33,     0,     0,    10,     0,
      39,     0,     0,     0,     0,   158,   161,   156,   157,   160,
     159,    13,   166,   119,   126,   128,   133,   140,   142,   145,
     149,   151,   155,     0,     0,    12,     0,    34,    38,     0,
     153,   154,   152,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    41,     0,
       0,     0,   162,   124,     0,   121,   125,   127,   131,   129,
     132,   130,   138,   136,   139,   137,   134,   135,   141,   143,
     144,   146,   147,   148,     0,     0,     0,    14,     0,     0,
      37,     0,   150,   120,     0,   163,     0,     0,    16,    40,
      35,   123,     0,    17,    24,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    53,     0,     0,     0,
       9,    89,    44,    59,     0,     0,    43,    49,     0,     0,
       0,     0,    22,    20,    25,     0,    18,   117,     0,     0,
      50,     0,    47,     0,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      36,    42,    48,    60,     0,   165,     0,    21,     0,   115,
      45,     0,    68,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   114,     0,    23,
     118,     0,    81,     0,     0,     0,     0,    67,     0,    90,
      92,    94,    96,    98,   100,   102,   104,   106,   108,   110,
      27,   116,     0,     0,     0,    66,     0,     0,    61,     0,
      54,     0,     0,     0,    82,     0,     0,     0,    72,    51,
      74,     0,     0,     0,     0,     0,    88,    70,    65,     0,
       0,    62,    73,     0,     0,    28,     0,    78,    84,    83,
       0,     0,     0,    71,     0,    30,    79,     0,     0,    69,
      52,    63,    55,     0,    88,     0,    87,    76,     0,    80,
       0,    89,    64,    75,    31,    85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -227,  -227,   265,    14,  -227,  -227,  -227,   140,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,   197,  -226,  -142,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,    -4,  -227,
    -227,  -227,  -227,  -227,     2,  -227,  -227,    -2,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,   -16,  -125,  -227,  -227,  -227,   232,
     233,    -7,   142,   224,    22,   -49,    56,  -227,  -227,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,   143,    10,    14,   106,   129,
     186,   130,   144,   241,   242,   283,     8,    15,    20,    80,
     127,    47,    48,   145,   146,   192,   260,   161,   252,   215,
     250,   272,   287,   216,   235,   217,   261,   292,   147,   232,
     276,   284,   233,   256,   269,   277,   278,   148,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   158,   211,   188,    54,    32,    84,    85,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   122,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   149,   181,   245,   189,   213,   244,     9,    16,
     133,    76,   214,   -19,     4,   125,     7,   255,    -4,     7,
     149,     3,   101,   102,   103,    71,    72,    73,   246,    18,
      19,    17,   112,    77,   271,   105,   133,   126,   274,    83,
      58,    59,    60,    61,   134,    12,   135,   136,   137,   138,
     139,    88,    89,    90,    91,    46,   140,   190,   104,   290,
     107,   108,   141,    55,   142,  -167,   -26,   180,   -26,   152,
     134,   153,   135,   136,   137,   138,   139,    50,    51,    52,
      21,    13,   140,    22,    69,    70,   150,    23,   141,   116,
     142,    99,   100,   267,   152,    45,   187,    57,   121,    56,
      68,    74,   181,    78,   150,    75,    81,    79,   149,    82,
     132,   109,   151,   181,   154,   111,    24,   133,   149,   149,
     114,   163,    25,    26,    27,    28,    29,    30,   113,   181,
     149,   115,   181,   117,   118,   149,   119,   120,  -164,   149,
     123,   124,   156,   191,   128,   131,   149,   159,   181,   149,
     157,   134,   160,   135,   136,   137,   138,   139,   164,   165,
     149,   179,   182,   140,   183,   149,   184,   193,   208,   141,
     209,   142,   210,   185,   280,   194,   195,   218,   196,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     197,   199,   150,   198,   200,   231,    62,    63,    64,    65,
      66,    67,   150,   150,    92,    93,    94,    95,    96,    97,
     201,   204,   202,   203,   150,   205,   212,   206,   -77,   150,
     248,   133,   230,   150,   207,   234,   236,   239,   251,   257,
     150,   238,   237,   150,   262,   240,   243,   265,   266,   -29,
     253,   254,   247,   133,   150,   263,   258,   273,   249,   150,
     268,   259,   270,   264,   279,   134,   275,   135,   136,   137,
     138,   139,   -86,   281,   285,   133,   134,   140,   288,   291,
      11,   155,   294,   141,   286,   142,   110,   134,   282,   135,
     136,   137,   138,   139,    21,   293,   289,    22,    86,   140,
      87,    23,    98,     0,     0,   141,     0,   142,     0,   134,
     295,   135,   136,   137,   138,   139,    21,     0,     0,    22,
       0,   140,     0,    23,     0,     0,     0,   141,    21,   142,
      24,    22,     0,     0,     0,    23,    25,    26,    27,    28,
      29,    30,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,    53,    25,    26,
      27,    28,    29,    30,    49,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,   -91,   -93,   -95,   -97,
    -109,  -105,  -103,  -107,   -99,  -101,  -111,  -113,     0,     0,
       0,     0,     0,     0,     0,    55,     0,  -167,   -91,   -93,
     -95,   -97,  -109,  -105,  -103,  -107,   -99,  -101,  -111,  -113
};

static const yytype_int16 yycheck[] =
{
      16,    17,   127,   145,    24,     5,    49,   233,    55,    24,
       3,    24,    55,    24,    49,    24,     2,   243,     0,     5,
     145,     0,    71,    72,    73,    12,    13,    14,    48,    57,
      58,    46,    81,    46,   260,    46,     3,    46,   264,    55,
       6,     7,     8,     9,    37,    44,    39,    40,    41,    42,
      43,    58,    59,    60,    61,    49,    49,    57,    74,   285,
      76,    77,    55,    44,    57,    46,    58,    60,    60,    58,
      37,    60,    39,    40,    41,    42,    43,    21,    22,    23,
       8,    55,    49,    11,    10,    11,   127,    15,    55,   105,
      57,    69,    70,    60,    58,    55,    60,    22,   114,    23,
       4,    46,   244,    55,   145,    47,    45,    58,   233,    45,
     126,    46,   128,   255,   130,    45,    44,     3,   243,   244,
      58,   137,    50,    51,    52,    53,    54,    55,    45,   271,
     255,    47,   274,    24,    47,   260,    47,    59,    46,   264,
      47,    59,    47,   159,    46,    59,   271,    44,   290,   274,
       5,    37,    44,    39,    40,    41,    42,    43,    57,    57,
     285,    57,    57,    49,    57,   290,    46,    44,   184,    55,
     186,    57,   188,    47,    60,    57,    24,   193,    25,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      26,    28,   233,    27,    33,   211,    16,    17,    18,    19,
      20,    21,   243,   244,    62,    63,    64,    65,    66,    67,
      34,    32,    31,    30,   255,    29,    45,    35,    59,   260,
     236,     3,    47,   264,    36,    55,    24,    58,    55,   245,
     271,    57,    45,   274,   250,    45,    59,   253,   254,    46,
      24,    46,    58,     3,   285,    24,    55,   263,    59,   290,
      38,    55,    24,    59,   270,    37,    47,    39,    40,    41,
      42,    43,    37,    57,    59,     3,    37,    49,    24,    55,
       5,   131,   288,    55,   278,    57,    79,    37,    60,    39,
      40,    41,    42,    43,     8,   287,   284,    11,    56,    49,
      57,    15,    68,    -1,    -1,    55,    -1,    57,    -1,    37,
      60,    39,    40,    41,    42,    43,     8,    -1,    -1,    11,
      -1,    49,    -1,    15,    -1,    -1,    -1,    55,     8,    57,
      44,    11,    -1,    -1,    -1,    15,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,    49,    64,    65,    66,    77,    55,
      67,    65,    44,    55,    68,    78,    24,    46,    57,    58,
      79,     8,    11,    15,    44,    50,    51,    52,    53,    54,
      55,   125,   126,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   140,   125,    55,    49,    82,    83,    44,
     137,   137,   137,    49,   125,    44,    23,    22,     6,     7,
       8,     9,    16,    17,    18,    19,    20,    21,     4,    10,
      11,    12,    13,    14,    46,    47,    24,    46,    55,    58,
      80,    45,    45,   125,   127,   128,   130,   131,   132,   132,
     132,   132,   133,   133,   133,   133,   133,   133,   134,   135,
     135,   136,   136,   136,   125,    46,    69,   125,   125,    46,
      83,    45,   136,    45,    58,    47,   125,    24,    47,    47,
      59,   125,   139,    47,    59,    24,    46,    81,    46,    70,
      72,    59,   125,     3,    37,    39,    40,    41,    42,    43,
      49,    55,    57,    66,    73,    84,    85,    99,   108,   126,
     140,   125,    58,    60,   125,    70,    47,     5,   122,    44,
      44,    88,    57,   125,    57,    57,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    57,
      60,    85,    57,    57,    46,    47,    71,    60,   124,     5,
      57,   125,    86,    44,    57,    24,    25,    26,    27,    28,
      33,    34,    31,    30,    32,    29,    35,    36,   125,   125,
     125,   123,    45,    49,    55,    90,    94,    96,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
      47,   125,   100,   103,    55,    95,    24,    45,    57,    58,
      45,    74,    75,    59,    84,    24,    48,    58,   125,    59,
      91,    55,    89,    24,    46,    84,   104,   125,    55,    55,
      87,    97,   125,    24,    59,   125,   125,    60,    38,   105,
      24,    84,    92,   125,    84,    47,   101,   106,   107,   125,
      60,    57,    60,    76,   102,    59,    99,    93,    24,   105,
      84,    55,    98,   108,   125,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    63,    62,    62,    64,    64,    65,    65,    67,
      66,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      68,    68,    71,    70,    72,    70,    70,    74,    73,    75,
      76,    73,    78,    79,    80,    81,    77,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    87,    85,    88,    89,    85,    85,    85,    85,    85,
      85,    91,    92,    93,    90,    90,    94,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,   100,   101,   102,
      99,   103,   104,    99,   106,   105,   107,   105,   105,   109,
     108,   110,   108,   111,   108,   112,   108,   113,   108,   114,
     108,   115,   108,   116,   108,   117,   108,   118,   108,   119,
     108,   120,   108,   121,   108,   123,   122,   124,   122,   125,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   133,   133,   134,   134,   134,   135,   135,   135,   135,
     136,   136,   137,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   138,   138,   140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       4,     1,     3,     3,     5,     4,     6,     7,     9,     0,
       9,    10,     0,     4,     0,     2,     0,     0,     7,     0,
       0,    11,     0,     0,     0,     0,    12,     3,     1,     0,
       4,     2,     2,     1,     1,     3,     3,     2,     2,     1,
       0,     0,     9,     0,     0,     9,     2,     2,     2,     1,
       2,     0,     0,     0,     8,     4,     2,     1,     0,     5,
       3,     5,     3,     1,     0,     1,     0,     0,     0,     0,
      11,     0,     0,     8,     0,     5,     0,     3,     0,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     4,     0,     3,     1,
       4,     1,     0,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     0,     8,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 92 "./compiler.y"
      { pushScope(); }
#line 1495 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 92 "./compiler.y"
                                      { dumpScope(); }
#line 1501 "./build/y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 107 "./compiler.y"
                 { currentVarType = (yyvsp[0].var_type); }
#line 1507 "./build/y.tab.c"
    break;

  case 11: /* IdentList: IDENT  */
#line 111 "./compiler.y"
            { createVariable(currentVarType, (yyvsp[0].s_var), 0); }
#line 1513 "./build/y.tab.c"
    break;

  case 12: /* IdentList: IdentList ',' IDENT  */
#line 112 "./compiler.y"
                           { createVariable(currentVarType, (yyvsp[0].s_var), 0); }
#line 1519 "./build/y.tab.c"
    break;

  case 13: /* IdentList: IDENT VAL_ASSIGN Expression  */
#line 113 "./compiler.y"
                                  {if(currentVarType==1){currentVarType=(yyvsp[0].object_val).type;} createVariable(currentVarType, (yyvsp[-2].s_var), 0); storeMatrix(findVariable((yyvsp[-2].s_var),0));}
#line 1525 "./build/y.tab.c"
    break;

  case 14: /* IdentList: IdentList ',' IDENT VAL_ASSIGN Expression  */
#line 114 "./compiler.y"
                                                 {if(currentVarType==1){currentVarType=(yyvsp[0].object_val).type;} createVariable(currentVarType, (yyvsp[-2].s_var), 0);storeMatrix(findVariable((yyvsp[-2].s_var),0)); }
#line 1531 "./build/y.tab.c"
    break;

  case 15: /* IdentList: IDENT '[' Expression ']'  */
#line 115 "./compiler.y"
                                 {printf("create array: %d\n",array_element_num); createVariable(currentVarType, (yyvsp[-3].s_var), 0); obj =findVariable((yyvsp[-3].s_var),0); code("newarray %s",arraytype(obj->type));astore(findVariable((yyvsp[-3].s_var),0));}
#line 1537 "./build/y.tab.c"
    break;

  case 16: /* IdentList: IdentList ',' IDENT '[' Expression ']'  */
#line 116 "./compiler.y"
                                              { createVariable(currentVarType, (yyvsp[-3].s_var), 0);  obj =findVariable((yyvsp[-3].s_var),0); code("newarray %s",arraytype(obj->type));}
#line 1543 "./build/y.tab.c"
    break;

  case 17: /* IdentList: IDENT '[' Expression ']' '[' Expression ']'  */
#line 117 "./compiler.y"
                                                   {createVariable(currentVarType, (yyvsp[-6].s_var), 0); codeRaw("multianewarray [[I 2");astore(findVariable((yyvsp[-6].s_var),0));}
#line 1549 "./build/y.tab.c"
    break;

  case 18: /* IdentList: IdentList ',' IDENT '[' Expression ']' '[' Expression ']'  */
#line 118 "./compiler.y"
                                                                 { createVariable(currentVarType, (yyvsp[-6].s_var), 0); codeRaw("multianewarray [[I 2");astore(findVariable((yyvsp[-6].s_var),0));}
#line 1555 "./build/y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 119 "./compiler.y"
                                 {createVariable(currentVarType, (yyvsp[-3].s_var), 0); obj =findVariable((yyvsp[-3].s_var),0); code("newarray %s",arraytype(obj->type));}
#line 1561 "./build/y.tab.c"
    break;

  case 20: /* IdentList: IDENT '[' Expression ']' $@3 VAL_ASSIGN '{' InitializerList '}'  */
#line 119 "./compiler.y"
                                                                                                                                                                                        {printf("create array: %d\n",array_element_num); astore(findVariable((yyvsp[-8].s_var),0)); }
#line 1567 "./build/y.tab.c"
    break;

  case 21: /* IdentList: IdentList ',' IDENT '[' Expression ']' VAL_ASSIGN '{' InitializerList '}'  */
#line 120 "./compiler.y"
                                                                                { createVariable(currentVarType, (yyvsp[-7].s_var), 0); }
#line 1573 "./build/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 125 "./compiler.y"
                          {codeRaw("dup");code("ldc %d",array_element_num);}
#line 1579 "./build/y.tab.c"
    break;

  case 23: /* InitializerList: InitializerList ',' $@4 Expression  */
#line 125 "./compiler.y"
                                                                                        {codeRaw("iastore"); array_element_num++; }
#line 1585 "./build/y.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 126 "./compiler.y"
      {codeRaw("dup");code("ldc %d",array_element_num);}
#line 1591 "./build/y.tab.c"
    break;

  case 25: /* InitializerList: $@5 Expression  */
#line 126 "./compiler.y"
                                                                   {codeRaw("iastore"); array_element_num++; }
#line 1597 "./build/y.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 130 "./compiler.y"
                                    {/* varAddrCheck($1,0); */}
#line 1603 "./build/y.tab.c"
    break;

  case 28: /* ArrayAssignmentStmt: ArrayIdent '[' Expression ']' $@6 VAL_ASSIGN Expression  */
#line 130 "./compiler.y"
                                                                                      {codeRaw("iastore");/* astore(findVariable($1,0)); */}
#line 1609 "./build/y.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 131 "./compiler.y"
                                    {codeRaw("aaload");}
#line 1615 "./build/y.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 131 "./compiler.y"
                                                                            { /*varAddrCheck($1,0); */}
#line 1621 "./build/y.tab.c"
    break;

  case 31: /* ArrayAssignmentStmt: ArrayIdent '[' Expression ']' $@7 '[' Expression ']' $@8 VAL_ASSIGN Expression  */
#line 131 "./compiler.y"
                                                                                                                              {codeRaw("iastore"); /*astore(findVariable($1,0));*/}
#line 1627 "./build/y.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 135 "./compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); }
#line 1633 "./build/y.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 135 "./compiler.y"
                                                                        {pushScope(); addfuncpara((yyvsp[-3].var_type));if(strcmp("main",(yyvsp[-2].s_var))==0){mainfunction=1;} functionreturn=0;}
#line 1639 "./build/y.tab.c"
    break;

  case 34: /* $@11: %empty  */
#line 135 "./compiler.y"
                                                                                                                                                                                                       { funcsig((yyvsp[-4].s_var)); }
#line 1645 "./build/y.tab.c"
    break;

  case 35: /* $@12: %empty  */
#line 135 "./compiler.y"
                                                                                                                                                                                                                                 {obj=findVariable((yyvsp[-7].s_var),1); code(".method public static %s%s",(yyvsp[-7].s_var),obj->symbol->func_sig); fprintf(yyout, "%*s.limit stack 100\n", scopeLevel << 2, ""); fprintf(yyout, "%*s.limit locals 100\n", scopeLevel << 2, ""); }
#line 1651 "./build/y.tab.c"
    break;

  case 36: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@9 $@10 FunctionParameterStmtList $@11 ')' '{' $@12 StmtList '}'  */
#line 135 "./compiler.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                   {if(functionreturn==0){codeRaw("return");} fprintf(yyout, "%*s.end method\n", scopeLevel << 2, ""); dumpScope(); functionreturn=0;}
#line 1657 "./build/y.tab.c"
    break;

  case 40: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 145 "./compiler.y"
                               { addfuncpara((yyvsp[-3].var_type) * 10); pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_DEFAULT); }
#line 1663 "./build/y.tab.c"
    break;

  case 41: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 146 "./compiler.y"
                       { addfuncpara((yyvsp[-1].var_type)); pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); }
#line 1669 "./build/y.tab.c"
    break;

  case 45: /* Stmt: COUT CoutParmListStmt ';'  */
#line 159 "./compiler.y"
                                 { if(coutnum==1){coutExpr();}stdoutPrint(); clearCout();coutnum=0;}
#line 1675 "./build/y.tab.c"
    break;

  case 46: /* Stmt: RETURN Expression ';'  */
#line 160 "./compiler.y"
                             {functionreturn=1;returncheck((yyvsp[-1].object_val).type);if(inIF==1){if(broken==1){code("elseBegin%d:",neststack[neststacknum]);code("ifEnd%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);code("ifEnd%d:",neststack[neststacknum-1]);inIF=0;}} }
#line 1681 "./build/y.tab.c"
    break;

  case 47: /* Stmt: RETURN ';'  */
#line 161 "./compiler.y"
                 {functionreturn=1; codeRaw("return"); }
#line 1687 "./build/y.tab.c"
    break;

  case 50: /* $@13: %empty  */
#line 164 "./compiler.y"
               { pushScope(); }
#line 1693 "./build/y.tab.c"
    break;

  case 51: /* $@14: %empty  */
#line 164 "./compiler.y"
                                            {code("loopStmt%d:",nestlabel);neststack[neststacknum]=nestlabel;neststacknum++;nestlabel++;}
#line 1699 "./build/y.tab.c"
    break;

  case 52: /* Stmt: FOR '(' $@13 For ')' '{' $@14 StmtList '}'  */
#line 164 "./compiler.y"
                                                                                                                                                       {code("goto controlLoop%d",neststack[neststacknum-1]);code("loop%dEnd:",neststack[neststacknum-1]);neststacknum--; dumpScope(); }
#line 1705 "./build/y.tab.c"
    break;

  case 53: /* $@15: %empty  */
#line 165 "./compiler.y"
            { code("loop%dStart:",nestlabel); neststack[neststacknum]=nestlabel;neststacknum++;nestlabel++;}
#line 1711 "./build/y.tab.c"
    break;

  case 54: /* $@16: %empty  */
#line 165 "./compiler.y"
                                                                                                                                { code("ifeq loop%dEnd",neststack[neststacknum-1]);pushScope(); }
#line 1717 "./build/y.tab.c"
    break;

  case 55: /* Stmt: WHILE $@15 '(' Expression ')' $@16 '{' StmtList '}'  */
#line 165 "./compiler.y"
                                                                                                                                                                                                                   { code("goto loop%dStart",neststack[neststacknum-1]);code("loop%dEnd:",neststack[neststacknum-1]);neststacknum--;dumpScope(); }
#line 1723 "./build/y.tab.c"
    break;

  case 56: /* Stmt: BREAK ';'  */
#line 166 "./compiler.y"
                { code("goto loop%dEnd",neststack[neststacknum-2]);neststacknum--; broken=1;}
#line 1729 "./build/y.tab.c"
    break;

  case 59: /* Stmt: DefineVariableStmt  */
#line 169 "./compiler.y"
                         { array_element_num=0; }
#line 1735 "./build/y.tab.c"
    break;

  case 61: /* $@17: %empty  */
#line 174 "./compiler.y"
             { code("loop%dStart:",nestlabel); }
#line 1741 "./build/y.tab.c"
    break;

  case 62: /* $@18: %empty  */
#line 174 "./compiler.y"
                                                    {code("ifeq loop%dEnd",nestlabel);code("goto loopStmt%d",nestlabel);}
#line 1747 "./build/y.tab.c"
    break;

  case 63: /* $@19: %empty  */
#line 174 "./compiler.y"
                                                                                                                              {code("controlLoop%d:",nestlabel);}
#line 1753 "./build/y.tab.c"
    break;

  case 64: /* For: F1 ';' $@17 F2 $@18 ';' $@19 F3  */
#line 174 "./compiler.y"
                                                                                                                                                                     { code("goto loop%dStart",nestlabel);}
#line 1759 "./build/y.tab.c"
    break;

  case 65: /* For: VARIABLE_T IDENT ':' IDENT  */
#line 175 "./compiler.y"
                                 { obj=findVariable((yyvsp[0].s_var),0); createVariable(obj->type, (yyvsp[-2].s_var), 0); varAddrCheck((yyvsp[0].s_var),0); }
#line 1765 "./build/y.tab.c"
    break;

  case 66: /* F1: VARIABLE_T F1_List1  */
#line 179 "./compiler.y"
                          { currentVarType = (yyvsp[-1].var_type); }
#line 1771 "./build/y.tab.c"
    break;

  case 69: /* F1_List1: F1_List1 ',' IDENT VAL_ASSIGN Expression  */
#line 183 "./compiler.y"
                                               { createVariable(currentVarType, (yyvsp[-2].s_var), 0);  storeMatrix(findVariable((yyvsp[-2].s_var),0));}
#line 1777 "./build/y.tab.c"
    break;

  case 70: /* F1_List1: IDENT VAL_ASSIGN Expression  */
#line 184 "./compiler.y"
                                  { createVariable(currentVarType, (yyvsp[-2].s_var), 0);  storeMatrix(findVariable((yyvsp[-2].s_var),0));}
#line 1783 "./build/y.tab.c"
    break;

  case 71: /* F1_List2: F1_List2 ',' IDENT VAL_ASSIGN Expression  */
#line 186 "./compiler.y"
                                               { storeMatrix(findVariable((yyvsp[-2].s_var),0));}
#line 1789 "./build/y.tab.c"
    break;

  case 72: /* F1_List2: IDENT VAL_ASSIGN Expression  */
#line 187 "./compiler.y"
                                  { storeMatrix(findVariable((yyvsp[-2].s_var),0));}
#line 1795 "./build/y.tab.c"
    break;

  case 77: /* $@20: %empty  */
#line 196 "./compiler.y"
                            {inIF=1; code("ifeq elseBegin%d",nestlabel);neststack[neststacknum]=nestlabel;nestlabel++;neststacknum++; pushScope(); }
#line 1801 "./build/y.tab.c"
    break;

  case 78: /* $@21: %empty  */
#line 196 "./compiler.y"
                                                                                                                                                                      {if(broken==1){code("goto ifEnd%d",neststack[neststacknum]);}else{code("goto ifEnd%d",neststack[neststacknum-1]);} dumpScope(); }
#line 1807 "./build/y.tab.c"
    break;

  case 79: /* $@22: %empty  */
#line 196 "./compiler.y"
                                                                                                                                                                                                                                                                                                        {inIF=0;}
#line 1813 "./build/y.tab.c"
    break;

  case 80: /* IFStmt: IF '(' Expression ')' $@20 '{' StmtList '}' $@21 $@22 ElseStmt  */
#line 196 "./compiler.y"
                                                                                                                                                                                                                                                                                                                          {if(broken==1){code("ifEnd%d:",neststack[neststacknum]);}else{code("ifEnd%d:",neststack[neststacknum-1]);}neststacknum--;broken=0;}
#line 1819 "./build/y.tab.c"
    break;

  case 81: /* $@23: %empty  */
#line 197 "./compiler.y"
                            {inIF=1;code("ifeq elseBegin%d",nestlabel);neststack[neststacknum]=nestlabel;nestlabel++;neststacknum++; }
#line 1825 "./build/y.tab.c"
    break;

  case 82: /* $@24: %empty  */
#line 197 "./compiler.y"
                                                                                                                                                {inIF=0;}
#line 1831 "./build/y.tab.c"
    break;

  case 83: /* IFStmt: IF '(' Expression ')' $@23 StmtList $@24 ElseStmt  */
#line 197 "./compiler.y"
                                                                                                                                                                   {if(broken==1){code("ifEnd%d:",neststack[neststacknum]);}else{code("ifEnd%d:",neststack[neststacknum-1]);}neststacknum--;broken=0;}
#line 1837 "./build/y.tab.c"
    break;

  case 84: /* $@25: %empty  */
#line 200 "./compiler.y"
           {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);} pushScope(); }
#line 1843 "./build/y.tab.c"
    break;

  case 85: /* ElseStmt: ELSE $@25 '{' StmtList '}'  */
#line 200 "./compiler.y"
                                                                                                                                                              { dumpScope(); }
#line 1849 "./build/y.tab.c"
    break;

  case 86: /* $@26: %empty  */
#line 201 "./compiler.y"
           {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);}}
#line 1855 "./build/y.tab.c"
    break;

  case 88: /* ElseStmt: %empty  */
#line 202 "./compiler.y"
      {if(broken==1){code("elseBegin%d:",neststack[neststacknum]);}else{code("elseBegin%d:",neststack[neststacknum-1]);}}
#line 1861 "./build/y.tab.c"
    break;

  case 89: /* $@27: %empty  */
#line 206 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);}
#line 1867 "./build/y.tab.c"
    break;

  case 90: /* IdentAssign: IDENT $@27 VAL_ASSIGN Expression  */
#line 206 "./compiler.y"
                                                                {obj = findVariable((yyvsp[-3].s_var),0);if((yyvsp[0].object_val).type==OBJECT_TYPE_INT&&obj->type==OBJECT_TYPE_FLOAT){codeRaw("i2f");}else if((yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT&&obj->type==OBJECT_TYPE_INT){codeRaw("f2i");} storeMatrix(findVariable((yyvsp[-3].s_var),0)); }
#line 1873 "./build/y.tab.c"
    break;

  case 91: /* $@28: %empty  */
#line 207 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1879 "./build/y.tab.c"
    break;

  case 92: /* IdentAssign: IDENT $@28 ADD_ASSIGN Expression  */
#line 207 "./compiler.y"
                                                                                                     {  if((yyvsp[0].object_val).type==OBJECT_TYPE_INT){codeRaw("iadd");}else if((yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){codeRaw("fadd");}storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1885 "./build/y.tab.c"
    break;

  case 93: /* $@29: %empty  */
#line 208 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1891 "./build/y.tab.c"
    break;

  case 94: /* IdentAssign: IDENT $@29 SUB_ASSIGN Expression  */
#line 208 "./compiler.y"
                                                                                                     {  if((yyvsp[0].object_val).type==OBJECT_TYPE_INT){codeRaw("isub");}else if((yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){codeRaw("fsub");}storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1897 "./build/y.tab.c"
    break;

  case 95: /* $@30: %empty  */
#line 209 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1903 "./build/y.tab.c"
    break;

  case 96: /* IdentAssign: IDENT $@30 MUL_ASSIGN Expression  */
#line 209 "./compiler.y"
                                                                                                     {  if((yyvsp[0].object_val).type==OBJECT_TYPE_INT){codeRaw("imul");}else if((yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){codeRaw("fmul");}storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1909 "./build/y.tab.c"
    break;

  case 97: /* $@31: %empty  */
#line 210 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1915 "./build/y.tab.c"
    break;

  case 98: /* IdentAssign: IDENT $@31 DIV_ASSIGN Expression  */
#line 210 "./compiler.y"
                                                                                                     {  if((yyvsp[0].object_val).type==OBJECT_TYPE_INT){codeRaw("idiv");}else if((yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){codeRaw("fdiv");}storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1921 "./build/y.tab.c"
    break;

  case 99: /* $@32: %empty  */
#line 211 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1927 "./build/y.tab.c"
    break;

  case 100: /* IdentAssign: IDENT $@32 SHR_ASSIGN Expression  */
#line 211 "./compiler.y"
                                                                                                     {  codeRaw("ishr");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1933 "./build/y.tab.c"
    break;

  case 101: /* $@33: %empty  */
#line 212 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);loadMatrix(findVariable((yyvsp[0].s_var),0),array);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1939 "./build/y.tab.c"
    break;

  case 102: /* IdentAssign: IDENT $@33 SHL_ASSIGN Expression  */
#line 212 "./compiler.y"
                                                                                                                                                                               {  codeRaw("ishl");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1945 "./build/y.tab.c"
    break;

  case 103: /* $@34: %empty  */
#line 213 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1951 "./build/y.tab.c"
    break;

  case 104: /* IdentAssign: IDENT $@34 BOR_ASSIGN Expression  */
#line 213 "./compiler.y"
                                                                                                     {  codeRaw("ior");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1957 "./build/y.tab.c"
    break;

  case 105: /* $@35: %empty  */
#line 214 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1963 "./build/y.tab.c"
    break;

  case 106: /* IdentAssign: IDENT $@35 BAN_ASSIGN Expression  */
#line 214 "./compiler.y"
                                                                                                     {  codeRaw("iand");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1969 "./build/y.tab.c"
    break;

  case 107: /* $@36: %empty  */
#line 215 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1975 "./build/y.tab.c"
    break;

  case 108: /* IdentAssign: IDENT $@36 BXO_ASSIGN Expression  */
#line 215 "./compiler.y"
                                                                                                     {  codeRaw("ixor");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1981 "./build/y.tab.c"
    break;

  case 109: /* $@37: %empty  */
#line 216 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);}
#line 1987 "./build/y.tab.c"
    break;

  case 110: /* IdentAssign: IDENT $@37 REM_ASSIGN Expression  */
#line 216 "./compiler.y"
                                                                                                     {  codeRaw("irem");storeMatrix(findVariable((yyvsp[-3].s_var),0));}
#line 1993 "./build/y.tab.c"
    break;

  case 111: /* $@38: %empty  */
#line 217 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);}
#line 1999 "./build/y.tab.c"
    break;

  case 112: /* IdentAssign: IDENT $@38 INC_ASSIGN  */
#line 217 "./compiler.y"
                                                     {obj=findVariable((yyvsp[-2].s_var),0); code("iinc %ld %d",obj->symbol->addr,1); }
#line 2005 "./build/y.tab.c"
    break;

  case 113: /* $@39: %empty  */
#line 218 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0);}
#line 2011 "./build/y.tab.c"
    break;

  case 114: /* IdentAssign: IDENT $@39 DEC_ASSIGN  */
#line 218 "./compiler.y"
                                                     { obj=findVariable((yyvsp[-2].s_var),0); code("iinc %ld %d",obj->symbol->addr,-1); }
#line 2017 "./build/y.tab.c"
    break;

  case 115: /* $@40: %empty  */
#line 224 "./compiler.y"
                           {coutExpr();codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");}
#line 2023 "./build/y.tab.c"
    break;

  case 116: /* CoutParmListStmt: CoutParmListStmt SHL $@40 Expression  */
#line 224 "./compiler.y"
                                                                                                                    { insertCout((yyvsp[0].object_val).type);coutnum++;}
#line 2029 "./build/y.tab.c"
    break;

  case 117: /* $@41: %empty  */
#line 225 "./compiler.y"
          {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");}
#line 2035 "./build/y.tab.c"
    break;

  case 118: /* CoutParmListStmt: SHL $@41 Expression  */
#line 225 "./compiler.y"
                                                                                        { insertCout((yyvsp[0].object_val).type); coutnum++;}
#line 2041 "./build/y.tab.c"
    break;

  case 120: /* Callfunction: IDENT '(' Funcparameter ')'  */
#line 233 "./compiler.y"
                                  { varAddrCheck((yyvsp[-3].s_var),1); IdentType(&(yyval.object_val), (yyvsp[-3].s_var),1); obj = findVariable((yyvsp[-3].s_var),1); printf("call: %s%s\n",(yyvsp[-3].s_var),obj->symbol->func_sig); code("invokestatic Main/%s%s",(yyvsp[-3].s_var),obj->symbol->func_sig);}
#line 2047 "./build/y.tab.c"
    break;

  case 125: /* LORExpression: LORExpression LOR LANExpression  */
#line 244 "./compiler.y"
                                      { printf("LOR\n"); ExpressionType('l',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("ior"); operatecheck=1;}
#line 2053 "./build/y.tab.c"
    break;

  case 127: /* LANExpression: LANExpression LAN BitwiseExpression  */
#line 249 "./compiler.y"
                                          { printf("LAN\n"); ExpressionType('l',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("iand");operatecheck=1;}
#line 2059 "./build/y.tab.c"
    break;

  case 129: /* BitwiseExpression: BitwiseExpression BOR RelationalExpression  */
#line 254 "./compiler.y"
                                                 { printf("BOR\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("ior");operatecheck=1;}
#line 2065 "./build/y.tab.c"
    break;

  case 130: /* BitwiseExpression: BitwiseExpression BXO RelationalExpression  */
#line 255 "./compiler.y"
                                                 { printf("BXO\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("ixor");operatecheck=1;}
#line 2071 "./build/y.tab.c"
    break;

  case 131: /* BitwiseExpression: BitwiseExpression BAN RelationalExpression  */
#line 256 "./compiler.y"
                                                 { printf("BAN\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("iand");operatecheck=1;}
#line 2077 "./build/y.tab.c"
    break;

  case 132: /* BitwiseExpression: BitwiseExpression BNT RelationalExpression  */
#line 257 "./compiler.y"
                                                 { printf("BNT\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;}
#line 2083 "./build/y.tab.c"
    break;

  case 134: /* RelationalExpression: RelationalExpression EQL ShiftExpression  */
#line 262 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;code("if_icmpeq EqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label);code("EqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;}
#line 2089 "./build/y.tab.c"
    break;

  case 135: /* RelationalExpression: RelationalExpression NEQ ShiftExpression  */
#line 263 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;code("if_icmpne notEqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label);code("notEqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;}
#line 2095 "./build/y.tab.c"
    break;

  case 136: /* RelationalExpression: RelationalExpression LES ShiftExpression  */
#line 264 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;code("if_icmplt lessThanLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label); code("lessThanLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;}
#line 2101 "./build/y.tab.c"
    break;

  case 137: /* RelationalExpression: RelationalExpression LEQ ShiftExpression  */
#line 265 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;}
#line 2107 "./build/y.tab.c"
    break;

  case 138: /* RelationalExpression: RelationalExpression GTR ShiftExpression  */
#line 266 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;if((yyvsp[-2].object_val).type==OBJECT_TYPE_INT&&(yyvsp[0].object_val).type==(yyvsp[-2].object_val).type){code("if_icmpgt greaterThanLabel%d",label);}else{codeRaw("fcmpg");code("ifgt greaterThanLabel%d",label);}codeRaw("iconst_0");code("goto endLabel%d",label); code("greaterThanLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;}
#line 2113 "./build/y.tab.c"
    break;

  case 139: /* RelationalExpression: RelationalExpression GEQ ShiftExpression  */
#line 267 "./compiler.y"
                                               {  ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); operatecheck=1;code("if_icmpge greaterThanOrEqualToLabel%d",label);codeRaw("iconst_0");code("goto endLabel%d",label); code("greaterThanOrEqualToLabel%d:",label);codeRaw("iconst_1");code("endLabel%d:",label);label++;}
#line 2119 "./build/y.tab.c"
    break;

  case 141: /* ShiftExpression: ShiftExpression SHR AdditiveExpression  */
#line 272 "./compiler.y"
                                             { ExpressionType('s',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); codeRaw("ishr");operatecheck=1;}
#line 2125 "./build/y.tab.c"
    break;

  case 143: /* AdditiveExpression: AdditiveExpression ADD MultiplicativeExpression  */
#line 277 "./compiler.y"
                                                      { ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));operatecheck=1; if((yyval.object_val).type==OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");}}
#line 2131 "./build/y.tab.c"
    break;

  case 144: /* AdditiveExpression: AdditiveExpression SUB MultiplicativeExpression  */
#line 278 "./compiler.y"
                                                      { ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));operatecheck=1; if((yyval.object_val).type==OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");}}
#line 2137 "./build/y.tab.c"
    break;

  case 146: /* MultiplicativeExpression: MultiplicativeExpression MUL CastExpression  */
#line 283 "./compiler.y"
                                                  { ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));operatecheck=1; if((yyval.object_val).type==OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");}}
#line 2143 "./build/y.tab.c"
    break;

  case 147: /* MultiplicativeExpression: MultiplicativeExpression DIV CastExpression  */
#line 284 "./compiler.y"
                                                  { ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));operatecheck=1; if((yyval.object_val).type==OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");}}
#line 2149 "./build/y.tab.c"
    break;

  case 148: /* MultiplicativeExpression: MultiplicativeExpression REM CastExpression  */
#line 285 "./compiler.y"
                                                  { ExpressionType('s',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));operatecheck=1; codeRaw("irem");}
#line 2155 "./build/y.tab.c"
    break;

  case 150: /* CastExpression: '(' VARIABLE_T ')' CastExpression  */
#line 290 "./compiler.y"
                                        { Cast((yyvsp[-2].var_type)); (yyval.object_val).type = (yyvsp[-2].var_type); if((yyval.object_val).type==OBJECT_TYPE_INT&&(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){codeRaw("f2i");}else if((yyval.object_val).type==OBJECT_TYPE_FLOAT&&(yyvsp[0].object_val).type==OBJECT_TYPE_INT){codeRaw("i2f");}else{codeRaw("i2f");}}
#line 2161 "./build/y.tab.c"
    break;

  case 152: /* UnaryExpression: NOT UnaryExpression  */
#line 295 "./compiler.y"
                          { (yyval.object_val).type = (yyvsp[0].object_val).type;operatecheck=1;codeRaw("iconst_1");codeRaw("ixor");}
#line 2167 "./build/y.tab.c"
    break;

  case 153: /* UnaryExpression: BNT UnaryExpression  */
#line 296 "./compiler.y"
                          { (yyval.object_val).type = (yyvsp[0].object_val).type; operatecheck=1;codeRaw("iconst_m1");codeRaw("ixor");}
#line 2173 "./build/y.tab.c"
    break;

  case 154: /* UnaryExpression: SUB UnaryExpression  */
#line 297 "./compiler.y"
                          { (yyval.object_val).type = (yyvsp[0].object_val).type; operatecheck=1;if((yyval.object_val).type==OBJECT_TYPE_INT){codeRaw("ineg");}else{codeRaw("fneg");}}
#line 2179 "./build/y.tab.c"
    break;

  case 156: /* PrimaryExpression: INT_LIT  */
#line 302 "./compiler.y"
              {  (yyval.object_val).type = OBJECT_TYPE_INT; if(functionreturn != 1){fprintf(yyout, "%*sldc %d\n", scopeLevel << 2, "", (yyvsp[0].i_var));} }
#line 2185 "./build/y.tab.c"
    break;

  case 157: /* PrimaryExpression: FLOAT_LIT  */
#line 303 "./compiler.y"
                { (yyval.object_val).type = OBJECT_TYPE_FLOAT; fprintf(yyout, "%*sldc %f\n", scopeLevel << 2, "", (yyvsp[0].f_var)); }
#line 2191 "./build/y.tab.c"
    break;

  case 158: /* PrimaryExpression: BOOL_LIT  */
#line 304 "./compiler.y"
               { (yyval.object_val).type = OBJECT_TYPE_BOOL; if((yyvsp[0].b_var)){codeRaw("iconst_1");}else{codeRaw("iconst_0");}}
#line 2197 "./build/y.tab.c"
    break;

  case 159: /* PrimaryExpression: IDENT  */
#line 305 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0); IdentType(&(yyval.object_val), (yyvsp[0].s_var),0);if(strcmp("endl",(yyvsp[0].s_var))==0){codeRaw("invokevirtual java/io/PrintStream.println()V");}else{loadMatrix(findVariable((yyvsp[0].s_var),0),array);} }
#line 2203 "./build/y.tab.c"
    break;

  case 160: /* PrimaryExpression: STR_LIT  */
#line 306 "./compiler.y"
              {  (yyval.object_val).type = OBJECT_TYPE_STR; fprintf(yyout, "%*sldc \"%s\"\n", scopeLevel << 2, "", (yyvsp[0].s_var)); }
#line 2209 "./build/y.tab.c"
    break;

  case 161: /* PrimaryExpression: CHAR_LIT  */
#line 307 "./compiler.y"
               {  (yyval.object_val).type = OBJECT_TYPE_CHAR;  fprintf(yyout, "%*sldc \"%c\"\n", scopeLevel << 2, "", (yyvsp[0].c_var));}
#line 2215 "./build/y.tab.c"
    break;

  case 162: /* PrimaryExpression: '(' Expression ')'  */
#line 308 "./compiler.y"
                         { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 2221 "./build/y.tab.c"
    break;

  case 163: /* PrimaryExpression: ArrayIdent '[' Expression ']'  */
#line 309 "./compiler.y"
                                     { codeRaw("iaload");}
#line 2227 "./build/y.tab.c"
    break;

  case 164: /* $@42: %empty  */
#line 310 "./compiler.y"
                                     {codeRaw("aaload");}
#line 2233 "./build/y.tab.c"
    break;

  case 165: /* PrimaryExpression: ArrayIdent '[' Expression ']' $@42 '[' Expression ']'  */
#line 310 "./compiler.y"
                                                                             { codeRaw("iaload"); }
#line 2239 "./build/y.tab.c"
    break;

  case 167: /* ArrayIdent: IDENT  */
#line 314 "./compiler.y"
          {array=1; varAddrCheck((yyvsp[0].s_var),0); IdentType(&(yyval.object_val), (yyvsp[0].s_var),0);loadMatrix(findVariable((yyvsp[0].s_var),0),array);array=0;}
#line 2245 "./build/y.tab.c"
    break;


#line 2249 "./build/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 315 "./compiler.y"

//fprintf(yyout, "%*siload %s\n", scopeLevel << 2, "", $<s_var>1);
//varAddrCheck($<s_var>1,0); IdentType(&$<object_val>$, $<s_var>1,0);
