#include <ncurses.h>


/* --------------------------------------------------------------
  main
   -------------------------------------------------------------- */
int main(void)
{
  int i;
  int key;
  int x, y;
  int oldx, oldy;

  initscr();

  /* 特殊キーを受け取る */
  noecho();
  cbreak();
  keypad(stdscr, TRUE);


  /* 初期座標 */
    x = 16;
    y = 4;
  move(y,x);
  printw("I am  %d years old.", 53);

  move(y+1,x);
  printw("I am  %d years old.", 33);

  attron(A_BLINK);
  move(y+1,x);
  printw("%s is  Happy today.", "Hirose");


 while ((key = getch()) != KEY_EVENT) {
    switch (key) {
    case KEY_UP :
      oldx = x;
      oldy = y;
      y--;
      if (y < 0) y = 0;
      break;
    case KEY_DOWN :
      oldx = x;
      oldy = y;
      y++;
      if (y > 17) y = 17;
      break;
    case KEY_LEFT :
      oldx = x;
      oldy = y;
      x--;
      if (x < 0) x = 0;
      break;
    case KEY_RIGHT :
      oldx = x;
      oldy = y;
      x++;
      if (x > 63) x = 63;
      break;
    }
  }


//  viewheart(x, y);  /* ハートを表示 */
//  moveheart(oldx,oldy, x,y);      /* キーでハートを動かす */

  endwin();
  return (0);
}



