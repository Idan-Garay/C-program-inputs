#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node *left, *right;
  int key;
  int height;
} nodetype, *ptr;

int getBiggerHeight(ptr n)
{
  int val = -1;
  if (n != NULL)
  {
    if (n->left != NULL && n->left->height > val)
      val = n->left->height;
    if (n->right != NULL && n->right->height > val)
      val = n->right->height;
  }
  return val;
}

int getHeight(ptr n)
{
  int val = -1;
  if (n != NULL)
    val = n->height;
  return val;
}

ptr createNode(int elem)
{
  ptr tmp = (ptr)calloc(1, sizeof(nodetype));
  if (tmp != NULL)
  {
    tmp->height = 0;
    tmp->key = elem;
    tmp->left = tmp->right = NULL;
  }
  return tmp;
}

void leftRotate(ptr *T)
{
  ptr x = *T;
  ptr y = x->right;
  x->right = y->left;
  y->left = x;
  *T = y;
  x->height = getBiggerHeight(x) + 1;
  y->height = getBiggerHeight(y) + 1;
}

void rightRotate(ptr *T)
{
  ptr x = *T;
  ptr y = x->left;
  x->left = y->right;
  y->right = x;
  *T = x;
  x->height = getBiggerHeight(x) + 1;
  y->height = getBiggerHeight(y) + 1;
}

void AVL_insert(ptr *T, int elem)
{
  if (*T == NULL)
  {
    *T = createNode(elem);
  }
  else if (elem < (*T)->key)
    AVL_insert(&(*T)->left, elem);
  else if (elem > (*T)->key)
    AVL_insert(&(*T)->right, elem);

  (*T)->height = getBiggerHeight(*T) + 1;
  int BF = getHeight((*T)->left) - getHeight((*T)->right);

  if (BF < -1)
  {
    if ((*T)->right->key > elem)
      rightRotate(&(*T)->right);
    leftRotate(T);
  }
  else if (BF > 1)
  {
    if ((*T)->left->key < elem)
      leftRotate(&(*T)->left);
    rightRotate(T);
  }
}

void AVL_deletion(ptr *T, int elem)
{
  if (*T != NULL)
  {
    if ((*T)->key != elem)
      elem < (*T)->key ? AVL_deletion(&(*T)->left, elem) : AVL_deletion(&(*T)->right, elem);
    else
    {
      ptr delNode = *T;

      if (delNode->left == NULL && delNode->right == NULL)
        *T = NULL;
      else if (delNode->left == NULL)
        *T = delNode->right;
      else if (delNode->right == NULL)
        *T = delNode->left;
      else
      {
        ptr *trav = &(*T)->left;

        while ((*trav)->right != NULL)
          trav = &(*trav)->right;

        delNode->key = (*trav)->key;
        delNode = *trav;
        *trav = (*trav)->left;
      }
      free(delNode);
    }

    int height = getBiggerHeight(*T) + 1;
    (*T)->height = height;
    int BF = getHeight((*T)->left) - getHeight((*T)->right);

    if (BF < -1)
    {
      if (elem < (*T)->right->key)
        rightRotate(&(*T)->right);
      leftRotate(T);
    }
    if (BF > 1)
    {
      if (elem > (*T)->left->key)
        leftRotate(&(*T)->left);
      rightRotate(T);
    }
  }
}

void preOrder(ptr T)
{
  if (T != NULL)
  {
    printf("%d -> ", T->key);
    preOrder(T->left);
    preOrder(T->right);
  }
}

int main()
{
  ptr T = NULL;
  int elem[5] = {1, 2, 3, 4, 5};
  int x;

  for (x = 0; x < 5; x++)
    AVL_insert(&T, elem[x]);

  preOrder(T);
  AVL_deletion(&T, 5);
  printf("\n");
  preOrder(T);

  return 0;
}