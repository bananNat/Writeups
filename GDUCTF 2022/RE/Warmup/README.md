# Warmup

Đây là chương trình đề cho. [link](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Warmup/Source/chall1.exe)

Chạy thử chương trình thì nó bảo mình nhập flag, nhập đại vào thì nó tắt chương trình ngay.

Sau đó mình load vào IDA để phân tích và mọi thứ sau đó hoàn toàn bế tắc vì có rất nhiều hàm trong chương trình này và minh không tìm được hàm main hay entry point của nó.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Warmup/images/1.png)

Sau đó mình xem hint của bài được cấp cho là `pyinstxtractor`, sau đó mình tra xem nó là gì thì đây là một đoạn [script](https://github.com/extremecoders-re/pyinstxtractor) dùng để extract ra các file pyc do `PyInstaller` nén lại thành 1 file _exe_ duy nhất để thực thi nó mà không cần cài trình biên dịch của python hay các module python có liên quan. Thế là mình tải script về và chạy thử.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Warmup/images/2.png)

Ok vậy là mình đã extract ra một folder chứa rất nhiều file python đã được compiled trong đó. Hèn gì lúc xem trong IDA lại có nhiều hàm đến vậy. Và để ý khi chạy script `pyinstxtractor` nó cũng cho mình biết một số entry point có thể. Trong đó có thằng `chall3.pyc` nhìn rất đáng ngờ. Mình bèn dùng một python decompiler là [uncompyle6](https://pypi.org/project/uncompyle6/) để xem code python của nó.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Warmup/images/3.png)

Vậy là ta đã tìm ra được hàm main của chương trình này. trong đoạn code có một đoạn so sánh inout của mình với một đoạn binary. Minh bèn đem chuỗi binary đó decode bằng [cyberchef](https://gchq.github.io/CyberChef/) thì nhận được flag luôn !!

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Warmup/images/4.png)
