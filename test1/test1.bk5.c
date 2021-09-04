#include <ncurses.h>


int main(void)
{
    initscr();
    noecho();
    cbreak();
    int y,x, yBeg, xBeg, yMax, xMax;

    refresh();

    move(3,3);
    getyx(stdscr,y,x);    //  カーソルの現在位置

    getbegyx(stdscr,yBeg,xBeg);   //  カーソルの最初の位置　開始位置

    getmaxyx(stdscr,yMax,xMax);   //  カーソルの最大　縦と横　　ターミナルのサイズに依存する。

    mvprintw(5, 5, "%d %d %d %d %d %d", y,x, yBeg, xBeg, yMax, xMax);

    WINDOW * win1 = newwin(yMax/2, xMax/2, yMax/4, xMax/4);

//    box(win1,yMax/2, xMax/2);     //  サブウインドウの表示
    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = ACS_VLINE;     //   枠のフォント設定   横線
    top = bottom = ACS_HLINE;    //   枠のフォント設定　　縦線
    tlc = ACS_ULCORNER;      //  上左角  
    trc = ACS_URCORNER;      //  上右角  
    blc = ACS_LLCORNER;      //  下左角  
    brc = ACS_LRCORNER;      //  下右角  
    wborder(win1, left,right, top, bottom, tlc, trc, blc, brc);
    wrefresh(win1);

    getch();
    endwin();

    return 0;
}
