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
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"
    ObjectType currentVarType;
    int yydebug = 1;
    int array_element_num=0;
    Object* obj;
    int autotype=0;

#line 82 "./build/y.tab.c"

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
  YYSYMBOL_VARIABLE_T = 44,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_STR_LIT = 46,                   /* STR_LIT  */
  YYSYMBOL_INT_LIT = 47,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 48,                 /* FLOAT_LIT  */
  YYSYMBOL_BOOL_LIT = 49,                  /* BOOL_LIT  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Program = 60,                   /* Program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 62,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 63,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 64,        /* DefineVariableStmt  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_IdentList = 66,                 /* IdentList  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_InitializerList = 68,           /* InitializerList  */
  YYSYMBOL_FunctionDefStmt = 69,           /* FunctionDefStmt  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_72_6 = 72,                      /* $@6  */
  YYSYMBOL_FunctionParameterStmtList = 73, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 74,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 75,                  /* StmtList  */
  YYSYMBOL_Stmt = 76,                      /* Stmt  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_For = 82,                       /* For  */
  YYSYMBOL_F1 = 83,                        /* F1  */
  YYSYMBOL_F1_List1 = 84,                  /* F1_List1  */
  YYSYMBOL_F1_List2 = 85,                  /* F1_List2  */
  YYSYMBOL_F2 = 86,                        /* F2  */
  YYSYMBOL_F3 = 87,                        /* F3  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_IFStmt = 89,                    /* IFStmt  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_91_14 = 91,                     /* $@14  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_ElseStmt = 93,                  /* ElseStmt  */
  YYSYMBOL_94_16 = 94,                     /* $@16  */
  YYSYMBOL_95_17 = 95,                     /* $@17  */
  YYSYMBOL_IdentAssign = 96,               /* IdentAssign  */
  YYSYMBOL_ArrayAssignmentStmt = 97,       /* ArrayAssignmentStmt  */
  YYSYMBOL_98_18 = 98,                     /* $@18  */
  YYSYMBOL_99_19 = 99,                     /* $@19  */
  YYSYMBOL_CoutParmListStmt = 100,         /* CoutParmListStmt  */
  YYSYMBOL_Expression = 101,               /* Expression  */
  YYSYMBOL_Callfunction = 102,             /* Callfunction  */
  YYSYMBOL_Funcparameter = 103,            /* Funcparameter  */
  YYSYMBOL_FuncparameterList = 104,        /* FuncparameterList  */
  YYSYMBOL_LORExpression = 105,            /* LORExpression  */
  YYSYMBOL_LANExpression = 106,            /* LANExpression  */
  YYSYMBOL_BitwiseExpression = 107,        /* BitwiseExpression  */
  YYSYMBOL_RelationalExpression = 108,     /* RelationalExpression  */
  YYSYMBOL_ShiftExpression = 109,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 110,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 111, /* MultiplicativeExpression  */
  YYSYMBOL_CastExpression = 112,           /* CastExpression  */
  YYSYMBOL_UnaryExpression = 113,          /* UnaryExpression  */
  YYSYMBOL_PrimaryExpression = 114         /* PrimaryExpression  */
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
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      50,    51,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    62,    63,    67,    68,    72,    73,    77,
      77,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      89,    90,    95,    96,    97,   102,   102,   102,   102,   105,
     106,   107,   110,   111,   116,   117,   121,   122,   123,   124,
     125,   125,   126,   127,   127,   127,   128,   128,   128,   129,
     130,   131,   132,   133,   138,   139,   142,   143,   144,   146,
     147,   149,   150,   152,   153,   155,   155,   156,   159,   159,
     159,   160,   160,   163,   163,   164,   164,   165,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   184,   184,   185,   185,   189,   190,   196,   200,   203,
     204,   206,   207,   209,   210,   213,   214,   218,   219,   220,
     221,   222,   227,   228,   229,   230,   231,   232,   233,   236,
     237,   241,   242,   243,   247,   248,   249,   250,   253,   254,
     257,   258,   259,   260,   264,   265,   266,   267,   268,   269,
     270,   271,   272
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
  "BREAK", "CONTINUE", "VARIABLE_T", "IDENT", "STR_LIT", "INT_LIT",
  "FLOAT_LIT", "BOOL_LIT", "'('", "')'", "'['", "']'", "':'", "';'", "','",
  "'{'", "'}'", "$accept", "Program", "$@1", "GlobalStmtList",
  "GlobalStmt", "DefineVariableStmt", "$@2", "IdentList", "$@3",
  "InitializerList", "FunctionDefStmt", "$@4", "$@5", "$@6",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@7", "$@8", "$@9", "$@10", "$@11", "For", "F1", "F1_List1", "F1_List2",
  "F2", "F3", "$@12", "IFStmt", "$@13", "$@14", "$@15", "ElseStmt", "$@16",
  "$@17", "IdentAssign", "ArrayAssignmentStmt", "$@18", "$@19",
  "CoutParmListStmt", "Expression", "Callfunction", "Funcparameter",
  "FuncparameterList", "LORExpression", "LANExpression",
  "BitwiseExpression", "RelationalExpression", "ShiftExpression",
  "AdditiveExpression", "MultiplicativeExpression", "CastExpression",
  "UnaryExpression", "PrimaryExpression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    48,    36,  -132,    41,    36,  -132,  -132,  -132,    39,
      60,  -132,  -132,   -21,   -38,  -132,   256,    52,  -132,    62,
      72,   271,   271,   271,   -42,  -132,  -132,  -132,  -132,   248,
    -132,  -132,    96,    99,    54,     4,   119,    92,    70,  -132,
    -132,  -132,    73,   -18,    80,    68,  -132,   256,  -132,  -132,
    -132,   256,   256,    78,    85,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   -15,   256,    91,    97,    72,   101,  -132,
     102,    94,    95,   256,  -132,    99,    54,     4,     4,     4,
       4,   119,   119,   119,   119,   119,   119,    92,    70,    70,
    -132,  -132,  -132,   107,   133,  -132,   103,   117,  -132,   121,
    -132,   256,   127,  -132,   128,   125,   -13,  -132,   210,  -132,
     256,  -132,   256,   126,   137,   180,   136,  -132,  -132,   228,
     138,   139,  -132,    14,  -132,  -132,     1,  -132,  -132,   140,
     141,   135,   -28,  -132,   256,   144,   256,     2,   256,   142,
     148,  -132,   145,  -132,  -132,   256,   298,  -132,  -132,  -132,
    -132,  -132,   256,  -132,    40,  -132,  -132,   256,  -132,   150,
    -132,   256,  -132,   149,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,  -132,  -132,   151,  -132,  -132,
    -132,   134,    65,   152,   156,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,   147,   210,   164,
     188,   159,   178,   181,  -132,   256,   214,   210,   186,   -22,
     189,   256,   185,   256,   199,   191,   204,   256,    10,   221,
    -132,   256,   215,   216,  -132,   210,   207,  -132,   242,   210,
    -132,  -132,  -132,   211,   232,  -132,  -132,   246,    30,   227,
     256,   132,   257,   247,   210,  -132,   256,  -132,  -132,  -132,
    -132,  -132,   256,  -132,   177,  -132,   298,  -132,  -132,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     7,     8,     0,
       0,     5,    25,    11,     0,    26,     0,     0,    10,     0,
      31,     0,     0,     0,   137,   138,   134,   135,   136,     0,
      13,   142,    97,   104,   106,   111,   118,   120,   123,   127,
     129,   133,     0,    12,     0,    27,    30,     0,   131,   132,
     130,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    33,     0,     0,   102,
       0,    99,     0,     0,   139,   103,   105,   109,   107,   110,
     108,   116,   114,   117,   115,   112,   113,   119,   121,   122,
     124,   125,   126,     0,     0,    14,     0,     0,    29,     0,
      98,     0,   140,   128,     0,     0,    16,    32,     0,   101,
       0,    17,    24,     0,     0,     0,     0,    43,    46,     0,
       0,     0,     9,    40,    36,    52,     0,    35,    42,     0,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
       0,    39,     0,    49,    50,     0,     0,    28,    34,    51,
      53,   141,     0,    20,     0,    18,    96,     0,    37,     0,
      44,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,     0,    22,    21,
      95,    71,    58,     0,    91,    78,    79,    80,    81,    82,
      88,    86,    85,    87,    83,    84,    41,     0,     0,     0,
       0,     0,     0,    57,    47,     0,     0,     0,    77,     0,
      56,     0,     0,    64,     0,     0,     0,     0,     0,    73,
      72,     0,     0,     0,    62,     0,     0,    63,     0,     0,
      93,    92,    69,     0,     0,    60,    55,     0,     0,    67,
       0,     0,     0,    77,     0,    76,     0,    45,    65,    54,
      61,    48,     0,    70,     0,    59,     0,    94,    74,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   275,    24,  -132,  -132,  -132,   143,
    -132,  -132,  -132,  -132,  -132,   212,  -127,  -131,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
      44,  -132,  -132,  -132,    31,  -132,  -132,    25,  -132,  -132,
    -132,  -132,   -16,  -117,  -132,  -132,  -132,   235,   243,    19,
      79,   233,    46,   -56,    71,  -132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,   135,    10,    14,   104,   142,
       8,    15,    20,    78,    45,    46,   136,   137,   156,   149,
     192,   150,   225,   211,   212,   220,   213,   236,   259,   266,
     138,   207,   253,   208,   230,   243,   244,   187,   139,   216,
     252,   147,    54,    31,    80,    81,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   140,   231,    16,   125,   158,    74,   167,    51,   -19,
      52,   123,    -4,   125,   100,   101,   102,    18,    19,   140,
      61,    62,    63,    64,    65,    66,     7,   113,   162,     7,
     163,    17,   232,   125,    75,    79,    82,   103,   126,   124,
     127,   128,   129,   130,   131,   132,   133,   126,     3,   127,
     128,   129,   130,   131,   132,   133,   134,   168,   105,   157,
      57,    58,    59,    60,    51,   134,   155,   126,   242,   127,
     128,   129,   130,   131,   132,   133,    87,    88,    89,    90,
       4,   218,    70,    71,    72,   134,     9,   158,   257,    12,
     228,   140,    48,    49,    50,   119,   162,   158,   189,    42,
     140,   140,    68,    69,   141,    13,   143,    43,   248,   209,
     210,   140,   251,   152,    98,    99,    44,   158,   140,    55,
     158,    56,   140,    67,    77,    76,    73,   264,   143,    83,
     166,   140,   169,   158,   140,   125,    84,   140,   106,   173,
      91,    92,    93,    94,    95,    96,   188,   140,   112,   107,
     111,   190,   109,   110,   114,   193,   116,   115,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   126,
     117,   127,   128,   129,   130,   131,   132,   133,   118,   120,
     125,   121,   122,   144,   145,   146,   148,   134,   161,   125,
     261,   -68,   170,   153,   154,   159,   160,   165,   171,   226,
     172,   191,   194,   214,   217,   234,   206,   237,   215,   219,
     222,   241,   221,   125,   126,   245,   127,   128,   129,   130,
     131,   132,   133,   126,   229,   127,   128,   129,   130,   131,
     132,   133,   134,   223,   260,   268,    21,   224,   227,    22,
     265,   134,   235,    23,   238,   233,   267,   126,   239,   127,
     128,   129,   130,   131,   132,   133,    21,   240,   -75,    22,
     246,   247,   249,    23,    21,   134,   250,    22,   254,   126,
     256,    23,   258,    24,    25,    26,    27,    28,    29,    21,
      11,   262,    22,   151,   263,   229,    23,   164,   255,   108,
      85,   269,    53,    24,    25,    26,    27,    28,    29,    86,
      97,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    47,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186
};

static const yytype_int16 yycheck[] =
{
      16,   118,    24,    24,     3,   136,    24,     5,    50,    24,
      52,    24,     0,     3,    70,    71,    72,    55,    56,   136,
      16,    17,    18,    19,    20,    21,     2,    83,    56,     5,
      58,    52,    54,     3,    52,    51,    52,    52,    37,    52,
      39,    40,    41,    42,    43,    44,    45,    37,     0,    39,
      40,    41,    42,    43,    44,    45,    55,    55,    74,    58,
       6,     7,     8,     9,    50,    55,    52,    37,    58,    39,
      40,    41,    42,    43,    44,    45,    57,    58,    59,    60,
      44,   208,    12,    13,    14,    55,    45,   218,    58,    50,
     217,   208,    21,    22,    23,   111,    56,   228,    58,    47,
     217,   218,    10,    11,   120,    45,   122,    45,   235,    44,
      45,   228,   239,   129,    68,    69,    44,   248,   235,    23,
     251,    22,   239,     4,    56,    45,    53,   254,   144,    51,
     146,   248,   148,   264,   251,     3,    51,   254,    47,   155,
      61,    62,    63,    64,    65,    66,   162,   264,    53,    52,
      56,   167,    51,    51,    47,   171,    53,    24,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    37,
      53,    39,    40,    41,    42,    43,    44,    45,    57,    52,
       3,    53,    57,    57,    47,     5,    50,    55,    53,     3,
      58,    57,    50,    55,    55,    55,    55,    53,    50,   215,
      55,    51,    53,    51,    57,   221,    55,   223,    52,    45,
      51,   227,    24,     3,    37,   231,    39,    40,    41,    42,
      43,    44,    45,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    55,    55,   250,    58,     8,    56,    24,    11,
     256,    55,    57,    15,    45,    56,   262,    37,    57,    39,
      40,    41,    42,    43,    44,    45,     8,    53,    37,    11,
      45,    45,    55,    15,     8,    55,    24,    11,    57,    37,
      24,    15,    45,    45,    46,    47,    48,    49,    50,     8,
       5,    24,    11,    55,   253,    38,    15,   144,   244,    77,
      55,   266,    44,    45,    46,    47,    48,    49,    50,    56,
      67,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,    44,    62,    63,    64,    69,    45,
      65,    63,    50,    45,    66,    70,    24,    52,    55,    56,
      71,     8,    11,    15,    45,    46,    47,    48,    49,    50,
     101,   102,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    47,    45,    44,    73,    74,    50,   113,   113,
     113,    50,    52,    44,   101,    23,    22,     6,     7,     8,
       9,    16,    17,    18,    19,    20,    21,     4,    10,    11,
      12,    13,    14,    53,    24,    52,    45,    56,    72,   101,
     103,   104,   101,    51,    51,   106,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   109,   110,   111,   111,
     112,   112,   112,    52,    67,   101,    47,    52,    74,    51,
      51,    56,    53,   112,    47,    24,    53,    53,    57,   101,
      52,    53,    57,    24,    52,     3,    37,    39,    40,    41,
      42,    43,    44,    45,    55,    64,    75,    76,    89,    97,
     102,   101,    68,   101,    57,    47,     5,   100,    50,    78,
      80,    55,   101,    55,    55,    52,    77,    58,    76,    55,
      55,    53,    56,    58,    68,    53,   101,     5,    55,   101,
      50,    50,    55,   101,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    96,   101,    58,
     101,    51,    79,   101,    53,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    55,    90,    92,    44,
      45,    82,    83,    85,    51,    52,    98,    57,    75,    45,
      84,    24,    51,    55,    56,    81,   101,    24,    75,    38,
      93,    24,    54,    56,   101,    57,    86,   101,    45,    57,
      53,   101,    58,    94,    95,   101,    45,    45,    75,    55,
      24,    75,    99,    91,    57,    89,    24,    58,    45,    87,
     101,    58,    24,    93,    75,   101,    88,   101,    58,    96
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    60,    62,    62,    63,    63,    65,
      64,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      66,    66,    68,    68,    68,    70,    71,    72,    69,    73,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      77,    76,    76,    78,    79,    76,    80,    81,    76,    76,
      76,    76,    76,    76,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    88,    87,    87,    90,    91,
      89,    92,    89,    94,    93,    95,    93,    93,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    98,    97,    99,    97,   100,   100,   101,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       4,     1,     3,     3,     5,     4,     6,     7,     9,     0,
       9,    10,     3,     1,     0,     0,     0,     0,    11,     3,
       1,     0,     4,     2,     2,     1,     1,     3,     3,     2,
       0,     4,     1,     0,     0,     9,     0,     0,     9,     2,
       2,     2,     1,     2,     5,     4,     2,     1,     0,     5,
       3,     5,     3,     1,     0,     0,     3,     0,     0,     0,
      10,     0,     7,     0,     5,     0,     3,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     0,     7,     0,    10,     3,     2,     1,     4,     1,
       0,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     4,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     7,     1
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
#line 62 "./compiler.y"
      { pushScope(); }
#line 1388 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 62 "./compiler.y"
                                      { dumpScope(); }
#line 1394 "./build/y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 77 "./compiler.y"
                 { currentVarType = (yyvsp[0].var_type); }
#line 1400 "./build/y.tab.c"
    break;

  case 11: /* IdentList: IDENT  */
#line 81 "./compiler.y"
            { createVariable(currentVarType, (yyvsp[0].s_var), 0); }
#line 1406 "./build/y.tab.c"
    break;

  case 12: /* IdentList: IdentList ',' IDENT  */
#line 82 "./compiler.y"
                           { createVariable(currentVarType, (yyvsp[0].s_var), 0); }
#line 1412 "./build/y.tab.c"
    break;

  case 13: /* IdentList: IDENT VAL_ASSIGN Expression  */
#line 83 "./compiler.y"
                                  {if(currentVarType==1){currentVarType=(yyvsp[0].object_val).type;} createVariable(currentVarType, (yyvsp[-2].s_var), 0); }
#line 1418 "./build/y.tab.c"
    break;

  case 14: /* IdentList: IdentList ',' IDENT VAL_ASSIGN Expression  */
#line 84 "./compiler.y"
                                                 {if(currentVarType==1){currentVarType=(yyvsp[0].object_val).type;} createVariable(currentVarType, (yyvsp[-2].s_var), 0); }
#line 1424 "./build/y.tab.c"
    break;

  case 15: /* IdentList: IDENT '[' INT_LIT ']'  */
#line 85 "./compiler.y"
                              {printf("INT_LIT %d\n", (yyvsp[-1].i_var));printf("create array: %d\n",array_element_num); createVariable(currentVarType, (yyvsp[-3].s_var), 0); }
#line 1430 "./build/y.tab.c"
    break;

  case 16: /* IdentList: IdentList ',' IDENT '[' INT_LIT ']'  */
#line 86 "./compiler.y"
                                           { createVariable(currentVarType, (yyvsp[-3].s_var), 0); }
#line 1436 "./build/y.tab.c"
    break;

  case 17: /* IdentList: IDENT '[' INT_LIT ']' '[' INT_LIT ']'  */
#line 87 "./compiler.y"
                                             {printf("INT_LIT %d\n", (yyvsp[-4].i_var));printf("INT_LIT %d\n", (yyvsp[-3].i_var)); createVariable(currentVarType, (yyvsp[-6].s_var), 0); }
#line 1442 "./build/y.tab.c"
    break;

  case 18: /* IdentList: IdentList ',' IDENT '[' INT_LIT ']' '[' INT_LIT ']'  */
#line 88 "./compiler.y"
                                                           {printf("INT_LIT %d\n", (yyvsp[-4].i_var));printf("INT_LIT %d\n", (yyvsp[-1].i_var)); createVariable(currentVarType, (yyvsp[-6].s_var), 0); }
#line 1448 "./build/y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 89 "./compiler.y"
                              {printf("INT_LIT %d\n", (yyvsp[-1].i_var));}
#line 1454 "./build/y.tab.c"
    break;

  case 20: /* IdentList: IDENT '[' INT_LIT ']' $@3 VAL_ASSIGN '{' InitializerList '}'  */
#line 89 "./compiler.y"
                                                                                                       {printf("create array: %d\n",array_element_num); createVariable(currentVarType, (yyvsp[-8].s_var), 0);  }
#line 1460 "./build/y.tab.c"
    break;

  case 21: /* IdentList: IdentList ',' IDENT '[' INT_LIT ']' VAL_ASSIGN '{' InitializerList '}'  */
#line 90 "./compiler.y"
                                                                             { createVariable(currentVarType, (yyvsp[-7].s_var), 0); }
#line 1466 "./build/y.tab.c"
    break;

  case 22: /* InitializerList: InitializerList ',' Expression  */
#line 95 "./compiler.y"
                                     {array_element_num++;}
#line 1472 "./build/y.tab.c"
    break;

  case 23: /* InitializerList: Expression  */
#line 96 "./compiler.y"
                 {array_element_num++;}
#line 1478 "./build/y.tab.c"
    break;

  case 25: /* $@4: %empty  */
#line 102 "./compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); }
#line 1484 "./build/y.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 102 "./compiler.y"
                                                                        {pushScope();addfuncpara((yyvsp[-3].var_type));}
#line 1490 "./build/y.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 102 "./compiler.y"
                                                                                                                                           {funcsig((yyvsp[-4].s_var));}
#line 1496 "./build/y.tab.c"
    break;

  case 28: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@4 $@5 FunctionParameterStmtList $@6 ')' '{' StmtList '}'  */
#line 102 "./compiler.y"
                                                                                                                                                                               { dumpScope(); }
#line 1502 "./build/y.tab.c"
    break;

  case 32: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 110 "./compiler.y"
                               {addfuncpara((yyvsp[-3].var_type)*10); pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_DEFAULT); }
#line 1508 "./build/y.tab.c"
    break;

  case 33: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 111 "./compiler.y"
                        {addfuncpara((yyvsp[-1].var_type)); pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); }
#line 1514 "./build/y.tab.c"
    break;

  case 37: /* Stmt: COUT CoutParmListStmt ';'  */
#line 122 "./compiler.y"
                                { stdoutPrint(); clearCout();}
#line 1520 "./build/y.tab.c"
    break;

  case 38: /* Stmt: RETURN Expression ';'  */
#line 123 "./compiler.y"
                            { printf("RETURN\n"); }
#line 1526 "./build/y.tab.c"
    break;

  case 39: /* Stmt: RETURN ';'  */
#line 124 "./compiler.y"
                 {printf("RETURN\n");}
#line 1532 "./build/y.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 125 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0); }
#line 1538 "./build/y.tab.c"
    break;

  case 43: /* $@8: %empty  */
#line 127 "./compiler.y"
          {printf("FOR\n");}
#line 1544 "./build/y.tab.c"
    break;

  case 44: /* $@9: %empty  */
#line 127 "./compiler.y"
                                 {pushScope();}
#line 1550 "./build/y.tab.c"
    break;

  case 45: /* Stmt: FOR $@8 '(' $@9 For ')' '{' StmtList '}'  */
#line 127 "./compiler.y"
                                                                          { dumpScope(); }
#line 1556 "./build/y.tab.c"
    break;

  case 46: /* $@10: %empty  */
#line 128 "./compiler.y"
            { printf("WHILE\n"); }
#line 1562 "./build/y.tab.c"
    break;

  case 47: /* $@11: %empty  */
#line 128 "./compiler.y"
                                                      { pushScope(); }
#line 1568 "./build/y.tab.c"
    break;

  case 48: /* Stmt: WHILE $@10 '(' Expression ')' $@11 '{' StmtList '}'  */
#line 128 "./compiler.y"
                                                                                        { dumpScope(); }
#line 1574 "./build/y.tab.c"
    break;

  case 49: /* Stmt: BREAK ';'  */
#line 129 "./compiler.y"
                 {printf("BREAK\n");}
#line 1580 "./build/y.tab.c"
    break;

  case 52: /* Stmt: DefineVariableStmt  */
#line 132 "./compiler.y"
                         {array_element_num=0;}
#line 1586 "./build/y.tab.c"
    break;

  case 55: /* For: VARIABLE_T IDENT ':' IDENT  */
#line 139 "./compiler.y"
                                 {obj=findVariable((yyvsp[0].s_var),0);createVariable(obj->type, (yyvsp[-2].s_var), 0);varAddrCheck((yyvsp[0].s_var),0);}
#line 1592 "./build/y.tab.c"
    break;

  case 56: /* F1: VARIABLE_T F1_List1  */
#line 142 "./compiler.y"
                          { currentVarType = (yyvsp[-1].var_type); }
#line 1598 "./build/y.tab.c"
    break;

  case 59: /* F1_List1: F1_List1 ',' IDENT VAL_ASSIGN Expression  */
#line 146 "./compiler.y"
                                               { createVariable(currentVarType, (yyvsp[-2].s_var), 0);}
#line 1604 "./build/y.tab.c"
    break;

  case 60: /* F1_List1: IDENT VAL_ASSIGN Expression  */
#line 147 "./compiler.y"
                                  { createVariable(currentVarType, (yyvsp[-2].s_var), 0);}
#line 1610 "./build/y.tab.c"
    break;

  case 65: /* $@12: %empty  */
#line 155 "./compiler.y"
            {varAddrCheck((yyvsp[0].s_var),0);}
#line 1616 "./build/y.tab.c"
    break;

  case 68: /* $@13: %empty  */
#line 159 "./compiler.y"
                            { printf("IF\n"); pushScope(); }
#line 1622 "./build/y.tab.c"
    break;

  case 69: /* $@14: %empty  */
#line 159 "./compiler.y"
                                                                              { dumpScope(); }
#line 1628 "./build/y.tab.c"
    break;

  case 71: /* $@15: %empty  */
#line 160 "./compiler.y"
                            { printf("IF\n"); }
#line 1634 "./build/y.tab.c"
    break;

  case 73: /* $@16: %empty  */
#line 163 "./compiler.y"
           { printf("ELSE\n"); pushScope(); }
#line 1640 "./build/y.tab.c"
    break;

  case 74: /* ElseStmt: ELSE $@16 '{' StmtList '}'  */
#line 163 "./compiler.y"
                                                               { dumpScope(); }
#line 1646 "./build/y.tab.c"
    break;

  case 75: /* $@17: %empty  */
#line 164 "./compiler.y"
           { printf("ELSE\n"); }
#line 1652 "./build/y.tab.c"
    break;

  case 78: /* IdentAssign: VAL_ASSIGN Expression  */
#line 169 "./compiler.y"
                             {printf("EQL_ASSIGN\n");}
#line 1658 "./build/y.tab.c"
    break;

  case 79: /* IdentAssign: ADD_ASSIGN Expression  */
#line 170 "./compiler.y"
                             {printf("ADD_ASSIGN\n");}
#line 1664 "./build/y.tab.c"
    break;

  case 80: /* IdentAssign: SUB_ASSIGN Expression  */
#line 171 "./compiler.y"
                             {printf("SUB_ASSIGN\n");}
#line 1670 "./build/y.tab.c"
    break;

  case 81: /* IdentAssign: MUL_ASSIGN Expression  */
#line 172 "./compiler.y"
                             {printf("MUL_ASSIGN\n");}
#line 1676 "./build/y.tab.c"
    break;

  case 82: /* IdentAssign: DIV_ASSIGN Expression  */
#line 173 "./compiler.y"
                             {printf("DIV_ASSIGN\n");}
#line 1682 "./build/y.tab.c"
    break;

  case 83: /* IdentAssign: SHR_ASSIGN Expression  */
#line 174 "./compiler.y"
                             {printf("SHR_ASSIGN\n");}
#line 1688 "./build/y.tab.c"
    break;

  case 84: /* IdentAssign: SHL_ASSIGN Expression  */
#line 175 "./compiler.y"
                             {printf("SHL_ASSIGN\n");}
#line 1694 "./build/y.tab.c"
    break;

  case 85: /* IdentAssign: BOR_ASSIGN Expression  */
#line 176 "./compiler.y"
                             {printf("BOR_ASSIGN\n");}
#line 1700 "./build/y.tab.c"
    break;

  case 86: /* IdentAssign: BAN_ASSIGN Expression  */
#line 177 "./compiler.y"
                             {printf("BAN_ASSIGN\n");}
#line 1706 "./build/y.tab.c"
    break;

  case 87: /* IdentAssign: BXO_ASSIGN Expression  */
#line 178 "./compiler.y"
                             {printf("BXO_ASSIGN\n");}
#line 1712 "./build/y.tab.c"
    break;

  case 88: /* IdentAssign: REM_ASSIGN Expression  */
#line 179 "./compiler.y"
                             {printf("REM_ASSIGN\n");}
#line 1718 "./build/y.tab.c"
    break;

  case 89: /* IdentAssign: INC_ASSIGN  */
#line 180 "./compiler.y"
                 {printf("INC_ASSIGN\n");}
#line 1724 "./build/y.tab.c"
    break;

  case 90: /* IdentAssign: DEC_ASSIGN  */
#line 181 "./compiler.y"
                 {printf("DEC_ASSIGN\n");}
#line 1730 "./build/y.tab.c"
    break;

  case 91: /* $@18: %empty  */
#line 184 "./compiler.y"
                                { varAddrCheck((yyvsp[-3].s_var),0);}
#line 1736 "./build/y.tab.c"
    break;

  case 92: /* ArrayAssignmentStmt: IDENT '[' Expression ']' $@18 VAL_ASSIGN Expression  */
#line 184 "./compiler.y"
                                                                             { printf("EQL_ASSIGN\n");}
#line 1742 "./build/y.tab.c"
    break;

  case 93: /* $@19: %empty  */
#line 185 "./compiler.y"
                                                   { varAddrCheck((yyvsp[-6].s_var),0); }
#line 1748 "./build/y.tab.c"
    break;

  case 94: /* ArrayAssignmentStmt: IDENT '[' Expression ']' '[' Expression ']' $@19 VAL_ASSIGN Expression  */
#line 185 "./compiler.y"
                                                                                                 {printf("EQL_ASSIGN\n");}
#line 1754 "./build/y.tab.c"
    break;

  case 95: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 189 "./compiler.y"
                                      { insertCout((yyvsp[0].object_val).type); }
#line 1760 "./build/y.tab.c"
    break;

  case 96: /* CoutParmListStmt: SHL Expression  */
#line 190 "./compiler.y"
                     { insertCout((yyvsp[0].object_val).type); }
#line 1766 "./build/y.tab.c"
    break;

  case 98: /* Callfunction: IDENT '(' Funcparameter ')'  */
#line 200 "./compiler.y"
                                    { varAddrCheck((yyvsp[-3].s_var),1); IdentType(&(yyval.object_val), (yyvsp[-3].s_var),1); obj = findVariable((yyvsp[-3].s_var),1);printf("call: %s%s\n",(yyvsp[-3].s_var),obj->symbol->func_sig);}
#line 1772 "./build/y.tab.c"
    break;

  case 103: /* LORExpression: LORExpression LOR LANExpression  */
#line 209 "./compiler.y"
                                      { printf("LOR\n"); ExpressionType('l',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); }
#line 1778 "./build/y.tab.c"
    break;

  case 105: /* LANExpression: LANExpression LAN BitwiseExpression  */
#line 213 "./compiler.y"
                                          { printf("LAN\n"); ExpressionType('l',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val)); }
#line 1784 "./build/y.tab.c"
    break;

  case 107: /* BitwiseExpression: BitwiseExpression BOR RelationalExpression  */
#line 218 "./compiler.y"
                                                 { printf("BOR\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1790 "./build/y.tab.c"
    break;

  case 108: /* BitwiseExpression: BitwiseExpression BXO RelationalExpression  */
#line 219 "./compiler.y"
                                                 { printf("BXO\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1796 "./build/y.tab.c"
    break;

  case 109: /* BitwiseExpression: BitwiseExpression BAN RelationalExpression  */
#line 220 "./compiler.y"
                                                 { printf("BAN\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1802 "./build/y.tab.c"
    break;

  case 110: /* BitwiseExpression: BitwiseExpression BNT RelationalExpression  */
#line 221 "./compiler.y"
                                                 { printf("BNT\n"); ExpressionType('b',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1808 "./build/y.tab.c"
    break;

  case 112: /* RelationalExpression: RelationalExpression EQL ShiftExpression  */
#line 227 "./compiler.y"
                                               { printf("EQL\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1814 "./build/y.tab.c"
    break;

  case 113: /* RelationalExpression: RelationalExpression NEQ ShiftExpression  */
#line 228 "./compiler.y"
                                               { printf("NEQ\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1820 "./build/y.tab.c"
    break;

  case 114: /* RelationalExpression: RelationalExpression LES ShiftExpression  */
#line 229 "./compiler.y"
                                               { printf("LES\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1826 "./build/y.tab.c"
    break;

  case 115: /* RelationalExpression: RelationalExpression LEQ ShiftExpression  */
#line 230 "./compiler.y"
                                               { printf("LEQ\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1832 "./build/y.tab.c"
    break;

  case 116: /* RelationalExpression: RelationalExpression GTR ShiftExpression  */
#line 231 "./compiler.y"
                                               { printf("GTR\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1838 "./build/y.tab.c"
    break;

  case 117: /* RelationalExpression: RelationalExpression GEQ ShiftExpression  */
#line 232 "./compiler.y"
                                               { printf("GEQ\n"); ExpressionType('r',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1844 "./build/y.tab.c"
    break;

  case 119: /* ShiftExpression: ShiftExpression SHR AdditiveExpression  */
#line 236 "./compiler.y"
                                             {printf("SHR\n");ExpressionType('s',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1850 "./build/y.tab.c"
    break;

  case 121: /* AdditiveExpression: AdditiveExpression ADD MultiplicativeExpression  */
#line 241 "./compiler.y"
                                                        { printf("ADD\n"); ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1856 "./build/y.tab.c"
    break;

  case 122: /* AdditiveExpression: AdditiveExpression SUB MultiplicativeExpression  */
#line 242 "./compiler.y"
                                                      { printf("SUB\n"); ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1862 "./build/y.tab.c"
    break;

  case 124: /* MultiplicativeExpression: MultiplicativeExpression MUL CastExpression  */
#line 247 "./compiler.y"
                                                  { printf("MUL\n"); ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1868 "./build/y.tab.c"
    break;

  case 125: /* MultiplicativeExpression: MultiplicativeExpression DIV CastExpression  */
#line 248 "./compiler.y"
                                                  { printf("DIV\n"); ExpressionType('m',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1874 "./build/y.tab.c"
    break;

  case 126: /* MultiplicativeExpression: MultiplicativeExpression REM CastExpression  */
#line 249 "./compiler.y"
                                                  { printf("REM\n"); ExpressionType('s',&(yyvsp[-2].object_val),&(yyvsp[0].object_val),&(yyval.object_val));}
#line 1880 "./build/y.tab.c"
    break;

  case 128: /* CastExpression: '(' VARIABLE_T ')' CastExpression  */
#line 253 "./compiler.y"
                                        {Cast((yyvsp[-2].var_type)); (yyval.object_val).type = (yyvsp[-2].var_type);}
#line 1886 "./build/y.tab.c"
    break;

  case 130: /* UnaryExpression: NOT UnaryExpression  */
#line 257 "./compiler.y"
                          { printf("NOT\n"); (yyval.object_val).type = (yyvsp[0].object_val).type;}
#line 1892 "./build/y.tab.c"
    break;

  case 131: /* UnaryExpression: BNT UnaryExpression  */
#line 258 "./compiler.y"
                          { printf("BNT\n"); (yyval.object_val).type = (yyvsp[0].object_val).type;}
#line 1898 "./build/y.tab.c"
    break;

  case 132: /* UnaryExpression: SUB UnaryExpression  */
#line 259 "./compiler.y"
                          { printf("NEG\n"); (yyval.object_val).type = (yyvsp[0].object_val).type;}
#line 1904 "./build/y.tab.c"
    break;

  case 134: /* PrimaryExpression: INT_LIT  */
#line 264 "./compiler.y"
              { printf("INT_LIT %d\n", (yyvsp[0].i_var)); (yyval.object_val).type = OBJECT_TYPE_INT ; }
#line 1910 "./build/y.tab.c"
    break;

  case 135: /* PrimaryExpression: FLOAT_LIT  */
#line 265 "./compiler.y"
                { printf("FLOAT_LIT %f\n", (yyvsp[0].f_var)); (yyval.object_val).type = OBJECT_TYPE_FLOAT ; }
#line 1916 "./build/y.tab.c"
    break;

  case 136: /* PrimaryExpression: BOOL_LIT  */
#line 266 "./compiler.y"
               { printf("BOOL_LIT %s\n", (yyvsp[0].b_var) ? "TRUE" : "FALSE"); (yyval.object_val).type = OBJECT_TYPE_BOOL ;}
#line 1922 "./build/y.tab.c"
    break;

  case 137: /* PrimaryExpression: IDENT  */
#line 267 "./compiler.y"
            { varAddrCheck((yyvsp[0].s_var),0); IdentType(&(yyval.object_val), (yyvsp[0].s_var),0); }
#line 1928 "./build/y.tab.c"
    break;

  case 138: /* PrimaryExpression: STR_LIT  */
#line 268 "./compiler.y"
              { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); (yyval.object_val).type = OBJECT_TYPE_STR; }
#line 1934 "./build/y.tab.c"
    break;

  case 139: /* PrimaryExpression: '(' Expression ')'  */
#line 269 "./compiler.y"
                          { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 1940 "./build/y.tab.c"
    break;

  case 140: /* PrimaryExpression: IDENT '[' Expression ']'  */
#line 270 "./compiler.y"
                               { varAddrCheck((yyvsp[-3].s_var),0); IdentType(&(yyval.object_val), (yyvsp[-3].s_var),0); }
#line 1946 "./build/y.tab.c"
    break;

  case 141: /* PrimaryExpression: IDENT '[' Expression ']' '[' Expression ']'  */
#line 271 "./compiler.y"
                                                  { varAddrCheck((yyvsp[-6].s_var),0); IdentType(&(yyval.object_val), (yyvsp[-6].s_var),0); }
#line 1952 "./build/y.tab.c"
    break;


#line 1956 "./build/y.tab.c"

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

#line 277 "./compiler.y"

/* C code section */
//{printf("Type = %d ",$<object_val>$.type);printf("curr expression = %d\n",$$.type);}  printf("Type = %d ",$<object_val>$.type);printf("curr expression = %d\n",$$.type);
//build/out/compiler  input/subtask0X-xxx/testcase0X.cpp
