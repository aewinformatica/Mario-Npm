#ifndef MAIN_H
#define MAIN_H
#pragma once
/* versao compilada com fullscreen a 640x480 (quando nao consegue com 320x240) */
//#define VERSAO_640_480

/* resolucao da tela */
#ifdef VERSAO_640_480
#define RES_X 640
#define RES_Y 480
#else
#define RES_X 320
#define RES_Y 240
#endif

/* frame rate (em frames por segundo) e velocidade de animacao (para tiles) */
#define FRAME_RATE      30

/* para manter o frame rate constante */
volatile int counter;

/* variavel contadora de lacos do jogo */
int lacos;

/* opcoes de linha de comando */
char modo_16_bits, arq_fase[2][256], vol_musica, vol_som;
#endif
