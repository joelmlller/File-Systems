# 1 "hello.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 370 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "hello.c" 2



int printf(const char * restrict, ...) __attribute__((__format__ (__printf__, 1, 2)));


int main()
{
    int i = 10;
    int number = 10;
    while(i > 0)
    {
        printf("%d = number hello world\n", 10);
        i--;
    }

    return 0;
}
