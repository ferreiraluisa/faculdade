// Generated from Lex01.g4 by ANTLR 4.4
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class Lex01 extends Lexer {
	static { RuntimeMetaData.checkVersion("4.4", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		KW_CLASS=1, KW_IF=2, KW_WHILE=3, SEMICOLON=4, OPEN_PAR=5, CLOSE_PAR=6, 
		PERIOD=7, IDENT=8, INTEGER_LITERAL=9, WS=10, COMMENT=11, LINE_COMMENT=12;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"'\\u0000'", "'\\u0001'", "'\\u0002'", "'\\u0003'", "'\\u0004'", "'\\u0005'", 
		"'\\u0006'", "'\\u0007'", "'\b'", "'\t'", "'\n'", "'\\u000B'", "'\f'"
	};
	public static final String[] ruleNames = {
		"KW_CLASS", "KW_IF", "KW_WHILE", "SEMICOLON", "OPEN_PAR", "CLOSE_PAR", 
		"PERIOD", "LETTER", "DIGIT", "IDENT", "INTEGER_LITERAL", "WS", "COMMENT", 
		"LINE_COMMENT"
	};


	public Lex01(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Lex01.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\16i\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3"+
		"\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t"+
		"\3\n\3\n\3\13\3\13\3\13\7\13>\n\13\f\13\16\13A\13\13\3\f\6\fD\n\f\r\f"+
		"\16\fE\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\7\16P\n\16\f\16\16\16S\13\16"+
		"\3\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\7\17^\n\17\f\17\16\17a\13"+
		"\17\3\17\5\17d\n\17\3\17\3\17\3\17\3\17\3Q\2\20\3\3\5\4\7\5\t\6\13\7\r"+
		"\b\17\t\21\2\23\2\25\n\27\13\31\f\33\r\35\16\3\2\5\4\2C\\c|\5\2\13\f\17"+
		"\17\"\"\4\2\f\f\17\17l\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2"+
		"\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31"+
		"\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\3\37\3\2\2\2\5%\3\2\2\2\7(\3\2\2\2"+
		"\t.\3\2\2\2\13\60\3\2\2\2\r\62\3\2\2\2\17\64\3\2\2\2\21\66\3\2\2\2\23"+
		"8\3\2\2\2\25:\3\2\2\2\27C\3\2\2\2\31G\3\2\2\2\33K\3\2\2\2\35Y\3\2\2\2"+
		"\37 \7e\2\2 !\7n\2\2!\"\7c\2\2\"#\7u\2\2#$\7u\2\2$\4\3\2\2\2%&\7k\2\2"+
		"&\'\7h\2\2\'\6\3\2\2\2()\7y\2\2)*\7j\2\2*+\7k\2\2+,\7n\2\2,-\7g\2\2-\b"+
		"\3\2\2\2./\7=\2\2/\n\3\2\2\2\60\61\7*\2\2\61\f\3\2\2\2\62\63\7+\2\2\63"+
		"\16\3\2\2\2\64\65\7\60\2\2\65\20\3\2\2\2\66\67\t\2\2\2\67\22\3\2\2\28"+
		"9\4\62;\29\24\3\2\2\2:?\5\21\t\2;>\5\21\t\2<>\5\23\n\2=;\3\2\2\2=<\3\2"+
		"\2\2>A\3\2\2\2?=\3\2\2\2?@\3\2\2\2@\26\3\2\2\2A?\3\2\2\2BD\5\23\n\2CB"+
		"\3\2\2\2DE\3\2\2\2EC\3\2\2\2EF\3\2\2\2F\30\3\2\2\2GH\t\3\2\2HI\3\2\2\2"+
		"IJ\b\r\2\2J\32\3\2\2\2KL\7\61\2\2LM\7,\2\2MQ\3\2\2\2NP\13\2\2\2ON\3\2"+
		"\2\2PS\3\2\2\2QR\3\2\2\2QO\3\2\2\2RT\3\2\2\2SQ\3\2\2\2TU\7,\2\2UV\7\61"+
		"\2\2VW\3\2\2\2WX\b\16\2\2X\34\3\2\2\2YZ\7\61\2\2Z[\7\61\2\2[_\3\2\2\2"+
		"\\^\n\4\2\2]\\\3\2\2\2^a\3\2\2\2_]\3\2\2\2_`\3\2\2\2`c\3\2\2\2a_\3\2\2"+
		"\2bd\7\17\2\2cb\3\2\2\2cd\3\2\2\2de\3\2\2\2ef\7\f\2\2fg\3\2\2\2gh\b\17"+
		"\2\2h\36\3\2\2\2\t\2=?EQ_c\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}