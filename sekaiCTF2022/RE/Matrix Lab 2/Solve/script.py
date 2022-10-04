# Use matlab web tool to find X and Y leading to find out C
X = [[16,2,3,13], [5,11,10,8], [9,7,6,12], [4,14,15,1]]
Y = [[1,1,1,1], [1,2,3,4], [1,3,6,10], [1,4,10,20]]
C = [[None for _ in range(len(X))] for _ in range(len(X))]
for i in range(len(X)):
    for j in range(len(X[i])):
        C[i][j] = X[i][j] + Y[i][j]
print(C)

# Use matlab to find B too when we have B it is quiet easy to retrieve the flag
B = [103, 30, 29, 102, 30, 104, 27, 31, 30, 125, 25, 121, 26, 103, 25, 11]
flag =""
for i in range(len(B)):
    flag += chr(B[i]^42)
print("SEKAI{" + flag + "}")
