%{
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

%}

%token TK_NUM TK_REAL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOLEAN TK_TIPO_CHAR TK_TRUE TK_FALSE
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_IGUAL_IGUAL TK_DIFERENTE TK_MAIS_MAIS TK_MENOS_MENOS TK_OU TK_E

%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				string codigo = "/*Compilador Pandora*/\n"
								"#include <iostream>\n"
								"#include<string.h>\n"
								"#include<stdio.h>\n"
								"int main(void) {\n";
								
				codigo += $5.traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";

				cout << codigo << endl;
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| TK_TIPO_INT TK_ID ';'
			{
				variavelRepetida($2.label);
				addSimbolo($2.label, "int", gentempcode());
				$$.traducao = "";
				$$.label = "";			
			}
			| TK_TIPO_FLOAT TK_ID ';'
			{
				variavelRepetida($2.label);
				addSimbolo($2.label, "float", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_CHAR TK_ID ';'
			{
				variavelRepetida($2.label);
				addSimbolo($2.label, "char", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			| TK_TIPO_BOOLEAN TK_ID ';'
			{
				variavelRepetida($2.label);
				addSimbolo($2.label, "boolean", gentempcode());
				$$.traducao = "";
				$$.label = "";
			}
			;

E 			: E '+' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " + " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " + " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " + " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}

			| E '-' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " - " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " - " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " - " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}

			| E '*' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;

				if($1.tipo == $3.tipo){
					$$.tipo = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " * " + $3.label + ";\n";
					addTemp($$.label, $$.tipo);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					$$.tipo = $3.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " * " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					$$.tipo = $1.tipo;
					addTemp($$.label, $$.tipo);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, $$.tipo);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " * " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}

			| E '/' E
			{
				$$.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				string aux = $3.valor;
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

				if($1.tipo == $3.tipo){
					tipoAux = $1.tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = " + $1.label + " / " + $3.label + ";\n";
					addTemp($$.label, tipoAux);
				}
				else if($1.tipo == "int" & $3.tipo == "float"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $1.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + labelAux + " / " + $3.label + ";\n";
				}
				else if($1.tipo == "float" & $3.tipo == "int"){
					tipoAux = "float";
					addTemp($$.label, tipoAux);
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n";

					labelAux = $$.label;
					$$.label = gentempcode();
					addTemp($$.label, tipoAux);
					$$.traducao = $$.traducao + "\t"+
					$$.label + " = " + $1.label + " / " + labelAux + ";\n";
				}
				else{
					yyerror("Operação inválida");
				}
			}
			
			// | E '%' E
			// {
			// 	$$.label = gentempcode();
			// 	string tipoAux;
			// 	string labelAux;

			// 	if($1.tipo == "int" & $3.tipo == "int"){
			// 		tipoAux = $1.tipo;
			// 		$$.traducao = $1.traducao + $3.traducao + "\t" + 
			// 		$$.label + " = " + $1.label + " % " + $3.label + ";\n";
			// 		addTemp($$.label, tipoAux);
			// 	}
			// 	else{
			// 		yyerror("operandos inválidos para % (temos float)");
			// 	}
			// }

			| E '>' E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " > " + $3.label + ";\n";
			}

			| E '<' E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " < " + $3.label + ";\n";
			}

			| E TK_MAIOR_IGUAL E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " >= " + $3.label + ";\n";
			}

			| E TK_MENOR_IGUAL E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " <= " + $3.label + ";\n";
			}

			| E TK_IGUAL_IGUAL E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " == " + $3.label + ";\n";
			}

			| E TK_DIFERENTE E
			{
				verificaOperacaoRelacional($1.tipo, $3.tipo);
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " != " + $3.label + ";\n";
			}

			| E TK_OU E
			{
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " || " + $3.label + ";\n";
			}

			| E TK_E E
			{
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $1.traducao + $3.traducao + "\t" + 
				$$.label + " = " + $1.label + " && " + $3.label + ";\n";
			}

			| '!' E
			{
				$$.label = gentempcode();
				addTemp($$.label, "boolean");
				$$.traducao = $2.traducao + "\t" + 
				$$.label + " = " + "!" + $2.label + ";\n";
			}

			| TK_ID TK_MAIS_MAIS
			{
				variavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}

			| TK_ID TK_MENOS_MENOS
			{
				variavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}

			|TK_TIPO_FLOAT '(' E ')'
			{		
				$$.label = gentempcode();
				$$.tipo  = "float";

				addTemp($$.label, $$.tipo);
				
				if($3.tipo == "int")
				{	
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(float) " + $3.label + ";\n";  
				}else
				{
					yyerror("operação inválida!");
				}
			}

			|TK_TIPO_INT '(' E ')'
			{	
				$$.label = gentempcode();
				$$.tipo  = "int";
				addTemp($$.label, $$.tipo);

				if($3.tipo == "float")
				{
					$$.traducao = $3.traducao + "\t" + 
					$$.label + " = " + "(int) " + $3.label + ";\n";
				}else
				{
					yyerror("operação inválida!");
				}
			}

			| TK_ID '=' E
			{
				variavelExistente($1.label);
				TIPO_SIMBOLO variavel = getSimbolo($1.label);

				if(variavel.tipoVariavel == $3.tipo){
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					variavel.labelVariavel + " = " + $3.label + ";\n";
				}
				else if (variavel.tipoVariavel == "int" & $3.tipo == "float")
				{
					$$.label = gentempcode();
					addTemp($$.label, "int");
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (int) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";
				}
				else if (variavel.tipoVariavel == "float" & $3.tipo == "int")
				{
					$$.label = gentempcode();
					addTemp($$.label, "float");
					$$.traducao = $1.traducao + $3.traducao + "\t" + 
					$$.label + " = (float) " + $3.label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + $$.label + ";\n";
				}
				else{
					yyerror("Atribuição inválida!");
				}
			}

			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}

			| TK_REAL
			{
				$$.tipo = "float";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				$$.valor = $1.label;
			}

			| TK_CHAR
			{
				$$.tipo = "char";
				$$.label = gentempcode();
				addTemp($$.label, $$.tipo);
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}

			| TK_ID '=' TK_TRUE
			{
				variavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = 1"  + ";\n";
			}

			| TK_ID '=' TK_FALSE
			{
				variavelExistente($1.label);
				TIPO_SIMBOLO variavel_1 = getSimbolo($1.label);
				$$.traducao = $1.traducao + $2.traducao + "\t" + 
				variavel_1.labelVariavel + " = 0"  + ";\n";
			}

			| TK_ID
			{ //indo na tabela de simbolo e verificando se o ID existe nela. 
				bool VarExiste = false;
				TIPO_SIMBOLO variavel = getSimbolo($1.label);
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == $1.label)
					{
						variavel = tabelaSimbolos[i];
						VarExiste = true;
					}	
				}

				if(!VarExiste)
				{
					yyerror("error: a variável '" + $1.label + "' não foi instanciada!");
				}

				$$.tipo = variavel.tipoVariavel;
				$$.label = variavel.labelVariavel;
				$$.traducao = "";
			}
			;

%%

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
