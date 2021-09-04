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

    //  小ウィンドウの定義
        WINDOW * win1 = newwin(yMax/2, xMax/2, yMax/4, xMax/4);

    //    box(win1,yMax/2, xMax/2);     //  サブウインドウの表示
        int left, right, top, bottom, tlc, trc, blc, brc;
        left = right = ACS_VLINE;     //   枠のフォント設定   横線
        top = bottom = ACS_HLINE;    //   枠のフォント設定　　縦線
        tlc = ACS_ULCORNER;      //  上左角  
        trc = ACS_URCORNER;      //  上右角  
        blc = ACS_LLCORNER;      //  下左角  
        brc = ACS_LRCORNER;      //  下右角  
        wborder(win1, left,right, top, bottom, tlc, trc, blc, brc);  // box is displayed.
    //  小ウィンドウの表示
        wrefresh(win1);  //  box refreshed.
        keypad(win1, true);  //  key move

    //  小ウィンドウの項目準備
        char * choices[] = {"Walk", "Jog", "Run","Crowl","Skip"};
        int choice;
        int highlight = 0;
        int c_cont = 0;


    //  小ウィンドウの項目動作対応
    while(1)
    {
        //  小ウィンドウでの画面表示セクション（テキスト表示）
        for ( int i = 0; i < 5 ; i++)       //   display array's texts
        {
            if ( i == highlight)
                wattron(win1, A_REVERSE);     // set highlight
            mvwprintw(win1, i+1, 1, *(choices + i));
            wattroff(win1, A_REVERSE);      // cancel highlight
        }


        //  小ウィンドウでの入力待ち処理
        choice = wgetch(win1);   // key operation like key_up or key_down

        //  小ウィンドウの入力後の処理（カウント）
        switch (choice)
        {
            case KEY_UP:  /* constant-expression */
                if (highlight > 0)
                    highlight--;
                break;
            case KEY_DOWN:  /* constant-expression */
                if (highlight < 4)
                    highlight++;
                break;
            default:
                break;
        }
        if(choice == 10)   //  10 means "Enter" key
            break;     // 小ウィンドウを終了
    }

    getch();    //  スクリーンでの入力待ち
    endwin();   //  終了

    return 0;
}
