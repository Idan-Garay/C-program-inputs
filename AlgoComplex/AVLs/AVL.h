#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left, *right;
  int height;
} node, *BST;

int height(BST B)
{
  return B != NULL ? B->height : -1;
}

int getBalanceFactor(BST B)
{
  return (height(B->left) - height(B->right));
}

BST leftRotate(BST B)
{
  BST y = B->right;
  BST x = y->left;
  y->left = B;
  B->right = x;

  B->height = (height(B->left) < height(B->right)) ? height(B->right) : height(B->left) + 1;
  y->height = (height(y->left) < height(y->right)) ? height(y->right) : height(y->left) + 1;

  return y;
}

BST rightRotate(BST B)
{
  BST y = B->left;
  BST x = y->right;
  y->right = B;
  B->left = x;

  B->height = (height(B->left) < height(B->right)) ? height(B->right) : height(B->left) + 1;
  y->height = (height(y->left) < height(y->right)) ? height(y->right) : height(y->left) + 1;
  return y;
}

// BST insert(BST B, int elem)
// {
//   int balance;

//   if (B == NULL)
//   {
//     B = calloc(1, sizeof(node));
//     if (B != NULL)
//     {
//       B->key = elem;
//       B->height = 0;
//     }
//     return B;
//   }
//   else if (B->key < elem)
//   {
//     B->right = insert(B->right, elem);
//   }
//   else if (B->key > elem)
//   {
//     B->left = insert(B->left, elem);
//   }
//   else
//   {
//     return B;
//   }

//   B->height = height(B->left) < height(B->right) ? height(B->left) : height(B->right);
//   balance = getBalanceFactor(B) // L - R subtrees;

//       if (balance > 1 && elem < B->key)
//   {
//     return rightRotate(B);
//   }
//   if (balance > 1 && elem > B->key)
//   {
//     return leftRotate(B);
//   }
//   if (balance < -1 && elem B->key)
//   {
//     return left
//   }
// }

BST insert(BST B, int elem)
{
  int balance;

  if (B == NULL)
  {
    B = (BST)calloc(1, sizeof(node));
    if (B != NULL)
    {
      B->key = elem;
      B->height = 1;
    }
    return B;
  }
  else if (B->key < elem)
  {
    B->right = insert(B->right, elem);
  }
  else if (B->key > elem)
  {
    B->left = insert(B->left, elem);
  }
  else
  {
    return B;
  }

  B->height = (height(B->left) < height(B->right)) ? height(B->right) : height(B->left) + 1;
  balance = getBalanceFactor(B);

  if (balance < -1 && elem > B->right->key)
  {
    return (leftRotate(B));
  }

  if (balance < -1 && elem < B->right->key)
  {
    B->right = rightRotate(B->right);
    return leftRotate(B);
  }

  if (balance > 1 && elem < B->left->key)
  {
    return rightRotate(B);
  }

  if (balance > 1 && elem > B->left->key)
  {
    B->left = leftRotate(B->left);
    return rightRotate(B);
  }

  return B;
}

// BST deleteNode(BST B, int elem)
// {
//   int balance;
//   BST *trav, temp;

//   if (B != NULL)
//   {
//     if (B->key == elem)
//     {
//       if (B->left == NULL)
//       {
//         temp = B;
//         B = temp->left;
//         free(temp);
//       }
//       else
//       {
//         for (trav = &B->left; (*trav)->right != NULL; trav = &(*trav)->right)
//         {
//           temp = *trav;
//           *trav = temp->left;
//           B->key = temp->key;
//           free(temp);
//         }
//         return B;
//       }
//       else if (B->key < elem)
//       {
//         B->right = deleteNode(B->right, elem);
//       }
//       else
//       {
//         B->left = deleteNode(B->left, elem);
//       }
//     }
//   else
//   {
//     return B;
//   }

//     B->height = (height(B->left) < height(B->right)) ? height(B->right) : height(B->left) + 1;
//     balace = getBalanceFactor(B);
//     if (balance < -1 && elem > B->right->key)
//     {
//       return (leftRotate(B));
//     }
//     if (balance < -1 && elem < B->right->key)
//     {
//       B->right = rightRotate(B->right);
//       return leftRotate(B);
//     }
//     if (balance > 1 && elem < B->left->key)
//     {
//       return rightRotate(B)
//     }
//     if (balance > 1 && elem > B->left->key)
//     {
//       B->left = leftRotate(B->left);
//       return = rightRotate(B);
//     }
//     return B;
//   }

void preOrder(BST B)
{
  if (B != NULL)
  {
    preOrder(B->left);
    printf(" %d,", B->key);
    preOrder(B->right);
  }
}