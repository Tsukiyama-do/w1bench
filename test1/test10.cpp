#include <ncurses.h>
#include "src/Board.hpp"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM 
#define BOARD_COLS BOARD_DIM * 2.5
#define ESC 0x1b

int main(void)
{
    initscr();
    refresh();
    cbreak();
 
    int xMax, yMax;
    int cy, cx;
    getmaxyx(stdscr, yMax, xMax);   //  スクリーンの大きさを取得

//    resizeterm(yMax + 6, xMax - 10);  // 画面サイズ変更

    WINDOW * board_win = newwin(BOARD_ROWS, BOARD_COLS, (yMax/2) - (BOARD_ROWS/2), (xMax/2) - (BOARD_COLS/2));
    box(board_win, 0, 0);
    keypad(board_win, TRUE);  // Function Key get available.
   mvwprintw(board_win, 3,3, "Enter your id : ");
    cy = 3;
    cx = 3 + 17;
    wmove(board_win,cy, cx);

    wrefresh(board_win);

    char id[10][50];
    int c;
    bool flag = true;
    int ii = 0, ij = 0;   // ii : 文字列番号  ij:  桁数
    // if  ( mvwgetstr(board_win, cy, cx, id) == OK) {
    //     mvwprintw(board_win, 5, 3, "The id is %s",id);
    //     wrefresh(board_win);

    // } ;
    // if (has_key(KEY_ENTER) == TRUE) {
    //  mvwprintw(board_win, 7,3, "Key enter is OK");   
    // } else {
    //  mvwprintw(board_win, 7,3, "Key enter is not OK");   
    // }
    while(flag ) {
        wmove(board_win, cy + ii, cx + ij);
        wrefresh(board_win);
        c = wgetch(board_win);
//        c = wgetch(board_win);
        switch(c) {
            case '\t' :
            case '\n' :
                id[ii][ij] = '\0';
                ii++;
                ij = 0;
                break;
            case KEY_F(9) :
                flag = false;
                id[ii][ij] = '\0';
                break;
            default : 
                id[ii][ij] = c;
                ij++;
                break;
        }
    }
    for (int j = 0 ; j <= ii; j++ ) {
        mvwprintw(board_win, cy + ii + 1 + j , cx ,id[j]);
    }
    wrefresh(board_win);

    getch();    //  スクリーンでの入力待ち

    endwin();   //  終了

    return 0;
}
