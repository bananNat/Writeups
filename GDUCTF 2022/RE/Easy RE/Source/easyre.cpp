#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
	char inp[1024] = "";
	printf("[+] Input Flag : ");
	scanf("%s",&inp);
	srand(1468);
	int enc[] = {0xa7, 0xc8, 0x87, 0xd6, 0x6e, 0x2a, 0xd8, 0x31, 0x49, 0x34, 0xe8, 0x35, 0x25, 0x9b, 0x5b, 0x11, 0x2c, 0xe2, 0xcb, 0x93, 0xcb, 0x67, 0xe, 0xb8, 0x7a};
	int k = 0;
	for(int i = 0;i < strlen(inp);i++){
		if((inp[i] ^(rand() & 0xff)) == enc[i])
		{
			k = k + 1;	
		}
		else
		{
			printf("Incorrect!");
			return 0;	
		}
		if(k == 25){
			printf("Correct!");
			return 0;
		}
	}
}
