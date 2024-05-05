all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -w
		./glf < exemplo.pandora

commit:
		git init
		git add .
		git commit -m "final commit"
		git branch -M Entrega_Final
		git push -u origin Entrega_Final