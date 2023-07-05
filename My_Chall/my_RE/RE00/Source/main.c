#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int check_pass( int size, char input[] )
{
    int check = 1;
    if( size != 0x27 )
    {
        return 1;
    }
    if( input[0] != 0x49 )
    {
        return check;
    }
    if( input[1] != 0x54 )
    {
        return check;
    }
    if( input[2] != 0x53 )
    {
        return check;
    }
    if( input[3] != 0x54 )
    {
        return check;
    }
    if( input[4] != 0x41 )
    {
        return check;
    }
    if( input[5] != 0x52 )
    {
        return check;
    }
    if( input[6] != 0x7b )
    {
        return check;
    }
    if( input[7] != 0x57 )
    {
        return check;
    }
    if( input[0x14] != 0x65 )
    {
        return check;
    }
    if( input[9] != 0x6c )
    {
        return check;
    }
    if( input[10] != 0x63 )
    {
        return check;
    }
    if( input[0xc] != 0x6d )
    {
        return check;
    }
    if( input[0xd] != 0x33 )
    {
        return check;
    }
    if( input[0xe] != 0x5f )
    {
        return check;
    }
    if( input[0xf] != 0x54 )
    {
        return check;
    }
    if( input[0x10] != 0x6f )
    {
        return check;
    }
    if( input[0x11] != 0x5f )
    {
        return check;
    }
    if( input[0x12] != 0x54 )
    {
        return check;
    }
    if( input[0x13] != 0x68 )
    {
        return check;
    }
    if( input[8] != 0x33 )
    {
        return check;
    }
    if( input[0x15] != 0x5f )
    {
        return check;
    }
    if( input[0x16] != 0x56 )
    {
        return check;
    }
    if( input[0x17] != 0x33 )
    {
        return check;
    }
    if( input[0x18] != 0x72 )
    {
        return check;
    }
    if( input[0x19] != 0x79 )
    {
        return check;
    }
    if( input[0x1a] != 0x5f )
    {
        return check;
    }
    if( input[0x1b] != 0x46 )
    {
        return check;
    }
    if( input[0x1c] != 0x31 )
    {
        return check;
    }
    if( input[0x1d] != 0x72 )
    {
        return check;
    }
    if( input[0x1e] != 0x73 )
    {
        return check;
    }
    if( input[0x1f] != 0x54 )
    {
        return check;
    }
    if( input[0x20] != 0x5f )
    {
        return check;
    }
    if( input[0x21] != 0x63 )
    {
        return check;
    }
    if( input[0x22] != 0x48 )
    {
        return check;
    }
    if( input[0x23] != 0x34 )
    {
        return check;
    }
    if( input[0x24] != 0x4c )
    {
        return check;
    }
    if( input[0x25] != 0x4c )
    {
        return check;
    }
    if( input[0x26] != 0x7d )
    {
        return check;
    }
    if( input[0xb] != 0x30 )
    {
        return check;
    }
    check = 0;
    return check;
}

int main()
{
    char input[160];
    int i = 0;
    printf("Enter pass: ");
    gets(input);
    fflush(stdin);
    int size = strlen(input);
    int check = check_pass(size,input);
    if( check == 1 )
    {
        printf("Sorry :(");
    }
    else
    {
        printf("Congrate :)");
    }
    return 0;
}
