#Matrix Lab 2

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/1.png)

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/2.png)

Tải file exe đề cho về nhìn thấy cái icon này là mình biết 99% là người ra đề đã dùng [pyinstaller](https://github.com/pyinstaller/pyinstaller) nên mình dùng [pyinstxtractor](https://github.com/extremecoders-re/pyinstxtractor) để extract từ exe ra các file pyc để chạy chương trình này.

**Pyinstxtractor** gợi ý cho mình những entry point có thể và mình thấy thằng Matrix_Lab.pyc là sus nhất nên sau đó mình tiến hành dùng [uncompyle6](https://pypi.org/project/uncompyle6/) để decompile pyc sang code python và nhận được source code của chương trình này.

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/3.png)

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/4.png)

Lúc này ta mới tiến hành dịch ngược chương trình này. [Source](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Source/Matrix_Lab_2.py)

Module `matlab.engine` được sử dụng trong bài là một API của [matlab](https://www.mathworks.com/help/matlab/matlab-engine-for-python.html) nhằm giúp cho các lập trình viên có thể sử dụng các hàm, chức năng của matlab để lập trình với python vì thế nên nếu máy bạn chưa cài matlab thì không có install được module này đâu nha :)

Dành cho bạn nào không muốn cài matlab vì quá lười giống mình thì bạn có thể đăng ký một tài khoản mathwork và sử dụng matlab web ở [đây](https://matlab.mathworks.com/). Việc này để test thử các hàm matlab xem nó chạy như thế nào.

Đầu tiên chương trình bảo mình nhập passcode, đây cũng chính là flag của đề bài. Sau đó tiến hành một số bước kiểm tra nó.

```python
 if len(flag) == 23 and flag[:6] == 'SEKAI{' and flag[-1:] == '}':
        A = [ord(i) ^ 42 for i in flag[6:-1]]
        B = matlab.double([A[i:i + 4] for i in range(0, len(A), 4)])
        X = [list(map(int, i)) for i in engine.magic(4)]
        Y = [list(map(int, i)) for i in engine.pascal(4)]
        C = [[None for _ in range(len(X))] for _ in range(len(X))]
        for i in range(len(X)):
            for j in range(len(X[i])):
                C[i][j] = X[i][j] + Y[i][j]

        C = matlab.double(C)
```

Check xem flag có đúng 23 ký tự hay không, check format flag cái đúng hay không, rồi đem phần giữa của flag gồm 16 ký tự, mỗi ký tự xor với 42 rồi nhét vào list `A`. Vậy ta có list `A` gồm 16 ký tự của flag đã được xor với 42.

Sau đó lấy từng bộ 4 ký tự của `A` nhét vào list `B` tạo thành một ma trận 4x4. Hàm `matlab.double` chỉ đơn giản là đổi kiểu dữ liệu từ int sang double thôi không cso gì đặc biệt.

Kế đến là `X` và `Y`, các bạn có thể tìm hiểu về hàm [list](https://www.w3schools.com/python/ref_func_list.asp) và [map](https://www.w3schools.com/python/ref_func_map.asp), đồng thời chạy trên matlab xem *engine.magic(4)* và *engine.pascal(4)* là gì.

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/5.png)

Có thể hiểu lúc này `X` và `Y` đang là 2 ma trận trong hình trên.

Mình viết lại đoạn code y chang đề để tìm `C` thêm vào đó là `X` và `Y` tìm được.

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/6.png)

Cuối cùng là phần mã hóa.

```python
if engine.mtimes(C, engine.rot90(engine.transpose(B), 1337)) == matlab.double([[2094, 2962, 1014, 2102], [2172, 3955, 1174, 3266], [3186, 4188, 1462, 3936], [3583, 5995, 1859, 5150]]):
            outcome = True
```

Phân tích:
1. **engine.transpose(B)** trả về ma trận chuyển vị của ma trận B, giả sử gọi là ma trận K
2. **engine.rot90(engine.transpose(B), 1337)** đem ma trận K xoay 90x1337 độ = 360x334 + 90 độ => ma trận K chỉ xoay 90 độ, giả sử gọi là ma trận Z
3. **engine.mtimes(C, engine.rot90(engine.transpose(B), 1337))** đem ma trận C nhân với ma trận Z rồi so sánh với ma trận đã được mã hóa.

Dịch ngược:
1. Đem ma trận nghịch đảo của `C` nhân với ma trận đề cho ra ma trận Z ( **Lưu ý**: thứ tự nhân ma trận phải chính xác )
2. Đem ma trận Z xoay 270 độ để về lại vị trí cũ ra ma trận K
3. Đem ma trận K chuyển vị lại ra ma trận B

![alt-text](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Images/7.png)

Okie phần khó đã xong, có ma trận `B` rồi thì đem từng phần tử đi xor với 42 là ra flag rồi. [script](https://github.com/bananNat/Writeups/blob/main/sekaiCTF2022/RE/Matrix%20Lab%202/Solve/script.py)
