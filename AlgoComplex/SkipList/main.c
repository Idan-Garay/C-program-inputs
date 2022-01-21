#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LEVEL 3

typedef struct node
{
  int key;
  struct node **forward;
  int level;
} nodetype, *list;

typedef struct
{
  int level;
  list header[MAX_LEVEL];
} SkipList;

void printSL(SkipList A);

int randomLevel()
{
  double random;
  int level = 0;

  do
  {
    random = (double)rand() / (double)RAND_MAX;
    level++;
  } while (random < 0.5 && level < MAX_LEVEL);

  // printf("h:%d\n", level);
  return level;
}

// void insert(SkipList *L, int key)
// {
//   list *trav, *update[MAX_LEVEL], tmp;
//   int x, nodeLevel;

//   for (x = L->level, trav = &L->header[x]; x >= 0; x--)
//   {
//     while (*trav != NULL && (*trav)->key < key)
//       trav = &(*trav)->forward[x];
//     update[x] = trav;
//   }

//   nodeLevel = randomLevel();
//   if (nodeLevel > L->level)
//   {
//     for (x = L->level - 1; x < nodeLevel; x++)
//     {
//       update[x] = &L->header[x];
//     }
//     L->level = nodeLevel;
//   }
//   tmp = calloc(1, sizeof(nodetype));
//   if (tmp != NULL)
//   {
//     tmp->key = key;
//     tmp->level = nodeLevel;
//     tmp->forward = (list *)calloc(nodeLevel, sizeof(list));
//     for (x = 0; x < tmp->level; x++)
//     {
//       tmp->forward[x] = *update[x];
//       *update[x] = tmp;
//     }
//   }
// }

void insert(SkipList *L, int key)
{
  list *trav, *update[MAX_LEVEL], tmp;
  int x, nodeLevel;

  for (x = L->level - 1, trav = &L->header[x]; x >= 0; x--, trav--)
  {
    while (*trav != NULL && (*trav)->key < key)
      trav = &(*trav)->forward[x];

    update[x] = trav;
  }

  nodeLevel = randomLevel();
  if (nodeLevel > L->level)
  {
    for (x = L->level; x < nodeLevel; x++)
      update[x] = &L->header[x];

    L->level = nodeLevel;
  }
  tmp = calloc(1, sizeof(nodetype));
  if (tmp != NULL)
  {
    tmp->key = key;
    tmp->level = nodeLevel;
    tmp->forward = (list *)calloc(nodeLevel, sizeof(list));
    for (x = 0; x < tmp->level; x++)
    {
      tmp->forward[x] = *update[x];
      *update[x] = tmp;
    }
  }
}

void initSkipList(SkipList *L)
{
  int x;

  for (x = 0; x < MAX_LEVEL; x++)
  {
    L->header[x] = NULL;
  }
  L->level = 1;
}

void deleteNode(SkipList *L, int elem)
{
  list delNode;
  list *trav, *update[MAX_LEVEL];
  int x, level;

  for (x = L->level - 1, trav = &L->header[x]; x >= 0; x--, trav--)
  {
    while (*trav != NULL && (*trav)->key < elem)
    {
      trav = &(*trav)->forward[x];
    }
    update[x] = trav;
  }

  if (*update[++x] != NULL && (*update[x])->key == elem)
  {
    delNode = *update[x];
    for (x = delNode->level - 1; x >= 0; x--)
    {
      *update[x] = (*update[x])->forward[x];
      if (*update[x] == NULL)
        L->level--;
    }
    free(delNode);
  }
}

int main()
{
  SkipList L;
  int elements[10] = {1, 6, 2, 5, 7, 3, 4, 8, 9, 10};
  int x = 0;

  initSkipList(&L);
  for (x = 0; x < 10; x++)
  {
    insert(&L, elements[x]);
  }

  printSL(L);
  deleteNode(&L, 6);
  printf("\n");
  printSL(L);

  return 0;
}

void printSL(SkipList A)
{
  list trav;
  int x;

  for (trav = A.header[0]; trav != NULL; trav = trav->forward[0])
  {
    printf("%d -> ", trav->key);
  }
}