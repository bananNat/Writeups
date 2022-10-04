public class Script
{

    public static void main(String[] args) {
        String str1 = "oz]{R]3l]]B#";
        String str2 = "50es6O4tL23E";
        String str3 = "tr3c10_F4TD2";
        char[][] myArray = new char[6][6];

        get2DArray(myArray, decrypt(str1, 2), 0, 5);
        get2DArray(myArray, decrypt(str2, 1), 1, 4);
        get2DArray(myArray, decrypt(str3, 0), 2, 3);
        
        getFlag(myArray);
        
        System.out.print("SEKAI{");
        for(int i = 0;i < 6; ++i)
        {
            for( int j = 0; j < 6; ++ j)
            {
                System.out.print(myArray[i][j]);
            }
        }
        System.out.print("}");
    }
    
    public static void getFlag(char[][] myArray)
    {
        for( int i = 0; i <= 6/2 ; ++i )
        {
            for( int j = 0; j < 6 - 2*i -1; ++j )
            {
                char c = myArray[i+j][6-1-i];
                myArray[i+j][6-1-i] = myArray[6-1-i][6-1-i-j];
                myArray[6-1-i][6-1-i-j] = myArray[6-1-i-j][i];
                myArray[6-1-i-j][i] = myArray[i][i+j];
                myArray[i][i+j] = c;
            }
        }
    }
    
    public static void get2DArray(char[][] myArray, char[] str, int n1, int n2)
    {
        int n3 = 0;
        for( int i = 0; i < 6; ++i )
        {
            myArray[n1][i] = str[n3];
            ++n3;
        }
        
        for( int i = 0; i < 6; ++i )
        {
            myArray[n2][6-1-i] = str[n3];
            ++n3;
        }
    }
    
    public static char[] decrypt(String str, int n)
        {
            char[] res = new char[12];
            char[] data = str.toCharArray();
            for( int i = 0; i < 12; ++i )
            {
                data[i] ^= (char)n;
            }
        
            int n2 = 5;
            int len = 6;
            for( int i = 0; i < 12; ++i, ++i )
            {
                res[n2] = data[i];
                res[len] = data[i+1];
                --n2;
                ++len;
            }
            return res;
        } 
}
