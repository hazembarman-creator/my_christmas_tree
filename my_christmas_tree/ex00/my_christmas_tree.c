#include <unistd.h>

//elements
char _ = ' ';
char point = '*';
char n = '\n';
char trunk = '|';

//starting values
int points = 1;
int h = 4;

//difference of every fourth brunching
int dif = 2;
int dif_c = 0;

int atoi(char* num){
    int res = 0;
    for(int i = 0; num[i] != '\0'; i++) res += res*10 + (num[i] - '0');
    return res;
}

int tree_max_width(int a){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < h; j++) points += 2;

        if(dif_c == 2){
            dif_c = 0;
            dif += 2;
        }

        points -= (2 + dif);
        dif_c++;
        h++;
    }

    int max = points + dif;

    points = 1;
    h = 4;
    dif = 2;
    dif_c = 0;

    return max;
}

void putc(char c, int count){
    for(int i = 0; i < count; i++) write(1, &c, 1);
}

void tree_printer(int a, int max){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < h; j++){
            //spaces print
            putc(_, (max - points) / 2);

            //points print
            putc(point, points);
            points += 2;

            //\n print
            putc(n, 1);
        }

        if(dif_c == 2){
            dif_c = 0;
            dif += 2;
        }

        points -= (2 + dif);
        dif_c++;
        h++;
    }
}

void my_christmas_tree(int a){
    //errors
    if(a <= 0) return;

    //max width counting for spaces counting
    int max = tree_max_width(a);

    //printing brunchings
    tree_printer(a, max);

    //printing trunk
    for(int i = 0; i < a; i++){
        int spaces = (max - a) / 2;
        if(a % 2 == 0) spaces = (max - a - 1) / 2 + 1;

        putc(_, spaces);
        putc(trunk, a);
        putc(n, 1);
    }
}       

int main(int size, char** args){
    //initializing
    dif = 2;
    dif_c = 0;
    points = 1;
    h = 4;

    //if there is no args
    if(size < 2) return 0;

    for(int i = 1; i < size; i ++) my_christmas_tree(atoi(&args[i][0]));

    return 0;
}
