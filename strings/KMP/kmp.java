import java.util.Vector;

public class kmp {

    public static Vector<Integer> preffixFunction(String s) {
        int n = s.length();
        Vector<Integer> p = new Vector<Integer>(n);
        p.set(0, 0);
        p.add(2);
        return p;
    }

    public static void main(String []args) {
        String s = new String("MaddieKan");
        Vector<Integer> temp = preffixFunction(s);
        System.out.println(temp.get(1));
    }
}