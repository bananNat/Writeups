# Math

Thoạt đầu mình cho chạy file thì đây là một chương trình trả lời 10 câu hỏi, có lẽ nếu mình trả lời đúng cả 10 câu thì sẽ có flag.

![alt text](https://github.com/bananNat/Writeups/blob/main/LITCTF%202022/RE/images/1.png)

Mình bắt đầu load vào ghidra để phân tích thì có hàm `grade test` làm mình chú ý

![alt text](https://github.com/bananNat/Writeups/blob/main/LITCTF%202022/RE/images/2.png)

Ta thấy cứ mỗi một lần check `submitted` mà đúng với `answers` thì biến check_correct sẽ được tăng lên 1 và nếu check_correct mà bằng 10 thì sẽ in ra flag. Vậy nên mình xem coi bên trong thằng `answers` chứa gì.

![alt text](https://github.com/bananNat/Writeups/blob/main/LITCTF%202022/RE/images/3.png)

Bùm vậy là ta có ở đây một vùng nhớ chứa kết quả của tất cả các câu hỏi của đề bài. Cứ mỗi 8 bytes lưu trữ đáp án của 1 câu hỏi. Thế là mình dựa vào cái stack này để trả lời đúng cả 10 câu hỏi để lấy được flag.

_Lưu ý_: dữ liệu được lưu trữ dưới dạng little endian nên ta phải đọc thứ tự các byte từ dưới lên nhé VD như từ ô 32-35 thì phải đọc theo thứ tự là 09de8d6d.

![alt text](https://github.com/bananNat/Writeups/blob/main/LITCTF%202022/RE/images/4.png)
