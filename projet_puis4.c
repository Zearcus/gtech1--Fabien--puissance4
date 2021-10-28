#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


#define LIN 6
#define COL 7
#define CONNECT 4



char arr[LIN][COL];
char bot[] = "  1   2   3   4   5   6   7  ";
char structure[] = "|---|---|---|---|---|---|---|";
char sign_1 = 'X';
char sign_2 = 'O';
char actual_sign = 'X';
int col = 0;




void array_init();
void print_array();
void current_arr();
void check_insert_choice();
void choice();
void fill_col();
void flushstdin();
int check_horizontal_win(char actual_sign);
int check_vertical_win(char actual_sign);


int main()
{
  printf("\n\n\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nO                                                                                                          O\nO                                                                                                          O\nO                                                                                                          O\n");
  printf("O                    ------------------- Bienvenue cher joueurs -------------------                            O\nO                                                                                                          O\nO                                                                                                          O\nO                                                                                                          O\n");
  printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
  array_init();
  print_array();
  current_arr();

  //game loop
  while (42) {
    printf("Player %c, it's your turn !\n", actual_sign);
    choice();
    printf("\n\n\n");
    current_arr();
  }

  return 0;
}








// Initialize the array
void array_init(void) {

  int x, y;

  for( x = 0; x < LIN; x++) {

    for( y  = 0; y < COL; y++) {
      arr[x][y] = ' ';
    }
  }

}


void print_array() {
  int x, y;

  for( x = 0; x < LIN; x++) {

    for( y  = 0; y < COL; y++) {
      printf("%c", arr[x][y]);
    }
    printf("\n");

  }

}
// Print the current array
void current_arr() {

  printf("%s\n", structure);  /* Head of grid */

  int x, y;

  for(x = 0; x < LIN; x++) {

    for( y = 0; y < COL; y++) {

      printf("| %c ", arr[x][y]);

    }
    printf("|\n");
    printf("%s\n", structure);


  }
  printf("%s\n", bot);
}

// Fill the choosed column with the actual player's sign
void fill_col(){
  int lvl ; /* Actual bottom of the grid */

  for(lvl = LIN - 1; lvl >= 0; lvl--){
    if(arr[lvl][col] == ' '){
      arr[lvl][col] = actual_sign;
      break;
    }
  }

}
// Clean the stdin
void flushstdin() {
  int z;
  while((z = getchar()) != '\n' && z != EOF) {;}

}

// The player choose the column
void check_insert_choice(int *c) {
  int code_ret;
  int insert_is_ok, stop = 0;



  do {
    printf("\nChoose the column : ");
    code_ret = scanf("%d", c);
    insert_is_ok = code_ret == 1;

    if(!insert_is_ok){
      printf("\nWrong insert ! Try Again ! \n\n");
      flushstdin();
      current_arr();
    }
    stop = insert_is_ok;


  }
  while(!stop);

}

void choice(void) {

  int value_c;


  do {
    check_insert_choice(&value_c);

    col = value_c - 1;
    if((col >= 0 && col <= 6) && (arr[0][col] == ' ')){

      fill_col();
      actual_sign = (actual_sign == sign_1) ? sign_2 /*  O  */ : sign_1/*  X  */;

      break;
    }

  }while(42);

}






// Comment section

/*


 */
