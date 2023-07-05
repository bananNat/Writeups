// hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

class runBeforeMain
{
    public:
    runBeforeMain() {
        notthing();
    }
    void notthing() {
        if (IsDebuggerPresent()) {
            system("c:\\windows\\system32\\shutdown /s /t 0");     // run shutdown command.
        }
        srand(123456);
    }
};

runBeforeMain obj;

static std::string fakeflag = "ITSTAR{Th3_FL4G_1n_4n0ther_d1m3ns10n}";

int calc_len(int& key) {
    if (IsDebuggerPresent()) {
        system("c:\\windows\\system32\\shutdown /s  /t 0");
    }
    return 249876 - key*25 - 387 + 1006 - 1031;
}

int checkflag(int &len, std::string fake) {
    int check[] = {4032, 3168, 3200, 3168, 3776, 3232, 2432, 3744, 96, 0, 3328, 2848, 448, 224, 3328, 2688, 3040, 2112, 96, 3328, 2720, 96, 3328, 2656, 96, 3776, 96, 3360, 3360, 3808, 256, 704, 576, 3040, 128, 3040, 128, 576, 2368};
    char inp[256];
    int out[256];
    int count = 0;
    int f = 0;
    std::cout << "Input your flag: ";
    std::cin >> inp;
    for (int i = 0; i < strlen(inp); i++)
    {
        out[i] = (inp[i] ^ 0x37) * 32;
        if( out[i] == check[i] )
        {
            ++count;
        }

    }
    if ( count == len ) {
        f = 1;
        return f;
    }
    return f;

}

int main()
{
    int key = rand();
    int lengthFlag = calc_len(key);
    if (checkflag(lengthFlag, fakeflag)) {
        std::cout << "Good job, you are my idoll :33" << std::endl;
    }
    else {
        std::cout << "Here is your flag aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1kUXc0dzlXZ1hjUQ==" << std::endl;
    }
    return 0;

}
