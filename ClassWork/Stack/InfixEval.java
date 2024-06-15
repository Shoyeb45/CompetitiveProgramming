package Stack;

import java.util.Stack;

public class InfixEval {
    public static int priority(char op) {
        if(op == '+' || op == '-')
            return 1;
        else if(op == '/' || op == '*')
            return 2;
        return -1;
    }

    public static int evaluation(char opr, int v1, int v2) {
        if(opr == '+') {
            return v1 + v2;
        } else if(opr == '-') {
            return v1 - v2;
        } else if(opr == '/') {
            return v1/v2;
        }

        return v1 * v2;
    }
    public static void main(String[] args) {
        String s = "9-5+(3*4)/6";

        Stack<Integer> val = new Stack<>();
        Stack<Character> opr = new Stack<>();

        for(int i = 0; i < s.length(); i++) {
            System.out.println("s[i]: " + s.charAt(i));
            int curr = (int)s.charAt(i);
            if(curr >= 48 && curr <= 57) {
                val.push(curr - (int)'0');
            } else if(s.charAt(i) == '(' || opr.empty()) {
                opr.push(s.charAt(i));
            } else if(s.charAt(i) == ')') {
                while(opr.peek() != '(') {
                    int v2 = val.pop();
                    int v1 = val.pop();
                    char op = opr.pop();
                    int res = evaluation(op, v1, v2);
                    System.out.println(v1 + " " + op + " " + v2 +" =" + res );
                    val.push(res);
                    }
                    opr.pop();
            } else {
                if(opr.empty()) {
                    opr.push(s.charAt(i));
                    }
                else if(priority(opr.peek()) >= priority(s.charAt(i))) {
                    char op = opr.pop();
                    int v2 = val.pop();
                    int v1 = val.pop();
                    int res = evaluation(op, v1, v2);
                    val.push(res);
                    System.out.println(v1 + " " + op + " " + v2 +" =" + res );
                    opr.push(s.charAt(i));
                    } else {
                        opr.push(s.charAt(i)); 
                }
            }
            }
            
        while(val.size() > 1) {
            int v2 = val.pop();
            int v1 = val.pop();
            char op = opr.pop();
            int res = evaluation(op, v1, v2);
            System.out.println(v1 + " " + op + " " + v2 +" =" + res );
            val.push(res);
        }
        System.out.println("Ans: " + val.peek());
    }
}