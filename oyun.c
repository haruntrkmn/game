#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct materials{
    int source;
    int wood;
    int stone;
    int metal;
    int power;
    int level;
    int wins;
    int range;
    int secure;
    int saves;
    int checker;
    int empty;
    char *name;
}player,user1,*ptr1,*ptr2;

struct language{
    char lang;
}lang,*ptr3;

void delay(float number_of_seconds){
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int ratior(int x, int y){
    float new_x = 50 * x / (x + y);
    x = new_x + 0.5;
    return x;
}
void saver(){
    int save = 0;
    char holder[100];
    int numbers[3][11];
    int i,j;
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 11 ; j++){
            numbers[i][j] = 0;
        }
    }
    char *name1 = (char*)malloc(sizeof(char)*20);
    char *name2 = (char*)malloc(sizeof(char)*20);
    char *name3 = (char*)malloc(sizeof(char)*20);
    FILE *fptr;
    fptr = fopen("save.txt","r");
    if(ptr3 -> lang == '1'){
        printf("kaydetmek istediginiz yeri seciniz\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("choose the place you want to save\n");
    }
    printf("_______________________________________________\n");
    fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&numbers[0][0],name1,&numbers[0][1],&numbers[0][2],&numbers[0][3],&numbers[0][4],&numbers[0][5],&numbers[0][6],&numbers[0][7],&numbers[0][8],&numbers[0][9],&numbers[0][10]);
    if(numbers[0][0] == 0){
        if(ptr3 -> lang == '1'){
            printf("1.Kayit          ");
        }
        else if(ptr3 -> lang == '2'){
            printf("1.Save          ");
        }
    }
    else if(numbers[0][0] == 1){
        printf("1.%s          ",name1);
    }


    fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&numbers[1][0],name2,&numbers[1][1],&numbers[1][2],&numbers[1][3],&numbers[1][4],&numbers[1][5],&numbers[1][6],&numbers[1][7],&numbers[1][8],&numbers[1][9],&numbers[1][10]);
    if(numbers[1][0] == 0){
        if(ptr3 -> lang == '1'){
            printf("2.Kayit          ");
        }
        else if(ptr3 -> lang == '2'){
            printf("2.Save          ");
        }
    }
    else if(numbers[1][0] == 1){
        printf("2.%s          ",name2);
    }


    fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&numbers[2][0],name3,&numbers[2][1],&numbers[2][2],&numbers[2][3],&numbers[2][4],&numbers[2][5],&numbers[2][6],&numbers[2][7],&numbers[2][8],&numbers[2][9],&numbers[2][10]);
    if(numbers[2][0] == 0){
        if(ptr3 -> lang == '1'){
            printf("3.Kayit          \n");
        }
        else if(ptr3 -> lang == '2'){
            printf("3.Save          \n");
        }
    }
    else if(numbers[2][0] == 1){
        printf("3.%s          \n",name3);
    }

    do{
        save = getch();
    }while(save != '1' && save != '2' && save != '3');

    fclose(fptr);



    if(ptr1 -> saves > 0){
        fptr = fopen("save.txt","w");
        if(fptr == NULL){
            if(ptr3 -> lang == '1'){
                printf("Hata!\n");
                printf("Devam etmek icin bir tusa basiniz\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("Error!\n");
                printf("Press any key to continue\n");
            }
            getch();
        }

        int total = ptr1 -> level + ptr1 -> source + ptr1 -> wood + ptr1 -> stone + ptr1 -> metal + ptr1 -> power;
        ptr1 -> secure = total * 9 - 37;

        if(save == '1'){
            ptr1 -> empty = 1;
            fprintf(fptr,"%d ",ptr1 -> empty);
            fprintf(fptr,"%s ",ptr1 -> name);
            fprintf(fptr,"%d ",ptr1 -> level);
            fprintf(fptr,"%d ",ptr1 -> wins);
            fprintf(fptr,"%d ",ptr1 -> source);
            fprintf(fptr,"%d ",ptr1 -> wood);
            fprintf(fptr,"%d ",ptr1 -> secure);
            fprintf(fptr,"%d ",ptr1 -> stone);
            fprintf(fptr,"%d ",ptr1 -> metal);
            fprintf(fptr,"%d ",ptr1 -> power);
            fprintf(fptr,"%d ",ptr1 -> range);
            fprintf(fptr,"%d\n",ptr1 -> saves - 1);


            fprintf(fptr,"%d ",numbers[1][0]);
            fprintf(fptr,"%s ",name2);
            fprintf(fptr,"%d ",numbers[1][1]);
            fprintf(fptr,"%d ",numbers[1][2]);
            fprintf(fptr,"%d ",numbers[1][3]);
            fprintf(fptr,"%d ",numbers[1][4]);
            fprintf(fptr,"%d ",numbers[1][5]);
            fprintf(fptr,"%d ",numbers[1][6]);
            fprintf(fptr,"%d ",numbers[1][7]);
            fprintf(fptr,"%d ",numbers[1][8]);
            fprintf(fptr,"%d ",numbers[1][9]);
            fprintf(fptr,"%d\n",numbers[1][10]);

            fprintf(fptr,"%d ",numbers[2][0]);
            fprintf(fptr,"%s ",name3);
            fprintf(fptr,"%d ",numbers[2][1]);
            fprintf(fptr,"%d ",numbers[2][2]);
            fprintf(fptr,"%d ",numbers[2][3]);
            fprintf(fptr,"%d ",numbers[2][4]);
            fprintf(fptr,"%d ",numbers[2][5]);
            fprintf(fptr,"%d ",numbers[2][6]);
            fprintf(fptr,"%d ",numbers[2][7]);
            fprintf(fptr,"%d ",numbers[2][8]);
            fprintf(fptr,"%d ",numbers[2][9]);
            fprintf(fptr,"%d\n",numbers[2][10]);
        }

        else if(save == '2'){
            ptr1 -> empty = 1;
            fprintf(fptr,"%d ",numbers[0][0]);
            fprintf(fptr,"%s ",name1);
            fprintf(fptr,"%d ",numbers[0][1]);
            fprintf(fptr,"%d ",numbers[0][2]);
            fprintf(fptr,"%d ",numbers[0][3]);
            fprintf(fptr,"%d ",numbers[0][4]);
            fprintf(fptr,"%d ",numbers[0][5]);
            fprintf(fptr,"%d ",numbers[0][6]);
            fprintf(fptr,"%d ",numbers[0][7]);
            fprintf(fptr,"%d ",numbers[0][8]);
            fprintf(fptr,"%d ",numbers[0][9]);
            fprintf(fptr,"%d\n",numbers[0][10]);

            fprintf(fptr,"%d ",ptr1 -> empty);
            fprintf(fptr,"%s ",ptr1 -> name);
            fprintf(fptr,"%d ",ptr1 -> level);
            fprintf(fptr,"%d ",ptr1 -> wins);
            fprintf(fptr,"%d ",ptr1 -> source);
            fprintf(fptr,"%d ",ptr1 -> wood);
            fprintf(fptr,"%d ",ptr1 -> secure);
            fprintf(fptr,"%d ",ptr1 -> stone);
            fprintf(fptr,"%d ",ptr1 -> metal);
            fprintf(fptr,"%d ",ptr1 -> power);
            fprintf(fptr,"%d ",ptr1 -> range);
            fprintf(fptr,"%d\n",ptr1 -> saves - 1);

            fprintf(fptr,"%d ",numbers[2][0]);
            fprintf(fptr,"%s ",name3);
            fprintf(fptr,"%d ",numbers[2][1]);
            fprintf(fptr,"%d ",numbers[2][2]);
            fprintf(fptr,"%d ",numbers[2][3]);
            fprintf(fptr,"%d ",numbers[2][4]);
            fprintf(fptr,"%d ",numbers[2][5]);
            fprintf(fptr,"%d ",numbers[2][6]);
            fprintf(fptr,"%d ",numbers[2][7]);
            fprintf(fptr,"%d ",numbers[2][8]);
            fprintf(fptr,"%d ",numbers[2][9]);
            fprintf(fptr,"%d\n",numbers[2][10]);
        }

        else if(save == '3'){
            ptr1 -> empty = 1;
            fprintf(fptr,"%d ",numbers[0][0]);
            fprintf(fptr,"%s ",name1);
            fprintf(fptr,"%d ",numbers[0][1]);
            fprintf(fptr,"%d ",numbers[0][2]);
            fprintf(fptr,"%d ",numbers[0][3]);
            fprintf(fptr,"%d ",numbers[0][4]);
            fprintf(fptr,"%d ",numbers[0][5]);
            fprintf(fptr,"%d ",numbers[0][6]);
            fprintf(fptr,"%d ",numbers[0][7]);
            fprintf(fptr,"%d ",numbers[0][8]);
            fprintf(fptr,"%d ",numbers[0][9]);
            fprintf(fptr,"%d\n",numbers[0][10]);

            fprintf(fptr,"%d ",numbers[1][0]);
            fprintf(fptr,"%s ",name2);
            fprintf(fptr,"%d ",numbers[1][1]);
            fprintf(fptr,"%d ",numbers[1][2]);
            fprintf(fptr,"%d ",numbers[1][3]);
            fprintf(fptr,"%d ",numbers[1][4]);
            fprintf(fptr,"%d ",numbers[1][5]);
            fprintf(fptr,"%d ",numbers[1][6]);
            fprintf(fptr,"%d ",numbers[1][7]);
            fprintf(fptr,"%d ",numbers[1][8]);
            fprintf(fptr,"%d ",numbers[1][9]);
            fprintf(fptr,"%d\n",numbers[1][10]);

            fprintf(fptr,"%d ",ptr1 -> empty);
            fprintf(fptr,"%s ",ptr1 -> name);
            fprintf(fptr,"%d ",ptr1 -> level);
            fprintf(fptr,"%d ",ptr1 -> wins);
            fprintf(fptr,"%d ",ptr1 -> source);
            fprintf(fptr,"%d ",ptr1 -> wood);
            fprintf(fptr,"%d ",ptr1 -> secure);
            fprintf(fptr,"%d ",ptr1 -> stone);
            fprintf(fptr,"%d ",ptr1 -> metal);
            fprintf(fptr,"%d ",ptr1 -> power);
            fprintf(fptr,"%d ",ptr1 -> range);
            fprintf(fptr,"%d\n",ptr1 -> saves - 1);
        }



        fclose(fptr);
    }


}



int sizer(char *array1){
    int size = 0;
    while (array1[size] != '\0'){
        size ++;
    }
return size;
}

void printer(char array1[20]){
    int i = 0;
    while(array1[i] != '\0'){
        printf("%c",array1[i]);
        i++;
    }
}


void info(){

    printf("__");
    printer(ptr1 -> name);
    printf("__\n\n");
    if(ptr3 -> lang == '1'){
        printf("seviye:\t%d\n",ptr1 -> level + 1);
        printf("zafer:\t%d\n",ptr1 -> wins);
        printf("kayit:\t%d\n",ptr1 -> saves);
        printf("____________\n");
        printf("kaynak:\t%d\n",ptr1 -> source);
        printf("tahta:\t%d\n",ptr1 -> wood);
        printf("tas:\t%d\n",ptr1 -> stone);
        printf("metal:\t%d\n\n",ptr1 -> metal);
        printf("guc:\t%d\n",ptr1 -> power);
    }
    else if(ptr3 -> lang == '2'){
        printf("level:\t%d\n",ptr1 -> level + 1);
        printf("wins:\t%d\n",ptr1 -> wins);
        printf("saves:\t%d\n",ptr1 -> saves);
        printf("____________\n");
        printf("source:\t%d\n",ptr1 -> source);
        printf("wood:\t%d\n",ptr1 -> wood);
        printf("stone:\t%d\n",ptr1 -> stone);
        printf("metal:\t%d\n\n",ptr1 -> metal);
        printf("power:\t%d\n",ptr1 -> power);
    }
}

void main_menu(){
    if(ptr3 -> lang == '1'){
        printf("\n_____________________________________________\n");
        printf("D : depo      ");
        printf("S : savas      ");
        printf("K : oyunu kaydet\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n_________________________________________\n");
        printf("D : depot      ");
        printf("S : war      ");
        printf("K : save game\n\n\n");
    }
}

void depot_menu(){
    if(ptr3 -> lang == '1'){
        printf("\n_________________________________________________\n");
        printf("M : malzeme uret      ");
        printf("B : birlestir      ");
        printf("A : geri\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n________________________________________\n");
        printf("M : produce      ");
        printf("B : unite      ");
        printf("A : back\n\n\n");
    }
}

void produce_menu(){
    if(ptr3 -> lang == '1'){
        printf("\n_______________________________________________________________________________\n");
        printf("z : tahta uret          x : tas uret          c : metal uret          D : bitir\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n__________________________________________________________________________________________\n");
        printf("z : produce wood          x : produce stone          c : produce metal          D : finish\n\n\n");
    }
}

void uniting_menu(){
    if(ptr3 -> lang == '1'){
        printf("\n_______________________________________________________________________________\n");
        printf("z : tahta           x : tas           c : metal           D : bitir\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n______________________________________________________________________________\n");
        printf("z : wood          x : stone          c : metal          D : finish\n\n\n");
    }
}
void victory_page(){
    int biggest = 0;
    int i;
    if (ptr2 -> source > biggest){
        biggest = ptr2 -> source;
    }
    if (ptr2 -> wood > biggest){
        biggest = ptr2 -> wood;
    }
    if (ptr2 -> stone > biggest){
        biggest = ptr2 -> stone;
    }
    if (ptr2 -> metal > biggest){
        biggest = ptr2 -> metal;
    }

    if (biggest < 10){
        biggest = 10;
    }


    system("cls");

    for (i = biggest - 10 ; i < biggest ; i++){
        delay(0.06);
        system("cls");
        if(ptr3 -> lang == '1'){
            printf("zafer!\n");
        }
        else if(ptr3 -> lang == '2'){
            printf("victory!\n");
        }
        if (i < ptr2 -> source){
            if(ptr3 -> lang == '1'){
                printf("kaynak:\t+%d\n",i+1);
            }
            else if(ptr3 -> lang == '2'){
                printf("source:\t+%d\n",i+1);
            }

        }
        else if(i >= ptr2 -> source){
            if(ptr3 -> lang == '1'){
                printf("kaynak:\t+%d\n",ptr2 -> source);
            }
            else if(ptr3 -> lang == '2'){
                printf("source:\t+%d\n",ptr2 -> source);
            }
        }

        if (i < ptr2 -> wood){
            if(ptr3 -> lang == '1'){
                printf("tahta:\t+%d\n",i+1);
            }
            else if(ptr3 -> lang == '2'){
                printf("wood:\t+%d\n",i+1);
            }
        }
        else if(i >= ptr2 -> wood){
            if(ptr3 -> lang == '1'){
                printf("tahta:\t+%d\n",ptr2 -> wood);
            }
            else if(ptr3 -> lang == '2'){
                printf("wood:\t+%d\n",ptr2 -> wood);
            }
        }

        if (i < ptr2 -> stone){
            if(ptr3 -> lang == '1'){
                printf("tas:\t+%d\n",i+1);
            }
            else if(ptr3 -> lang == '2'){
                printf("stone:\t+%d\n",i+1);
            }
        }
        else if(i >= ptr2 -> stone){
            if(ptr3 -> lang == '1'){
                printf("tas:\t+%d\n",ptr2 -> stone);
            }
            else if(ptr3 -> lang == '2'){
                printf("stone:\t+%d\n",ptr2 -> stone);
            }
        }

        if (i < ptr2 -> metal){
            printf("metal:\t+%d\n",i+1);
        }
        else if(i >= ptr2 -> metal){
            printf("metal:\t+%d\n",ptr2 -> metal);
        }
    }
}
void lose_page(){
    system("cls");
    if(ptr3 -> lang == '1'){
        printf("maglubiyet!\n");
        printf("kalan kaynak:\t%d\n",ptr1 -> source);
        printf("kalan tahta:\t%d\n",ptr1 -> wood);
        printf("kalan tas:\t%d\n",ptr1 -> stone);
        printf("kalan metal:\t%d\n",ptr1 -> metal);
    }
    else if(ptr3 -> lang == '2'){
        printf("defeat!\n");
        printf("remainig source:\t%d\n",ptr1 -> source);
        printf("remaining wood:\t%d\n",ptr1 -> wood);
        printf("remaining stone:\t%d\n",ptr1 -> stone);
        printf("remaining metal:\t%d\n",ptr1 -> metal);
    }

}

void war_menu(){
    if(ptr3 -> lang == '1'){
        printf("\nsaldirmak istediginiz bolgeyi secin");
        printf("\n_________________________________________________________________________________________________________________\n");
        printf("1 : Bolge 1          2 : Bolge 2          3 : Bolge 3          4 : Bolge 4          5 : Bolge 5          A : geri\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\nchoose the area you want to attack");
        printf("\n____________________________________________________________________________________________________________\n");
        printf("1 : Area 1          2 : Area 2          3 : Area 3          4 : Area 4          5 : Area 5          A : back\n");
    }
}

void war_info(){
    printf("__");
    printer(ptr1 -> name);
    printf("__\n\n");
    if(ptr3 -> lang == '1'){
        printf("guc: %d\n",ptr1 -> power);
    }
    else if(ptr3 -> lang == '2'){
        printf("power: %d\n",ptr1 -> power);
    }
}

int war_moment(int section,int level_checker,int win_checker){
    system("cls");
    int player = ptr1 -> power;
    int enemy = ptr2 -> power;
    int win = 0;
    int lose = 0;
    int round = 1;

    printf("%s:\t",ptr1 -> name);
    if(sizer(ptr1 -> name) < 7){
        printf("\t");
    }

    printf("%d\n",player);
    if(ptr3 -> lang == '1'){
        printf("Bolge %d:\t%d\n",section,enemy);
    }
    else if(ptr3 -> lang == '2'){
        printf("Area %d: \t%d\n",section,enemy);
    }
    player = ratior(player,enemy);
    enemy = 50 - player;
    if(ptr3 -> lang == '1'){
        printf("savasa baslamak icin bir tusa basiniz ");
    }
    else if(ptr3 -> lang == '2'){
        printf("press any key to start battle ");
    }
    getch();
    do{
        system("cls");
        int i,j,random;
        int medium = 100;
        int slow = 100;

        srand(time(NULL));
        random = rand() % 50;

        if (random > 30){
            medium = 50 - (random - 30);
            slow = 50 - (random - 45);
        }
        for (i = 0 ; i < 50 ; i++){
            if (i > medium){
                delay(0.038);
            }
            else if (i > slow){
                delay(0.04);
            }
            delay(0.025);
            system("cls");
            for (j = 0 ; j < 50 ; j++){
                if (j == player){
                    printf(".");
                }
                else{
                    printf("_");
                }
            }
            printf("\n");

            for (j = 0 ; j < i ; j++){
                printf("_");
            }
            printf("*");
            for (j = i+1 ; j < 50 ; j++){
                printf("_");
            }
            printf("\n");
            if(ptr3 -> lang == '1'){
                printf("%d.tur\n",round);
            }
            else if(ptr3 -> lang == '2'){
                printf("round %d\n",round);
            }
            printf("%s:\t",ptr1 -> name);
            if(sizer(ptr1 -> name) < 7){
                printf("\t");
            }
            printf("%d\n",win);
            if(ptr3 -> lang == '1'){
                printf("Bolge %d:\t%d\n",section,lose);
            }
            else if(ptr3 -> lang == '2'){
                printf("Area %d: \t%d\n",section,lose);
            }

        }

        for (i = 48 ; i > -1 ;  i--){
            delay(0.025);
            if (i < random + 5){
                delay(0.04);
            }
            else if (i < random + 20){
                delay(0.038);
            }

            system("cls");
            for (j = 0 ; j < 50 ; j++){
                if (j == player){
                    printf(".");
                }
                else{
                    printf("_");
                }
            }
            printf("\n");
            for (j = 0 ; j < i ; j++){
                printf("_");
            }
            printf("*");
            for (j = i+1 ; j < 50 ; j++){
                printf("_");
            }
            if (i == random){
                if (random <= player && player != 0){
                    win++;
                }
                else{
                    lose++;
                }
            }
            printf("\n");
            if(ptr3 -> lang == '1'){
                printf("%d.tur\n",round);
            }
            else if(ptr3 -> lang == '2'){
                printf("round %d\n",round);
            }
            printf("%s:\t",ptr1 -> name);
            if(sizer(ptr1 -> name) < 7){
                printf("\t");
            }
            printf("%d\n",win);
            if(ptr3 -> lang == '1'){
                printf("Bolge %d:\t%d\n",section,lose);
            }
            else if(ptr3 -> lang == '2'){
                printf("Area %d: \t%d\n",section,lose);
            }
            if (i == random ){
                if(random <= player){
                    if (win < 3){
                        if(ptr3 -> lang == '1'){
                            printf("\nturu kazandiniz!\n");
                        }
                        else if(ptr3 -> lang == '2'){
                            printf("\nyou have won the round!\n");
                        }
                    }
                }
                else{
                    if (lose < 3){
                        if(ptr3 -> lang == '1'){
                            printf("\nturu kaybettiniz\n");
                        }
                        else if(ptr3 -> lang == '2'){
                            printf("\nyou have lost the round\n");
                        }
                    }
                }
                if (win < 3 && lose < 3){
                    if(ptr3 -> lang == '1'){
                        printf("%d. tura gecmek icin bir tusa basiniz\n",round+1);
                    }
                    else if(ptr3 -> lang == '2'){
                        printf("press any key to continue with round %d\n",round+1);
                    }
                }
                else{
                    if (win == 3){
                        if (level_checker == 1){
                            ptr1 -> level++;
                            win_checker = 1;
                        }

                        ptr1 -> wins++;
                        if(ptr3 -> lang == '1'){
                            printf("savasi kazandiniz!\n");
                        }
                        else if(ptr3 -> lang == '2'){
                            printf("victory!\n");
                        }
                        ptr1 -> source = ptr1 -> source + ptr2 -> source;
                        ptr1 -> wood = ptr1 -> wood + ptr2 -> wood;
                        ptr1 -> stone = ptr1 -> stone + ptr2 -> stone;
                        ptr1 -> metal = ptr1 -> metal + ptr2 -> metal;
                    }
                    else{
                        if(ptr3 -> lang == '1'){
                            printf("savasi kaybettiniz\n");
                        }
                        else if(ptr3 -> lang == '2'){
                            printf("defeat\n");
                        }
                        ptr1 -> power = 0;


                    }
                    if(ptr3 -> lang == '1'){
                        printf("savas raporu icin bir tusa basiniz\n");
                    }
                    else if(ptr3 -> lang == '2'){
                        printf("press any key for war report\n");
                    }
                }
                round++;
                getch();
                break;
            }
        }

    }while(win < 3 && lose < 3);
    if (win ==3){
        victory_page();
    }
    else{
        lose_page();
    }

    if(ptr3 -> lang == '1'){
        printf("\n________\n");
        printf("A: devam\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n___________\n");
        printf("A: continue\n");
    }

    return win_checker;

}

void question1(){
    if(ptr3 -> lang == '1'){
        printf("\n__________________________________________________\n");
        printf("emin misiniz?          D : evet          M : hayir\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n______________________________________________\n");
        printf("are you sure?          D : yes          M : no\n\n\n");
    }
}

void question2(){
    if(ptr3 -> lang == '1'){
        printf("\n__________________________________________________\n");
        printf("emin misiniz?          D : evet          B : hayir\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n______________________________________________\n");
        printf("are you sure?          D : yes          B : no\n\n\n");
    }
}

void question3(){
    if(ptr3 -> lang == '1'){
        printf("\n__________________________________________________\n");
        printf("emin misiniz?          A : evet          S : hayir\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n______________________________________________\n");
        printf("are you sure?          A : yes          S : no\n\n\n");
    }
}
void question4(int level_checker,int win_checker){
    if (level_checker == 1 && win_checker == 1){
        if(ptr3 -> lang == '1'){
            printf("\nseviye atladin!");
        }
        else if(ptr3 -> lang == '2'){
            printf("\nlevel up!");
        }
        ptr1 -> range = ptr1 -> power;
        ptr1 -> saves = 3;
    }

    if(ptr3 -> lang == '1'){
        printf("\n_______________________________\n");
        printf("A : anasayfa          S : savas\n\n\n");
    }
    else if(ptr3 -> lang == '2'){
        printf("\n______________________________\n");
        printf("A : main page          S : war\n\n\n");
    }
}


void main_page(){
    system("cls");
    info();
    main_menu();
}

void depot(){
    system("cls");
    info();
    depot_menu();
}

void produce(){
    char x;
    do {
        system("cls");
        info();
        produce_menu();
        x = getch();

        if (x == 'z' && ptr1 -> source >= 2){
            ptr1 -> wood++;
            ptr1 -> source = ptr1 -> source - 2;
            ptr1 -> power = ptr1 -> power + 2;
        }

        else if (x == 'x' && ptr1 -> source >= 5){
            ptr1 -> stone++;
            ptr1 -> source = ptr1 -> source - 5;
            ptr1 -> power = ptr1 -> power + 6;
        }

        else if (x == 'c' && ptr1 -> source >= 10){
            ptr1 -> metal++;
            ptr1 -> source = ptr1 -> source - 10;
            ptr1 -> power = ptr1 -> power + 15;
        }
        else if (x == 'd'){
            system("cls");
            info();
            produce_menu();
            question1();
            break;
        }

    }while(1);

}

void uniting(){
    int points = 0;
    int addition = 0;
    char x,y;
    int i;
    int random = 0;
    int success = 0;
    int number = 0;
    int min = 1000;
    do{
        system("cls");
        info();
        uniting_menu();
        if (success == 1){
            if(ptr3 -> lang == '1'){
                printf("islem basarili !\nguc +%d\n",addition);
            }
            else if(ptr3 -> lang == '2'){
                printf("success !\npower +%d\n",addition);
            }
        }
        else if (success == 2){
            if(ptr3 -> lang == '1'){
                printf("islem basarisiz\nguc -10\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("failed\npower -10\n");
            }
        }
        if(ptr3 -> lang == '1'){
            printf("materyal1: ");
        }
        else if(ptr3 -> lang == '2'){
            printf("material1: ");
        }

        do {
            x = getch();
        }while (x != 'z' && x != 'x' && x != 'c' && x != 'd');
        if (x == 'z'){
            if(ptr3 -> lang == '1'){
                printf("tahta\nmateryal2: ");
            }
            else if(ptr3 -> lang == '2'){
                printf("wood\nmaterial2: ");
            }
            if (ptr1 -> wood < min){
                min = ptr1 -> wood;
            }
            points+= 1;
            }

        else if (x == 'x'){
            if(ptr3 -> lang == '1'){
                printf("tas\nmateryal2: ");
            }
            else if(ptr3 -> lang == '2'){
                printf("stone\nmaterial2: ");
            }
            if (ptr1 -> stone < min){
                min = ptr1 -> stone;
            }
            points+= 2;
        }

        else if (x == 'c'){
            if(ptr3 -> lang == '1'){
                printf("metal\nmateryal2: ");
            }
            else if(ptr3 -> lang == '2'){
                printf("metal\nmaterial2: ");
            }
            if (ptr1 -> metal < min){
                min = ptr1 -> metal;
            }
            points+= 4;
        }
        else if (x == 'd'){
            question2();
            break;
        }
        do {
            y = getch();
        }while (y != 'z' && y != 'x' && y != 'c' && y != 'd');
        if (y == 'z'){
            if(ptr3 -> lang == '1'){
                printf("tahta\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("wood\n");
            }

            if (ptr1 -> wood < min){
                min = ptr1 -> wood;
            }
            if (x == 'z'){
                min = min/2;
            }
            points+= 1;
        }
        else if (y == 'x'){
            if(ptr3 -> lang == '1'){
                printf("tas\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("stone\n");
            }
            if (ptr1 -> stone < min){
                min = ptr1 -> stone;
            }
            if (x == 'x'){
                min = min/2;
            }
            points+= 2;
        }
        else if (y == 'c'){
            printf("metal\n");
            if (ptr1 -> metal < min){
                min = ptr1 -> metal;
            }
            if (x == 'c'){
                min = min/2;
            }
            points+= 4;
        }
        else if (y == 'd'){
            question2();
            break;
        }

        do {
            if(ptr3 -> lang == '1'){
                printf("miktar: ");
            }
            else if(ptr3 -> lang == '2'){
                printf("amount: ");
            }
            scanf("%d",&number);
        }
        while (number < 0);

        while (number > min){
            if(ptr3 -> lang == '1'){
                printf("yetersiz materyal\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("insufficient material\n");
            }
            do {
                if(ptr3 -> lang == '1'){
                    printf("miktar: ");
                }
                else if(ptr3 -> lang == '2'){
                    printf("amount: ");
                }
                scanf("%d",&number);
            }
            while (number < 0);
        }

        srand(time(NULL));

        if (points == 2){
            random = rand() % 10;
            if (random < 9){
                success = 1;
                ptr1 -> power = ptr1 -> power + 10*number*(ptr1 -> level + 1);
                addition = 10*number*(ptr1 -> level + 1);
                ptr1 -> wood = ptr1 -> wood - number*2;
            }
            else {
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> wood = ptr1 -> wood - number*2;
                success = 2;
            }
        }

        else if (points == 3){
            random = rand() % 10;
            if (random < 8){
                success = 1;
                ptr1 -> power = ptr1 -> power + 12*number*(ptr1 -> level + 1);
                addition = 12*number*(ptr1 -> level + 1);
                ptr1 -> wood = ptr1 -> wood - number;
                ptr1 -> stone = ptr1 -> stone - number;
            }
            else {
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> wood = ptr1 -> wood - number;
                ptr1 -> stone = ptr1 -> stone - number;
                success = 2;
            }
        }

        else if (points == 4){
            random = rand() % 10;
            if (random < 7){
                success = 1;
                ptr1 -> power = ptr1 -> power + 40*number*(ptr1 -> level + 1);
                addition = 40*number*(ptr1 -> level + 1);
                ptr1 -> stone = ptr1 -> stone - number*2;
            }
            else {
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> stone = ptr1 -> stone - number*2;
                success = 2;
            }
        }

        else if (points == 5){
            random = rand() % 10;
            if (random < 6){
                success = 1;
                ptr1 -> power = ptr1 -> power + 20*number*(ptr1 -> level + 1);
                addition = 20*number*(ptr1 -> level + 1);
                ptr1 -> wood = ptr1 -> wood - number;
                ptr1 -> metal = ptr1 -> metal - number;
            }
            else{
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> wood = ptr1 -> wood - number;
                ptr1 -> metal = ptr1 -> metal - number;
                success = 2;
            }
        }

        else if (points == 6){
            random = rand() % 10;
            if (random < 4){
                success = 1;
                ptr1 -> power = ptr1 -> power + 60*number*(ptr1 -> level + 1);
                addition = 60*number*(ptr1 -> level + 1);
                ptr1 -> metal = ptr1 -> metal - number;
                ptr1 -> stone = ptr1 -> stone - number;
            }
            else {
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> metal = ptr1 -> metal - number;
                ptr1 -> stone = ptr1 -> stone - number;
                success = 2;
            }
        }

        else if (points == 8){
            random = rand() % 10;
            if (random < 3){
                success = 1;
                ptr1 -> power = ptr1 -> power + 80*number*(ptr1 -> level + 1);
                addition = 80*number*(ptr1 -> level + 1);
                ptr1 -> metal = ptr1 -> metal - number;
                ptr1 -> metal = ptr1 -> metal - number;
            }
            else{
                if (ptr1 -> power > 10){
                    ptr1 -> power = ptr1 -> power - 10;
                }
                ptr1 -> metal = ptr1 -> metal - number;
                ptr1 -> metal = ptr1 -> metal - number;
                success = 2;
            }
        }
        if (number == 0){
            success = 0;
        }

        min = 1000;
        points = 0;


    }while (1);


}

void war_page(){
    int i;
    char x;
    system("cls");
    war_info();
    war_menu();
    int counter = 0;
    int level_checker = 0;
    int win_checker = 0;
    srand(time(NULL));


    if (ptr1 -> range == 0){
        ptr1 -> range = 200;
    }

    do{
        int section = 0;
        do{
            x = getch();
            if (x == '1'){
                section = 1;
            }
            else if (x == '2'){
                section = 2;
            }
            else if (x == '3'){
                section = 3;
            }
            else if (x == '4'){
                section = 4;
            }
            else if (x == '5'){
                section = 5;
            }
        }while(x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != 'a');


        if (x == 'a'){
            if (counter == 1){
                question4(level_checker,win_checker);
            }
            else{
                question3();
            }
            break;
        }

        else if (x == '1'){

            ptr2 -> power = rand() % 100 + (ptr1 -> range)*1/2 ;
            ptr2 -> source = (rand() % 5 + 5) * (ptr1 -> level + 2);
            ptr2 -> wood = (rand() % 15) * (ptr1 -> level + 2);
            ptr2 -> stone = (rand() % 15) * (ptr1 -> level + 2);
            ptr2 -> metal = (rand() % 5) * (ptr1 -> level + 2);

            war_moment(section,level_checker,win_checker);
            counter = 1;
        }
        else if ( x == '2'){


            ptr2 -> power = rand() % 100 + ptr1 -> range ;
            ptr2 -> source = (rand() % 5 + 5) * (ptr1 -> level + 2);
            ptr2 -> wood = (rand() % 10 + 5) * (ptr1 -> level + 2);
            ptr2 -> stone = (rand() % 10 + 5) * (ptr1 -> level + 2);
            ptr2 -> metal = (rand() % 5) * (ptr1 -> level + 2);

            war_moment(section,level_checker,win_checker);
            counter = 1;
        }
        else if ( x == '3'){


            ptr2 -> power = rand() % 100 + (ptr1 -> range)*6/4 ;
            ptr2 -> source = (rand() % 5 + 10) * (ptr1 -> level + 2);
            ptr2 -> wood = (rand() % 5 + 10) * (ptr1 -> level + 2);
            ptr2 -> stone = (rand() % 5 + 10) * (ptr1 -> level + 2);
            ptr2 -> metal = (rand() % 5 + 5) * (ptr1 -> level + 2);


            war_moment(section,level_checker,win_checker);
            counter = 1;
        }
        else if ( x == '4'){



            ptr2 -> power = rand() % 100 + (ptr1 -> range)*8/4;
            ptr2 -> source = (rand() % 10 + 15) * (ptr1 -> level + 2);
            ptr2 -> wood = (rand() % 5 + 15) * (ptr1 -> level + 2);
            ptr2 -> stone = (rand() % 10 + 15) * (ptr1 -> level + 2);
            ptr2 -> metal = (rand() % 7 + 5) * (ptr1 -> level + 2);

            war_moment(section,level_checker,win_checker);
            counter = 1;
        }
        else if ( x == '5'){


            ptr2 -> power = rand() % 100 + (ptr1 -> range)*10/4;
            ptr2 -> source = (rand() % 10 + 25) * (ptr1 -> level + 2);
            ptr2 -> wood = (rand() % 5 + 20) * (ptr1 -> level + 2);
            ptr2 -> stone = (rand() % 10 + 25) * (ptr1 -> level + 2);
            ptr2 -> metal = (rand() % 3 + 12) * (ptr1 -> level + 2);

            level_checker = 1;
            win_checker = war_moment(section,level_checker,win_checker);
            counter = 1;

        }


    }while(1);

}





int main(){


int length = 0;
int first = 0;
int second = 0;

ptr1 = &player;
ptr2 = &user1;
ptr3 = &lang;

lang.lang = 0;

player.source = 100;
player.wood = 0;
player.stone = 0;
player.metal = 0;
player.power = 0;
player.level = 0;
player.wins = 0;
player.range = 0;
player.saves = 3;
player.checker = 0;
player.empty = 0;
player.secure = 0;
player.name = (char*)malloc(sizeof(char)*20);

user1.source = 0;
user1.wood = 0;
user1.stone = 0;
user1.metal = 0;
user1.power = 0;


printf("1.Turkce\n");
printf("2.English\n");

do{
    ptr3 -> lang = getch();
}while(ptr3 -> lang != '1' && ptr3 -> lang != '2');

system("cls");

if(ptr3 -> lang == '1'){
    printf("1.Yeni Oyuna Basla\n");
    printf("2.Oyun Yukle\n");
    printf("3.Nasil Oynanir?\n");
}
else if(ptr3 -> lang == '2'){
    printf("1.Start New Game\n");
    printf("2.Load Game\n");
    printf("3.How to Play?\n");
}
do{
    first = getch();
}while (first != '1' && first != '2' && first != '3');

if (first == '3'){
    system("cls");
    if(ptr3 -> lang == '1'){
        printf("oyundaki amac maksimum guc elde edip seviyeyi artirmaktir.\nbunun icin kaynaklari dogru bir sekilde kullanmak ");
        printf("gerekir.\n3 cesit kaynak vardir: tahta, tas ve metal. her kaynagin uretimi sirasinda degeri kadar guc elde edilir.\n");
        printf("birbiriyle ayni veya birbirinden farkli kaynaklar birlestirilerek normalde elde edilebilecekten daha fazla guc elde edilebilir.\n");
        printf("birlestirme islemi esnasinda kaynaklarin bosa gitme ve gucun 10 puan dusme ihtimali vardir.\n");
        printf("kaynaklarin degerleri arttikca birlestirme sirasinda basarisiz olma ihtimali de artar.\n");
        printf("savas bolumunde guclerine gore 1'den 5'e dogru siralanmis 5 bolge vardir. \n");
        printf("bir bolgeye saldirma karari verildikten sonra o bolgenin gucu gorunur. saldirma karari geri alinamaz. \n");
        printf("savasi kazanma ihtimali guclerin oraniyla dogru orantilidir.\n");
        printf("5. bolgeye karsi zafer elde edilirse seviye atlanir. \n5. bolgeyle savasmak icin ilk 4 bolgeyle savasma zorunlulugu yoktur.\n");
        printf("seviye atlaninca rakiplerin gucleri ve olasi zaferde elde edilecek kaynak miktari artar.\n");
        printf("her seviye icin 3 kayit hakki vardir. seviye atlaninca kayit hakki tekrar 3 olur.\n");

        printf("\noyuna baslamak icin 1'e, ilave notlar icin 2'ye basiniz. \n");
    }
    else if(ptr3 -> lang == '2'){
        printf("the aim of this game is gaining maximum power.\nin order to do this it is necessary to use materials correctly.\n");
        printf("there are 3 different types of materials: wood, stone and metal. during the production of a material, power increases\n");
        printf("as much as value of that material.\n");
        printf("gaining much more power is possible by uniting same or different materials.\n");
        printf("a possibility exists that materials can be wasted and the power can be reduced 10 points during the uniting operation.\n");
        printf("the possibility of failing increases as much as values of materials being used in uniting.\n");
        printf("in the war page, there are 5 different areas ordered by their power.\n");
        printf("after giving the order of attacking an area, the power of that area appears. the order cannot be canceled.\n");
        printf("the possibility of winning a battle is directly proportional with the ratio of powers.\n");
        printf("after a victory against Area 5, level increases. fighting previous 4 areas is not necessary to fight Area 5.\n");
        printf("when the level increases, the powers of enemies and amount of materials to be gained after a win increase as well.\n");
        printf("in each level there are 3 save chances. when the level increases, save chance increase to 3 again.\n");

        printf("\npress 1 to start game, press 2 for additional notes. \n");

    }
    do {
        second = getch();
    }while (second != '1' && second != '2');



    if (second == '2'){
        system("cls");
        if(ptr3 -> lang == '1'){
            printf("eger oyun gerektigi gibi calismiyorsa buyuk olasilikla kullanici bir hata yapmis demektir.\n");
            printf("""(sayi girilmesi gereken yere harf girmek, gereksiz yere enter'a basmak vb.)\n""");
            printf("boyle durumlarda oyunun yeniden baslatilmasi gerekir.\n\n");
            printf("birlestirme bolumunde kaynak 1 ve kaynak 2 girilmis, miktar girme bolumunde birlestirme isleminden\n");
            printf("vazgecilmisse, miktar degeri olarak 0 girmek yeterli olacaktir.\n\n");
            printf("5. bolgeyle savasma karari almadan once kaynak biriktirilmesi tavsiye edilir.\n");
            printf("zira bir sonraki seviyede rakiplerin gucleri artacagindan, mevcut guc yeterli olmayabilir.\n");
            printf("\nbaslamak icin bir tusa basiniz");
        }

        else if(ptr3 -> lang == '2'){
            printf("if the game is not working normally, it is highly possible that user made a mistake.\n");
            printf("""(to enter a letter when should be entered a number, pressing 'enter' unnecessarily etc.)\n""");
            printf("in the cases like that, the game should be restarted.\n\n");
            printf("in the uniting page, if the material 1 and material 2 is selected but the process wanted to be canceled,");
            printf(" entering 0 as amount will be enough to cancel the process.\n\n");
            printf("it is recommended to save source and materials before fighting Area 5,\n");
            printf("because of the fact that enemies will be stronger in the next level and current power may not be enough.\n");
            printf("\npress and key to start");
        }
        getch();
    }

}



if (first == '2'){


    FILE *fptr;
    fptr = fopen("save.txt","r");

    if (fptr == NULL){
        system("cls");
        if (ptr3 -> lang == '1'){
            printf("oyun yuklemede hata!\n");
            printf("_____________\n");
            printf("1 : yeni oyun\n");
        }
        else if(ptr3 -> lang == '2'){
            printf("an error has occurred while loading the game!\n");
            printf("____________\n");
            printf("1 : new game\n");
        }
        first = getch();
    }

    else {
        int empty[3];
        empty[0] = 0;
        empty[1] = 0;
        empty[2] = 0;

        int total[3];
        total[0] = 0;
        total[1] = 0;
        total[2] = 0;

        int info[3][10];

        char *name1 = (char*)malloc(sizeof(char)*20);
        char *name2 = (char*)malloc(sizeof(char)*20);
        char *name3 = (char*)malloc(sizeof(char)*20);

        fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&empty[0],name1,&ptr1 -> level,&ptr1 -> wins,&ptr1 -> source,&ptr1 -> wood,&ptr1 -> secure,&ptr1 -> stone,&ptr1 -> metal,&ptr1 -> power,&ptr1 -> range,&ptr1 -> saves);
        info[0][0] = ptr1 -> level;
        info[0][1] = ptr1 -> wins;
        info[0][2] = ptr1 -> source;
        info[0][3] = ptr1 -> wood;
        info[0][4] = ptr1 -> secure;
        info[0][5] = ptr1 -> stone;
        info[0][6] = ptr1 -> metal;
        info[0][7] = ptr1 -> power;
        info[0][8] = ptr1 -> range;
        info[0][9] = ptr1 -> saves;

        total[0] = ptr1 -> level + ptr1 -> source + ptr1 -> wood + ptr1 -> stone + ptr1 -> metal + ptr1 -> power;

        fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&empty[1],name2,&ptr1 -> level,&ptr1 -> wins,&ptr1 -> source,&ptr1 -> wood,&ptr1 -> secure,&ptr1 -> stone,&ptr1 -> metal,&ptr1 -> power,&ptr1 -> range,&ptr1 -> saves);
        info[1][0] = ptr1 -> level;
        info[1][1] = ptr1 -> wins;
        info[1][2] = ptr1 -> source;
        info[1][3] = ptr1 -> wood;
        info[1][4] = ptr1 -> secure;
        info[1][5] = ptr1 -> stone;
        info[1][6] = ptr1 -> metal;
        info[1][7] = ptr1 -> power;
        info[1][8] = ptr1 -> range;
        info[1][9] = ptr1 -> saves;

        total[1] = ptr1 -> level + ptr1 -> source + ptr1 -> wood + ptr1 -> stone + ptr1 -> metal + ptr1 -> power;

        fscanf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d",&empty[2],name3,&ptr1 -> level,&ptr1 -> wins,&ptr1 -> source,&ptr1 -> wood,&ptr1 -> secure,&ptr1 -> stone,&ptr1 -> metal,&ptr1 -> power,&ptr1 -> range,&ptr1 -> saves);
        info[2][0] = ptr1 -> level;
        info[2][1] = ptr1 -> wins;
        info[2][2] = ptr1 -> source;
        info[2][3] = ptr1 -> wood;
        info[2][4] = ptr1 -> secure;
        info[2][5] = ptr1 -> stone;
        info[2][6] = ptr1 -> metal;
        info[2][7] = ptr1 -> power;
        info[2][8] = ptr1 -> range;
        info[2][9] = ptr1 -> saves;

        total[2] = ptr1 -> level + ptr1 -> source + ptr1 -> wood + ptr1 -> stone + ptr1 -> metal + ptr1 -> power;
        printf("yuklemek istediginiz bolumu seciniz\n");
        printf("_______________________________________________\n");
        if(empty[0] == 0){
            if(ptr3 -> lang == '1'){
                printf("1.Yukle          ");
            }
            else if(ptr3 -> lang == '2'){
                printf("2.Load          ");
            }
        }
        else if(empty[0] == 1){
            printf("1.%s          ",name1);
        }
        if(empty[1] == 0){
            if(ptr3 -> lang == '1'){
                printf("2.Yukle          ");
            }
            else if(ptr3 -> lang == '2'){
                printf("2.Load          ");
            }
        }
        else if(empty[1] == 1){
            printf("2.%s          ",name2);
        }
        if(empty[2] == 0){
            if(ptr3 -> lang == '1'){
                printf("3.Yukle          \n");
            }
            else if(ptr3 -> lang == '2'){
                printf("3.Load          \n");
            }
        }
        else if(empty[2] == 1){
            printf("3.%s          \n",name3);
        }

        char tc = getch();
        int ti = 0;
        if (tc == '1'){
            ti = 1;
            strcpy(ptr1 -> name,name1);
        }
        else if (tc == '2'){
            ti = 2;
            strcpy(ptr1 -> name,name2);
        }
        else if (tc == '3'){
            ti = 3;
            strcpy(ptr1 -> name,name3);
        }

        if(ti == 1){
            ptr1 -> level = info[0][0];
            ptr1 -> wins = info[0][1];
            ptr1 -> source = info[0][2];
            ptr1 -> wood = info[0][3];
            ptr1 -> secure = info[0][4];
            ptr1 -> stone = info[0][5];
            ptr1 -> metal = info[0][6];
            ptr1 -> power = info[0][7];
            ptr1 -> range = info[0][8];
            ptr1 -> saves = info[0][9];
        }

        else if(ti == 2){
            ptr1 -> level = info[1][0];
            ptr1 -> wins = info[1][1];
            ptr1 -> source = info[1][2];
            ptr1 -> wood = info[1][3];
            ptr1 -> secure = info[1][4];
            ptr1 -> stone = info[1][5];
            ptr1 -> metal = info[1][6];
            ptr1 -> power = info[1][7];
            ptr1 -> range = info[1][8];
            ptr1 -> saves = info[1][9];
        }

        else if(ti == 3){
            ptr1 -> level = info[2][0];
            ptr1 -> wins = info[2][1];
            ptr1 -> source = info[2][2];
            ptr1 -> wood = info[2][3];
            ptr1 -> secure = info[2][4];
            ptr1 -> stone = info[2][5];
            ptr1 -> metal = info[2][6];
            ptr1 -> power = info[2][7];
            ptr1 -> range = info[2][8];
            ptr1 -> saves = info[2][9];
        }



        if (ptr1 -> secure == (total[ti-1] * 9) - 37){
            ptr1 -> checker = 1;
            system("cls");
            if(ptr3 -> lang == '1'){
                printf("yukleme basarili!\n");
                printf("_________\n");
                printf("1 : devam\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("the game has successfully loaded!\n");
                printf("____________\n");
                printf("1 : continue\n");
            }
            do{
                first = getch();
            }while (first != '1');
        }
        else{
            system("cls");
            if(ptr3 -> lang == '1'){
                printf("kayit dosyasinda hata!\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("save file has crashed!\n");
            }
            getch();
            return EXIT_FAILURE;
        }
    }

    fclose(fptr);

}



system("cls");
if(ptr1 -> checker == 0){
    if(ptr3 -> lang == '1'){
        printf("adinizi giriniz: ");
    }
    else if(ptr3 -> lang == '2'){
        printf("enter your name: ");
    }
    scanf("%s",ptr1 -> name);
    length = sizer(ptr1 -> name) + 1;
    ptr1 -> name = (char*)realloc(ptr1 -> name,sizeof(char)*length);
}

FILE *fptr;
fptr = fopen("save.txt","r");
if (fptr == NULL){
    fclose(fptr);
    fptr = fopen("save.txt","w");
    fprintf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d\n",0,"null",0,0,100,0,863,0,0,0,0,0);
    fprintf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d\n",0,"null",0,0,100,0,863,0,0,0,0,0);
    fprintf(fptr,"%d %s %d %d %d %d %d %d %d %d %d %d\n",0,"null",0,0,100,0,863,0,0,0,0,0);
    fclose(fptr);
}
else {
    fclose(fptr);
}


char x = 'a';

while (1){

    while(x == 'a'){
        main_page();
        if ( (ptr1 -> power == 0) && (ptr1 -> source < 2) && ( (ptr1 -> wood + ptr1 -> stone + ptr1 -> metal) < 2 ) ){
            if(ptr3 -> lang == '1'){
                printf("oyun bitti!\n");
                printf("yuksek skor:\nharun: seviye 15\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("game over!\n");
                printf("high score:\nharun: level 15\n");
            }
            getch();
            return EXIT_SUCCESS;
        }
        do{
            x = getch();
        }while (x != 'd' && x != 's' && x != 'k');

    }


    while (x == 'd'){
        depot();
        do{
            x = getch();
        }while (x != 'm' && x != 'b' && x != 'a');
    }



    while (x == 'm'){
        produce();

        do{
            x = getch();
        }while (x != 'd' && x != 'm');
    }

    while (x == 'k'){
        saver();
        system("cls");
        if(ptr1 -> saves > 0){
            if(ptr3 -> lang == '1'){
                printf("oyun kaydedildi!\n");
                printf("________\n");
                printf("A: Devam\n");
                ptr1 -> saves--;
            }
            else if(ptr3 -> lang == '2'){
                printf("game saved!\n");
                printf("___________\n");
                printf("A: Continue\n");
                ptr1 -> saves--;
            }
        }
        else if(ptr1 -> saves <= 0){
            if(ptr3 -> lang == '1'){
                printf("kayit hakkiniz kalmadi\n");
                printf("________\n");
                printf("A: Devam\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("the game cannot be saved\n");
                printf("___________\n");
                printf("A: Continue\n");
            }
        }
        do{
            x = getch();
        }while (x != 'a');
    }

    while (x == 'b'){
        uniting();
        do{
            x = getch();
        }while (x != 'd' && x != 'b');
    }

    while (x == 's'){
        if ( (ptr1 -> power == 0) && (ptr1 -> source < 2) && ( (ptr1 -> wood + ptr1 -> stone + ptr1 -> metal) < 2 ) ){
            if(ptr3 -> lang == '1'){
                printf("oyun bitti!\n");
                printf("yuksek skor:\nismail: seviye 15\n");
            }
            else if(ptr3 -> lang == '2'){
                printf("game over!\n");
                printf("high score:\nharun: level 15\n");
            }
            getch();
            return EXIT_SUCCESS;
        }
        war_page();
        do{
            x = getch();
        }while (x != 'a' && x != 's');

    }

}





return EXIT_SUCCESS;
}
