
/*
 O arquivo come�a com a defini��o de uma gram�tica.
 O tipo pode ser "grammar" ou "lexer grammar".
 Se for "lexer grammar", � apenas um analisador l�xico;
 se for "grammar", combina analisador l�xico e sint�tico.
 O nome da gram�tica tem que ser o mesmo do arquivo.
 Ser� gerada uma classe Java com mesmo nome da gram�tica.
*/

lexer grammar Lex01;

/*
Em seguida, devem ser listadas as regras que definem lexemes.
O nome dos lexemes deve come�ar com letra mai�scula.
Podem tamb�m ser definidos express�es auxiliares que n�o configuram lexemes,
mas s�o usadas para auxiliar na constru��o dos lexems (nesse caso usar diretiva "fragment").
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
