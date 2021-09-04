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
  raw();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLUE);
  attron(COLOR_PAIR(1));
  mvprintw(10, 10, "AHH my eyes");
  attroff(COLOR_PAIR(1));
  mvprintw(15, 10, "AHH my eyes");

//  refresh();
  mvprintw(16, 10, "How old are you? : ");
  move(16,31);

  int c = getch();

  move(17,10);

  printw("It is %c", c);  
  getch();
  endwin();
  return (0);
}



