/*	
	SHINY - An HTML to GemText converter
	------------------------------------
	WIP: Please provide suggestions to:
		gtlsgamr<gtlsgamr@tilde.team> or 
		gtlsgamr<gtlsgamr@ctrl-c.club>  
	------------------------------------
	At this point, the program assumes a few things:
		* You will not nest tags on the same line.
		* You will start anchor tag attributes with the href attribute:
			<a href=""..... > </a>   <---- Correct
			<a class="" href=""..... > </a>   <---- Correct
		* One type of tag on one line, if possible.
		* You will enter html without meta data. It might work with it, but try to input only the stuff that you want to convert and nothing else.
*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

int in_tag = 0;
int btn_tag = 0;
void tagparser(char c) {
  switch (c) {
  case 'a':
    printf("\n");
    switch (getchar()) {
    case ' ':
      if (getchar() == 'h') {
        printf("=> ");
        for (c = getchar(); c != '='; c = getchar()) {}
        getchar();
        for (c = getchar(); c != 39 && c != '"'; c = getchar()) {
          printf("%c", c);
        }
        printf(" ");
        getchar();
        for (c = getchar(); c != '<'; c = getchar()) {
          printf("%c", c);
        }
        printf("\n");
        in_tag = 1;
      } else {
        for (c = getchar(); c != ' ' && getchar() != 'h'; c = getchar()) {}
        printf("=> ");
        for (c = getchar(); c != '='; c = getchar()) {}
        getchar();
        for (c = getchar(); c != 39 && c != '"'; c = getchar()) {
          printf("%c", c);
        }
        printf(" ");
        getchar();
        for (c = getchar(); c != '<'; c = getchar()) {
          printf("%c", c);
        }
        printf("\n");
        in_tag = 1;
      }
      break;
    default:
      ;
    }
    break;

  case 'l':
    switch (getchar()) {
    case 'i':
      printf("* ");
      for (c = getchar(); c != '>'; c = getchar()) {}
      for (c = getchar(); c != '<'; c = getchar()) {
        printf("%c", c);
      }
      btn_tag = 0;
      in_tag = 1;
      break;
    default:
      break;
    }
    break;

  case 'h':
    in_tag = 1;
    btn_tag = 0;
    switch (getchar()) {
    case '1':
      printf("%c ", '#');
      break;
    case '2':
      printf("%c%c ", '#', '#');
      break;
    case '3':
      printf("%c%c%c ", '#', '#', '#');
      break;
    case '4':
      printf("%c%c%c ", '#', '#', '#');
      break;
    case '5':
      printf("%c%c%c ", '#', '#', '#');
      break;
    case '6':
      printf("%c%c%c ", '#', '#', '#');
      break;
    default:
      break;
    }
    break;
  case 'b':
    for (c = getchar(); c != '>'; c = getchar()) {}
    break;
  case 'p':
    break;
  default:
    ;
  }
}

void parser() {
  int c;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case '<':
      in_tag = 1;
      c = getchar();
      tagparser(c);
      break;

    case '>':
      btn_tag = in_tag ? 1 : 0;
      in_tag = 0;
      c = getchar();
      break;

    default:
      ;
    }
    if (in_tag == 0 && btn_tag == 1) {
      printf("%c", c);
    }
  }

}

int main(int argc, char * argv[]) {
  parser();
  return 0;
}
