# Rota
Ta được cung cấp 2 file `rota` và `flag.jpg.enc`

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/1.png)

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/2.png)

Ta chạy thử file Rota

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/5.png)

File Rota này yêu cầu một file khác làm input mà file còn lại ta nhận được có đuôi .enc(encrypt) nên có thể đoán được file flag.jpg đã được cho vào Rota để mã hóa thành file flag.jpg.enc, vậy công việc của ta là sẽ decrypt nó để đọc được flag. Mình load vào Ghidra để phân tích.

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/3.png)

Vào hàm main, sau một hồi xem nó có gì thì mình thấy nó gọi 3 hàm khả nghi `FUN_00401200`, `FUN_004016c0` và `FUN_00401460`.

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/4.png)

Phân tích sâu vào hàm `FUN_004016c0` ta thấy đây là đoạn code dùng để mã hóa file flag.jpg.

Sau một hồi research thì đây là đoạn script dùng để giải bài này [Script](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/script/decrypt.py)

Cuối cùng thì xem flag thôi !!

![alt text](https://github.com/bananNat/Writeups/blob/main/FPTU%20Hacking%20CTF%202022/Rota/images/6.png)

