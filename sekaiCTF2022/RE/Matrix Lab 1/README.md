# Matrix Lab 1

Đề cho mình một file [class java](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%201/Source/Matrix_Lab_1.class) là code java đã được compiled nên mình dùng [tool](http://www.javadecompilers.com/) này để decompiled nó lại để xem code nó như thế nào. Đây là code java sau khi đã được decompiled: [source](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%201/Source/Matrix_Lab_1.java)

Mình bắt đầu đọc code và phân tích từng function xem chương trình này chạy như thế nào.

Đầu tiên là hàm `main`

```java
private static int length;
public static void main(final String[] array) {
        final Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the flag: ");
        final String next = scanner.next();
        if (next.length() != 43) {
            System.out.println("Oops, wrong flag!");
            return;
        }
        final String substring = next.substring(0, Sekai.length);
        final String substring2 = next.substring(Sekai.length, next.length() - 1);
        final String substring3 = next.substring(next.length() - 1);
        if (substring.equals("SEKAI{") && substring3.equals("}")) {
            assert substring2.length() == Sekai.length * Sekai.length;
            if (solve(substring2)) {
                System.out.println("Congratulations, you got the flag!");
            }
            else {
                System.out.println("Oops, wrong flag!");
            }
        }
        else {
            System.out.println("Oops, wrong flag!");
        }
    }
static {
        Sekai.length = (int)Math.pow(2.0, 3.0) - 2;
    }
```

Ta có thể dễ dàng nhận ra biến length hay Sekai.length có giá trị bằng 6. Hàm `Main` yêu cầu ta nhập flag vào và kiểm tra nó, nếu flag có độ dài khác 43 thì in ra sai rồi kết thúc ngay, suy ra flag có 43 ký tự. Sau đó chương trình tiến hành cắt chuỗi `SEKAI{` ở đầu và `}` ở đuôi ra rồi đem phần giữa  truyền vào hàm `solve` để kiểm tra. Lúc này nếu ta để ý thì flag có 43 ký tự mà cắt chuỗi đầu đuôi đi thì đoạn giữa này sẽ có 36 ký tự bằng với 6x6, hãy nhớ điểm này nhé vì nó khá quan trọng khúc sau đấy.

Trước khi đến với hàm `solve` thì mình sẽ đi qua 3 hàm còn lại trước vì hàm `solve` này chủ yếu gọi các hàm này để mã hóa và kiểm tra flag của chúng ta.

Kế đến là hàm `transform`

```java
public static char[][] transform(final char[] array, final int n) {
        final char[][] array2 = new char[n][n];
        for (int i = 0; i < n * n; ++i) {
            array2[i / n][i % n] = array[i];
        }
        return array2;
    }
```

Hàm này nhận vào 1 mảng ký tự `array` và một số nguyên n rồi trả về 1 mảng 2 chiều có kích thước nxn là `array2`, có thể hiểu nôm na nó là một ma trận với n hàng và n cột. Vòng lặp for có chức năng điền từng ký tự của mảng `array` vào lần lượt từng vị trí trên mỗi hàng có n vị trí từ trái sang phải tương ứng với index [0][0], [0][1], [0][2], ... [0][n-1] và cứ như vậy cho đến khi điền đủ n hàng hoàn thành ma trận nxn `array2` thì return.

Kế đến là hàm `getArray`

```java
public static char[] getArray(final char[][] array, final int n, final int n2) {
        final char[] array2 = new char[Sekai.length * 2];
        int n3 = 0;
        for (int i = 0; i < Sekai.length; ++i) {
            array2[n3] = array[n][i];
            ++n3;
        }
        for (int j = 0; j < Sekai.length; ++j) {
            array2[n3] = array[n2][Sekai.length - 1 - j];
            ++n3;
        }
        return array2;
    }
```
Hàm này nhận vào một mảng 2 chiều `array` và 2 số n, n2; return ra một mảng ký tự `array2` có 12 ký tự ( do Sekai.length*2 ). Sau đó có 2 vòng for mỗi vòng sẽ điền lần lượt từng 6 ký tự vào `array2`. Với vòng for đầu tiên sẽ lấy từ hàng có index n của ma trận `array` lấy 6 ký tự đầu tiên của hàng này điền vào 6 ký tự đầu tiên của `array2`. Vòng for sau thì lấy từ hàng n2 của ma trận `array` điền tiếp 6 ký tự tiếp theo nhưng là theo chiều ngược lại của hàng n2. Khi điền đủ 12 ký tự vào mảng `array2` rồi thì return nó.

Kế đến là hàm `encrypt`

```java
public static String encrypt(final char[] array, final int n) {
        final char[] data = new char[Sekai.length * 2];
        int n2 = Sekai.length - 1;
        int length = Sekai.length;
        for (int i = 0; i < Sekai.length * 2; ++i, ++i) {
            data[i] = array[n2--];
            data[i + 1] = array[length++];
        }
        for (int j = 0; j < Sekai.length * 2; ++j) {
            final char[] array2 = data;
            final int n3 = j;
            array2[n3] ^= (char)n;
        }
        return String.valueOf(data);
    }
```

Hàm này rất quan trọng vì nó dùng để mã hóa flag của chúng ta. Hàm này nhận vào mảng ký tự `array` và số n rồi trả về chuỗi `data` được convert từ char array sang string sau khi đã mã hóa. Đầu tiên mảng data được khai báo có 12 ký tự; n2 có giá trị bằng 5 và length bằng 6, 2 biến này dùng để đánh dấu vị trí để lấy ký tự từ `array` ở vòng for sau. Vòng for sau nhằm điền các ký tự từ `array` vào `data` theo quy tắc sau:

- Mỗi vòng for điền 2 ký tự
- Ký tự đầu tiên lấy bắt đầu từ index n2 là 5 và sau mỗi vòng for lùi dần về 0
- Ký tự thứ hai lấy bắt đầu từ index length là 6 và sau mỗi vòng for thì tăng dần lên 11
- Sau mỗi vòng for tăng i lên 2 đơn vị

Ở vòng for thứ 2, ta đem từng ký tự của data đi xor với n (trên code khai báo thêm `array2` rồi trỏ vào `data` nên thay đổi `array2` cũng là thay đổi `data`). Cuối cùng return chuỗi `data` 12 ký tự đã được mã hóa.

Cuối cùng đến với nhân vật chính của chúng ta hàm `solve`

```java
public static boolean solve(final String s) {
        final char[][] transform = transform(s.toCharArray(), Sekai.length);
        for (int i = 0; i <= Sekai.length / 2; ++i) {
            for (int j = 0; j < Sekai.length - 2 * i - 1; ++j) {
                final char c = transform[i][i + j];
                transform[i][i + j] = transform[Sekai.length - 1 - i - j][i];
                transform[Sekai.length - 1 - i - j][i] = transform[Sekai.length - 1 - i][Sekai.length - 1 - i - j];
                transform[Sekai.length - 1 - i][Sekai.length - 1 - i - j] = transform[i + j][Sekai.length - 1 - i];
                transform[i + j][Sekai.length - 1 - i] = c;
            }
        }
        return "oz]{R]3l]]B#50es6O4tL23Etr3c10_F4TD2".equals( encrypt(getArray(transform, 0, 5), 2) + encrypt(getArray(transform, 1, 4), 1) + encrypt(getArray(transform, 2, 3), 0)));
    }
```
Quá trình diễn ra như sau:
1. Chuỗi `s` 36 ký tự được biến thành ma trận 6x6 được gọi là `transform`
2. Vòng for lồng nhau hoán đổi vị trí các ký tự trong ma trận
3. Hàm `getArray` lấy 2 hàng từ ma trận `transform` tạo ra 1 mảng 12 ký tự
4. Hàm `encrypt` mã hóa mảng 12 ký tự rồi trả về chuỗi 12 ký tự
5. Cộng 3 chuỗi lại rồi so sánh với chuỗi đã cho.

OK vậy là mình đã phân tích xong chương trình chạy như thế nào. Bây giờ thì viết script để đảo ngược lại quá trình này. Mình chủ yếu dựa vào những đoạn code trên mà viết sao cho nó ngược lại nên chưa được tối ưu lắm. [Script](https://github.com/bananNat/Writeups/tree/main/sekaiCTF2022/RE/Matrix%20Lab%201/Solve)
