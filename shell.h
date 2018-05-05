struct node{
	char* c;
	struct node* left;
	struct node* right;
};
void prompt();
void excute(char* command );
void filecopy(int from , int to);
void blank(char* );
struct node* operate(char** ,int left , int right);
void readnode(struct node*);
void deal(struct node*);
int divide(char* buffer , char*a[]);
#define ARGL 40
#define ARGC 30
#define READ 0
#define WRITE 1
