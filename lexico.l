%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
SIMBOLO [:;<=>?@[\]^`{|} 0x0020]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{DIGITO}|{SIMBOLO})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{ return TK_TIPO_INT; }
"float"		{ return TK_TIPO_FLOAT; }
"boolean"		{ return TK_TIPO_BOOLEAN; }
"char"      { return TK_TIPO_CHAR; } 

"True"      { return TK_TRUE; }
"False"     { return TK_FALSE; }

">="		{ return TK_MAIOR_IGUAL; }
"<="        { return TK_MENOR_IGUAL; }
"=="        { return TK_IGUAL_IGUAL; }
"!="        { return TK_DIFERENTE; }
"--"        { return TK_MENOS_MENOS; }
"++"        { return TK_MAIS_MAIS; }
"||"        { return TK_OU; }
"&&"        { return TK_E; }

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"="		    { return '='; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}		{ yylval.label = yytext; return TK_REAL; }
{CHAR}		{ yylval.label = yytext; return TK_CHAR; }

.			{ *yytext; }

%%
