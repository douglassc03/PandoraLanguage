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
#line 1 "sintatico.y"

								//Coisas q o compilador faz 
// -->criei tipo auxiliar para simnular q to fazendo a conversao quando por exemplo somo float com int(conversao de tipo).
// -->fizemos dar erro quando tem divisão por zero.
// --> se a var não tiver declarada da erro.

								//FAZER:
//--> ENTENDER PQ QUANDO ATRIBUO UMA VAR, ELA APARECE NA ORDEM ERRADA(mas funciona noraml, só a ordem q esta errada).

//    ex: int a;
//        a = 2;
// resultado:
// 		t2 = 2;
// 		t1 = t2;
// 		return 0;

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;

struct atributos {
	string label;
	string traducao;
	string tipo;
	string valor;
};

typedef struct {
	string nomeVariavel;
	string tipoVariavel;
	string labelVariavel;
}TIPO_SIMBOLO;

typedef struct {
	string tipoVariavel;
	string labelVariavel;
}TIPO_TEMP;

vector<TIPO_SIMBOLO> tabelaSimbolos;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;

int yylex(void);
void yyerror(string);

// chamando funcoes 
string gentempcode();
void variavelRepetida(string variavel);
void variavelExistente(string nomeVariavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addTemp(string label, string tipo);
void verificaOperacaoRelacional(string tipo_1, string tipo_2);


#line 134 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_CHAR = 260,                 /* TK_CHAR  */
    TK_MAIN = 261,                 /* TK_MAIN  */
    TK_ID = 262,                   /* TK_ID  */
    TK_TIPO_INT = 263,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 264,           /* TK_TIPO_FLOAT  */
    TK_TIPO_BOOLEAN = 265,         /* TK_TIPO_BOOLEAN  */
    TK_TIPO_CHAR = 266,            /* TK_TIPO_CHAR  */
    TK_TRUE = 267,                 /* TK_TRUE  */
    TK_FALSE = 268,                /* TK_FALSE  */
    TK_MAIOR_IGUAL = 269,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 270,          /* TK_MENOR_IGUAL  */
    TK_IGUAL_IGUAL = 271,          /* TK_IGUAL_IGUAL  */
    TK_DIFERENTE = 272,            /* TK_DIFERENTE  */
    TK_MAIS_MAIS = 273,            /* TK_MAIS_MAIS  */
    TK_MENOS_MENOS = 274,          /* TK_MENOS_MENOS  */
    TK_OU = 275,                   /* TK_OU  */
    TK_E = 276,                    /* TK_E  */
    TK_FIM = 277,                  /* TK_FIM  */
    TK_ERROR = 278                 /* TK_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_MAIN 261
#define TK_ID 262
#define TK_TIPO_INT 263
#define TK_TIPO_FLOAT 264
#define TK_TIPO_BOOLEAN 265
#define TK_TIPO_CHAR 266
#define TK_TRUE 267
#define TK_FALSE 268
#define TK_MAIOR_IGUAL 269
#define TK_MENOR_IGUAL 270
#define TK_IGUAL_IGUAL 271
#define TK_DIFERENTE 272
#define TK_MAIS_MAIS 273
#define TK_MENOS_MENOS 274
#define TK_OU 275
#define TK_E 276
#define TK_FIM 277
#define TK_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_CHAR = 5,                    /* TK_CHAR  */
  YYSYMBOL_TK_MAIN = 6,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 7,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 8,                /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 9,              /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_BOOLEAN = 10,           /* TK_TIPO_BOOLEAN  */
  YYSYMBOL_TK_TIPO_CHAR = 11,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TRUE = 12,                   /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 13,                  /* TK_FALSE  */
  YYSYMBOL_TK_MAIOR_IGUAL = 14,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 15,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_IGUAL_IGUAL = 16,            /* TK_IGUAL_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 17,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_MAIS_MAIS = 18,              /* TK_MAIS_MAIS  */
  YYSYMBOL_TK_MENOS_MENOS = 19,            /* TK_MENOS_MENOS  */
  YYSYMBOL_TK_OU = 20,                     /* TK_OU  */
  YYSYMBOL_TK_E = 21,                      /* TK_E  */
  YYSYMBOL_TK_FIM = 22,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 23,                  /* TK_ERROR  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_S = 38,                         /* S  */
  YYSYMBOL_BLOCO = 39,                     /* BLOCO  */
  YYSYMBOL_COMANDOS = 40,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 41,                   /* COMANDO  */
  YYSYMBOL_E = 42                          /* E  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  71

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
       2,     2,     2,    35,     2,     2,     2,     2,     2,     2,
      25,    26,    31,    24,     2,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      34,    36,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    93,    99,   104,   109,   110,   117,   124,
     131,   140,   181,   222,   263,   341,   350,   359,   368,   377,
     386,   395,   403,   411,   419,   427,   435,   452,   468,   498,
     507,   516,   524,   532,   540
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_CHAR", "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_TIPO_FLOAT",
  "TK_TIPO_BOOLEAN", "TK_TIPO_CHAR", "TK_TRUE", "TK_FALSE",
  "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_IGUAL_IGUAL", "TK_DIFERENTE",
  "TK_MAIS_MAIS", "TK_MENOS_MENOS", "TK_OU", "TK_E", "TK_FIM", "TK_ERROR",
  "'+'", "'('", "')'", "'{'", "'}'", "';'", "'-'", "'*'", "'/'", "'>'",
  "'<'", "'!'", "'='", "$accept", "S", "BLOCO", "COMANDOS", "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-6)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    22,    23,     4,    -6,    12,     9,    -3,    -6,    -6,
      -6,    -6,    -2,     5,    37,    24,    32,    17,    14,    -3,
      44,    -6,    -6,     6,    11,    17,    34,    17,    38,    40,
      18,    41,   107,    -6,    -6,    17,    17,    17,    17,    17,
      17,    17,    -6,    17,    17,    17,    17,    17,    -6,    -6,
     107,    -6,    65,    -6,    86,    -6,    -6,   107,   107,   107,
     107,   107,   107,   128,   107,   107,   107,   107,   107,    -6,
      -6
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,    29,
      30,    31,    34,     0,     0,     0,     0,     0,     0,     5,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,    32,    33,
      28,     7,     0,     8,     0,    10,     9,    17,    18,    19,
      20,    21,    22,    11,    12,    13,    14,    15,    16,    27,
      26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -6,    -6,    -6,    51,    -6,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    18,    19,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       9,    10,    11,     1,    12,    13,    14,    15,    16,     9,
      10,    11,    24,    12,    30,    31,    21,    22,    48,    49,
       9,    10,    11,     4,    12,    30,    31,    32,     3,     5,
      25,    28,    17,    50,    23,    52,     7,    54,     6,    29,
      51,    17,    33,    25,    26,    57,    58,    59,    60,    61,
      62,    63,    17,    64,    65,    66,    67,    68,    35,    36,
      37,    38,    27,    53,    39,    40,    27,    55,    41,    56,
      34,     0,     0,    42,    43,    44,    45,    46,    47,    35,
      36,    37,    38,     0,     0,    39,    40,     0,     0,    41,
       0,    69,     0,     0,     0,    43,    44,    45,    46,    47,
      35,    36,    37,    38,     0,     0,    39,    40,     0,     0,
      41,     0,    70,     0,     0,     0,    43,    44,    45,    46,
      47,    35,    36,    37,    38,     0,     0,    39,    40,     0,
       0,    41,     0,     0,     0,     0,     0,    43,    44,    45,
      46,    47,    35,    36,    37,    38,     0,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46,    47
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     8,     7,     8,     9,    10,    11,     3,
       4,     5,     7,     7,     8,     9,    18,    19,    12,    13,
       3,     4,     5,     0,     7,     8,     9,    17,     6,    25,
      25,     7,    35,    23,    36,    25,    27,    27,    26,     7,
      29,    35,    28,    25,     7,    35,    36,    37,    38,    39,
      40,    41,    35,    43,    44,    45,    46,    47,    14,    15,
      16,    17,    25,    29,    20,    21,    25,    29,    24,    29,
      19,    -1,    -1,    29,    30,    31,    32,    33,    34,    14,
      15,    16,    17,    -1,    -1,    20,    21,    -1,    -1,    24,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      14,    15,    16,    17,    -1,    -1,    20,    21,    -1,    -1,
      24,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    14,    15,    16,    17,    -1,    -1,    20,    21,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    14,    15,    16,    17,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    38,     6,     0,    25,    26,    27,    39,     3,
       4,     5,     7,     8,     9,    10,    11,    35,    40,    41,
      42,    18,    19,    36,     7,    25,     7,    25,     7,     7,
       8,     9,    42,    28,    40,    14,    15,    16,    17,    20,
      21,    24,    29,    30,    31,    32,    33,    34,    12,    13,
      42,    29,    42,    29,    42,    29,    29,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    26,
      26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    40,    40,    41,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     4,     3,     1,
       1,     1,     3,     3,     1
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 77 "sintatico.y"
                        {
				string codigo = "/*Compilador Pandora*/\n"
								"#include <iostream>\n"
								"#include<string.h>\n"
								"#include<stdio.h>\n"
								"int main(void) {\n";
								
				codigo += yyvsp[0].traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";

				cout << codigo << endl;
			}
#line 1317 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' COMANDOS '}'  */
#line 94 "sintatico.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1325 "y.tab.c"
    break;

  case 4: /* COMANDOS: COMANDO COMANDOS  */
#line 100 "sintatico.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1333 "y.tab.c"
    break;

  case 5: /* COMANDOS: %empty  */
#line 104 "sintatico.y"
                        {
				yyval.traducao = "";
			}
#line 1341 "y.tab.c"
    break;

  case 7: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 111 "sintatico.y"
                        {
				variavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "int", gentempcode());
				yyval.traducao = "";
				yyval.label = "";			
			}
#line 1352 "y.tab.c"
    break;

  case 8: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 118 "sintatico.y"
                        {
				variavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "float", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1363 "y.tab.c"
    break;

  case 9: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 125 "sintatico.y"
                        {
				variavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "char", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1374 "y.tab.c"
    break;

  case 10: /* COMANDO: TK_TIPO_BOOLEAN TK_ID ';'  */
#line 132 "sintatico.y"
                        {
				variavelRepetida(yyvsp[-1].label);
				addSimbolo(yyvsp[-1].label, "boolean", gentempcode());
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1385 "y.tab.c"
    break;

  case 11: /* E: E '+' E  */
#line 141 "sintatico.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " + " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " + " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
#line 1429 "y.tab.c"
    break;

  case 12: /* E: E '-' E  */
#line 182 "sintatico.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					tipoAux = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, tipoAux);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					tipoAux = "float";
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " - " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					tipoAux = "float";
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " - " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
#line 1473 "y.tab.c"
    break;

  case 13: /* E: E '*' E  */
#line 223 "sintatico.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " * " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " * " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
#line 1517 "y.tab.c"
    break;

  case 14: /* E: E '/' E  */
#line 264 "sintatico.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				string aux = yyvsp[0].valor;
				int cont = 0;
				int ponto = 0;

				for(int i = 0; i < aux.size(); i++)
				{
					if(aux[i] == '.')
					{
						ponto = 1;
					}
					if(aux[i] == '0')
					{
						cont++;
					}
				}

				if(cont == aux.size() || (cont + ponto) == aux.size()){
					yyerror("ERRO: divisão por 0!");
				}

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					tipoAux = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, tipoAux);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					tipoAux = "float";
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " / " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					tipoAux = "float";
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, tipoAux);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " / " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
#line 1581 "y.tab.c"
    break;

  case 15: /* E: E '>' E  */
#line 342 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
			}
#line 1593 "y.tab.c"
    break;

  case 16: /* E: E '<' E  */
#line 351 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
			}
#line 1605 "y.tab.c"
    break;

  case 17: /* E: E TK_MAIOR_IGUAL E  */
#line 360 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
			}
#line 1617 "y.tab.c"
    break;

  case 18: /* E: E TK_MENOR_IGUAL E  */
#line 369 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
			}
#line 1629 "y.tab.c"
    break;

  case 19: /* E: E TK_IGUAL_IGUAL E  */
#line 378 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
			}
#line 1641 "y.tab.c"
    break;

  case 20: /* E: E TK_DIFERENTE E  */
#line 387 "sintatico.y"
                        {
				verificaOperacaoRelacional(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
			}
#line 1653 "y.tab.c"
    break;

  case 21: /* E: E TK_OU E  */
#line 396 "sintatico.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
			}
#line 1664 "y.tab.c"
    break;

  case 22: /* E: E TK_E E  */
#line 404 "sintatico.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
			}
#line 1675 "y.tab.c"
    break;

  case 23: /* E: '!' E  */
#line 412 "sintatico.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "boolean");
				yyval.traducao = yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
			}
#line 1686 "y.tab.c"
    break;

  case 24: /* E: TK_ID TK_MAIS_MAIS  */
#line 420 "sintatico.y"
                        {
				variavelExistente(yyvsp[-1].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
#line 1697 "y.tab.c"
    break;

  case 25: /* E: TK_ID TK_MENOS_MENOS  */
#line 428 "sintatico.y"
                        {
				variavelExistente(yyvsp[-1].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
#line 1708 "y.tab.c"
    break;

  case 26: /* E: TK_TIPO_FLOAT '(' E ')'  */
#line 436 "sintatico.y"
                        {		
				yyval.label = gentempcode();
				yyval.tipo  = "float";

				addTemp(yyval.label, yyval.tipo);
				
				if(yyvsp[-1].tipo == "int")
				{	
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(float) " + yyvsp[-1].label + ";\n";  
				}else
				{
					yyerror("operação inválida!");
				}
			}
#line 1728 "y.tab.c"
    break;

  case 27: /* E: TK_TIPO_INT '(' E ')'  */
#line 453 "sintatico.y"
                        {	
				yyval.label = gentempcode();
				yyval.tipo  = "int";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[-1].tipo == "float")
				{
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(int) " + yyvsp[-1].label + ";\n";
				}else
				{
					yyerror("operação inválida!");
				}
			}
#line 1747 "y.tab.c"
    break;

  case 28: /* E: TK_ID '=' E  */
#line 469 "sintatico.y"
                        {
				variavelExistente(yyvsp[-2].label);
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-2].label);

				if(variavel.tipoVariavel == yyvsp[0].tipo){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					variavel.labelVariavel + " = " + yyvsp[0].label + ";\n";
				}
				else if (variavel.tipoVariavel == "int" & yyvsp[0].tipo == "float")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "int");
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";
				}
				else if (variavel.tipoVariavel == "float" & yyvsp[0].tipo == "int")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "float");
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";
				}
				else{
					yyerror("Atribuição inválida!");
				}
			}
#line 1780 "y.tab.c"
    break;

  case 29: /* E: TK_NUM  */
#line 499 "sintatico.y"
                        {
				yyval.tipo = "int";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 1792 "y.tab.c"
    break;

  case 30: /* E: TK_REAL  */
#line 508 "sintatico.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 1804 "y.tab.c"
    break;

  case 31: /* E: TK_CHAR  */
#line 517 "sintatico.y"
                        {
				yyval.tipo = "char";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 1815 "y.tab.c"
    break;

  case 32: /* E: TK_ID '=' TK_TRUE  */
#line 525 "sintatico.y"
                        {
				variavelExistente(yyvsp[-2].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-2].label);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao + "\t" + 
				variavel_1.labelVariavel + " = 1"  + ";\n";
			}
#line 1826 "y.tab.c"
    break;

  case 33: /* E: TK_ID '=' TK_FALSE  */
#line 533 "sintatico.y"
                        {
				variavelExistente(yyvsp[-2].label);
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-2].label);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao + "\t" + 
				variavel_1.labelVariavel + " = 0"  + ";\n";
			}
#line 1837 "y.tab.c"
    break;

  case 34: /* E: TK_ID  */
#line 541 "sintatico.y"
                        { //indo na tabela de simbolo e verificando se o ID existe nela. 
				bool VarExiste = false;
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[0].label);
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == yyvsp[0].label)
					{
						variavel = tabelaSimbolos[i];
						VarExiste = true;
					}	
				}

				if(!VarExiste)
				{
					yyerror("error: a variável '" + yyvsp[0].label + "' não foi instanciada!");
				}

				yyval.tipo = variavel.tipoVariavel;
				yyval.label = variavel.labelVariavel;
				yyval.traducao = "";
			}
#line 1862 "y.tab.c"
    break;


#line 1866 "y.tab.c"

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

#line 563 "sintatico.y"


#include "lex.yy.c"

int yyparse();

// FUNCOES
string gentempcode()
{
	var_temp_qnt++;
	return "t" + to_string(var_temp_qnt);
}

void variavelRepetida(string variavel){

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			yyerror("Variável já existe!");
		}
	}
}

void variavelExistente(string nomeVariavel){
	bool VarExiste = false;
	for (int i = 0; i < tabelaSimbolos.size(); i++){
		if(tabelaSimbolos[i].nomeVariavel == nomeVariavel){
			VarExiste = true;
		}
	}
	
	if(!VarExiste) {
		yyerror("error: a variável '" + nomeVariavel + "' não foi instanciada!");
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){
	for (int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
			return tabelaSimbolos[i];					
	}
}

void addSimbolo(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;
	tabelaSimbolos.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);
	atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

void verificaOperacaoRelacional(string tipo_1, string tipo_2){
	if(tipo_1 == "char" || tipo_2 == "char" || tipo_1 == "boolean" || tipo_2 == "boolean" || tipo_1 == "boolean" || tipo_2 == "char" || tipo_1 == "char" ||tipo_2 == "boolean")
	{
		yyerror ("Operação relacional não é válida!");
	}
}


//MAIN
int main(int argc, char* argv[])
{
	var_temp_qnt = 0;

	yyparse();

	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				
