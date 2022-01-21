< -1)
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