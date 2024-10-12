import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Solution {
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next()
        {
            while(st==null || !st.hasMoreTokens())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
        long nextLong()
        {
            return Long.parseLong(next());
        }
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
        String nextLine()
        {
            String str="";
            try
            {
                str = br.readLine().trim();
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter
    {
        private final BufferedWriter bw;
        public FastWriter()
        {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }
        public void print(Object object) throws IOException
        {
            bw.append(""+object);
        }
        public void println(Object object) throws IOException
        {
            print(object);
            bw.append("\n");
        }
        public void close() throws IOException
        {
            bw.close();
        }
    }
    static final int MOD = (int)1e9+7;
    static final int MAX = Integer.MAX_VALUE;
    static final int MIN = Integer.MIN_VALUE;
    public static boolean isPrime(int n) {if(n==1) return false;if(n==2 || n==3) return true;for(int i = 2; i*i<=n;i++) {if(n%i==0) return false;}return true;}
    public static long gcd(long a,long b) { return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();}

    public static long lcm(long a,long b) {return (a*b)/gcd(a,b);}
    public static int lcm(int a,int b) {return (int) ((a*b)/gcd(a,b));}
    public static boolean even(long n) {if((n&1)!=0) return false;return true;}
    public static long pow(long a , long b){
        if(a == 0 && b == 0) return 1;
        else if(b == 0) return 1;
        else if(a == 0) return 0;
        long ans = pow(a,b/2);
        if(b%2==0) return  (ans*ans % MOD);
        return  (((ans *ans) % MOD) *a )% MOD;
    }

    public static void main(String[] args) throws IOException {
        try
        {
            FastReader in  = new FastReader();
            FastWriter out = new FastWriter();
            // Write your code here
            long t = in.nextLong();
            while(t-->0) {
                int n = in.nextInt();
                int arr[] = new int[n];
                HashSet<Integer> set = new HashSet<>();
                boolean flag = false;
                for(int i = 0 ; i < n;i++) {
                    arr[i] = in.nextInt();
//                    if(arr[i] == 1)
//                    {
//                        flag = true;
//                    }
                    set.add(arr[i]);
                }
//                if(flag){
//                    out.println(n);
//                    continue;
//                }
                if(set.size() == 1 ){
                    out.println(n*arr[0]);
                    continue;
                }
                int res = arr[0];

                for(int i = 1 ;i < n ;i++)
                {
                    if(arr[i] == 1)
                    {
                        res += 1;
                        continue;
                    }
                    if(res >= arr[i]){
                        int val = arr[i];
//                        int mul = 2;
                        while(val != 1 && res >= val)
                        {
                            val += arr[i];
                        }
                        res = val;
//                        System.out.println(res);
                    }
                    else {
                        res = arr[i];
                    }
                }
                out.println(res);

            }
            out.close();
        }
        catch (Exception e) {
            throw e;
        }
    }
}
class Pair {
     int first;
     int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    // Override hashCode() and equals() methods

    @Override
    public int hashCode() {
        return 31 * first + second;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Pair other = (Pair) obj;
        return first == other.first && second == other.second;
    }
}
