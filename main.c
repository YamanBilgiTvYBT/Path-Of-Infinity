#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpfr.h>
#include <windows.h>

#define P 10000000L

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Run Path Of Infinity? (Y/N): ");
    char c = getchar();
    if(c == 'N' || c == 'n'){
        Sleep(1000);
        return 0;
    }
    if(c != 'Y' && c != 'y'){
        return 0;
    }
    Sleep(250);
    system("cls");
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("Starting...");
    Sleep(250);
    system("cls");
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Starting...");
    Sleep(250);
    system("cls");
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("Starting...");
    Sleep(250);
    system("cls");
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Starting...");
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
    Sleep(1000);
    mpfr_t x;
    mpfr_init2(x, P);
    mpfr_set_ui(x, 2, MPFR_RNDN);
    while(1){
        mp_exp_t e;
        char *s = mpfr_get_str(NULL, &e, 10, 0, x, MPFR_RNDN);
        if(!s){
            printf("ERROR:");
            break;
        }
        char *d = s;
        if(*d == '-'){
            d++;
        }
        int n = strlen(d);
        while(n > 1 && d[n - 1] == '0'){
            d[--n] = '\0';
        }
        system("cls");
        if(e <= 0){
            printf("0.");
            for(mp_exp_t i = 0; i < -e; i++){
                printf("0");
            }
            printf("%s\n", d);
        }
        else if((size_t)e >= (size_t)n){
            printf("%.*s\n", n, d);
        }
        else{
            printf("%.*s.%s\n", (int)e, d, d + e);
        }
        mpfr_free_str(s);
        fflush(stdout);
        mpfr_mul(x, x, x, MPFR_RNDN);
    }
    mpfr_clear(x);
    return 0;
}
