import java.util.*;;

public class Watermelon4A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int w = input.nextInt();

        if((w / 2) % 2 == 0)
        System.out.println("Yes");
        else
        System.out.println("No");

        input.close();

    }
}