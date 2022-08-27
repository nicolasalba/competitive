2. Rabin Karp.java

public class C {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String t;
    String p;
    long prime = 257;
    long mod = (int)1e9 + 7;// mod is prime and mod * mod < LONG_MAX_VALUE

    private void solve() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = st.nextToken();
        p = st.nextToken();
        int n = t.length();
        int m = p.length();

        if (n < m) {
            return;
        }

        long patterHash = 0;
        for (int i = 0; i < m; i++) {
            int charValue = p.charAt(i) - 'a' + 1;
            patterHash = multiply(patterHash, prime, mod);
            patterHash = add(patterHash, charValue, mod);
        }

        long currentHash = 0;
        for (int i = 0; i < m; i++) {
            int charValue = t.charAt(i) - 'a' + 1;
            currentHash = multiply(currentHash, prime, mod);
            currentHash = add(currentHash, charValue, mod);
        }

        long maxPower = 1;
        for (int i = 0; i < m - 1; i++) {
            maxPower = multiply(maxPower, prime, mod);
        }

        for (int i = 0; i <= n - m; i++) {
            if (currentHash == patterHash) {
                System.out.print("Same hash found starting in index " + i + " the substring is: ");
                System.out.println(t.substring(i, i + m));
            }
            if (i + m < n) {
                int head = t.charAt(i) - 'a' + 1;
                int next = t.charAt(i + m) - 'a' + 1;

                currentHash = subtract(currentHash, multiply(maxPower, head, mod), mod);
                currentHash = multiply(currentHash, prime, mod);
                currentHash = add(currentHash, next, mod);
            }
        }
    }

    public long add(long a, long b, long mod) {
        return ((a % mod) + (b % mod))%mod;
    }

    public long subtract(long a, long b, long mod) {
        long result = ((a % mod) - (b % mod))%mod;
        if (result < 0) {
            result += mod;
        }
        return result;
    }

    public long multiply(long a, long b, long mod) {
        return ((a % mod) * (b % mod)) % mod;
    }

    public static void main(String[] args) throws IOException {
        new C().solve();
    }
}