# Not keygen

Ban đầu mình cho chạy thử file exe đề cho thì đây là một chương trình check username và password.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/1.png)

Sau đó mình load vào IDA để phân tích. Ban đầu khá là vất vả vì mình không biết entry point của chương trình nằm ở đâu. Sau đó câu này có một hint là `base64 encoding`, nên mình đã tra từ khóa này trong IDA nhưng vẫn không tìm thấy gì :)

Lần mò một hồi thì mình thấy hàm này hơi khả nghi.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/2.png)

Bên trong hàm này có một đoạn chương trình sẽ gọi hàm `GetWindowTextA`, mình đoán đây là chỗ lấy thông tin nhập từ bàn phím. Mặt khác có 2 chuỗi nhìn rất giống base64 encoding được chuyển vào *edi* và *edx*.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/3.png)

Sau đó mình đem 2 chuỗi này decode trên [cyberchef](https://gchq.github.io/CyberChef/) nhưng không thu được chuỗi gì có nghĩa. Mình bèn đặt thử break point ở đây và phân tích từ từ xem sao.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/4.png)

Mình thử nhập cả username và password đều là _admin_. Lúc này khi chương trình chạy đến break point của mình register RDI đang giữ đoạn chuỗi base64 ban nãy đồng thời register RDX cũng đang giữ một đoạn base64 gì đó. Ok và mọi thứ càng sáng tỏ hơn khi ngay phía dưới đó là một đoạn lệnh so sánh giá trị của 2 chuỗi base64 này từ `edx` và `edi`.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/6.png)

Lúc này mình cũng khá chắc là 2 đoạn base64 tìm thấy là username và password rồi nhưng mà tại sao ban nãy decode không được. Thế là mình quay lại cyberchef vẫn là decode bằng base64 nhưng thử hết các bảng chữ cái. Và bingo đến khi mình chọn cái `z64` thì nó đã decode ra một đoạn có nghĩa.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/6.png)

Nhập username và password vào chương trình lần lượt là `Owgduadmin` và `A123@#4!Asq` thì ta sẽ nhận được flag của bài.

![alt text](https://github.com/bananNat/Writeups/blob/main/GDUCTF%202022/RE/Not%20keygen/Images/7.png)
