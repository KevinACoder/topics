#ifndef TOPICS_DEFINE
#define TOPICS_DEFINE

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::vector;

//data structure
typedef double val_type;
typedef std::vector<val_type> ARR_1D_F;
struct sl_node //singal linked-list node 
{
	val_type  _val;
	sl_node   *_next;

	sl_node(val_type val):_val(val),_next(nullptr){}
};

struct dl_node //double linked-list node
{
	val_type  _val;
	dl_node   *_prev;
	dl_node   *_next;

	dl_node(val_type val):_val(val),_prev(nullptr),_next(nullptr){}
};

struct bst_node
{
	val_type	_val;
	bst_node	*_left;
	bst_node	*_right;

	bst_node(val_type val):_val(val),_left(nullptr),_right(nullptr){}
};

struct stack
{
	sl_node   *_list;

public:
	stack():_list(nullptr){}
	bool is_empty();
	void push(val_type data);
	val_type pop();
	val_type peek();

private:
	sl_node *new_node(val_type data);
};

struct queue
{
	stack    _stack_in;
	stack    _stack_out;

public:
	queue():_stack_in(),_stack_out(){}
	void enqueue(val_type data);
	val_type dequeue();
	bool is_empty();
};

struct graph
{
	sl_node		**_adj_list;
	int			*_node_list;
	int         _node_num;

public:
	graph(int num);
	void add_edge(int u, int v);
	void bfs_print(int u);
	void dfs_print(int u);

private:
	sl_node *new_node(int data);
	void dfs_until(int u, bool visited[]);
};

//algorithm
// ...sort
void cocktail_sort(val_type*& arr, const int len);
void bucket_sort(val_type*& arr, const int n);
string frequency_sort(string str);
void merge(val_type arr[], int low, int middle, int up);
void merge_sort(val_type arr[], int low, int up);
bst_node* insert_bst(bst_node *root, val_type key);
void inorder_visit(bst_node *root, val_type*& arr, int& ix);
void bst_sort(val_type*& arr, const int len);
void bubble_sort(val_type arr[], const int len);
void selection_sort(val_type arr[], const int len);
void insert_sort(val_type arr[], const int len);
int partition(val_type arr[], int low, int high); //return partition position
void quick_sort(val_type arr[], int low, int high);

void sort_demo();

// ...linked list
void linked_list_demo();
sl_node *sorted_insert(sl_node *head, val_type data);
void print_list(sl_node *head);
sl_node *del_by_key(sl_node *head, val_type key);
sl_node *del_by_pos(sl_node *head, int pos);
int get_length(sl_node *head);
int get_length_recursive(sl_node *head);
void del_list(sl_node **head_ref);
bool search_list_recursive(sl_node *head, val_type key);
sl_node *get_the_nth_node(sl_node *head, int n);
sl_node *get_the_nth_node_from_tail(sl_node *head, int n);
sl_node *get_mid_node(sl_node *head);//get middle node of list
sl_node *rev_list(sl_node *head); //reverse list
sl_node *cp_list(sl_node *head); //copy and create a new list
bool is_list_palindrome(sl_node *head); //check if list is palindrome
bool is_list_palindrome2(sl_node *head);
sl_node *find_prev_node(sl_node *head, sl_node *target); //return prev node of target
sl_node *rm_duplicate_node(sl_node *head);
void swap_nodes(sl_node **head_ref, sl_node *node1, sl_node *node2);
bool node_exist(sl_node *head, sl_node *node); //check if node exist in list
sl_node *get_tail(sl_node *head);

// ...binary search tree
bst_node *insert(bst_node *root, val_type key);
bst_node *search(bst_node *root, val_type key);
void print_inorder(bst_node *root);

// ...stack
void stack_demo();

// ...queue
void queue_demo();

// ...graph
void graph_demo();

// ...test boost
void boost_demo();

#endif