# Compilador Pandora
O Pandora é o desenvolvimento de um compilador que é demonstrado na disciplina Compiladores na Universidade Federal Rural do Rio de Janeiro.

## Entregas:

O projeto está sendo desenvolvido e será feito em 3 entregas. No momento somente foi concluída a entrega 1.

### Entrega 1:

- Expressão
- Tipos: Boolean, Int, Float, Char, 
- Conversão: Implícita, Explícita.
- Operadores: Lógico, Aritmético, Relacional
- Variável
- Atribuição

## Instalação

É necessário as ferramentas ``flex``, ``bison`` e ``gpp``.

### Ubuntu 
```console
sudo apt install build-essential flex bison
```

## Execução

Foi criado um ``Makefile`` com os comandos para a execução e o arquivo exemplo.foca será direcionado para a entrar do compilador gerado ao final do script.

```console
make
```

Materiais sobre a disciplina de compiladores: http://filipe.braida.com.br/pages/courses/compiladores/
