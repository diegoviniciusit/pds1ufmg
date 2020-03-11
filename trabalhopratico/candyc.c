#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>

//amount of lines, columns and candy types
#define N_LIN 12
#define N_COL 8
#define N_TYPES 6

//candy types
#define TRIANGLE 1
#define RECTANGLE 2
#define CIRCLE 3
#define ROUNDED_RECTANGLE 4
#define P_TRIANGLE 5
#define UPSIDE_TRIANGLE 6

//screen height, width, infographic (score and moves) height, size of infographic font, fps, margin size, max moves, background file
#define SCREEN_H 960
// #define SCREEN_H 640
#define SCREEN_W 720
// #define SCREEN_W 480
#define INFO_H 96
// #define INFO_H 64
#define SIZE_FONT 40
// #define SIZE_FONT 25
#define FPS 60
#define MARGIN 5
#define MAX_MOVES 10
#define BACKGROUND_FILE "background.jpg"

/*candy structure
	type: is used to store the candy type (0 - 6), with 0 being the candy that won't be drawed
	active: is used to store if the candy has to be considered while searching for sequences, it will be 0 after a sequence is made with that candy
*/
typedef struct Candy {
	int type;
	int active;
	ALLEGRO_COLOR color;
} Candy;

//allegro font global variable
ALLEGRO_FONT *size_f;
//candy global matrix
Candy M[N_LIN][N_COL];
//colors global variable
ALLEGRO_COLOR colors[N_TYPES + 1];
//background global variable
ALLEGRO_BITMAP *background = NULL;

//width of a single cell
const float CELL_W = (float) SCREEN_W / N_COL;
//height of a single cell
const float CELL_H = (float) (SCREEN_H - INFO_H) / N_LIN;
//global moves variable
int moves = MAX_MOVES;
//global score variable
int score = 0;
//global to determine if the game is running, is needed because of the option to play again
int game_running = 1;
//chars that will store the text that contains the score and moves
char my_score[100], my_moves[100];

//function to initialize allegro, returns -1 if something goes wrong, and 0 otherwise
int initializeAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_TIMER **timer, ALLEGRO_SAMPLE **moveSound, ALLEGRO_SAMPLE **scoreSound)
{
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}
	//initialize timer with that amount of fps configured
	*timer = al_create_timer(1.0 / FPS);
	if (!*timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	*display = al_create_display(SCREEN_W, SCREEN_H);
	if (!*display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(*timer);
		return -1;
	}
	*event_queue = al_create_event_queue();
	if (!*event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(*display);
		al_destroy_timer(*timer);
		return -1;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "failed to initialize images!\n");
        return -1;
	}
	background = al_load_bitmap(BACKGROUND_FILE);
    if (!background) {
		fprintf(stderr, "failed to load background bitmap!\n");
		return -1;
    }
	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }
	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }
	*moveSound = al_load_sample("moveSound.wav");
	if (!*moveSound) {
		fprintf(stderr, "audio clip move not loaded!\n");
		return -1;
	}
	*scoreSound = al_load_sample("scoreSound.wav");
	if (!*scoreSound) {
		fprintf(stderr, "audio clip score not loaded!\n");
		return -1;
	}
	if (!al_reserve_samples(2)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}
	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
        return -1;
    }
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize keyboard!\n");
        return -1;
    }
	al_init_font_addon();
	al_init_ttf_addon();
	size_f = al_load_font("arial.ttf", SIZE_FONT, 1);
	//initialize events that the game will be listening to
    al_register_event_source(*event_queue, al_get_display_event_source(*display));
    al_register_event_source(*event_queue, al_get_timer_event_source(*timer));
	al_register_event_source(*event_queue, al_get_keyboard_event_source());
	al_register_event_source(*event_queue, al_get_mouse_event_source());
	//starts timer
	al_start_timer(*timer);
	//initialize colors, 0 being white for the animation before completing a sequence
	colors[0] = al_map_rgb(255, 255, 255);
	colors[TRIANGLE] = al_map_rgb(255, 0, 0);
	colors[RECTANGLE] = al_map_rgb(255, 255, 0);
	colors[CIRCLE] = al_map_rgb(0, 0, 255);
	colors[ROUNDED_RECTANGLE] = al_map_rgb(0, 255, 0);
	colors[P_TRIANGLE] = al_map_rgb(0, 255, 255);
	colors[UPSIDE_TRIANGLE] = al_map_rgb(255, 0, 255);
	srand(time(NULL));
    return 0;
}

//generates a candy and returns it
Candy generateCandie()
{
	Candy candy;
	candy.type = rand() % N_TYPES + 1;
	candy.color  = colors[candy.type];
	candy.active = 1;
	return candy;
}

//initialize the candy matrix
void initCandies()
{
	int i, j;
    for (i = 0; i < N_LIN; i++) {
        for (j = 0; j < N_COL; j++) {
            M[i][j] = generateCandie();
        }
    }
}

//pauses the game, stopping the timer and resting the screen
void pause(ALLEGRO_TIMER *timer, float seconds)
{
	al_stop_timer(timer);
	al_rest(seconds);
	al_start_timer(timer);
}

//draw a candy according to its type
void drawCandy(int lin, int col)
{
	//which x should the candy be initialized (not counting margin)
	int cell_x = CELL_W * col;
	//which y should the candy be initialized (not counting margin)
	int cell_y = CELL_H * lin;
	if (M[lin][col].type == TRIANGLE) {
		al_draw_filled_triangle(cell_x + MARGIN, cell_y + CELL_H - MARGIN, cell_x + CELL_W - MARGIN, cell_y + CELL_H - MARGIN, cell_x + CELL_W / 2, cell_y + MARGIN, M[lin][col].color);
	} else if (M[lin][col].type == RECTANGLE) {
		al_draw_filled_rectangle(cell_x + MARGIN, cell_y + MARGIN, cell_x - MARGIN + CELL_W, cell_y - MARGIN + CELL_H, M[lin][col].color);
	} else if (M[lin][col].type == CIRCLE) {
		al_draw_filled_ellipse(cell_x + CELL_W / 2, cell_y + CELL_H / 2, CELL_W / 2 - MARGIN, CELL_H / 2 - MARGIN, M[lin][col].color);
	} else if (M[lin][col].type == ROUNDED_RECTANGLE) {
		al_draw_filled_rounded_rectangle(cell_x + MARGIN, cell_y + MARGIN, cell_x - MARGIN + CELL_W, cell_y - MARGIN + CELL_H, CELL_W / 3, CELL_H / 3, M[lin][col].color);
	} else if (M[lin][col].type == P_TRIANGLE) {
		al_draw_filled_triangle(cell_x + MARGIN, cell_y + CELL_H - MARGIN, cell_x + CELL_W - MARGIN, cell_y + CELL_H - MARGIN, cell_x + MARGIN, cell_y + MARGIN, M[lin][col].color);
	} else if (M[lin][col].type == UPSIDE_TRIANGLE) {
		al_draw_filled_triangle(cell_x + MARGIN, cell_y + MARGIN, cell_x + CELL_W - MARGIN, cell_y + MARGIN, cell_x + CELL_W / 2, cell_y + CELL_H - MARGIN, M[lin][col].color);
	}
}

//draw the whole scenario
void drawScenario(ALLEGRO_DISPLAY *display)
{
	//draw the background bitmap
    al_draw_bitmap(background, 0, 0, 0);
	//store the score in my_score
	sprintf(my_score, "Score: %d", score);
	//draw the my_score text with size_f and white color on the bottom of the screen
	al_draw_text(size_f, al_map_rgb(255, 255, 255), 10, SCREEN_H - (INFO_H / 2), 0, my_score);
	//store the moves in my_moves
	sprintf(my_moves, "Moves: %d", moves);
	//draw the my_moves text with size_f and white color on the bottom of the screen
	al_draw_text(size_f, al_map_rgb(255, 255, 255), SCREEN_W - 200, SCREEN_H - (INFO_H / 2), 0, my_moves);
	int i, j;
	//draw candies
	for (i = 0; i < N_LIN; i++) {
		for (j = 0; j < N_COL; j++) {
			drawCandy(i, j);
		}
	}
	//flipping display, because everything is drawed in a mirrored screen, and when you flip you change them and it gets updated
	al_flip_display();
}

//get the candy cell, using the x and y position that the user clicked, and manipulating that position according to the cell size
void getCell(int x, int y, int *lin, int *col)
{
	*lin = y / CELL_H;
	*col = x / CELL_W;
}

//get the distance between two points
int getDistance(int lin_src, int col_src, int lin_dest, int col_dest)
{
    int lin_res, col_res;
    lin_res = lin_src - lin_dest;
    col_res = col_src - col_dest;
    return sqrt((lin_res * lin_res) + (col_res * col_res));
}

//check if ths first candy is in a diagonal position comparing it to the second one
int isCandyDiagonal(int lin_src, int col_src, int lin_dest, int col_dest)
{
	if (lin_src == lin_dest || col_src == col_dest) {
		return 0;
	}
	return 1;
}

//change one cell with another one
void changeCells(int lin_src, int col_src, int lin_dest, int col_dest)
{
    Candy aux = M[lin_src][col_src];
    M[lin_src][col_src] = M[lin_dest][col_dest];
    M[lin_dest][col_dest] = aux;
}

//score the sequence using the starting line, finishing line, starting column and finishing column, returning the points made
int scoreSequence(int lin, int lin2, int col, int col2)
{
	int points = 0;
	for (int i = lin; i <= lin2; i++) {
		for (int j = col; j <= col2; j++) {
			points++;
			//setting the color to white
			M[i][j].color = colors[0];
			//deactivating it, for it not to be scored again
			M[i][j].active = 0;
		}
	}
	return points;
}

//checks the candy matrix and returns the points made
int checkGame()
{
	int i, j, k, lastType, points = 0;
	/*checks the lines sequences
	it goes starting from the second column, if the last candy type is the same as the one it's being verified at the moment and if it is active, 
	then it stores that there's a K number of candies in sequence, when the line is over or the sequence is broke by some other type of candy, 
	it verifies if there was a sequence greater than 3, if there was, then it scores it*/
	for (i = 0; i < N_LIN; i++) {
		k = 1;
		lastType = M[i][0].type;
		for (j = 1; j < N_COL; j++) {
			if (lastType == M[i][j].type && M[i][j].active == 1) {
				k++;
				if (k >= 3 && j == N_COL - 1) {
					points += scoreSequence(i, i, j - k + 1, j);
				}
			} else {
				if (k >= 3) {
					points += scoreSequence(i, i, j - k, j - 1);
				}
				k = 1;
				lastType = M[i][j].type;
			}
		}
	}
	/*checks the columns sequences
	it goes starting from the second line, if the last candy type is the same as the one it's being verified at the moment and if it is active, 
	then it stores that there's a K number of candies in sequence, when the line is over or the sequence is broke by some other type of candy, 
	it verifies if there was a sequence greater than 3, if there was, then it scores it*/
	for (i = 0; i < N_COL; i++) {
		k = 1;
		lastType = M[0][i].type;
		for (j = 1; j < N_LIN; j++) {
			if (lastType == M[j][i].type && M[j][i].active == 1) {
				k++;
				if (k >= 3 && j == N_LIN - 1) {
					points += scoreSequence(j - k + 1, j, i, i);
				}
			} else {
				if (k >= 3) {
					points += scoreSequence(j - k, j - 1, i, i);
				}
				k = 1;
				lastType = M[j][i].type;
			}
		}
	}
	return points;
}

//updates the game, dropping the candies if needed
void updateGame()
{
	int offset;
	/*goes candy by candy, starting with the last one of the first row, 
	and then goes verifying if a candy is deactivated, if it is, then adds one to the offset,
	the offset is how many rows the candy will have to be dropped, 
	and then verifies if there is an offset greater than 0, if there is, then it changes that candy with the one that is
	deactivated below him, making the candy fall*/
	for (int j = 0; j < N_COL; j++) {
		offset = 0;
		for (int i = N_LIN - 1; i >= 0; i--) {
			if (M[i][j].active == 0) {
				M[i][j].type = 0;
				offset++;
			} else if (offset) {
				M[i + offset][j].type = M[i][j].type;
				M[i + offset][j].color = M[i][j].color;
				M[i + offset][j].active = M[i][j].active;
				M[i][j].type = 0;
				M[i][j].active = 0;
			}
		}
	}
}

//fill the matrix with candies, replacing the ones with type 0
void fillMatrix()
{
	for (int i = 0; i < N_LIN; i++) {
		for (int j = 0; j < N_COL; j++) {
			if (M[i][j].type == 0) {
				M[i][j] = generateCandie();
			}
		}
	}
}

//starts the game, initializing the candies, and drawing the scenario
void startGame(ALLEGRO_DISPLAY *display)
{
	/*initialize the candies and check if there is a sequence,
	if there is, that erase that sequence and fill the matrix,
	keep doing that until there is no sequence left
	*/
    initCandies();
	int combinations = checkGame();
	if (combinations > 0) {
		do {
			updateGame();
			fillMatrix();
		} while (checkGame() > 0);
	}
	//draw the scenario
    drawScenario(display);
}

//return 1 if there is a new record, and stores it, return 0 if there isn't
int newRecord(int score, int *record)
{
	//read the record file
	FILE *arq = fopen("record.txt", "r");
	*record = -1;
	if (arq != NULL) {
		fscanf(arq, "%d", record);
		fclose(arq);
	}
	//check if the record store is lower than the one the player did
	if (score > *record) {
		//if it is lower, than stores the new record
		arq = fopen("record.txt", "w");
		fprintf(arq, "%d", score);
		fclose(arq);
		return 1;
	}
	return 0;
}

//end the game
void endGame(ALLEGRO_TIMER **timer)
{
	//pause the timer
	pause(*timer, 1);
	int record;
	//clear everything to black
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//print the final score
	sprintf(my_score, "Final score: %d", score);
	al_draw_text(size_f, al_map_rgb(200, 0, 30), SCREEN_W / 3.5, SCREEN_H / 2 - 200, 0, my_score);
	if (newRecord(score, &record)) {
		al_draw_text(size_f, al_map_rgb(255, 255, 255), SCREEN_W / 3.8, SCREEN_H / 2 - 100, 0, "NEW RECORD!");
	} else {
		sprintf(my_score, "Record: %d", record);
		al_draw_text(size_f, al_map_rgb(0, 200, 30), SCREEN_W / 3.5, SCREEN_H / 2 - 100, 0, my_score);
	}
	al_flip_display();
	pause(*timer, 2);
	game_running = 0;
}

//restarts the game
void restartGame(ALLEGRO_DISPLAY *display)
{
	game_running = 1;
	score = 0;
	moves = MAX_MOVES;
	startGame(display);
}

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE *moveSound = NULL, *scoreSound = NULL;
    int erroAllegro;
	//initialize allegro, returns the error if there is one
    erroAllegro = initializeAllegro(&display, &event_queue, &timer, &moveSound, &scoreSound);
    if (erroAllegro < 0) {
        return erroAllegro;
    }
	//starts the game
	startGame(display);
	int playing = 1, animation_in_progress = 0, lin_src, lin_dest, col_src, col_dest, points, play_again = 0;
	while (playing) {
        ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		/*if key down, checks if it was esc, if it was, then ends the game
		if it was space and the game was finished, than the game restarts*/
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				playing = 0;
			} else if (game_running == 0 && ev.keyboard.keycode == ALLEGRO_KEY_SPACE) {
				play_again = 1;
			}
		} else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && !animation_in_progress) {
			//get the cell that was clicked
			getCell(ev.mouse.x, ev.mouse.y, &lin_src, &col_src);
		} else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && !animation_in_progress) {
			//get the cell that was released
			getCell(ev.mouse.x, ev.mouse.y, &lin_dest, &col_dest);
			//check if the game doesn't have an active animation, if the game is running, the distance, if the candies are in a diagonal position, if the type is different than 0 and different between the two candies
			if (animation_in_progress == 0 && game_running == 1 && getDistance(lin_src, col_src, lin_dest, col_dest) == 1 && isCandyDiagonal(lin_src, col_src, lin_dest, col_dest) == 0 && M[lin_src][col_src].type && M[lin_dest][col_dest].type && M[lin_src][col_src].type != M[lin_dest][col_dest].type) {
				//change the cells positions
				changeCells(lin_src, col_src, lin_dest, col_dest);
				//plays a sound
				al_play_sample(moveSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				//reduces a move
				moves--;
				//redraw the screen
		        drawScenario(display);
				//sets that an animation is in progress
				animation_in_progress = 1;
			}
		} else if (ev.type == ALLEGRO_EVENT_TIMER) {
			//checks timer (it's running 60x per second)
			/*if the game is running then check the points, 
			if there is some points that was made, sets the animation, 
			redraw the scenario, pause the timer, calculate the score
			updates the candies position, draw again, check if there are
			more points, fill the matrix again, redraw and play a sound for
			the candies dropping
			*/
			if (game_running == 1) {
				points = checkGame();
				while (points > 0) {
					animation_in_progress = 1;
					drawScenario(display);
					pause(timer, 1.0);
					score += pow(2, points);
					updateGame();
					drawScenario(display);
					points = checkGame();
					fillMatrix();
					drawScenario(display);
					al_play_sample(scoreSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				}
			}
			//if there is no moves, then checks if the game is running, if it is then just goes to the end screen
			if (moves == 0) {
				if (game_running == 1) {
					endGame(&timer);
				} else {
					//asks to press space if the player wants to play again
					char play_again_text[100];
					al_clear_to_color(al_map_rgb(0, 0, 0));
					sprintf(play_again_text, "Press space to play again");
					al_draw_text(size_f, al_map_rgb(255, 255, 255), SCREEN_W / 6, SCREEN_H / 2 - 200, 0, play_again_text);
					al_flip_display();
					pause(timer, 0.4);
					if (play_again == 1) {
						restartGame(display);
						play_again = 0;
					}
				}
			}
			animation_in_progress = 0;
		} else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			//check if the user clicked on the X
			playing = 0;
		}
	}
	//destroy the objects
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_sample(moveSound);
	al_destroy_sample(scoreSound);
    return 0;
}