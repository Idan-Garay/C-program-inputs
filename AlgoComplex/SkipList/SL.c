#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LEVEL 3

typedef struct node
{
  int key;
  struct node **forward;
  int level;
} SLnode, *nodePtr;

typedef struct
{
  int level;
  SLnode *header[MAX_LEVEL];
} SkipList;

void printSL(SkipList L);

void initSL(SkipList *SL)
{
  int x;
  for (x = 0; x < MAX_LEVEL; x++)
  {
    SL->header[x] = NULL;
  }
}

int generateLevel()
{
  float random;
  int level = 0;

  do
  {
    random = (float)rand() / RAND_MAX;
    level++;
  } while (random < 0.5 && level < MAX_LEVEL);
  printf("level: %d\n", level);
  return level;
}

void insert(SkipList *SL, int elem)
{
  nodePtr *trav, tmp, *update[MAX_LEVEL];
  int x, lvl;

  for (x = SL->level, trav = &SL->header[x]; x >= 0; x--)
  {
    while (*trav != NULL && (*trav)->key < elem)
    {
      trav = &(*trav)->forward[x];
    }
    update[x] = trav;
  }

  lvl = generateLevel();

  if (lvl > SL->level) //  if level: 3 > SLevel: 1
  {
    for (x = SL->level + 1; x < lvl; x++)
    {
      update[x] = &SL->header[x];
    }
    SL->level = lvl;
  }

  tmp = (nodePtr)calloc(1, sizeof(SLnode));
  if (tmp != NULL)
  {
    tmp->forward = (nodePtr *)calloc(lvl, sizeof(nodePtr));
    tmp->key = elem;
    tmp->level = lvl;
    for (x = 0; x < lvl; x++)
    {
      tmp->forward[x] = *update[x];
      *update[x] = tmp;
    }
  }
}

int main()
{
  SkipList L;

  initSL(&L);

  insert(&L, 5);
  insert(&L, 6);
  // insert(&L, 7);
  // insert(&L, 4);
  printSL(L);
  return 0;
}

void printSL(SkipList L)
{
  int x;
  nodePtr trav;

  for (x = L.level; x >= 0; x--)
  {
    for (trav = L.header[x]; trav != NULL; trav = trav->forward[x])
    {
      printf(" %d ->", trav->key);
    }
    printf("\n");
  }
}