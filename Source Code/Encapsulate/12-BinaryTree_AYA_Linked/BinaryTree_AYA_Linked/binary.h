

#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LE(a, b) ((a)<=(b))
#define GT(a, b) ((a)>(b))
#define GE(a, b) ((a)>=(b))

//#define EQ(a, b) (!strcmp((a), (b)))
//#define LT(a, b) (strcmp((a), (b))<0)
//#define LE(a, b) (strcmp((a), (b))<=0)
//#define GT(a, b) (strcmp((a), (b))>0)
//#define GE(a, b) (strcmp((a), (b))>=0)


struct TreeEntry{

	int key;
	int entry;
};

struct TreeNode{

	TreeEntry entry;
	TreeNode* left,* right;
};

typedef TreeNode *Tree;

void CreateTree     (Tree* );
void ClearTree      (Tree* );
int  TreeEmpty      (Tree* );
int  TreeFull       (Tree* );
int  TreeSize       (Tree* );
int  TreeDepth      (Tree* );
//void Preorder     (Tree* , void (*) (TreeEntry));
void Inorder        (Tree* , void (*) (TreeEntry));
//void Postorder    (Tree* , void (*) (TreeEntry));
void InsertTree     (Tree* , TreeEntry*);
int DeleteTree      (Tree* , TreeEntry* , int );
void DeleteNodeTree (Tree* );
int FindTree        (Tree* , TreeEntry* , int );