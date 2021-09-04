#include <ncurses.h>


/* --------------------------------------------------------------
  main
   -------------------------------------------------------------- */
int main(void)
{
  int height,width,start_y, start_x;
  height = 5;
  width = 20;
  start_x = start_y = 3;

  /*  Initialization of screen */
  initscr();

  refresh();
  WINDOW * win = newwin(height, width, start_y, start_x);

  /* 特殊キーを受け取る */
  raw();
  // cbreak();
  // noecho();

  refresh();

  /* Create box */
  box(win, 0,0 );
  mvwprintw(win, 2,2, "This is test");
  wrefresh(win);

  mvprintw(15, 10, "How old are you? : ");
  move(15,31);

  int c = getch();

  move(16,10);

  printw("It is %c", c);  
  getch();
  endwin();
  return (0);
}



