#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "RenderSystem.h"

#include "InputSystem.h" // 기능 별로 모듈화를 한다는 개념에 대해 생각해 봅시다!


namespace global
{
    namespace time
    {
        ULONGLONG previousTime;
        ULONGLONG currentTime;
        ULONGLONG deltaTime;

        int updateCount;
        int fixedUpdateCount;

        void InitTime()
        {
            currentTime = previousTime = GetTickCount64();
        }

        void UpdateTime()
        {
            previousTime = currentTime;
            currentTime = GetTickCount64();

            deltaTime = currentTime - previousTime;
        }

        ULONGLONG GetDeltaTime()
        {
            return deltaTime;
        }
    };

    COORD prePlayerPos; // 기존 플레이어 위치
    COORD curPlayerPos; // 현재 플레이어 위치
    SMALL_RECT consoleScreenSize;

    const int playerMoveSpeed = 1000;
    
};

enum {
    black,
    blue,
    green,
    cyan,
    red,
    purple,
    brown,
    lightgray,
    darkgray,
    lightblue,
    lightgreen,
    lightcyan,
    lightred,
    lightpurple,
    yellow,
    white
};



void setColor(int forground, int background)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}

void GotoXY(int x, int y)
{
    COORD Cur = { x, y };
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

bool Quiz1()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("수도퀴즈!\n");
    GotoXY(30, 10);
    printf("캐나다의 수도는?\n");
    GotoXY(30, 12);
    printf("1. 보고타   2. 오타와   3. 벤쿠버   4. 부다페스트   5. 토론토");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '2')
        {
            GotoXY(30, 14);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '4' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 14);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 14);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }
        else
            return false;
            continue;
        
    }
}

bool Quiz2()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("북한에서는 이것을 얼음 보숭이라고 부르는데\n");
    GotoXY(30, 11);
    printf("이것은 무엇 일까요?");
    GotoXY(30, 13);
    printf("1. 북금곰   2. 시베리안 허스키   3. 아이스 하키   4. 아이스크림   5. 고드름");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '4')
        {
            GotoXY(30, 15);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '2' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 15);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 15);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz3()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("줄임말퀴즈!\n");
    GotoXY(30, 12);
    printf("좋댓구알은 무엇의 줄임말일까요? 답 입력 후 엔터를 눌러주세요. (띄어쓰기X, 쉼표X)");
    char str1[40]; 
    GotoXY(30, 14);
    std::cin >> str1;
    GotoXY(30, 14);
    std::cout << str1 << std::endl;
    Sleep(1000);
    GotoXY(30, 14);
    printf("                             ");

    for (int i = 1; i <= 3; i++)
    {
        char str2[40] = "좋아요댓글구독알림설정";
        if (strcmp(str1, str2) == 0)
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(2000);
            return true;
            break;
        }
        else if (strcmp(str1, str2) == 1 || strcmp(str1, str2) == -1)
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                GotoXY(30, 14);
                std::cin >> str1;
                GotoXY(30, 14);
                std::cout << str1 << std::endl;
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz4()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("영어퀴즈!\n");
    GotoXY(30, 12);
    printf("물티슈의 영어 표기로 알맞은 것은?");
    GotoXY(30, 14);
    printf("1. water tissue   2. hand tissue   3. wet tissue   4. wash tissue   5. cleaning tissue");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '3')
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '4' || userAnswer == '2' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz5()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("넌센스 퀴즈!\n");
    GotoXY(30, 12);
    printf("울다가 다시 웃는 사람을 다섯 글자로? 입력 후 엔터를 눌러주세요. (띄어쓰기 X, 쉼표 X)");
    char str1[40];
    GotoXY(30, 14);
    std::cin >> str1;
    GotoXY(30, 14);
    std::cout << str1 << std::endl;
    Sleep(1000);
    GotoXY(30, 14);
    printf("                             ");

    for (int i = 1; i <= 3; i++)
    {
        char str2[40] = "아까운사람";
        if (strcmp(str1, str2) == 0)
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(2000);
            return true;
            break;
        }
        else if (strcmp(str1, str2) == 1 || strcmp(str1, str2) == -1)
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                GotoXY(30, 14);
                std::cin >> str1;
                GotoXY(30, 14);
                std::cout << str1 << std::endl;
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz6()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("수학문제!\n");
    GotoXY(30, 12);
    printf("1, 4, 10, 22, 46, ? 다음 물음표 안에 들어갈 숫자를 찾으세요.");
    GotoXY(30, 13);
    printf("1. 94  2. 122   3. 64   4. 86   5. 104");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '1')
        {
            GotoXY(30, 15);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '3' || userAnswer == '4' || userAnswer == '2' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 15);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 15);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                continue;
            }
            return false;
        }
        else
            continue;

    }
}

bool Quiz7()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("넌센스 퀴즈!\n");
    GotoXY(30, 12);
    printf("숫자 5가 가장 싫어하는 집은? 입력 후 엔터를 눌러주세요. (띄어쓰기 X, 쉼표 X)");
    char str1[40];
    GotoXY(30, 14);
    std::cin >> str1;
    GotoXY(30, 14);
    std::cout << str1 << std::endl;
    Sleep(1000);
    GotoXY(30, 14);
    printf("                             ");

    for (int i = 1; i <= 3; i++)
    {
        char str2[40] = "오페라하우스";
        if (strcmp(str1, str2) == 0)
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(2000);
            return true;
            break;
        }
        else if (strcmp(str1, str2) == 1 || strcmp(str1, str2) == -1)
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                GotoXY(30, 14);
                std::cin >> str1;
                GotoXY(30, 14);
                std::cout << str1 << std::endl;
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz8()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("순수 우리말로 '즐거운' 이라는 뜻을 가진 단어는 다음 중 무엇일까요?\n");
    GotoXY(30, 13);
    printf("1. 가온누리   2. 라온   3. 동살   4. 시나브로   5. 행복");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '2')
        {
            GotoXY(30, 15);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '1' || userAnswer == '3' || userAnswer == '4' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 15);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 15);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 15);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz9()  
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("초성퀴즈!\n");
    GotoXY(30, 12);
    printf("주제 : 한국영화제목");
    GotoXY(30, 13);
    printf(" 'ㅈㅎㄴ ㄴㅃㄴ ㅇㅅㅎㄴ' 입력 후 엔터를 눌러주세요. (띄어쓰기 X, 쉼표 X)");
    char str1[40];
    GotoXY(30, 14);
    std::cin >> str1;
    GotoXY(30, 14);
    std::cout << str1 << std::endl;
    Sleep(1000);
    GotoXY(30, 14);
    printf("                             ");

    for (int i = 1; i <= 3; i++)
    {
        char str2[40] = "좋은놈나쁜놈이상한놈";
        if (strcmp(str1, str2) == 0)
        {
            GotoXY(30, 16);
            printf("$1 획득하셨습니다!");
            Sleep(2000);
            return true;
            break;
        }
        else if (strcmp(str1, str2) == 1 || strcmp(str1, str2) == -1)
        {
            if (i == 3)
            {
                GotoXY(30, 16);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 16);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 16);
                printf("                             ");
                GotoXY(30, 14);
                std::cin >> str1;
                GotoXY(30, 14);
                std::cout << str1 << std::endl;
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }

    }
}

bool Quiz10()
{
    GotoXY(30, 8);
    printf("문제를 맞히면 $1 달러를 드립니다 (기회 3번)\n");
    GotoXY(30, 10);
    printf("수도퀴즈!\n");
    GotoXY(30, 10);
    printf("싱가포르의 수도는?\n");
    GotoXY(30, 12);
    printf("1. 싱가포르   2. 보고타   3. 카트만두   4. 마닐라   5. 부다페스트");

    for (int i = 1; i <= 3; i++)
    {
        auto userAnswer = global::input::answerKey();
        if (userAnswer == '1')
        {
            GotoXY(30, 14);
            printf("$1 획득하셨습니다!");
            Sleep(1000);
            return true;
            break;
        }
        else if (userAnswer == '2' || userAnswer == '3' || userAnswer == '4' || userAnswer == '5')
        {
            if (i == 3)
            {
                GotoXY(30, 14);
                printf("돈을 얻지 못했습니다...");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                break;
            }
            else
            {
                GotoXY(30, 14);
                printf("틀렸습니다. 다시 시도하세요");
                Sleep(1000);
                GotoXY(30, 14);
                printf("                             ");
                continue;
            }
            return false;
        }
        else
            return false;
        continue;

    }
}

void UpdatePlayerPosition()
{

    //global::prePlayerPos = global::curPlayerPos; // 현재 위치 경신 전에 일단, 저장. 구조체를 쓰면 이런게 편한겁니다. :)

    //if (global::input::IsUpKeyOn())
    //{
    //    global::input::Set(global::input::UP_KEY_INDEX, false);

    //    global::curPlayerPos.Y = --global::y;
    //}

    //if (global::input::IsDownKeyOn())
    //{
    //    global::input::Set(global::input::DOWN_KEY_INDEX, false);

    //    global::curPlayerPos.Y = ++global::y;

    //}

    //if (global::input::IsLeftKeyOn())
    //{
    //    global::input::Set(global::input::LEFT_KEY_INDEX, false);

    //    global::curPlayerPos.X = --global::x;

    //}

    //if (global::input::IsRightKeyOn())
    //{
    //    global::input::Set(global::input::RIGHT_KEY_INDEX, false);

    //    global::curPlayerPos.X = ++global::x;

    //}
}

void UpdatePlayer()
{
    // 키 입력과 화면 출력과 게임 로직 갱신을 분리해서 생각해 봅시다.
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();

    while (elapsedTime >= global::playerMoveSpeed)
    {
        UpdatePlayerPosition();

        elapsedTime -= global::playerMoveSpeed;
    }
}

void StartGame()
{
    // 깜박이는 커서를 좀 진정 시키자.
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
    cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // 콘솔창 크기를 가져 오고
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    global::consoleScreenSize.Left = csbi.srWindow.Left;
    global::consoleScreenSize.Right = csbi.srWindow.Right;
    global::consoleScreenSize.Bottom = csbi.srWindow.Bottom;
    global::consoleScreenSize.Top = csbi.srWindow.Top;

    //// 플레이어 시작 위치 설정
    //global::prePlayerPos.X = 1;
    //global::prePlayerPos.Y = 2;
    //global::curPlayerPos.X = 1;
    //global::curPlayerPos.Y = 2;


}

void EndGame()
{
    GotoXY(20, 12);
    printf("게임 클리어");
}

void ProcessInput()
{
    global::input::UpdateInput();
}

void PrintCountsPerSecond();
void PrintPlayerPostion();

void Lobby()
{
    printf("\n\n\n\n");
    printf("       $$$$$$      $$      $$   $$   $$    $$          $$$$$$    $$$$$$   $$$$$$      $$      $$    $$\n");
    printf("       $$   $$    $$$$     $$$  $$   $$  $$            $$   $$   $$  $$   $$         $$$$     $$  $$  \n");
    printf("       $$$$$     $$  $$    $$ $ $$   $$$$              $$$$$     $$$$     $$$$$     $$  $$    $$$$    \n");
    printf("       $$   $$  $$$$$$$$   $$  $$$   $$  $$            $$   $$   $$  $$   $$       $$$$$$$$   $$  $$  \n");
    printf("       $$$$$$  $$      $$  $$   $$   $$    $$          $$$$$$    $$   $$  $$$$$$  $$      $$  $$    $$\n");
}

int menuDraw()
{
    int x = 45;
    int y = 12;
    GotoXY(x - 2, y);
    printf("> 탈 출 시 작 :)");
    GotoXY(x - 2, y + 1);
    printf("    포  기 :(   ");

    while (1)
    {
        int n = global::input::keyControl();
        switch (n)
        {
        case global::input::UP_KEY_INDEX:
        {
            if (y > 12)
            {
                GotoXY(x - 2, y);
                printf(" ");
                GotoXY(x - 2, --y);
                printf(">");
            }
            break;
        }
        case global::input::DOWN_KEY_INDEX:
        {
            if (y < 13)
            {
                GotoXY(x - 2, y);
                printf(" ");
                GotoXY(x - 2, ++y);
                printf(">");
            }
            break;
        }

        case global::input::SUBMIT:
        {
            return y - 12;
        }
        }

    }

}

char tempMaze[41][63];

char b_Maze[41][63] = // width=50, height=20
{
    {"1111111111111111111111111111111111111111111111111111111111111"},
    {"1000001000000000000000001100001000000000011000000000000000001"},
    {"1011101011111101101101111101111111111101011111101111111111101"},
    {"1s11101211100001101100000000001000000001011000000001011400001"},
    {"1111101111101111101001011111111111111111011111101111011111111"},
    {"1000000000001000001001011101000031000000000000001000000000001"},
    {"1111111111111111111111011101011111111111011111111111111011111"},
    {"1000011000001000000001000001011100001101000000000000000000001"},
    {"1111011111101111111101111101011101101101011111111101101011111"},
    {"1000011000000000000001000000000001100001000011001001101000001"},
    {"1011111111011101111101001011111111101111011011011111101111111"},
    {"1000001000011001001100001000001000000000011000000001001100001"},
    {"1011111111011111001001011111111111111111011011101111111101101"},
    {"1011001601000000001001000001000000000000011001100000000001101"},
    {"1011101101111101111111101101111111111111011111001111011111101"},
    {"1000000001000001000000001001000000000000011001001000000011101"},
    {"1111011111111101111111111111111101111011111101111111011011101"},
    {"1000000001000000000111111000000000001001000001001000011001001"},
    {"1011111111011111111111111111011111111111111101001111011111111"},
    {"1000001000001000001700000000001000001001000001011001000000001"},
    {"1011101011111111011111111011111001101001111101011011111111101"},
    {"1011001001000000000001100000001@01100000000000001000000001101"},
    {"1011111111001111111101101111111111101111111111111011111101101"},
    {"1000000001001001000000001111001000000000011001000000001000001"},
    {"1011101111111001111101111111001111101111011101111011001111101"},
    {"1011100000000001000001000000000000001111000000001011001081101"},
    {"1011111111101111011111111111111011111001111101111001111011101"},
    {"1000001000001001000001000000001000001001001001001001001000001"},
    {"1011101111101001111101111011111011111101001001001111001111111"},
    {"1011100001100000000000000000000011100001000000000000000000001"},
    {"1011111111101101011111001011111001101111011111001111111101111"},
    {"1001110000001101000001001000001000000001000001001111000001001"},
    {"1111111111111101111111111111111111101111111111111111011111001"},
    {"1000011000001000000001000000001000001!01000001000000000000001"},
    {"1111011111101011101101011111111111101001001111111011111101111"},
    {"1000000000000011001111000000000001100001000001001000001100001"},
    {"1011111111111111001081111111011111101111001111001001111111101"},
    {"1000051000000000000001000000000011101001000000001000001000001"},
    {"1011111011111101111111111011111011101001011111101111111011101"},
    {"10000010000011000011000000000010000000000000011000000010111?1"},
    {"1111111111111111111111111111111111111111111111111111111111111"}
};

void drawMap(int*x , int* y)
{
    system("cls");
    DWORD dw;
    int h, w;
    for (h = 0; h < 41;h++)
    {
        for (int w = 0; w < 63; w++)
        {   char temp = tempMaze[h][w];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7) | 0 << 4);
           // if (b_Maze[h][w] != tempMaze[h][w])
            {
               // int dist = (int)sqrt((*y - b) * (*y - b) + (*x- a) * (*x - a));
               // if (dist <= 5)
                {
                    //if(isPlayerSight(w,h,*x,*y))
                    {
                        if (temp == '0')
                        {
                            setColor(black, black);
                            printf("  ");
                        }
                        else if (temp == '1')
                        {
                            /*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7) << 4);
                            WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "  ", 2, &dw, NULL);*/
                            setColor(white, black);
                            printf("■");
                        }
                        else if (temp == '2' || temp == '3' || temp == '4' || temp == '5' || temp == '6' || temp == '7' || temp == '8' || temp == '9' || temp == '!' || temp == '@')
                        {
                            setColor(lightred, black);
                            printf("▣");
                        }
                        else if (temp == '?')
                        {
                            setColor(lightgreen, black);
                            printf("▥");
                        }
                        else if (temp == 's')
                        {
                            *x = w;
                            *y = h;
                            setColor(lightblue, black);
                            printf("♀");
                        }
                    }
                }
            }
          
            /*else
            {
                setColor(black, black);
                printf("11");
            }*/
        }
        printf("\n");

    }

}
void Update()
{
    global::time::updateCount += 1;

    UpdatePlayer();
    //DrawPlayer(false);
}
void FixedUpdate()
{
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();

    while (elapsedTime >= 20) //0.02초
    {
        global::time::fixedUpdateCount += 1;

        elapsedTime -= 20;
    }
}

void move(int* x, int* y, int _x, int _y, int* vault)
{

    char& mapObject = tempMaze[*y + _y][*x + _x];
    setColor(white, black);
    if (mapObject == '0')
    {
        GotoXY(2 * (*x), *y);
        printf("  ");
        tempMaze[*y][*x] = '0';
        setColor(lightblue, black);
        GotoXY(2 * (*x + _x), *y + _y);
        printf("♀");

        *x += _x;
        *y += _y;
        tempMaze[*y][*x] = 's';
    }
    else if (mapObject == '2')
    {

        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz1() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '3')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz2() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '4')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz3() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '5')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz4() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '6')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz5() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '7')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz6() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '8')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz7() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '9')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz8() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '!')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz9() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '@')
    {
        tempMaze[*y + _y][*x + _x] = '0';
        system("cls");
        if (Quiz10() == true)
        {
            *vault += 1;
        }
        else
        {
            *vault = *vault;
        }
        drawMap(x, y);
    }
    else if (mapObject == '?')
    {
        if (*vault >= 7)
        {
            tempMaze[*y + _y][*x + _x] = '0';
            system("cls");
            EndGame();
        }
        else if (*vault < 7)
        {
            tempMaze[*y + _y][*x + _x] = '?';
        }


        //drawMap(x, y);
    }
}

void drawUI(int* x, int* y, int * vault)
{
    setColor(white, black);
    GotoXY(3, 42);
    printf("위치 : %02d, %02d", *x, *y);

    setColor(green, black);
    GotoXY(34, 42);
    printf("Money : $%d", *vault);
}

void gLoop(int mapCode)
{
    int x, y;
    int playing = 1;
    int vault = 0;

    if (mapCode == 0)
    {
        memcpy(tempMaze, b_Maze, sizeof(tempMaze));
    }

    drawMap(&x, &y);

    while (playing)
    {
        drawUI(&x, &y, &vault);
        
        global::time::UpdateTime();
        ProcessInput();
        FixedUpdate();
        Update();
        switch (global::input::keyControl())
        {
        case global::input::UP_KEY_INDEX:
        {
            move(&x, &y, 0, -1, &vault);
            break;
        }
        case global::input::DOWN_KEY_INDEX:
        {
            move(&x, &y, 0, 1, &vault);
            break;
        }
        case global::input::LEFT_KEY_INDEX:
        {
            move(&x, &y, -1, 0, &vault);
            break;
        }
        case global::input::RIGHT_KEY_INDEX:
        {
            move(&x, &y, 1, 0, &vault);
            break;
        }

        case global::input::ESC:
        {
            playing = 0;
        }
        }
    }

}

bool isPlayerSight(int x, int y, int pX, int pY)
{
    static float sightRange = 5;
    bool isInSight = false;

    if (sightRange < sqrt((pY - y) * (pY - y) + (pX - x) * (pX - x)))
        isInSight = false;
    else
        isInSight = true;

    return isInSight;
}

void Render(int* x, int* y, int _x, int _y)
{
    //GotoXY(0, 0); // 프레임 카운트 출력 위치
    //PrintCountsPerSecond();

    //GotoXY(50, 0); // 플레이어 위치 정보
    //PrintPlayerPostion();

    // 위치가 달라지면 갱신
    /*if ((global::prePlayerPos.X + 1 == global::curPlayerPos.X))
    {
        GotoXY(*x-1, *y);
        printf(" ");
        GotoXY(*x, *y);
        printf("▲");
    }*/
}

bool IsGameRun()
{
    return true;
}

void PrintPlayerPostion()
{
    printf("Player Position (%d, %d)", global::curPlayerPos.X, global::curPlayerPos.Y);
}

void PrintCountsPerSecond()
{
    static ULONGLONG elapsedTime;

    elapsedTime += global::time::GetDeltaTime();
    if (elapsedTime >= 1000)
    {
        printf("updateCount : %d \t fixedUpdateCount : %d \n",
            global::time::updateCount, global::time::fixedUpdateCount);


        elapsedTime = 0;
        global::time::updateCount = 0;
        global::time::fixedUpdateCount = 0;
    }
}

int main()
{
    global::time::InitTime();

    StartGame();
    bool isDrawMenu = false;

    while (IsGameRun())
    {
        Lobby();

        int menucode = menuDraw();
        if (menucode == 0)			//탈출시작
        {
            gLoop(0);
        }
        else if (menucode == 1)		//포기..
        {
            return 0;
        }
        system("cls");

    }

    EndGame();

    return 0;
}