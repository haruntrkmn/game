#include "levels.h"

using namespace std;

void wait(float seconds){
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct f{
    int field[HEIGHT][LENGTH];
    void create();
    void print();
};

struct p{
    int x, y, score;
    bool ifable_a(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_d(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_w(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_s(int field[HEIGHT][LENGTH], int x, int y);
    bool Move(char c, int &x, int &y, int field[HEIGHT][LENGTH]);
    void info(int x, int y);
};

struct e{
    int x, y, xinit, yinit, range, speed, counter;
    bool gothit;
    bool down, right;
    bool ifable_left(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_right(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_up(int field[HEIGHT][LENGTH], int x, int y);
    bool ifable_down(int field[HEIGHT][LENGTH], int x, int y);
    bool MoveDownUp(int &x, int y, int counter, int range, int speed, bool &down, int field[HEIGHT][LENGTH], bool downinit);
    bool MoveLeftRight(int &x, int &y, int counter, int range, int speed, bool &right, int field[HEIGHT][LENGTH], bool rightinit);
    bool MoveRandom(int &x, int &y, int counter, int range, int speed, int field[HEIGHT][LENGTH]);
    bool Follow(int &x, int &y, int gox, int goy, int counter, int speed, int field[HEIGHT][LENGTH]);
    void info (int ex, int ey);
};

struct b{
    int x, y;
    bool gotpoint;
};

struct s{
    int x, y, xint, yint;
    int shoot(int field[HEIGHT][LENGTH], int x, int y);
};

int s::shoot(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x][y] != 3 && field[x][y] != 4  && field[x][y] != 6){
        field[x][y] = 0;
        gotoxy(y * 2 + 1, x);
        cout << " ";
    }
    y++;
    if (field[x][y] != 4 && field[x][y] != 0 && field[x][y] != 5  && field[x][y] != 6){
        return 1;
    }
    else if (field[x][y] == 4){
        return 4;
    }
    else {
        gotoxy(y * 2 + 1, x);
        if (field[x][y] != 6){
            cout << "-";
            field[x][y] = 8;
        }
        return 0;
    }
}

void f::create(){
    /// empty (dot) = 0
    /// border (x) = 1
    /// finish (empty) = 2
    /// player (o) = 3
    /// enemy (#) = 4
    /// random move borders for enemy = 5
    /// point (+) = 6
    /// door  (x) = 7
    /// bullet (-) = 8
    int i,j;
    for (i = 0 ; i < HEIGHT ; i++){
        for (j = 0 ; j < LENGTH ; j++){
            field[i][j] = 0;
        }
    }

    for (i = 0 ; i < HEIGHT ; i++){
        for (j = 0 ; j < LENGTH ; j++){
            if (i == 0){
                field[i][j] = 1;
            }
            else if (i == HEIGHT - 1){
                field[i][j] = 1;
            }
            if (j == 0){
                field[i][j] = 1;
            }
            else if (j == LENGTH - 1){
                field[i][j] = 1;
            }
        }
    }
    field[HEIGHT / 2][LENGTH - 1] = 2;
    field[HEIGHT / 2][1] = 3;
}

void f::print(){
    int i,j;
    for (i = 0 ; i < HEIGHT ; i++){
        for (j = 0 ; j < LENGTH ; j++){
            if (field[i][j] == 0){
                cout << "  ";
            }
            else if (field[i][j] == 1){
                cout << " x";
            }
            else if (field[i][j] == 2){
                cout << " ";
            }
            else if (field[i][j] == 3){
                cout << " O";
            }
            else if (field[i][j] == 4){
                cout << " X";
            }
            else if (field[i][j] == 6){
                cout << " +";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

bool p::ifable_a(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x][y - 1] == 1){
        return 0;
    }
    else {
        return 1;
    }
}
bool p::ifable_d(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x][y + 1] == 1){
        return 0;
    }
    else {
        return 1;
    }
}
bool p::ifable_w(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x - 1][y] == 1){
        return 0;
    }
    else {
        return 1;
    }
}
bool p::ifable_s(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x + 1][y] == 1){
        return 0;
    }
    else {
        return 1;
    }
}

bool e::ifable_left(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x][y - 1] == 1 || field[x][y - 1] == 5 || field[x][y - 1] == 6){
        return 0;
    }
    return 1;
}
bool e::ifable_right(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x][y + 1] == 1 || field[x][y + 1] == 5 || field[x][y + 1] == 6){
        return 0;
    }
    return 1;
}
bool e::ifable_up(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x - 1][y] == 1 || field[x - 1][y] == 5 || field[x - 1][y] == 6){
        return 0;
    }
    return 1;
}
bool e::ifable_down(int field[HEIGHT][LENGTH], int x, int y){
    if (field[x + 1][y] == 1 || field[x + 1][y] == 5 || field[x + 1][y] == 6){
        return 0;
    }
    return 1;
}

bool p::Move(char c, int &x, int &y, int field[HEIGHT][LENGTH]){
    switch (c){
    case 'a' :
        if (ifable_a(field, x, y)){
            gotoxy(y * 2 + 1, x);
            cout << " ";
            y--;
            if (field[x][y + 1] != 6 && field[x][y + 1] != 7){
                field[x][y + 1] = 0;
            }
            if (field[x][y] == 4){
                return 1;
            }
            gotoxy(2 * y + 1, x);
            cout << "O";
            if (field[x][y] != 2 && field[x][y] != 6 && field[x][y] != 7){
                field[x][y] = 3;
            }
        }
        return 0;

    case 'd' :
        if (ifable_d(field, x, y)){
            gotoxy(2 * y + 1, x);
            cout << " ";
            y++;
            if (field[x][y - 1] != 6 && field[x][y - 1] != 7){
                field[x][y - 1] = 0;
            }
            if (field[x][y] == 4){
                return 1;
            }
            gotoxy(2 * y + 1, x);
            cout << "O";
            if (field[x][y] != 2 && field[x][y] != 6 && field[x][y] != 7){
                field[x][y] = 3;
            }
        }
        return 0;


    case 'w' :
        if (ifable_w(field, x, y)){
            gotoxy(2 * y + 1, x);
            cout << " ";
            x--;
            if (field[x + 1][y] != 6 && field[x + 1][y] != 7){
                field[x + 1][y] = 0;
            }
            if (field[x][y] == 4){
                return 1;
            }
            gotoxy(2 * y + 1, x);
            cout << "O";
            if (field[x][y] != 2 && field[x][y] != 6 && field[x][y] != 7){
                field[x][y] = 3;
            }
        }
        return 0;


    case 's' :
        if (ifable_s(field, x, y)){
            gotoxy(2 * y + 1, x);
            cout << " ";
            x++;
            if (field[x - 1][y] != 6 && field[x - 1][y] != 7){
                field[x - 1][y] = 0;
            }
            if (field[x][y] == 4){
                return 1;
            }
            gotoxy(2 * y + 1, x);
            cout << "O";
            if (field[x][y] != 2 && field[x][y] != 6 && field[x][y] != 7){
                field[x][y] = 3;
            }


        }
        return 0;
    }
    return 0;
}

void p::info(int x, int y){
    gotoxy(1, HEIGHT + 2);
    cout << "\t\t\t\t\r";
    cout << " player: " << x << " " << y;
}

bool e::MoveDownUp(int &x, int y, int counter, int range, int speed, bool &down, int field[HEIGHT][LENGTH], bool downinit){
    int upborder;
    int downborder;
    if (downinit){
        upborder = xinit;
        downborder = xinit + range;
    }
    else if(!downinit){
        downborder = xinit;
        upborder = xinit - range;
    }
    if (counter % speed == 0){
        if (down){
            gotoxy(y * 2 + 1, x);
            cout << " ";
            x++;
            gotoxy(y * 2 + 1, x);
            cout << "#";
            if (x == downborder){
                down = 0;
            }
            if (field[x][y] == 3){
                field[x - 1][y] = 0;
                return 1;
            }
            field[x - 1][y] = 0;
            field[x][y] = 4;
        }
        else if (!down){
            gotoxy(y * 2 + 1, x);
            cout << " ";
            x--;
            gotoxy(y * 2 + 1, x);
            cout << "#";
            if (x == upborder){
                down = 1;
            }
            if (field[x][y] == 3){
                field[x + 1][y] = 0;
                return 1;
            }
            field[x + 1][y] = 0;
            field[x][y] = 4;


        }
    }
    return 0;
}
bool e::MoveLeftRight(int &x, int &y, int counter, int range, int speed, bool &right, int field[HEIGHT][LENGTH], bool rightinit){
    struct f fieldstr;
    int rightborder;
    int leftborder;
    if (rightinit){
        rightborder = yinit + range;
        leftborder = yinit;
    }
    else if(!rightinit){
        leftborder = yinit - range;
        rightborder = yinit;
    }
    if (counter % speed == 0){
        if (right){
            gotoxy(y * 2 + 1, x);
            cout << " ";
            y++;
            gotoxy(y * 2 + 1, x);
            cout << "#";
            if (y == rightborder){
                right = 0;
            }
            if (field[x][y] == 3){
                field[x][y - 1] = 0;
                return 1;
            }
            field[x][y - 1] = 0;
            field[x][y] = 4;
        }
        else if (!right){
            gotoxy(y * 2 + 1, x);
            cout << " ";
            y--;
            gotoxy(y * 2 + 1, x);
            cout << "#";
            if (y == leftborder){
                right = 1;
            }
            if (field[x][y] == 3){
                field[x][y + 1] = 0;
                return 1;
            }
            field[x][y + 1] = 0;
            field[x][y] = 4;
        }
    }
    return 0;
}
bool e::MoveRandom(int &x, int &y, int counter, int range, int speed, int field[HEIGHT][LENGTH]){
    int i, j;
    int leftborder, rightborder, upborder, downborder;

    if (counter % speed == 0){
        if (yinit - range - 1 < 0){
            leftborder = 0;
        }
        else{
            leftborder = yinit - range - 1;
        }

        if (yinit + range + 1 > LENGTH - 1){
            rightborder = LENGTH - 1;
        }
        else{
            rightborder = yinit + range + 1;
        }

        if (xinit - range - 1 < 0){
            upborder = 0;
        }
        else{
            upborder = xinit - range - 1;
        }

        if (xinit + range + 1 > HEIGHT - 1){
            downborder = HEIGHT - 1;
        }
        else{
            downborder = xinit + range + 1;
        }

        /// random move borders
        for (j = leftborder ; j < rightborder ; j++){
            if (field[upborder][j] != 1){
                field[upborder][j] = 5;
            }
            if (field[downborder][j] != 1){
                field[downborder][j] = 5;
            }
        }
        for (i = upborder ; i < downborder ; i++){
            if (field[i][leftborder] != 1){
                field[i][leftborder] = 5;
            }
            if (field[i][rightborder] != 1){
                field[i][rightborder] = 5;
            }
        }
        /// random move borders

        gotoxy(2 * y + 1, x);
        cout << "X";
        i = rand() % 4;
        if (i == 0){
            if (ifable_left(field, x, y)){
                ///go left
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x][y + 1] = 0;
                field[x][y] = 4;
                return 0;
            }
            else {
                ///go right
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x][y - 1] = 0;
                field[x][y] = 4;
                return 0;
            }
        }
        else if(i == 1){
            if (ifable_right(field, x, y)){
                ///go right
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x][y - 1] = 0;
                field[x][y] = 4;
                return 0;
            }
            else {
                ///go left
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x][y + 1] = 0;
                field[x][y] = 4;
                return 0;
            }
        }
        else if(i == 2){
            if (ifable_up(field, x, y)){
                ///go up
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x + 1][y] = 0;
                field[x][y] = 4;
                return 0;
            }
            else {
                ///go down
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x - 1][y] = 0;
                field[x][y] = 4;
                return 0;
            }
        }
        else if(i == 3){
            if (ifable_down(field, x, y)){
                ///go down
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x - 1][y] = 0;
                field[x][y] = 4;
                return 0;
            }
            else {
                ///go up
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    return 1;
                }
                field[x + 1][y] = 0;
                field[x][y] = 4;
                return 0;
            }
        }
    }
    return 0;
}

bool e::Follow(int &x, int &y, int gox, int goy, int counter, int speed, int field[HEIGHT][LENGTH]){
    if (counter % speed == 0){
        if (gox == x && goy > y){
            ///go right
            if (field[x][y + 1] != 4 && field[x][y + 1] != 1  && field[x][y + 1] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x][y - 1] != 6){
                        field[x][y - 1] = 0;
                    }
                    return 1;
                }
                if (field[x][y - 1] != 6){
                    field[x][y - 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox < x && goy > y){
            ///go right up
            if (field[x - 1][y + 1] != 4 && field[x - 1][y + 1] != 1  && field[x - 1][y + 1] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x--;
                y++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x + 1][y + 1] != 6){
                        field[x + 1][y - 1] = 0;
                    }
                    return 1;
                }
                if (field[x + 1][y - 1]){
                    field[x + 1][y - 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox < x && goy == y){
            ///go up
            if (field[x - 1][y] != 4 && field[x - 1][y] != 1  && field[x - 1][y] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x + 1][y] != 6){
                        field[x + 1][y] = 0;
                    }
                    return 1;
                }
                if (field[x + 1][y] != 6){
                    field[x + 1][y] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox < x && goy < y){
            ///go left up
            if (field[x - 1][y - 1] != 4 && field[x - 1][y - 1] != 1  && field[x - 1][y - 1] != 1){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x--;
                y--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x + 1][y + 1] != 6){
                        field[x + 1][y + 1] = 0;
                    }
                    return 1;
                }
                if (field[x + 1][y + 1] != 6){
                    field[x + 1][y + 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox == x && goy < y){
            ///go left
            if (field[x][y - 1] != 4 && field[x][y - 1] != 1  && field[x][y - 1] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                y--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x][y + 1] != 6){
                        field[x][y + 1] = 0;
                    }
                    return 1;
                }
                if (field[x][y + 1] != 6){
                    field[x][y + 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox > x && goy < y){
            ///go left down
            if (field[x + 1][y - 1] != 4 && field[x + 1][y - 1] != 1  && field[x + 1][y - 1] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x++;
                y--;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x - 1][y + 1] != 6){
                        field[x - 1][y + 1] = 0;
                    }
                    return 1;
                }
                if (field[x - 1][y + 1] != 6){
                    field[x - 1][y + 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox > x && goy == y){
            ///go down
            if (field[x + 1][y] != 4 && field[x + 1][y] != 1  && field[x + 1][y] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x - 1][y] != 6){
                        field[x - 1][y] = 0;
                    }
                    return 1;
                }
                if (field[x - 1][y] != 6){
                    field[x - 1][y] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
        else if (gox > x && goy > y){
            ///go right down
            if (field[x + 1][y + 1] != 4 && field[x + 1][y + 1] != 1  && field[x + 1][y + 1] != 7){
                gotoxy(y * 2 + 1, x);
                cout << " ";
                x++;
                y++;
                gotoxy(2 * y + 1, x);
                cout << "X";
                if (field[x][y] == 3){
                    if (field[x - 1][y - 1] != 6){
                        field[x - 1][y - 1] = 0;
                    }
                    return 1;
                }
                if (field[x - 1][y - 1] != 6){
                    field[x - 1][y - 1] = 0;
                }
                if (field[x][y] != 6){
                    field[x][y] = 4;
                }
                return 0;
            }
        }
    }
    return 0;
}

void pointreplacer(int field[HEIGHT][LENGTH]){
    int i, j;
    for (i = 0 ; i < HEIGHT; i++){
        for (j = 0 ; j < LENGTH ; j++){
            if (field[i][j] == 6){
                gotoxy(j * 2 + 1, i);
                cout << "+";
            }
            else if (field[i][j] == 7){
                field[i][j] = 1;
                gotoxy(j * 2 + 1, i);
                cout << "x";
            }
            field[HEIGHT / 2][LENGTH - 1] = 1;
            gotoxy((LENGTH - 1) * 2 + 1, HEIGHT / 2);
            cout << "x";
        }
    }
}





int main(){

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);


    srand(time(NULL));
    struct f fieldstr;
    struct p player;
    struct b point1, point2, point3, point4, point5, point6, point7, point8;
    struct e enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, enemym1, enemym2, enemym3, enemym4;
    struct s bullet;
    int i, j, k;
    char c = ' ';
    player.x = HEIGHT / 2;
    player.y = 1;
    bool init = 1;
    bool dynamic = 0;
    bool ifpoint = 0;
    bool iffollow = 0;
    bool shooting = 0;
    bool hit = 0;
    bool ifshot = 0;
    bool restart = 0;
    bool dooropen = 0;
    bool first = 1;
    bool first1 = 1;
    int counter = 0;
    int level = 0;
    player.score = 0;
    int levelpass = 0;
    fieldstr.create();
    char password[7];
    string message = " ";
    string winmessage = " ";
    string hitmessage = " ";
    string restartmessage = " ";
    /// game loop
    while (1){
        if (level == 0 && init){
            dynamic = 0;
            ifpoint = 0;
            winmessage = "press any key to continue";
            fieldstr.print();
            gotoxy(22, 3);
            cout << "w,a,s,d to move";
            gotoxy(1 ,HEIGHT);
            cout << "---------------------" << endl;
            cout << " level 0: introduction" ;
            init = 0;
        }
        else if (level == 1 && init){
            dynamic = 0;
            winmessage = "that was easy";
            level1(fieldstr.field);
            fieldstr.print();
            gotoxy(1 ,HEIGHT);
            cout << "------------------" << endl;
            cout << " level 1: labyrinth" ;
            init = 0;
        }
        else if (level == 2){
            if (init){
                dynamic = 0;
                ifpoint = 0;
                winmessage = "well done";
                level2(fieldstr.field);
                fieldstr.print();
                gotoxy(1 ,HEIGHT);
                cout << "-------------------------" << endl;
                cout << " level 2: labyrinth (hard)" ;
                init = 0;
            }
            if (player.x == 9 && player.y == 23){
                fieldstr.field[9][26] = 1;
                gotoxy(53, 9);
                cout << "x";
                fieldstr.field[6][26] = 0;
                gotoxy(53, 6);
                cout << " ";
                gotoxy(1 ,HEIGHT);
                cout << "--------------------------------" << endl;
                cout << " level 2: labyrinth (really hard)";
            }
            if (player.x == 6 && player.y == 27){
                fieldstr.field[7][27] = 1;
                fieldstr.field[7][28] = 0;
                gotoxy(57, 7);
                cout << " ";
                gotoxy(55, 7);
                cout << "x";
            }
            if (player.x == 6 && player.y == 28){
                fieldstr.field[7][28] = 1;
                fieldstr.field[7][27] = 0;
                gotoxy(55, 7);
                cout << " ";
                gotoxy(57, 7);
                cout << "x";
                fieldstr.field[10][27] = 0;
                gotoxy(55,10);
                cout << " ";
                gotoxy(1 ,HEIGHT);
                cout << "---------------------------------------" << endl;
                cout << " level 2: labyrinth (you shall not pass)";
            }
        }
        else if (level == 3){
            if (init){
                dynamic = 1;
                ifpoint = 0;

                enemy1.x = 1;
                enemy1.y = 15;
                enemy1.down = 1;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 10;
                enemy1.speed = 8;
                enemy1.gothit = 0;

                enemy2.x = 11;
                enemy2.y = 3;
                enemy2.down = 1;
                enemy2.xinit = enemy2.x;
                enemy2.yinit = enemy2.y;
                enemy2.range = 3;
                enemy2.speed = 8;
                enemy2.gothit = 0;

                enemy3.x = 6;
                enemy3.y = 7;
                enemy3.right = 0;
                enemy3.xinit = enemy3.x;
                enemy3.yinit = enemy3.y;
                enemy3.range = 3;
                enemy3.speed = 8;
                enemy3.gothit = 0;

                enemy4.x = 8;
                enemy4.y = 24;
                enemy4.right = 1;
                enemy4.xinit = enemy4.x;
                enemy4.yinit = enemy4.y;
                enemy4.range = 4;
                enemy4.speed = 8;
                enemy4.gothit = 0;

                winmessage = "well done";
                hitmessage = "these are not points";
                fieldstr.print();
                gotoxy(1 ,HEIGHT);
                cout << "---------------------------" << endl;
                cout << " level 3: collect all points";
                init = 0;
            }

            wait(0.01);
            hit += enemy1.MoveDownUp(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, enemy1.down, fieldstr.field, 1);
            hit += enemy2.MoveDownUp(enemy2.x, enemy2.y, counter, enemy2.range, enemy2.speed, enemy2.down, fieldstr.field, 1);
            hit += enemy3.MoveLeftRight(enemy3.x, enemy3.y, counter, enemy3.range, enemy3.speed, enemy3.right, fieldstr.field, 0);
            hit += enemy4.MoveLeftRight(enemy4.x, enemy4.y, counter, enemy4.range, enemy4.speed, enemy4.right, fieldstr.field, 1);
            counter++;
            if (counter == 64){
                counter = 0;
            }
        }
        else if (level == 4){
            if (init){
                dynamic = 0;
                ifpoint = 0;
                point1.x = 3;
                point1.y = 15;
                point1.gotpoint = 0;
                winmessage = "well done";
                fieldstr.print();
                fieldstr.field[8][29] = 1;
                gotoxy(59, 8);
                cout << "x";
                gotoxy(point1.y * 2 + 1, point1.x);
                cout << "+";
                gotoxy(1 ,HEIGHT);
                cout << "-----------------------------" << endl;
                cout << " level 4: that is a real point" ;
                init = 0;
            }
            if (player.x == point1.x && player.y == point1.y && point1.gotpoint == 0){
                point1.gotpoint = 1;
                gotoxy(1 ,HEIGHT + 2);
                cout << "you got the point" ;
                fieldstr.field[8][29] = 2;
                gotoxy(59, 8);
                cout << " ";
            }
        }
        else if (level == 5){
            if (init){
                dynamic = 1;
                ifpoint = 0;
                level5(fieldstr.field);

                enemy1.x = 6;
                enemy1.y = 3;
                enemy1.right = 1;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 1;
                enemy1.speed = 32;
                enemy1.gothit = 0;

                enemy2.x = 3;
                enemy2.y = 11;
                enemy2.down = 1;
                enemy2.xinit = enemy2.x;
                enemy2.yinit = enemy2.y;
                enemy2.range = 1;
                enemy2.speed = 32;
                enemy2.gothit = 0;

                enemy3.x = 6;
                enemy3.y = 17;
                enemy3.right = 1;
                enemy3.xinit = enemy3.x;
                enemy3.yinit = enemy3.y;
                enemy3.range = 2;
                enemy3.speed = 32;
                enemy3.gothit = 0;

                enemy4.x = 7;
                enemy4.y = 20;
                enemy4.down = 1;
                enemy4.xinit = enemy4.x;
                enemy4.yinit = enemy4.y;
                enemy4.range = 2;
                enemy4.speed = 32;
                enemy4.gothit = 0;

                enemy5.x = 9;
                enemy5.y = 21;
                enemy5.down = 0;
                enemy5.xinit = enemy5.x;
                enemy5.yinit = enemy5.y;
                enemy5.range = 2;
                enemy5.speed = 32;
                enemy5.gothit = 0;

                enemy6.x = 7;
                enemy6.y = 22;
                enemy6.down = 1;
                enemy6.xinit = enemy6.x;
                enemy6.yinit = enemy6.y;
                enemy6.range = 2;
                enemy6.speed = 32;
                enemy6.gothit = 0;

                message = "------------------------------\n level 5: reach exit if you can";
                winmessage = "well done";
                hitmessage = "try again";
                fieldstr.print();
                gotoxy(1, HEIGHT);
                cout << message;
                init = 0;
            }

            wait(0.01);
            hit += enemy1.MoveLeftRight(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, enemy1.right, fieldstr.field, 1);
            hit += enemy2.MoveDownUp(enemy2.x, enemy2.y, counter, enemy2.range, enemy2.speed, enemy2.down, fieldstr.field, 1);
            hit += enemy3.MoveLeftRight(enemy3.x, enemy3.y, counter, enemy3.range, enemy3.speed, enemy3.right, fieldstr.field, 1);
            hit += enemy4.MoveDownUp(enemy4.x, enemy4.y, counter, enemy4.range, enemy4.speed, enemy4.down, fieldstr.field, 1);
            hit += enemy5.MoveDownUp(enemy5.x, enemy5.y, counter, enemy5.range, enemy5.speed, enemy5.down, fieldstr.field, 0);
            hit += enemy6.MoveDownUp(enemy6.x, enemy6.y, counter, enemy6.range, enemy6.speed, enemy6.down, fieldstr.field, 1);
            counter++;
            if (counter == 64){
                counter = 0;
            }
        }
        else if (level == 6){
            if (init){
                dynamic = 1;
                ifpoint = 1;
                level6(fieldstr.field);

                enemy1.x = 2;
                enemy1.y = 28;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 3;
                enemy1.speed = 16;
                enemy1.gothit = 0;

                point1.x = 1;
                point1.y = 28;
                point1.gotpoint = 0;
                message = "--------------------------\n level 6: monster in a cage";
                winmessage = "well done";
                hitmessage = "try again";
                fieldstr.print();
                fieldstr.field[8][29] = 1;
                gotoxy(59, 8);
                cout << "x";
                fieldstr.field[point1.x][point1.y] = 6;
                gotoxy(point1.y * 2 + 1, point1.x);
                cout << "+";
                gotoxy(1, HEIGHT);
                cout << message;
                init = 0;
            }
            if (player.x == point1.x && player.y == point1.y && point1.gotpoint == 0){
                point1.gotpoint = 1;
                gotoxy(1 ,HEIGHT);
                cout << "                              " << endl;
                cout << "                              " << endl;
                gotoxy(1 ,HEIGHT);
                cout << "-----------------" << endl;
                cout << " you got the point" ;
                fieldstr.field[8][29] = 2;
                gotoxy(59, 8);
                cout << " ";
            }

            wait(0.01);
            hit += enemy1.MoveRandom(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, fieldstr.field);
            counter++;
            if (counter == 64){
                counter = 0;
            }
        }
        else if (level == 7){
            if (init){
                dynamic = 1;
                ifpoint = 1;
                level7(fieldstr.field);

                enemy1.x = 2;
                enemy1.y = 3;
                enemy1.down = 1;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 3;
                enemy1.speed = 64;
                enemy1.gothit = 0;

                enemy2.x = 14;
                enemy2.y = 3;
                enemy2.down = 0;
                enemy2.xinit = enemy2.x;
                enemy2.yinit = enemy2.y;
                enemy2.range = 3;
                enemy2.speed = 64;
                enemy2.gothit = 0;

                enemy3.x = 2;
                enemy3.y = 26;
                enemy3.down = 1;
                enemy3.xinit = enemy3.x;
                enemy3.yinit = enemy3.y;
                enemy3.range = 3;
                enemy3.speed = 64;
                enemy3.gothit = 0;

                enemy4.x = 14;
                enemy4.y = 26;
                enemy4.down = 0;
                enemy4.xinit = enemy4.x;
                enemy4.yinit = enemy4.y;
                enemy4.range = 3;
                enemy4.speed = 64;
                enemy4.gothit = 0;

                point1.x = 1;
                point1.y = 3;
                point1.gotpoint = 0;
                point2.x = 1;
                point2.y = 8;
                point2.gotpoint = 0;
                point3.x = 15;
                point3.y = 3;
                point3.gotpoint = 0;
                point4.x = 15;
                point4.y = 8;
                point4.gotpoint = 0;
                point5.x = 1;
                point5.y = 21;
                point5.gotpoint = 0;
                point6.x = 1;
                point6.y = 26;
                point6.gotpoint = 0;
                point7.x = 15;
                point7.y = 21;
                point7.gotpoint = 0;
                point8.x = 15;
                point8.y = 26;
                point8.gotpoint = 0;



                message = "-----------------------\n level 7: annoying level";
                winmessage = "well done";
                hitmessage = "try again";
                fieldstr.print();
                gotoxy(1, HEIGHT);
                cout << message;
                init = 0;
            }

            if (player.x == point8.x && player.y == point8.y && point8.gotpoint == 0){
                fieldstr.field[1][4] = 7;
                gotoxy(9, 1);
                cout << " ";
                point8.gotpoint = 1;
            }
            else if (player.x == point2.x && player.y == point2.y && point2.gotpoint == 0){
                fieldstr.field[1][25] = 7;
                gotoxy(51, 1);
                cout << " ";
                point2.gotpoint = 1;
            }
            else if (player.x == point5.x && player.y == point5.y && point5.gotpoint == 0){
                fieldstr.field[15][4] = 7;
                gotoxy(9, 15);
                cout << " ";
                point5.gotpoint = 1;
            }
            else if (player.x == point4.x && player.y == point4.y && point4.gotpoint == 0){
                fieldstr.field[15][25] = 7;
                gotoxy(51, 15);
                cout << " ";
                point4.gotpoint = 1;
            }
            else if (player.x == point7.x && player.y == point7.y  && point7.gotpoint == 0){
                fieldstr.field[8][29] = 2;
                gotoxy(59, 8);
                cout << " ";
                point7.gotpoint = 1;
                gotoxy(1, HEIGHT + 2);
                cout << "                                  ";
                gotoxy(1, HEIGHT + 2);
                cout << "door is open";
            }


            wait(0.01);
            hit += enemy1.MoveDownUp(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, enemy1.down, fieldstr.field, 1);
            hit += enemy2.MoveDownUp(enemy2.x, enemy2.y, counter, enemy2.range, enemy2.speed, enemy2.down, fieldstr.field, 0);
            hit += enemy3.MoveDownUp(enemy3.x, enemy3.y, counter, enemy3.range, enemy3.speed, enemy3.down, fieldstr.field, 1);
            hit += enemy4.MoveDownUp(enemy4.x, enemy4.y, counter, enemy4.range, enemy4.speed, enemy4.down, fieldstr.field, 0);
            counter++;
            if (counter == 64){
                counter = 0;
            }
        }
        else if (level == 8){
            if (init){
                dynamic = 1;
                ifpoint = 0;
                shooting = 1;
                levelpass = 45;

                enemy1.x = 1;
                enemy1.y = 10;
                enemy1.down = 1;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 6;
                enemy1.speed = 16;
                enemy1.gothit = 0;

                enemy2.x = 15;
                enemy2.y = 17;
                enemy2.down = 0;
                enemy2.xinit = enemy2.x;
                enemy2.yinit = enemy2.y;
                enemy2.range = 6;
                enemy2.speed = 16;
                enemy2.gothit = 0;

                enemy3.x = 8;
                enemy3.y = 25;
                enemy3.xinit = enemy3.x;
                enemy3.yinit = enemy3.y;
                enemy3.range = 3;
                enemy3.speed = 16;
                enemy3.gothit = 0;

                message = "-------------------------\n level 8: press v to shoot";
                winmessage = "well done";
                hitmessage = "try again";
                restartmessage = "distance = score";
                fieldstr.print();
                fieldstr.field[8][29] = 1;
                gotoxy(59, 8);
                cout << "x";
                gotoxy(1, HEIGHT);
                cout << message;
                gotoxy(49, HEIGHT);
                cout << "-----------";
                gotoxy(49, HEIGHT + 1);
                cout << "score: 0/" << levelpass;
                init = 0;
            }


            wait(0.01);
            if (!enemy1.gothit){
                hit += enemy1.MoveDownUp(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, enemy1.down, fieldstr.field, 1);
            }
            if (!enemy2.gothit){
                hit += enemy2.MoveDownUp(enemy2.x, enemy2.y, counter, enemy2.range, enemy2.speed, enemy2.down, fieldstr.field, 0);
            }
            if (!enemy3.gothit){
                hit += enemy3.MoveRandom(enemy3.x, enemy3.y, counter, enemy3.range, enemy3.speed, fieldstr.field);
            }
            counter++;
            if (counter == 64){
                counter = 0;
            }
            if (enemy1.gothit && enemy2.gothit && enemy3.gothit && player.score < levelpass){
                restart = 1;
            }
            else if (enemy1.gothit && enemy2.gothit && player.score >= levelpass && !dooropen){
                dooropen = 1;
                gotoxy(1, HEIGHT + 3);
                cout << "                                 ";
                gotoxy(1, HEIGHT + 3);
                cout << "door is open";
                fieldstr.field[8][29] = 2;
                gotoxy(59, 8);
                cout << " ";
            }
        }
        else if (level == 9){
            if (init){
                dynamic = 1;
                ifpoint = 1;
                shooting = 0;
                level9(fieldstr.field);

                enemy1.x = 1;
                enemy1.y = 20;
                enemy1.right = 0;
                enemy1.xinit = enemy1.x;
                enemy1.yinit = enemy1.y;
                enemy1.range = 2;
                enemy1.speed = 64;

                enemy2.x = 1;
                enemy2.y = 16;
                enemy2.right = 0;
                enemy2.xinit = enemy2.x;
                enemy2.yinit = enemy2.y;
                enemy2.range = 5;
                enemy2.speed = 32;

                enemy3.x = 2;
                enemy3.y = 17;
                enemy3.right = 0;
                enemy3.xinit = enemy3.x;
                enemy3.yinit = enemy3.y;
                enemy3.range = 5;
                enemy3.speed = 32;

                enemy4.x = 2;
                enemy4.y = 22;
                enemy4.right = 0;
                enemy4.xinit = enemy4.x;
                enemy4.yinit = enemy4.y;
                enemy4.range = 5;
                enemy4.speed = 32;

                point1.x = 1;
                point1.y = 17;
                point1.gotpoint = 0;
                message = "--------------------\n level 9: hidden door";
                winmessage = "you found the door!";
                hitmessage = "try again";
                fieldstr.print();
                gotoxy(1, HEIGHT + 3);
                cout << "                                ";
                gotoxy(1, HEIGHT + 3);
                cout << "point's location: " << point1.x << "," << point1.y;
                gotoxy(1, HEIGHT);
                cout << message;
                init = 0;
            }


            if (player.x == point1.x && player.y == point1.y && point1.gotpoint == 0){
                int randx, randy;
                randx = rand() % 8 + 8;
                randy = rand() % 22 + 1;
                gotoxy(1, HEIGHT + 2);
                cout << "                                ";
                gotoxy(1, HEIGHT + 2);
                cout << "door's location: " << randx << "," << randy;
                fieldstr.field[randx][randy] = 2;
                point1.gotpoint = 1;
            }

            wait(0.01);
            hit += enemy1.MoveLeftRight(enemy1.x, enemy1.y, counter, enemy1.range, enemy1.speed, enemy1.right, fieldstr.field, 0);
            hit += enemy2.MoveLeftRight(enemy2.x, enemy2.y, counter, enemy2.range, enemy2.speed, enemy2.right, fieldstr.field, 0);
            hit += enemy3.MoveLeftRight(enemy3.x, enemy3.y, counter, enemy3.range, enemy3.speed, enemy3.right, fieldstr.field, 0);
            hit += enemy4.MoveLeftRight(enemy4.x, enemy4.y, counter, enemy4.range, enemy4.speed, enemy4.right, fieldstr.field, 0);
            counter++;
            if (counter == 64){
                counter = 0;
            }
        }
        else if (level == 10){
            if (init){
                dooropen = 0;
                dynamic = 1;
                ifpoint = 1;
                shooting = 1;
                iffollow = 1;
                levelpass = 5;
                level10(fieldstr.field);

                enemym1.x = 12;
                enemym1.y = 1;
                enemym1.xinit = enemym1.x;
                enemym1.yinit = enemym1.y;
                enemym1.speed = 64;

                enemym2.x = 3;
                enemym2.y = 12;
                enemym2.xinit = enemym2.x;
                enemym2.yinit = enemym2.y;
                enemym2.speed = 64;

                enemym3.x = 14;
                enemym3.y = 16;
                enemym3.xinit = enemym3.x;
                enemym3.yinit = enemym3.y;
                enemym3.speed = 64;

                enemym4.x = 14;
                enemym4.y = 22;
                enemym4.xinit = enemym4.x;
                enemym4.yinit = enemym4.y;
                enemym4.speed = 64;

                point1.x = 8;
                point1.y = 14;
                point1.gotpoint = 0;
                point2.x = 15;
                point2.y = 5;
                point2.gotpoint = 0;
                point3.x = 15;
                point3.y = 28;
                point3.gotpoint = 0;
                point4.x = 1;
                point4.y = 1;
                point4.gotpoint = 0;
                point5.x = 1;
                point5.y = 28;
                point5.gotpoint = 0;
                point6.x = 15;
                point6.y = 13;
                point6.gotpoint = 0;
                point7.x = 1;
                point7.y = 8;
                point7.gotpoint = 0;
                point8.x = 1;
                point8.y = 19;
                point8.gotpoint = 0;

                message = "-----------------------------\n level 10: do not wake them up";
                winmessage = "you survived!";
                hitmessage = "try again";
                fieldstr.field[8][29] = 1;
                fieldstr.print();
                gotoxy(point1.y * 2 + 1, point1.x);
                cout << "+";
                gotoxy(1, HEIGHT);
                cout << message;
                gotoxy(49, HEIGHT);
                cout << "-----------";
                gotoxy(49, HEIGHT + 1);
                cout << "kills: 0/" << levelpass;
                init = 0;
            }

            if (player.x == point1.x && player.y == point1.y && point1.gotpoint == 0){
                fieldstr.field[14][5] = 7;
                gotoxy(11, 14);
                cout << " ";
                point1.gotpoint = 1;
            }
            if (player.x == point2.x && player.y == point2.y && point2.gotpoint == 0){
                fieldstr.field[15][27] = 7;
                gotoxy(55, 15);
                cout << " ";
                point2.gotpoint = 1;
            }
            if (player.x == point3.x && player.y == point3.y && point3.gotpoint == 0){
                fieldstr.field[1][2] = 7;
                gotoxy(5, 1);
                cout << " ";
                point3.gotpoint = 1;
            }
            if (player.x == point4.x && player.y == point4.y && point4.gotpoint == 0){
                fieldstr.field[2][28] = 7;
                gotoxy(57, 2);
                cout << " ";
                point4.gotpoint = 1;
            }
            if (player.x == point5.x && player.y == point5.y && point5.gotpoint == 0){
                fieldstr.field[14][13] = 7;
                gotoxy(27, 14);
                cout << " ";
                point5.gotpoint = 1;
            }
            if (player.x == point6.x && player.y == point6.y && point6.gotpoint == 0){
                fieldstr.field[1][7] = 7;
                gotoxy(15, 1);
                cout << " ";
                point6.gotpoint = 1;
            }
            if (player.x == point7.x && player.y == point7.y && point7.gotpoint == 0){
                fieldstr.field[1][20] = 7;
                gotoxy(41, 1);
                cout << " ";
                point7.gotpoint = 1;
            }
            else if (player.x == point8.x && player.y == point8.y  && point8.gotpoint == 0 && first1){
                if (dooropen){
                    fieldstr.field[8][29] = 2;
                    gotoxy(59, 8);
                    cout << " ";
                    point8.gotpoint = 1;
                    gotoxy(1, HEIGHT + 2);
                    cout << "                                  ";
                    gotoxy(1, HEIGHT + 2);
                    cout << "door is open";
                }
                else {
                    dooropen = 1;
                    point8.gotpoint = 1;
                    gotoxy(1, HEIGHT + 2);
                    cout << "                                  ";
                    gotoxy(1, HEIGHT + 2);
                    cout << "now kill";
                    first1 = 0;
                }
            }

            wait(0.01);

            hit += enemym1.Follow(enemym1.x, enemym1.y, player.x, player.y, counter, enemym1.speed, fieldstr.field);
            hit += enemym2.Follow(enemym2.x, enemym2.y, player.x, player.y, counter, enemym2.speed, fieldstr.field);
            hit += enemym3.Follow(enemym3.x, enemym3.y, player.x, player.y, counter, enemym3.speed, fieldstr.field);
            hit += enemym4.Follow(enemym4.x, enemym4.y, player.x, player.y, counter, enemym4.speed, fieldstr.field);

            counter++;
            if (counter == 64){
                counter = 0;
            }

            else if (player.score >= levelpass && first){
                if (dooropen){
                    gotoxy(1, HEIGHT + 3);
                    cout << "                                 ";
                    gotoxy(1, HEIGHT + 3);
                    cout << "door is open";
                    fieldstr.field[8][29] = 2;
                    gotoxy(59, 8);
                    cout << " ";
                }
                else {
                    dooropen = 1;
                    gotoxy(1, HEIGHT + 3);
                    cout << "                                 ";
                    gotoxy(1, HEIGHT + 3);
                    cout << "collect all points";
                    first = 0;
                }
            }
        }
        else if (level == 11){
            cout << "there was a hidden password in level 0: " << endl;
            for (i = 0 ; i < 7 ; i++){
                do{
                    c = getch();
                }while (i == 0 && c != 'w' || i == 1 && c != 'a' || i == 2 && c != 's' || i == 3 && c != 'd' || i == 4 && c != 't' || i == 5 && c != 'o' || i == 6 && c != 'e');
                cout << c;
            }
            cout << endl << "congrats! the game is over. thanks for playing." << endl;
            getch();
            return 0;
        }
        if (!dynamic){
            do{
            c = getch();
            }while (c != 'a' && c != 'd' && c != 'w' && c != 's');
            player.Move(c, player.x, player.y, fieldstr.field);
        }

        else if (dynamic){
            if (_kbhit()){
                c = getch();
            };
            if (c == 'v' && shooting && !ifshot){
                bullet.x = player.x;
                bullet.y = player.y;
                bullet.xint = player.x;
                bullet.yint = player.y;
                ifshot = 1;
            }
            if (ifshot && counter % 3 == 0){
                if (bullet.shoot(fieldstr.field, bullet.x, bullet.y) == 0){
                    bullet.y++;
                }
                else if (bullet.shoot(fieldstr.field, bullet.x, bullet.y) == 1){
                    ifshot = 0;
                }
                ///enemy got hit
                else if (bullet.shoot(fieldstr.field, bullet.x, bullet.y) == 4){
                    player.score++;
                    gotoxy(bullet.y * 2 + 3, bullet.x);
                    cout << " ";
                    fieldstr.field[bullet.x][bullet.y + 1] = 0;
                    ifshot = 0;
                    if (bullet.x == enemy1.x && bullet.y + 1 == enemy1.y){
                        enemy1.gothit = 1;
                        player.score = player.score + enemy1.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy2.x && bullet.y + 1 == enemy2.y){
                        enemy2.gothit = 1;
                        player.score = player.score + enemy2.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy3.x && bullet.y + 1 == enemy3.y){
                        enemy3.gothit = 1;
                        player.score = player.score + enemy3.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy4.x && bullet.y + 1 == enemy4.y){
                        enemy4.gothit = 1;
                        player.score = player.score + enemy4.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy5.x && bullet.y + 1 == enemy5.y){
                        enemy5.gothit = 1;
                        player.score = player.score + enemy5.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy6.x && bullet.y + 1 == enemy6.y){
                        enemy6.gothit = 1;
                        player.score = player.score + enemy6.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy7.x && bullet.y + 1 == enemy7.y){
                        enemy7.gothit = 1;
                        player.score = player.score + enemy7.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemy8.x && bullet.y + 1 == enemy8.y){
                        enemy8.gothit = 1;
                        player.score = player.score + enemy8.y - bullet.yint;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "score:" << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemym1.x && bullet.y + 1 == enemym1.y){
                        enemym1.x = 3;
                        enemym1.y = 9;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "kills: " << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemym2.x && bullet.y + 1 == enemym2.y){
                        enemym2.x = 1;
                        enemym2.y = 25;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "kills: " << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemym3.x && bullet.y + 1 == enemym3.y){
                        enemym3.x = 12;
                        enemym3.y = 25;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "kills: " << player.score << "/" << levelpass;
                    }
                    else if (bullet.x == enemym4.x && bullet.y + 1 == enemym4.y){
                        enemym4.x = 15;
                        enemym4.y = 10;
                        gotoxy(49, HEIGHT + 1);
                        cout << "                             ";
                        gotoxy(49, HEIGHT + 1);
                        cout << "kills: " << player.score << "/" << levelpass;
                    }
                }
            }

            hit += player.Move(c, player.x, player.y, fieldstr.field);
            c = ' ';
            /// hit
            if (hit){
                if (iffollow){
                    gotoxy(1, HEIGHT + 3);
                    cout << "                    ";
                    first = 1;
                    first1 = 1;
                    dooropen = 0;
                    fieldstr.field[enemym1.x][enemym1.y] = 0;
                    gotoxy(enemym1.y * 2 + 1, enemym1.x);
                    cout << " ";
                    enemym1.x = enemym1.xinit;
                    enemym1.y = enemym1.yinit;

                    fieldstr.field[enemym2.x][enemym2.y] = 0;
                    gotoxy(enemym2.y * 2 + 1, enemym2.x);
                    cout << " ";
                    enemym2.x = enemym2.xinit;
                    enemym2.y = enemym2.yinit;

                    fieldstr.field[enemym3.x][enemym3.y] = 0;
                    gotoxy(enemym3.y * 2 + 1, enemym3.x);
                    cout << " ";
                    enemym3.x = enemym3.xinit;
                    enemym3.y = enemym3.yinit;

                    fieldstr.field[enemym4.x][enemym4.y] = 0;
                    gotoxy(enemym4.y * 2 + 1, enemym4.x);
                    cout << " ";
                    enemym4.x = enemym4.xinit;
                    enemym4.y = enemym4.yinit;
                }


                /// point replacing
                if (ifpoint){
                    pointreplacer(fieldstr.field);
                    point1.gotpoint = 0;
                    point2.gotpoint = 0;
                    point3.gotpoint = 0;
                    point4.gotpoint = 0;
                    point5.gotpoint = 0;
                    point6.gotpoint = 0;
                    point7.gotpoint = 0;
                    point8.gotpoint = 0;
                    gotoxy(1, HEIGHT);
                    cout << message;
                }

                player.score = 0;
                if (shooting){
                    player.score = 0;
                    enemy1.gothit = 0;
                    enemy2.gothit = 0;
                    enemy3.gothit = 0;
                    enemy4.gothit = 0;
                    enemy5.gothit = 0;
                    enemy6.gothit = 0;
                    enemy7.gothit = 0;
                    enemy8.gothit = 0;
                    gotoxy(49, HEIGHT);
                    cout << "-----------";
                    gotoxy(49, HEIGHT + 1);
                    cout << "                            ";
                    gotoxy(49, HEIGHT + 1);
                    if (iffollow){
                        cout << "kills: 0/" << levelpass;
                    }
                    else {
                        cout << "score: 0/" << levelpass;
                    }
                }
                gotoxy(1 ,HEIGHT + 2);
                cout << "                                       ";
                gotoxy(1 ,HEIGHT + 2);
                cout << hitmessage << endl;
                hit = 0;
                fieldstr.field[player.x][player.y] = 0;
                gotoxy(player.y * 2 + 1, player.x);
                cout << " ";
                player.x = HEIGHT / 2;
                player.y = 1;
                fieldstr.field[player.x][player.y] = 3;
                gotoxy(player.y * 2 + 1, player.x);
                cout << "O";
            }
            else if (shooting && restart){
                player.score = 0;
                fieldstr.field[player.x][player.y] = 0;
                gotoxy(player.y * 2 + 1, player.x);
                cout << " ";
                player.x = HEIGHT / 2;
                player.y = 1;
                fieldstr.field[player.x][player.y] = 3;
                gotoxy(player.y * 2 + 1, player.x);
                cout << "O";
                gotoxy(1 ,HEIGHT + 2);
                cout << restartmessage << endl;
                gotoxy(49, HEIGHT);
                cout << "-----------";
                gotoxy(49, HEIGHT + 1);
                cout << "score: 0/" << levelpass;
                enemy1.gothit = 0;
                enemy2.gothit = 0;
                enemy3.gothit = 0;
                enemy4.gothit = 0;
                enemy5.gothit = 0;
                enemy6.gothit = 0;
                enemy7.gothit = 0;
                enemy8.gothit = 0;
                restart = 0;
            }

        }

        if (fieldstr.field[player.x][player.y] == 2){
            player.score = 0;
            levelpass = 0;
            restart = 0;
            point1.gotpoint = 0;
            point2.gotpoint = 0;
            point3.gotpoint = 0;
            point4.gotpoint = 0;
            point5.gotpoint = 0;
            point6.gotpoint = 0;
            point7.gotpoint = 0;
            point8.gotpoint = 0;
            init = 1;
            shooting = 0;
            fieldstr.create();
            player.x = HEIGHT / 2;
            player.y = 1;
            level++;
            gotoxy(1 ,HEIGHT + 2);
            cout << "                                       ";
            gotoxy(1 ,HEIGHT + 2);
            cout << winmessage << endl;
            getch();
            system("cls");
        }
    }

    system("cls");
    cout << "game over!" << endl;
    getchar();









return 0;
}
