# Easy RE

Bài này cho một file cpp. Đọc theo các dòng code của đề bài [source](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Easy%20RE/Source/easyre.cpp) thì ta thấy chương trình sau khi nhận input từ người dùng thì sẽ đem từng ký tự đi mã hóa rồi check xem coi nó có bằng giá trị hex trong một array gồm 25 giá trị hex không nếu đúng thì là _Correct_ và nếu sai thì là _Incorrect_.

_Lưu ý_ dòng code mã hóa này
```cpp
 	int enc[] = {0xa7, 0xc8, 0x87, 0xd6, 0x6e, 0x2a, 0xd8, 0x31, 0x49, 0x34, 0xe8, 0x35, 0x25, 0x9b, 0x5b, 0x11, 0x2c, 0xe2, 0xcb, 0x93, 0xcb, 0x67, 0xe, 0xb8, 0x7a};
 	int k = 0;
 	for(int i = 0;i < strlen(inp);i++){
 		if((inp[i] ^(rand() & 0xff)) == enc[i])
 		{
 			k = k + 1;	
 		}
```

Từng ký tự từ input của mình sẽ được XOR với cụm `rand()&0xff` và sẽ bằng enc vậy thì input đúng của chúng ta sẽ chỉ cần lấy enc XOR ngược lại với cụm `rand()&0xff` thôi. Từ đó mình có [script](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Easy%20RE/Solve.cpp)

Flag: `GDUCTF{70u_l1k3_r3v3rs3?}`
