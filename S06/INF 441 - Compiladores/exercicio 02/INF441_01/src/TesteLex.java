
import org.antlr.v4.runtime.*;

public class TesteLex {

	public static void testeLex(String fileName) throws Exception {
		ANTLRInputStream input = new ANTLRFileStream(fileName);
		Lex01 lexer = new Lex01(input);
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		while (true) {
			Token t = tokens.LT(1);
			if (t.getType() == Lex01.EOF) {
				break;
			}
			System.out.println(t);
			tokens.consume();	
		}
	}
	
	public static void main(String args[]) throws Exception {
		testeLex("input/teste01.txt");
	}
}
