#define NIL NULL
#define LEFT 0
#define RIGHT 1
#define left child[left]
#define right child[right]

void printRBT(RBT T);

enum color_t
{
  BLACK,
  RED
};

typedef struct node
{
  int key;
  struct node *parent;
  struct node *child[2];
  enum color_t color;
} RBnode;

struct RBtree
{
  RBnode *root;
}

#define childDir(N) (N == (N->parent)->right ? RIGHT : LEFT)

RBnode *
GetParent(RBnode *N)
{
  return N == NULL ? NULL : N->Parent;
}

RBnode *GetGrandParent(RBnode *N)
{
  return GetParent(GetParent(N));
}
RBnode *GetSibling(RBnode *N)
{
  RBnode *P = GetParent(N);
  return P->child[1 - childDir(N)];
}
RBnode *GetUncle(RBnode *N)
{
  RBnode *P = GetParent(N);
  return GetSibling(P);
}

RBnode *GetCloseNephew(RBnode *N)
{
  RBnode *P = GetParent(N);
  int dir;
  RBnode *S;

  dir = childDir(N);
  S = P->child[1 - dir]; // sibling of N

  return S->child[dir];
}

RBnode *GetDistantNephew(RBnode *N)
{
  RBnode *P = GetParent(N);
  int dir;
  RBnode *S;

  dir = childDir(N);
  S = P->child[1 - dir]; // sibling of N

  return S->child[1 - dir]; // the nephew distant from N
}

RBnode *RotateDirRoot(
    RBtree *T, // red–black tree
    RBnode *P, // root of subtree (may be the root of T)
    int dir)
{ // dir ∈ { LEFT, RIGHT }
  RBnode *G = P->parent;
  RBnode *S = P->child[1 - dir];
  RBnode *C;
  // assert(S != NIL); // pointer to true node required
  C = S->child[dir];
  P->child[1 - dir] = C;
  if (C != NIL)
    C->parent = P;
  S->child[dir] = P;
  P->parent = S;
  S->parent = G;
  if (G != NULL)
    G->child[P == G->right ? RIGHT : LEFT] = S;
  else
    T->root = S;
  return S; // new root of subtree
}

#define RotateDir(N, dir) RotateDirRoot(T, N, dir)
#define RotateLeft(N) RotateDirRoot(T, N, LEFT)
#define RotateRight(N) RotateDirRoot(T, N, RIGHT)