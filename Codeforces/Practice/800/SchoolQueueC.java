import java.util.*;

public class SchoolQueueC {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), t = sc.nextInt();
        String queueLine = sc.next();
        char[] queue = queueLine.toCharArray();

        while (t-- > 0) {
            int i = 0;
            while (i < n - 1) {
                if (queue[i] == 'B' && queue[i + 1] == 'G') {
                    queue[i] = 'G';
                    queue[i + 1] = 'B';
                    i += 2;
                } else {
                    i++;
                }

            }
        }

        for (int i = 0; i < queue.length; i++) {
            System.out.print(queue[i]);
        }

        sc.close();
    }
}