/*
 ============================================================================
 Name        : Main.c
 Author      : teyamagu
 Version     :
 Copyright   : teyamagu
 Description : LifeGame with C Lang. Sample
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _CELLDATA {
	int top;
	int bottom;
	int left;
	int right;
	int center;
	int next;
} CELLDATA;

typedef struct _CELL {
	CELLDATA status;
//	void (*print)(status);
//	void (*init)(status);
} CELL;

#define CELLS 9

typedef struct _BOARD {
	CELLDATA status[CELLS];
} BOARD;

typedef struct _INITSTATUS {
	char status[10];
} INITSTATUS;

void CELLInit(CELLDATA *self)
{
	self->top = 0;
	self->bottom = 0;
	self->left = 0;
	self->right = 0;
	self->center = 0;
	self->next = 0;
}

void BOARDInit(BOARD *self)
{
	int loopcounter = 0;

	for (loopcounter = 0; loopcounter < CELLS; loopcounter++){
		CELLInit(&(self->status[loopcounter]));
	}
}

void CELLSET(CELLDATA *self, int number)
{
	self->next= number;
}

void BOARDSET(BOARD *self, INITSTATUS setstatus)
{
	int loopcounter = 0;

	for (loopcounter = 0; loopcounter < CELLS; loopcounter++){
		CELLSET(&(self->status[loopcounter]), setstatus.status[loopcounter]-48);
	}
}

void CELLPrint(CELLDATA self)
{
	printf("top = %d, bottom = %d, left = %d, right = %d, center = %d, next = %d\n", \
		self.top, self.bottom, self.left, self.right, self.center, self.next);
}

void BOARDPrint(BOARD self)
{
	int loopcounter = 0;

	for (loopcounter = 0; loopcounter < CELLS; loopcounter++){
		printf("%d", self.status[loopcounter].next);
	}
}

void CELLUpdate(CELLDATA *self)
{
	if (self->top + self->bottom + self->left + self->right + self->center > 3){
		self->next = 1;
	}else{
		self->next = 0;
	}
}

void BOARDcheck(BOARD *self)
{
	int loopcounter = 0;

	for (loopcounter = 0; loopcounter < CELLS; loopcounter++){
		CELLUpdate(&(self->status[loopcounter]));
	}
}

void BOARDFeedBack(BOARD *self)
{
	int loopcounter = 0;

	for (loopcounter = 1; loopcounter < CELLS-1; loopcounter++){
		self->status[loopcounter].left = self->status[loopcounter-1].next;
	}
}

void BOARDUpdate(BOARD *self)
{
//	BOARDFeedback(self);
	BOARDcheck(self);
}


void LifeGame(INITSTATUS initstatus)
{
	CELLDATA single;

	CELLInit(&single);
	CELLPrint(single);

	BOARD board;
	BOARDInit(&board);

	BOARDSET(&board, initstatus);
	BOARDPrint(board);

	BOARDUpdate(&board);
	BOARDPrint(board);
}

int main(void)
{
	INITSTATUS dummtinput;
//	dummtinput.status = (char *)malloc(sizeof(char)*10);
	dummtinput.status[0] = '1';
	dummtinput.status[1] = '1';
	dummtinput.status[2] = '1';
	dummtinput.status[3] = '1';
	dummtinput.status[4] = '1';
	dummtinput.status[5] = '1';
	dummtinput.status[6] = '1';
	dummtinput.status[7] = '1';
	dummtinput.status[8] = '0';

	LifeGame(dummtinput);

//	free(dummtinput.status);

	return EXIT_SUCCESS;
}
