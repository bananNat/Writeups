import java.util.*; import javax.crypto.Cipher; import javax.crypto.spec.SecretKeySpec;
import java.security.*; class WarmUp {public static void main(String args[]) {
Scanner b = new Scanner(System.in); System.out.print("Enter password: ");
String c = b.next(); String f = c.substring(7,c.length()-1); WarmUp a = new WarmUp(); if (a.checkPassword(f)) {System.out.println("Access granted."); }
else {System.out.println("Access denied!"); } } public char[] mixing(String password) {
char[] a = password.toCharArray(); for (int b=0; b<a.length; b++) {char c = a[b]; c = switchBits(c,0,2); c = switchBits(c,1,3);c = switchBits(c,5,6); c = switchBits(c,4,7);
c = switchBits(c,0,3);c = switchBits(c,3,4); c = switchBits(c,2,6); c = switchBits(c,6,7); c = switchBits(c,0,1); a[b] = c; } return a;
} public char switchBits(char c, int p1, int p2) {
char mask1 = (char)(1 << p1);
char mask2 = (char)(1 << p2);char bit1 = (char)(c & mask1); char bit2 = (char)(c & mask2); char rest = (char)(c & ~(mask1 | mask2)); char shift = (char)(p2 - p1); char result = (char)((bit1<<shift) | (bit2>>shift) | rest); return result;
} public boolean checkPassword(String password) {char[] mixed = mixing(password); char[] expected = {
49,198,116,243,196,230,243,242,84,102,177,243,240,96,243,246,196,116,37,243,39,84,118,84,243,55,68,246,243,167,163,167,132 }; return Arrays.equals(mixed, expected); } }
