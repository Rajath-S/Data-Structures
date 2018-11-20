#define MAXLENGTH 10
#define LETTERS 26
typedef char Entry[MAXLENGTH];
typedef char Key[MAXLENGTH];
typedef struct trienode Trienode;

struct trienode{
Trienode* branch[LETTERS];
Entry* ref;
};
Trienode* Triesearch(Trienode* root,Key target);
Trienode* InsertTrie(Trienode* root,Key newkey,Entry* newentry);
Trienode* CreateNode();
