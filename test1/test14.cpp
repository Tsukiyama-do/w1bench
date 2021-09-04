#include <ncurses.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM 
#define BOARD_COLS BOARD_DIM * 2.5
#define ESC 0x1b

int main(void)
{
    setlocale(LC_ALL,"");
    initscr();
    refresh();
    cbreak();
 
    int xMax, yMax;
    int cy, cx;
    getmaxyx(stdscr, yMax, xMax);   //  スクリーンの大きさを取得

//    resizeterm(yMax + 6, xMax - 10);  // 画面サイズ変更

    WINDOW * ru_win = newwin(yMax/2 ,xMax/2  , 0, 0);    // define Right top window
    box(ru_win, 0, 0);
    WINDOW * lu_win = newwin(yMax/2 ,xMax/2  , 0 , xMax/2);    // define left top window
    box(lu_win, 0, 0);
    WINDOW * by_win = newwin(yMax/2 - 4 ,xMax   , yMax/2  , 0);    // define body window
    box(by_win, 0, 0);
    WINDOW * btm_win = newwin(4 ,xMax  , yMax - 4  , 0);    // define bottom window
    box(btm_win, 0, 0);

    mvwprintw(ru_win, 1,1, "Right top win");   // labelling right top  
        mvwprintw(ru_win, 2,1, "File Name    :");   //   
        mvwprintw(ru_win, 3,1, "Your Name    :");   //   
        mvwprintw(ru_win, 4,1, "Date         :");   //   
    mvwprintw(lu_win, 1,1, "Left top win");   // labelling left top  
        mvwprintw(lu_win, 2,1, "道はあるようで無い :");   //   
        mvwprintw(lu_win, 3,1, "本を読む           :");   //   
        mvwprintw(lu_win, 4,1, "銚子電鉄に乗りたい :");   //   
    mvwprintw(by_win, 1,1, "Body win");   // labelling body 
    mvwprintw(btm_win, 1,1, "Bottom win yMax : %d, xMax : %d", yMax, xMax);   // labelling bottom   

    wrefresh(ru_win);
    wrefresh(lu_win);
    wrefresh(by_win);
    wrefresh(btm_win);
    keypad(ru_win, TRUE);  // Function Key get available.
    keypad(lu_win, TRUE);  // Function Key get available.
    keypad(by_win, TRUE);  // Function Key get available.
    keypad(btm_win, TRUE);  // Function Key get available.


    char ru_str[5][15];    //  入力したものの入れ場所
    char lu_str[5][45];     //  入力したものの入れ場所
//    char by_str[5][15];     //  入力したものの入れ場所
    int i_ru = 0, i_lu = 0, i_by = 0, j_ru = 0, j_lu = 0, j_by = 0;

    WINDOW * cur_win;    //  カーソルのいるWINDOW
    cur_win = ru_win;      //  カーソルのいるWINDOW
    wmove(cur_win,2, 15);   //  カーソルを最初のWINDOWに移動
    char c_str[100];
    wrefresh(cur_win);     // WINDOWS再表示
    int c;                //  wgetchを受入る変数
    bool wflag = true;   //  while loop control
    bool flag_j = false;
    while( wflag) {
        if (flag_j == true) {     // Japanese
            c = wgetstr(cur_win,c_str);   // Multibyte area string
            switch(c) {
                case OK :
                        if (cur_win == ru_win) {
                        } else if( cur_win == lu_win) {
                            strcpy(lu_str[i_lu],c_str);   // Arrayに1文字を入れる
                            i_lu++;
                            wmove(cur_win,i_lu + 2, 22);   //  次の行へ移動
                        } else {
                        }
                    break;
                case ERR :
                        if (cur_win == ru_win) {
                        } else if( cur_win == lu_win) {
                            wmove(cur_win,i_lu + 2, 22);   //  次の行へ移動
                        } else {
                        }
                        break;
            }
        } else {         // Non Japanese
            c = wgetch(cur_win);
            switch(c) {
                case '\t' :
                case '\n' :
                        if (cur_win == ru_win) {
                            ru_str[i_ru][j_ru] = '\0';   // LFを入れる
                            i_ru++;                      //  次の入れ物へ
                            j_ru = 0;                     //  最初の桁にリセット
                            wmove(cur_win,i_ru + 2, 15);   //  次の行へ移動
                        } else if( cur_win == lu_win) {
                        } else {
                        }
                        break;
                case KEY_F(9) :                 //  次のカーソルに移動させる
                        if (cur_win == ru_win){
                            cur_win = lu_win;
                            flag_j = true;      // Japanese area
                            wmove(cur_win, i_lu + 2,22);
                        } else if( cur_win == lu_win) {
                        }
                        break;
                case KEY_F(8) :                    //  入力ループを抜ける
                        wflag = false;
                        break;
                default:
                        if (cur_win == ru_win) {
                            ru_str[i_ru][j_ru] = c;    // Arrayに1文字を入れる
                            j_ru++;
                            wmove(cur_win,i_ru + 2, j_ru +15);   //  次の行へ移動
                        } else if( cur_win == lu_win) {
                        } else {
                        }
                    break;
            }
        }
        wrefresh(cur_win);     // WINDOWS再表示

        //     for (int j = 0 ; j <= ii; j++ ) {
        // mvwprintw(board_win, cy + ii + 1 + j , cx ,id[j]);
    }
        // wrefresh(ru_win);     // WINDOWS再表示
        // wrefresh(lu_win);     // WINDOWS再表示
        // wrefresh(by_win);     // WINDOWS再表示
        // wrefresh(btm_win);     // WINDOWS再表示


    getch();    //  スクリーンでの入力待ち

    endwin();   //  終了

    return 0;
}
