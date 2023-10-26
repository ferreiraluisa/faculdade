
/*
 O arquivo começa com a definição de uma gramática.
 O tipo pode ser "grammar" ou "lexer grammar".
 Se for "lexer grammar", é apenas um analisador léxico;
 se for "grammar", combina analisador léxico e sintático.
 O nome da gramática tem que ser o mesmo do arquivo.
 Será gerada uma classe Java com mesmo nome da gramática.
*/

lexer grammar Lex01;

/*
Em seguida, devem ser listadas as regras que definem lexemes.
O nome dos lexemes deve começar com letra maiúscula.
Podem também ser definidos expressões auxiliares que não configuram lexemes,
mas são usadas para auxiliar na construção dos lexems (nesse caso usar diretiva "fragment").
*/


KW_CLASS : 'class';

KW_IF : 'if';

KW_WHILE : 'while';

SEMICOLON : ';';

OPEN_PAR : '(';

CLOSE_PAR : ')';

PERIOD : '.';

KW_PROGRAM: 'program';

fragment
LETTER : 'a'..'z' | 'A'..'Z' ;

fragment
DIGIT : '0'..'9' ;

IDENT : LETTER (LETTER | DIGIT)* ;


INTEGER_LITERAL : DIGIT+ ;

FLOAT: DIGIT* (PERIOD DIGIT*)? (('E' | 'e') ('+' | '-')? DIGIT*)? ;

WS : (' '|'\r'|'\t'|'\n') -> skip ;

COMMENT : '/*' .*? '*/' -> skip ;

LINE_COMMENT : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;
