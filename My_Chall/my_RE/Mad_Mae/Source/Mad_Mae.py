print('Welcome to ITSTAR !')
print('Starting....')
try:
    import matlab.engine
    engine = matlab.engine.start_matlab()
    flag = input('Enter the lab passcode: ').strip()
    outcome = False
    if len(flag) == 24 and flag[:7] == 'ITSTAR' and flag[-1:] == '}':
        A = [ord(i) ^ 42 for i in flag[7:-1]]
        B = matlab.double([A[i:i + 4] for i in range(0, len(A), 4)])
        X = [list(map(int, i)) for i in engine.magic(4)]
        Y = [list(map(int, i)) for i in engine.pascal(4)]
        C = [[None for _ in range(len(X))] for _ in range(len(X))]
        for i in range(len(X)):
            for j in range(len(X[i])):
                C[i][j] = X[i][j] + Y[i][j]

        C = matlab.double(C)
        if engine.mtimes(C, engine.rot90(engine.transpose(B), 1016)) == matlab.double([[3989, 4328, 4257, 2315], [3902, 4516, 3993, 2689], [5334, 5852, 5478, 2792], [6367, 6950, 6456, 3619]]):
            outcome = True
    elif outcome:
        print('Congratulation! Your input is the flag.')
    else:
        print('Access Denied! Your flag: ITSTAR{aHR0cHM6Ly95b3V0dS5iZS9kUXc0dzlXZ1hjUQ==}')
except:
    print('Unknown error. Maybe you are running the lab in an unsupported environment...')
    print('Your flag: ITSTAR{aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1NNVZfSVhNZXdsNCZ0PTIxODJz}')