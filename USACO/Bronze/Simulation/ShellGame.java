
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ShellGame {
    public static int choose(boolean[] games, int idx, int[][] arr) {
        int ans;
        ans = 0;
        games[idx] = true;

        for(var it: arr) {  // 0 2 1
            boolean temp = games[it[0]];
            games[it[0]] = games[it[1]];
            games[it[1]] = temp;

            if(games[it[2]]) {
                ans++;
            }
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio("shell");

		
        int n = io.nextInt();

        int[][] arr = new int[n][3];
        for(var it: arr) {
            for(int i = 0; i <= 2; i++) {
                it[i] = io.nextInt();
                it[i]--;
            }
        }

        boolean[] games = new boolean[3];

        int[] ans = new int[3];
        for(int i = 0; i < 3; i++) {
            ans[i] = choose(games, i, arr);
            for(int j = 0; j < 3; j++) {
                games[j] = false;
            }
        }
        Arrays.sort(ans);

        io.println(ans[2]);
        io.close();
    }

    static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
}